#include "breezestyleconfigdata.h"

namespace Breeze {

void StyleConfigData::load()
{

}

StyleConfigData *StyleConfigData::self()
{
    static StyleConfigData s_data;
    return &s_data;
}

KSharedConfigPtr StyleConfigData::sharedConfig()
{
    return KSharedConfig::openConfig();
}

}
