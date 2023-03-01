// Vanilla definitions not in gbafe.h.

// Functions.
const void NewFadeIn(int fadeRate);
const void NewFadeOut(int fadeRate);
const int FadeInExists();
const int FadeOutExists();
const void StartEkrAnimeDrvProc();
const void EndEkrAnimeDrvProc();
const int GetValueFromEasingFunction(u8 rateFunction, int startX, int endX, u32 currentT, u32 endT); //! FE8U = 0x8012DCC
const void CopyTileGfxForObj(void* src, void* dest, u8 width, u8 height);
ProcState* startopinfoview(ProcState* parent, int charIndex);
const void drawopinfochars(u8 charIndex, int X, int Y, u16 width, u16 height, u8 paletteDarkness);
const void _ProcSleepCallback(Proc* proc);
const void* MMS_GetGfx(u8 classID);
const void Sound_SongTransition(u16 songID, u32 unk1, u32 unk2, int speed, u32 unk4);
const Proc* StartScreenMenuScrollingBg(Proc* parent, void* graphicsDest, u8 paletteSlot); //! FE8U = 0x8086BB8
const void SetEventId(u16 eventId); //! FE8U = 0x8083D80
const void UnsetEventId(u16 eventId); //! FE8U = 0x8083D94
const u8 CheckEventId(u16 eventId); //! FE8U = 0x8083DA8

// Procs.
extern const ProcInstruction gProc_FadeOut[];
extern const ProcInstruction gProc_FadeIn[];
extern const ProcInstruction gProc_ekrUnitMainMini[];

// Graphics.
extern const void* ClassReelBGTiles;
extern const u16 ClassReelBGPalette[16];
extern const u16 gPal_ClassReelGlyphs2[16]; //! FE8U = 0x8A37300
extern const void* op_class_font_address[];
extern Proc* ClassReelLetterProcs[20];
extern const u16 gPal_MapSprite[112];

// OAMData.
extern const ObjData gObj_8x8;
extern const ObjData gObj_16x16;
extern const ObjData gObj_32x32;
extern const ObjData gObj_16x32;

// Buffers.
extern u8 gSMSGfxBuffer_Frame1[0x2000];
extern u8 gSMSGfxBuffer_Frame2[0x2000];
extern u8 gSMSGfxBuffer_Frame3[0x2000];
extern u16 gpStatScreenPageBg0Map[0x280]; //! FE8U = 0x2003D2C
extern u16 gpStatScreenPageBg1Map[0x280]; //! FE8U = 0x200422C
extern u16 gpStatScreenPageBg2Map[0x280]; //! FE8U = 0x200472C