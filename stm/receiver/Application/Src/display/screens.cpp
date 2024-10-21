#include "display/screens.hpp"
#include "display/screens/scroll.hpp"
#include "display/screens/edit.hpp"
#include "display/screens/live.hpp"
#include "display/options/redirect.hpp"
#include "display/options/toggle.hpp"
#include "display/options/action.hpp"
#include "display/titles/text.hpp"
#include "display/titles/image.hpp"
#include "display/streams/print.hpp"
#include "signal.h"
#include "eeprom.h"
#include "bitmaps.h"
#include <stdio.h>

Screen* Screens_GetScreen(enum ScreenName name) {
    if (name == ScrnMenu) {
        return new Scroll(new Image(bm_logo, 128, 16),
            new Option*[3] {
                new Action("Test Steering", &Signal_TestSteering),
                new Action("Test Motor", &Signal_TestMotor),
                new Action("Blah Blah", &Signal_TestMotor)
            }, 3);
    }
    return nullptr;
}
