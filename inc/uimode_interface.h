#pragma once

#include <QMap>
#include <QPair>
#include <functional>

class UIModeInterface
{
 public:
    using Metods = QPair<std::function<void(void)>, std::function<void(void)>>;
    using Modes  = QMap<unsigned int, Metods>;

    UIModeInterface() {}

    void setPreviousUIMode();
    void clearUIMode(unsigned int mode);

    inline bool isUIModePresent(unsigned int mode) const { return mActiveMode & mode; }
    inline unsigned int getActiveMode() const { return mActiveMode; }

    inline void setUIModes(const Modes& modes) { mModes = modes; }
    void setUIMode(unsigned int set_mode, unsigned int clear_mode, bool is_active);
    void setUIMode(unsigned int mode, bool is_active);
    void setUIMode(unsigned int mode);

 private:
    Modes mModes;
    unsigned int mActiveMode{0};
    unsigned int mPreviousMode{0};
};
