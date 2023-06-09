/*
 * Widget Showcase
 * Copyright (C) 2014-2018 Martin Bříza <mbriza@redhat.com>
 * Copyright (C) 2019 Jan Grulich <jgrulich@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include <QApplication>
#include "qstylefactory.h"
#include "widgetfactory.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setProperty("KDE_COLOR_SCHEME_PATH","D:/BreezeLight.colors");
    QApplication::setStyle(QStyleFactory::create("breeze"));
    QApplication::setFont(QFont("Microsoft YaHei", 12));

    WidgetFactory fact;
    fact.show();

    return app.exec();
}
