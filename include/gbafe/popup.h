#ifndef GBAFE_POPUP_H
#define GBAFE_POPUP_H

#include <stdint.h>

#include "proc.h"
#include "unit.h"

struct PopupProc {
	/* 00 */ PROC_HEADER;

	/* 2C */ const u32* pDefinition;
	/* 30 */ int clock;

	/* 34 */ s8 xTileParam;
	/* 35 */ s8 yTileParam;

	/* 36 */ u8 winStyle;

	/* 37 */ u8 xTileReal;
	/* 38 */ u8 yTileReal;

	/* 39 */ u8 xTileSize;
	/* 3A */ u8 yTileSize;

	/* 3B */ u8 textColorId;

	/* 3E */ u16 iconId;
	/* 40 */ u16 iconObjTileId;
	/* 42 */ u8  iconPalId;
	/* 44 */ u8  iconX;

	/* 46 */ u16 xGfxSize;

	/* 48 */ u16 soundId;
};

#endif // GBAFE_POPUP_H
