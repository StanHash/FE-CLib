#ifndef GBAFE_SOUND_H
#define GBAFE_SOUND_H

#include "common.h"
#include "chapterdata.h"

typedef struct SongTableEntry SongTableEntry;
typedef struct MusicPlayerInfo MusicPlayerInfo;

// TODO
u16 Sound_GetCurrentSong(void); //! FE8U = 0x8002259
s8 Sound_IsSongPlaying(void); //! FE8U = 0x8002265
void Sound_SetVolume_8002274(int volume); //! FE8U = 0x8002275
void Sound_SetSongVolume(int volume); //! FE8U = 0x80022ED
void Sound_FadeSongOut(int speed); //! FE8U = 0x800231D
void Sound_FadeOut_Song(int speed); //! FE8U = 0x800237D
void Sound_FadeOut_Sfx(int speed); //! FE8U = 0x80023E1
void Sound_PlaySong(int songId, void* player); //! FE8U = 0x8002449
void Sound_PlaySongSmoothCommon(int songId, int speed, void* player); //! FE8U = 0x8002479
void Sound_PlaySongSmooth(int songId, void* player); //! FE8U = 0x80024D5
void Sound_PlaySongSmoothExt(int songId, int speed, void* player); //! FE8U = 0x80024E5
void StartSongVolumeTransitionB(int volume, int b, int c, struct Proc* parent); //! FE8U = 0x8002731
void PlaySongDelayed(int songId, int delay, void* player); //! FE8U = 0x8002859
void Sound_PlaySongCore(int songId, void* player); //! FE8U = 0x8002891
void SetSoundDefaultMaxChannels(void); //! FE8U = 0x80028D1
void SetSoundMaxChannels(int maxchn); //! FE8U = 0x80028E9
void Sound_SetupMaxChannelsForSong(int songId); //! FE8U = 0x80028FD
void CancelPlaySongDelayed(void); //! FE8U = 0x8002AB9

// TODO: m4a header
void m4aSongNumStart(int);

#define PlaySfx(aSongId) do { \
	if (!gChapterData.muteSfxOption) \
		m4aSongNumStart(aSongId); \
} while (0)

struct SongTableEntry {
  /* 00 */ const void* songHeader;
  /* 04 */ const u32 priority;
};
extern const SongTableEntry gSongTable[]; //! FE8U = 0x224470

// Thanks to 7743 for the details on this. TODO, not everything here is final.
struct MusicPlayerInfo {
  /* 00 */ void* songHeader;
  /* 04 */ u32 status;
  /* 08 */ u8 trackCount;
  /* 09 */ u8 priority;
  /* 0A */ u8 cmd;
  /* 0B */ u8 unk_B;
  /* 0C */ u32 clock;
  /* 10 */ u8 gap[8];
  /* 18 */ u32 memAccAreaPtr;
  /* 1C */ u16 tempoD;
  /* 1E */ u16 tempoU;
  /* 20 */ u16 tempoI;
  /* 22 */ u16 tempoC;
  /* 24 */ u16 fadeOI;
  /* 26 */ u16 fadeOC;
  /* 28 */ u16 fadeOV;
  /* 2A */ u16 _pad2A;
  /* 2C */ void* tracksArray;
  /* 30 */ void* instrument_tonedata_topdata;
  /* 34 */ u32 ident;
  /* 38 */ u32 func;
  /* 3C */ u32 intp;
};
extern MusicPlayerInfo gMusicPlayerInfo0; //! FE8U = 0x3006440
extern MusicPlayerInfo gMusicPlayerInfo1; //! FE8U = 03006650
extern MusicPlayerInfo gMusicSEPlayerInfo2; //! FE8U = 03006690
extern MusicPlayerInfo gMusicSEPlayerInfo3; //! FE8U = 030066D0
extern MusicPlayerInfo gMusicSEPlayerInfoUnk1; //! FE8U = 030063C0
extern MusicPlayerInfo gMusicSEPlayerInfoUnk2; //! FE8U = 03006400
extern MusicPlayerInfo gMusicSEPlayerInfoUnk3; //! FE8U = 03006610
extern MusicPlayerInfo gMusicSEPlayerInfo4; //! FE8U = 03006720
extern MusicPlayerInfo gMusicSEPlayerInfo5; //! FE8U = 03006760

#endif // GBAFE_SOUND_H
