#ifndef BREEZECOMMON_EXPORT_H
#define BREEZECOMMON_EXPORT_H

#ifndef QT_STATIC
#    if defined(QT_BUILD_BREEZE_LIB)
#        define BREEZECOMMON_EXPORT Q_DECL_EXPORT
#    else
#        define BREEZECOMMON_EXPORT Q_DECL_IMPORT
#    endif
#else
#    define BREEZECOMMON_EXPORT
#endif

#endif // BREEZECOMMON_EXPORT_H
