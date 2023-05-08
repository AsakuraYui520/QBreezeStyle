TARGET = qbreezestyle

INCLUDEPATH += $$PWD/animations $$PWD/kde

HEADERS += \
    animations/breezeanimation.h \
    animations/breezeanimationdata.h \
    animations/breezeanimations.h \
    animations/breezebaseengine.h \
    animations/breezebusyindicatordata.h \
    animations/breezebusyindicatorengine.h \
    animations/breezedatamap.h \
    animations/breezedialdata.h \
    animations/breezedialengine.h \
    animations/breezeenabledata.h \
    animations/breezegenericdata.h \
    animations/breezeheaderviewdata.h \
    animations/breezeheaderviewengine.h \
    animations/breezescrollbardata.h \
    animations/breezescrollbarengine.h \
    animations/breezespinboxdata.h \
    animations/breezespinboxengine.h \
    animations/breezestackedwidgetdata.h \
    animations/breezestackedwidgetengine.h \
    animations/breezetabbardata.h \
    animations/breezetabbarengine.h \
    animations/breezetoolboxengine.h \
    animations/breezetransitiondata.h \
    animations/breezetransitionwidget.h \
    animations/breezewidgetstatedata.h \
    animations/breezewidgetstateengine.h \
    breeze.h \
    breezeaddeventfilter.h \
    breezeblurhelper.h \
    breezeboxshadowrenderer.h \
    breezecommon_export.h \
    breezeframeshadow.h \
    breezehelper.h \
    breezemdiwindowshadow.h \
    breezemetrics.h \
    breezemnemonics.h \
    breezepropertynames.h \
    breezesettings.h \
    breezeshadowhelper.h \
    breezesplitterproxy.h \
    breezestyle.h \
    breezestyleconfigdata.h \
    breezestyleplugin.h \
    breezetileset.h \
    breezetoolsareamanager.h \
    breezewidgetexplorer.h \
    breezewindowmanager.h \
    config-breeze.h \
    kde/kcolorscheme.h \
    kde/kcolorschemehelpers_p.h \
    kde/kcolorspaces_p.h \
    kde/kcolorutils.h \
    kde/ksharedconfig.h \
    kde/kstatefulbrush.h \
    kde/kwindowshadow.h



SOURCES += \
    animations/breezeanimation.cpp \
    animations/breezeanimationdata.cpp \
    animations/breezeanimations.cpp \
    animations/breezebaseengine.cpp \
    animations/breezebusyindicatordata.cpp \
    animations/breezebusyindicatorengine.cpp \
    animations/breezedialdata.cpp \
    animations/breezedialengine.cpp \
    animations/breezeenabledata.cpp \
    animations/breezegenericdata.cpp \
    animations/breezeheaderviewdata.cpp \
    animations/breezeheaderviewengine.cpp \
    animations/breezescrollbardata.cpp \
    animations/breezescrollbarengine.cpp \
    animations/breezespinboxdata.cpp \
    animations/breezespinboxengine.cpp \
    animations/breezestackedwidgetdata.cpp \
    animations/breezestackedwidgetengine.cpp \
    animations/breezetabbardata.cpp \
    animations/breezetabbarengine.cpp \
    animations/breezetoolboxengine.cpp \
    animations/breezetransitiondata.cpp \
    animations/breezetransitionwidget.cpp \
    animations/breezewidgetstatedata.cpp \
    animations/breezewidgetstateengine.cpp \
    breezeaddeventfilter.cpp \
    breezeblurhelper.cpp \
    breezeboxshadowrenderer.cpp \
    breezeframeshadow.cpp \
    breezehelper.cpp \
    breezemdiwindowshadow.cpp \
    breezemnemonics.cpp \
    breezepropertynames.cpp \
    breezeshadowhelper.cpp \
    breezesplitterproxy.cpp \
    breezestyle.cpp \
    breezestyleconfigdata.cpp \
    breezestyleplugin.cpp \
    breezetileset.cpp \
    breezetoolsareamanager.cpp \
    breezewidgetexplorer.cpp \
    breezewindowmanager.cpp \
    kde/kcolorscheme.cpp \
    kde/kcolorspaces.cpp \
    kde/kcolorutils.cpp \
    kde/kstatefulbrush.cpp \
    kde/kwindowshadow.cpp


QT += widgets-private

DEFINES += _USE_MATH_DEFINES QT_BUILD_BREEZE_LIB

DISTFILES += breeze.json

PLUGIN_TYPE = styles
PLUGIN_CLASS_NAME = QBreezeStylePlugin
load(qt_plugin)

RESOURCES += \
    breeze.qrc


