#ifndef GBAFE_H
#define GBAFE_H

#ifdef __cplusplus
extern "C" {
#endif

#pragma long_calls

#include "gba/gba.h"

#pragma long_calls_off

#include "gbafe/armfunc.h"
#include "gbafe/random.h"
#include "gbafe/hardware.h"
#include "gbafe/vramtransfer.h"
#include "gbafe/proc.h"
#include "gbafe/text.h"
#include "gbafe/face.h"
#include "gbafe/ap.h"
#include "gbafe/hiobj.h"
#include "gbafe/compress.h"
#include "gbafe/class.h"
#include "gbafe/character.h"
#include "gbafe/game.h"
#include "gbafe/item.h"
#include "gbafe/unit.h"
#include "gbafe/map.h"
#include "gbafe/menu.h"
#include "gbafe/targetselect.h"
#include "gbafe/levelup.h"
#include "gbafe/standunit.h"
#include "gbafe/mu.h"
#include "gbafe/trap.h"
#include "gbafe/action.h"
#include "gbafe/chapterdata.h"
#include "gbafe/animinterpreter.h"
#include "gbafe/ai.h"
#include "gbafe/sound.h"
#include "gbafe/debugprint.h"
#include "gbafe/other.h"
#include "gbafe/popup.h"
#include "gbafe/icon.h"
#include "gbafe/sram.h"
#include "gbafe/save.h"
#include "gbafe/event.h"

#ifdef __cplusplus
} // extern "C"
#endif

#endif // GBAFE_H
