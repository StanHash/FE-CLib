// Custom labels used by my project


// Functions
void PlayBGM(u16 songID);       // Check if music option is ON before calling m4aSongNumStart.
void PlaySFX(u16 songID);       // Check if SFX option is ON before calling m4aSongNumStart.


struct ExtraRAMBitfield {
  
  unsigned fadeKeepDISPCNT : 1;
  unsigned dontBufferMinimugs : 1;
  
};
extern struct ExtraRAMBitfield extraRAMBitfield;      // 0x3000007

struct ProcStateBlend {
  
  /* 00 */ PROC_HEADER;
  /* 29 */ s8 eva_incr;           // Value to add to 1st targets every loop iteration.
  /* 2A */ s8 evb_incr;           // Value to add to 2nd targets every loop iteration.
  /* 2B */ u8 updateFrame;        // The amount of frames per blend update.
  /* 2C */ u16 bldcnt;            // BLDCNT
  /* 2E */ u8 eva_init;           // Initial 1st targets value.
  /* 2F */ u8 evb_init;           // Initial 2nd targets value.
  /* 30 */ u8 timer;              // Increased every frame. End proc if this is equal to limit.
  /* 31 */ u8 limit;              // End proc if this is equal to timer.
  
};
extern const struct ProcInstruction Procs_Blend[];    // Project2/Generic/Blend/Blend.event

extern Proc* opinfoview2_Start(Proc* proc, u8 charIndex);    // Project2/Generic/opinfoview2/opinfoview2.event


// Repointed tables
extern const struct SMSData StandingMapSpriteTable[];


// Graphics
extern const void* segmentTitleFont;
extern const u16 segmentTitleFontPal[16];
extern const void* ClassReelBGOAM;