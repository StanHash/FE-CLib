#ifndef GBAFE_ANIMINTERPRETER_H
#define GBAFE_ANIMINTERPRETER_H

#include "common.h"

typedef struct AnimationInterpreter AnimationInterpreter;
typedef struct AnimationInterpreter AIStruct;
typedef struct AnimationInterpreterBuffer AISBuffer;

struct AnimationInterpreter {
	/* 00 */ u16 state;
	/* 02 */ s16 xPosition;
	/* 04 */ s16 yPosition;
	/* 06 */ u16 delayTimer;
	/* 08 */ u16 oam2base;
	/* 0A */ u16 drawLayerPriority;
	/* 0C */ u16 state2;
	/* 0E */ u16 nextRoundId;
	/* 10 */ u16 state3;
	/* 12 */ u8 currentRoundType;
	/* 13 */ u8 frameIndex;

	/* 14 */ u8 queuedCommandCount;
	/* 15 */ u8 commandQueue[0x7];
  
  /* 1C */ u16 oam0base;
  /* 1E */ u16 oam1base;

	/* 20 */ const void* pCurrentFrame;
	/* 24 */ const void* pStartFrame;
	/* 28 */ const void* pSheet;
	/* 2C */ const void* pSheetBuffer;
	/* 30 */ const void* pStartObjData; // aka "OAM data"

	/* 34 */ struct AnimationInterpreter* pPrev;
	/* 38 */ struct AnimationInterpreter* pNext;

	/* 40 */ const void* pUnk40;
	/* 44 */ const struct AISBuffer* pAISBuffer;
};

// Used by class reel, where it's stored at 0x2000000.
struct AnimationInterpreterBuffer {
  /* 00 */ u8 unk0;
  /* 01 */ u8 genericPalID;
  /* 02 */ s16 xPos;
  /* 04 */ s16 yPos;
  /* 06 */ u16 animID;
  /* 08 */ u16 charPalID;               // If -1, genericPalID is used.
  /* 0A */ u16 AISMode;                 // 0: melee, 1: melee critical, 6: Equipped with melee weapon, etc.
  /* 0C */ u16 state2;                  // Orred with AIS+0xCh.
  /* 0E */ u16 tileOffset;
  /* 10 */ u16 palOffset;
  /* 14 */ AIStruct* AIS1;
  /* 18 */ AIStruct* AIS2;
  /* 1C */ void* sheet;
  /* 20 */ void* pal;
  /* 24 */ void* rtlOAM;
  /* 28 */ void* frameData;
  /* 2C */ void* sheetPointer;
  /* 30 */ struct AISMagicEffectsBuffer* magicEffects;
  /* 34 */ Proc* Procs_ekrUnitMainMini;
};
extern AISBuffer gAISBuffer; //! FE8U = 0x2000000
const void LoadBufferIntoAIS(AISBuffer* aisBuffer);
const void StartEkrUnitMainMini(AISBuffer* aisBuffer);
const void EndEkrUnitMainMini(AISBuffer* aisBuffer);

extern u8 gBattleCharacterIndices[2]; //! FE8U = 0x203E190

void UpdateAISs(void); //! FE8U = 0x8004E41
void ClearAISs(void); //! FE8U = 0x8004EB9
struct AnimationInterpreter* CreateAIS(const u32* animScript, int depth); //! FE8U = 0x8004F49
void SortAISs(void); //! FE8U = 0x8004FAD
void DeleteAIS(struct AnimationInterpreter* ais); //! FE8U = 0x8005005
void DisplayAIS(struct AnimationInterpreter* ais); //! FE8U = 0x8005035

int GetAISSubjectId(const struct AnimationInterpreter*); //! FE8U = 0x805A16D
int IsBatteRoundTypeAMiss(u16); //! FE8U = 0x805A185
int GetBattleAnimRoundType(int index); //! FE8U = 0x8058A0D

void StartEkrNamewinAppear(int, int, int);

// This function starts and returns a proc that mimics an AIS, without adding an AIS to the AISarray.
// unk3 is some kind of control code I think.
struct Proc* StartEkrsubAnimeEmulator(s16 X, s16 Y, void* frameData, u8 unk3, struct Proc* parent, u32 OAM0OAM1, u16 OAM2); //! FE8U = 0x80716C9

#endif // GBAFE_ANIMINTERPRETER_H
