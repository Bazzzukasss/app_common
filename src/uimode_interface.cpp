#include "uimode_interface.h"

void UIModeInterface::setUIMode(unsigned int set_mode, unsigned int clear_mode, bool is_active)
{
    mPreviousMode = mActiveMode;
    clearUIMode(clear_mode);
    setUIMode(set_mode, is_active);
}

void UIModeInterface::setUIMode(unsigned int mode, bool is_active)
{
    mPreviousMode = mActiveMode;
    if (is_active)
        setUIMode(mode);
    else
        clearUIMode(mode);
}

void UIModeInterface::setUIMode(unsigned int mode)
{
    mPreviousMode = mActiveMode;
    mActiveMode |= mode;
    for (auto m : mModes.keys())
    {
        if ((m & mActiveMode) == m)
            mModes[m].first();
    }
}

void UIModeInterface::setPreviousUIMode()
{
    setUIMode(mPreviousMode, true);
}

void UIModeInterface::clearUIMode(unsigned int mode)
{
    mActiveMode &= ~mode;
    for (auto m : mModes.keys())
    {
        if ((m & mode) == m)
            mModes[m].second();
    }
}
