#pragma once
#include "DEBUGLOG.h"
#include "SongSettings.h"
#include "Samples.h"
#include "Instruments.h"
#include "Pattern.h"
#include <assert.h>


// Song File Version info
//////////////////////////////////////////////////////////////////
#define SONGFILE_VER_MAJOR 0
#define SONGFILE_VER_MINOR 1
#define SONGFILE_VER_MICRO 0
// concats the 3 version values into a string
#define SONGFILE_VER_STRING(maj, min, mic) #maj "." #min "." #mic
// allows calling the above macro with macro arguments
#define SONGFILE_VER_STRING2(maj, min, mic) SONGFILE_VER_STRING(maj, min, mic)
// The final actual "public" macro for a version string
#define SONGFILE_VERSION SONGFILE_VER_STRING2(SONGFILE_VER_MAJOR, SONGFILE_VER_MINOR, SONGFILE_VER_MICRO)
//////////////////////////////////////////////////////////////////

struct Song
{
  void reset();
  void load(SDL_RWops *file);
  void save(SDL_RWops *file);

  Sample samples[NUM_SAMPLES];
  Instrument instruments[NUM_INSTR];
  PatternSequencer patseq;
  SongSettings settings;
};

class SongFileLoader
{
public:
  static const char constexpr HeaderStr[] = "SONGST";
  STATIC_HEADER_CHECK(HeaderStr, FILE_HEADER_LEN);

  /* TODO: define outside class Song, and use that instead of all of these structures as dependency */
  SongFileLoader(Song *song);

  ~SongFileLoader();

  enum ret_t {
    HEADER_OK=0,
    HEADER_OLD,
    HEADER_BAD,
    FILE_LOADED,
    FILE_NOT_LOADED,
  };

  // convenience function
  size_t save(SDL_RWops *file);

  ret_t load(SDL_RWops *file);

private:
  ret_t readHeader(SDL_RWops *file);

/* Here lies a collection of subclassed FileLoaders that are associated with
handling a particular filetype. In this case, Song. */
  VersionChunkLoader *vcl;
  SongSettingsChunkLoader *sscl;
  SampleChunkLoader *scl;
  InstrumentChunkLoader *icl;
  PatternChunkLoader *pcl;
  PatternSequencerChunkLoader *pscl;


  int loadOld(SDL_RWops *file); // load the oldest file format
/* Need a handle on these guys for loadOld() */
  Song *song;
};
