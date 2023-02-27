#ifndef GBAFE_DIALOGUE_H
#define GBAFE_DIALOGUE_H

#include "proc.h"

struct DialogueState {
  /* 00 */ void* charPointer;
  /* 04 */ u32 unk4;
  /* 08 */ s8 defaultTextColId;
  /* 09 */ u8 currLine;
  /* 0A */ u8 displayLineCount;
  /* 0B */ u8 currLineId;
  
  /* 0C */ u8 xPos;
  /* 0D */ u8 yPos;
  /* 0E */ u8 width;
  
  /* 0F */ u8 facePos;
  /* 10 */ u8 facePos2;
  /* 11 */ u8 currFacePos;
  
  /* 12 */ u8 displayInstantly;
  /* 13 */ u8 charDelay;
  /* 14 */ u8 delayCounter;
  
  /* 15 */ u8 textDrawnFlag;
  
  /* 16 */ u8 toggleMouthMove;
  /* 17 */ u8 toggleSmile;
  
  /* 18 */ u32 faceProcs[8];
  /* 38 */ u32 unk38;
  
  /* 3C */ u32 goldAmount;
  /* 40 */ char goldAmountChars[0x20];
  /* 60 */ char someString[0x20];
  
  /* 80 */ u16 bitfield; // Enumerated below
  
  /* 82 */ u8 unk82;
  /* 83 */ u8 toggleInvertFlags;
};

enum
{
	// Dialogue flags

	DIALOGUE_1 = (1 << 0),
	DIALOGUE_2 = (1 << 1),
	DIALOGUE_NOSKIP = (1 << 2),
	DIALOGUE_NOFAST = (1 << 3),
	DIALOGUE_10 = (1 << 4),
	DIALOGUE_20 = (1 << 5),
	DIALOGUE_40 = (1 << 6),
	DIALOGUE_80 = (1 << 7),
	DIALOGUE_100 = (1 << 8),
};

enum
{
	// Dialogue options identifiers

	DIALOGUE_OPT_BACK,
	DIALOGUE_OPT_FIRST,
	DIALOGUE_OPT_SECOND,
};

// TODO: more

void Dialogue_BoxAppearingAnimationLoop(struct Proc* proc); //!< FE8U:080083F9
void Dialogue_InitGfx(unsigned tileId, unsigned lineCount, u8 boolUseBubble); //!< FE8U:0800680D
void Dialogue_InitFont(void); //!< FE8U:08006979
void StartDialogue(int xTile, int yTile, const char* cstring, struct Proc* parent); //!< FE8U:0800698D
void SetDialogueFlag(unsigned flag); //!< FE8U:08006AA9
void Dialogue_SetDefaultTextColor(int color); //!< FE8U:08006B11
void Dialogue_SetActiveFacePosition(unsigned dialogueSlot); //!< FE8U:08007839
// void StartDialogueFace(unsigned portrait, int x, int y, unsigned display, unsigned dialogueSlot); //!< FE8U:08007939
void Procs_TextBoxSlideAnimationLoop(Proc* proc); //!< FE8U: 08007FDC
void Procs_TextBoxSlideAnimation2Loop(Proc* proc); //!< FE8U: 08007DA4
// void Dialogue_ClearLines(void); //!< FE8U:08008251
int GetLastDialoguePromptResult(void); //!< FE8U:08008A01

extern struct DialogueState* gpDialogueState; //!< FE8U:0859133C

#endif // GBAFE_DIALOGUE_H
