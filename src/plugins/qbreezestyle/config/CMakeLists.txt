### configuration plugin
add_definitions(-DTRANSLATION_DOMAIN=\"breeze_style_config\")
set(kstyle_breeze_config_PART_SRCS breezestyleconfig.cpp)

set(kstyle_breeze_config_PART_SRCS ${kstyle_breeze_config_PART_SRCS} breezestyleconfigmodule.cpp)

kconfig_add_kcfg_files(kstyle_breeze_config_PART_SRCS ../breezestyleconfigdata.kcfgc)
set(kstyle_breeze_config_PART_FORMS ui/breezestyleconfig.ui)
ki18n_wrap_ui(kstyle_breeze_config_PART_FORMS_HEADERS ${kstyle_breeze_config_PART_FORMS})

kcoreaddons_add_plugin(breezestyleconfig SOURCES
    ${kstyle_breeze_config_PART_SRCS}
    ${kstyle_breeze_config_PART_FORMS_HEADERS}
    INSTALL_NAMESPACE "plasma/kcms/systemsettings_qwidgets"
)

target_link_libraries(breezestyleconfig Qt::Core Qt::Gui Qt::Widgets Qt::DBus)
target_link_libraries(breezestyleconfig KF${QT_MAJOR_VERSION}::CoreAddons KF${QT_MAJOR_VERSION}::ConfigCore KF${QT_MAJOR_VERSION}::ConfigWidgets KF${QT_MAJOR_VERSION}::I18n)
if(QT_MAJOR_VERSION STREQUAL "6")
    target_link_libraries(breezestyleconfig KF${QT_MAJOR_VERSION}::KCMUtils)
endif()
kcmutils_generate_desktop_file(breezestyleconfig)

set(breeze_settings_SOURCES main.cpp)
add_executable(breeze-settings5 ${breeze_settings_SOURCES} )
target_link_libraries(breeze-settings5 Qt::Core Qt::Gui Qt::Widgets )
target_link_libraries(breeze-settings5 KF${QT_MAJOR_VERSION}::I18n KF${QT_MAJOR_VERSION}::KCMUtils KF${QT_MAJOR_VERSION}::CoreAddons)

install(TARGETS breeze-settings5 ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

# icon
ecm_install_icons(ICONS sc-apps-breeze-settings.svgz
    DESTINATION ${KDE_INSTALL_ICONDIR}
    THEME hicolor )
