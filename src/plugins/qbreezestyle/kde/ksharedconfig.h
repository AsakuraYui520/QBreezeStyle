/*
  This file is part of the KDE libraries
  Copyright (c) 1999 Preston Brown <pbrown@kde.org>
  Copyright (C) 1997-1999 Matthias Kalle Dalheimer (kalle@kde.org)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Library General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Library General Public License for more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; see the file COPYING.LIB.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.
*/

#ifndef KSHAREDCONFIG_H
#define KSHAREDCONFIG_H

//#include <kconfig.h>
#include <QExplicitlySharedDataPointer>
#include <QSettings>
#include <QColor>

class KConfig
{
public:
    enum OpenFlag {
        IncludeGlobals  = 0x01, ///< Blend kdeglobals into the config object.
        CascadeConfig   = 0x02, ///< Cascade to system-wide config files.

        SimpleConfig    = 0x00, ///< Just a single config file.
        NoCascade       = IncludeGlobals, ///< Include user's globals, but omit system settings.
        NoGlobals       = CascadeConfig, ///< Cascade to system settings, but omit user's globals.
        FullConfig      = IncludeGlobals | CascadeConfig ///< Fully-fledged config, including globals and cascading to system settings
    };
    Q_DECLARE_FLAGS(OpenFlags, OpenFlag)

    explicit KConfig(const QString & fileName, OpenFlags mode = FullConfig)
        :settings(fileName, QSettings::IniFormat)
    {
        _name = fileName;
        Q_UNUSED(mode)
    }

    QString name() const { return _name; }

    bool hasGroup(const QString & group) const { return settings.childGroups().contains(group); }

    QMap<QString,QVariant> group(const QString & group)
    {
        settings.beginGroup(group);
        const QStringList keys = settings.allKeys();
        QMap<QString,QVariant> entryMap;
        for(const auto& key : keys)
            entryMap.insert(key,settings.value(key));
        settings.endGroup();

        return entryMap;
    }
protected:
    QSettings settings;
    QString _name;
};

class /*KCONFIGCORE_EXPORT*/ KSharedConfig : public KConfig, public QSharedData //krazy:exclude=dpointer (only for refcounting)
{
public:
    typedef QExplicitlySharedDataPointer<KSharedConfig> Ptr;

public:
    /**
     * Creates a KSharedConfig object to manipulate a configuration file
     *
     * If an absolute path is specified for @p fileName, that file will be used
     * as the store for the configuration settings.  If a non-absolute path
     * is provided, the file will be looked for in the standard directory
     * specified by resourceType.  If no path is provided, a default
     * configuration file will be used based on the name of the main
     * application component.
     *
     * @p mode determines whether the user or global settings will be allowed
     * to influence the values returned by this object.  See KConfig::OpenFlags for
     * more details.
     *
     * @param fileName     the configuration file to open. If empty, it will be determined
     *                     automatically (from --config on the command line, otherwise
     *                     from the application name + "rc")
     * @param mode         how global settings should affect the configuration
     *                     options exposed by this KConfig object
     * @param resourceType The standard directory to look for the configuration
     *                     file in (see QStandardPaths)
     *
     * @sa KConfig
     */
//    static KSharedConfig::Ptr openConfig(const QString &fileName = QString(),
//                                         OpenFlags mode = FullConfig,
//                                         QStandardPaths::StandardLocation type = QStandardPaths::GenericConfigLocation);

    static KSharedConfig::Ptr openConfig(const QString &fileName = QString(), OpenFlags mode = FullConfig)
    {
        KSharedConfig::Ptr ptr(new KSharedConfig(fileName, mode));
        return ptr;
    }


    virtual ~KSharedConfig() {}

private:
    Q_DISABLE_COPY(KSharedConfig)
//    KConfigGroup groupImpl(const QByteArray &aGroup) Q_DECL_OVERRIDE;
//    const KConfigGroup groupImpl(const QByteArray &aGroup) const Q_DECL_OVERRIDE;

    KSharedConfig(const QString &fileName, OpenFlags mode = FullConfig)
        :KConfig(fileName, mode)
    {

    }


};
typedef KSharedConfig::Ptr KSharedConfigPtr;

class KConfigGroup
{
public:
    explicit KConfigGroup(const KSharedConfigPtr &config,const QString &group)
    {
        entryMap = config->group(group);
    }

    KConfigGroup(const QMap<QString,QVariant> & map)
        :entryMap(map)
    {

    }

    ~KConfigGroup()
    {

    }

    bool hasKey(const QString & key) const
    {
        return entryMap.contains(key);
    }

    template<typename T>
    T readEntry(const QString & name, const T defaultValue = T()) const
    {
        return entryMap.value(name, defaultValue).value<T>();
    }

    template<>
    QColor readEntry(const QString & name, const QColor defaultValue) const
    {
        QStringList strRGB =  entryMap.value(name, defaultValue).toStringList();
        if(strRGB.size() == 3)
            return QColor(strRGB[0].toInt(),strRGB[1].toInt(),strRGB[2].toInt());
        else if(strRGB.size() == 4)
            return QColor(strRGB[0].toInt(),strRGB[1].toInt(),strRGB[2].toInt(),strRGB[3].toInt());
        else
            return defaultValue;
    }
private:
    QMap<QString,QVariant> entryMap;
};



#endif // multiple inclusion guard
