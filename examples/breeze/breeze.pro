QT += charts

SOURCES += \
    main.cpp\
	widgetfactory.cpp
	
HEADERS += \
    widgetfactory.h

FORMS += \
    widgetfactory.ui

target.path = $$[QT_INSTALL_EXAMPLES]/breeze
INSTALLS += target
