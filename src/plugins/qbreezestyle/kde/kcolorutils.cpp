/* This file is part of the KDE project
 * Copyright (C) 2007 Matthew Woehlke <mw_triad@users.sourceforge.net>
 * Copyright (C) 2007 Thomas Zander <zander@kde.org>
 * Copyright (C) 2007 Zack Rusin <zack@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#include "kcolorutils.h"
#include "kcolorspaces_p.h"
#include "kguiaddons_colorhelpers_p.h"

#include <QColor>
#include <QImage>
#include <QtNumeric> // qIsNaN

#include <math.h>

// BEGIN internal helper functions
static inline qreal mixQreal(qreal a, qreal b, qreal bias)
{
    return a + (b - a) * bias;
}
// END internal helper functions

qreal KColorUtils::luma(const QColor &color)
{
    return KColorSpaces::KHCY::luma(color);
}

void KColorUtils::getHcy(const QColor &color, qreal *h, qreal *c, qreal *y, qreal *a)
{
    if (!c || !h || !y) {
        return;
    }
    KColorSpaces::KHCY khcy(color);
    *c = khcy.c;
    *h = khcy.h;
    *y = khcy.y;
    if (a) {
        *a = khcy.a;
    }
}

static qreal contrastRatioForLuma(qreal y1, qreal y2)
{
    if (y1 > y2) {
        return (y1 + 0.05) / (y2 + 0.05);
    } else {
        return (y2 + 0.05) / (y1 + 0.05);
    }
}

qreal KColorUtils::contrastRatio(const QColor &c1, const QColor &c2)
{
    return contrastRatioForLuma(luma(c1), luma(c2));
}

QColor KColorUtils::lighten(const QColor &color, qreal ky, qreal kc)
{
    KColorSpaces::KHCY c(color);
    c.y = 1.0 - normalize((1.0 - c.y) * (1.0 - ky));
    c.c = 1.0 - normalize((1.0 - c.c) * kc);
    return c.qColor();
}

QColor KColorUtils::darken(const QColor &color, qreal ky, qreal kc)
{
    KColorSpaces::KHCY c(color);
    c.y = normalize(c.y * (1.0 - ky));
    c.c = normalize(c.c * kc);
    return c.qColor();
}

QColor KColorUtils::shade(const QColor &color, qreal ky, qreal kc)
{
    KColorSpaces::KHCY c(color);
    c.y = normalize(c.y + ky);
    c.c = normalize(c.c + kc);
    return c.qColor();
}

static QColor tintHelper(const QColor &base, qreal baseLuma, const QColor &color, qreal amount)
{
    KColorSpaces::KHCY result(KColorUtils::mix(base, color, pow(amount, 0.3)));
    result.y = mixQreal(baseLuma, result.y, amount);

    return result.qColor();
}

QColor KColorUtils::tint(const QColor &base, const QColor &color, qreal amount)
{
    if (amount <= 0.0) {
        return base;
    }
    if (amount >= 1.0) {
        return color;
    }
    if (qIsNaN(amount)) {
        return base;
    }

    qreal baseLuma = luma(base); //cache value because luma call is expensive
    double ri = contrastRatioForLuma(baseLuma, luma(color));
    double rg = 1.0 + ((ri + 1.0) * amount * amount * amount);
    double u = 1.0, l = 0.0;
    QColor result;
    for (int i = 12; i; --i) {
        double a = 0.5 * (l + u);
        result = tintHelper(base, baseLuma, color, a);
        double ra = contrastRatioForLuma(baseLuma, luma(result));
        if (ra > rg) {
            u = a;
        } else {
            l = a;
        }
    }
    return result;
}

QColor KColorUtils::mix(const QColor &c1, const QColor &c2, qreal bias)
{
    if (bias <= 0.0) {
        return c1;
    }
    if (bias >= 1.0) {
        return c2;
    }
    if (qIsNaN(bias)) {
        return c1;
    }

    qreal r = mixQreal(c1.redF(),   c2.redF(),   bias);
    qreal g = mixQreal(c1.greenF(), c2.greenF(), bias);
    qreal b = mixQreal(c1.blueF(),  c2.blueF(),  bias);
    qreal a = mixQreal(c1.alphaF(), c2.alphaF(), bias);

    return QColor::fromRgbF(r, g, b, a);
}

QColor KColorUtils::overlayColors(const QColor &base, const QColor &paint,
                                  QPainter::CompositionMode comp)
{
    // This isn't the fastest way, but should be "fast enough".
    // It's also the only safe way to use QPainter::CompositionMode
    QImage img(1, 1, QImage::Format_ARGB32_Premultiplied);
    QPainter p(&img);
    QColor start = base;
    start.setAlpha(255); // opaque
    p.fillRect(0, 0, 1, 1, start);
    p.setCompositionMode(comp);
    p.fillRect(0, 0, 1, 1, paint);
    p.end();
    return img.pixel(0, 0);
}
