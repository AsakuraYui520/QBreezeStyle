#ifndef BREEZESTYLECONFIGDATA_H
#define BREEZESTYLECONFIGDATA_H

#include <QColor>
#include <KSharedConfig>

namespace Breeze
{

class StyleConfigData
{
public:
    void load();

    static StyleConfigData *self();

    enum MnemonicsMode
    {
        MN_AUTO,
        MN_NEVER,
        MN_ALWAYS
    };

    enum ShadowSize
    {
        ShadowNone,
        ShadowSmall,
        ShadowMedium,
        ShadowLarge,
        ShadowVeryLarge,
    };

    enum WindowDragMode
    {
        WD_NONE,
        WD_MINIMAL,
        WD_FULL
    };

    KSharedConfigPtr sharedConfig();

    static int mnemonicsMode() { return MN_AUTO; }

    static int animationsDuration() { return self()->AnimationsDuration; }

    static int animationSteps() { return 10; }

    static bool animationsEnabled() { return self()->AnimationsEnabled; }

    static void setAnimationsDuration(int duration) { self()->AnimationsDuration = duration; }

    static void setAnimationsEnabled(bool enabled) { self()->AnimationsEnabled = enabled; }

    static bool stackedWidgetTransitionsEnabled() { return false;}

    static bool progressBarAnimated() { return true; }

    static int progressBarBusyStepDuration() { return 800; }

    static int splitterProxyWidth() { return 12; }

    static ShadowSize shadowSize() { return ShadowLarge; }

    static QColor shadowColor() { return QColor(0,0,0); }

    static int shadowStrength() { return 255; }

    static bool widgetExplorerEnabled() { return false;}

    static bool viewInvertSortIndicator() { return false;}

    static bool drawWidgetRects() { return false;}

    static int windowDragMode() {return WD_FULL; }

    static QStringList windowDragWhiteList() { return QStringList();}

    static QStringList windowDragBlackList() { return QStringList();}

    static int menuOpacity() { return 100;}

    static bool tabBarDrawCenteredTabs() { return false;}

    static bool dockWidgetDrawFrame() { return false;}

    static bool menuItemDrawStrongFocus() { return true;}

    static bool viewDrawTreeBranchLines() { return true;}

    static bool splitterProxyEnabled() { return true;}

    static int scrollBarAddLineButtons() { return 0;}

    static int scrollBarSubLineButtons() { return 0;}

    static bool viewDrawFocusIndicator() { return true;}

    static bool sidePanelDrawFrame() { return false;}

    static bool sliderDrawTickMarks() { return true;}

    static bool outlineCloseButton() { return false;}

    static bool toolBarDrawItemSeparator() { return true;}


private:
    Q_DISABLE_COPY(StyleConfigData)

    StyleConfigData() {}

    int AnimationsDuration = 250;

    bool AnimationsEnabled = true;
};

}
#endif // BREEZESTYLECONFIGDATA_H
