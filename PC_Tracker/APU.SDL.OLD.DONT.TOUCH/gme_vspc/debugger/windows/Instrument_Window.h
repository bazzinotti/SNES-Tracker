#pragma once
#include "BaseD.h"
#include "gme/Spc_Dsp_Register_Map_Interface.h"
#include "sdl_dblclick.h"
#include "Colors.h"
#include "sdlfont.h"
#include "Experience.h"
#include "gui/Clickable_Text.h"
#include "gui/cursor.h"


struct Instrument_Window : public BaseD,
public Experience
{

  Instrument_Window();
  void run();
  void draw();
  void receive_event(SDL_Event &ev);

  void play_pitch(int p);
  void pause_spc();
  void restore_spc();

  void inc_voice();
  void dec_voice();
  void inc_octave();
  void dec_octave();

  struct Start_Stop
  {
    Start_Stop() : startc("Start", 10, 10), stopc("Stop ", 10, 10) {}
    Clickable_Text startc, stopc;
    bool is_started=false;
  } start_stop;
  

  struct Adjustable
  {
    Adjustable(const char *label) : up_arrow("\x5c"), down_arrow("\x5c"), label(label) {}
    Clickable_Text up_arrow,down_arrow;
    Clickable_Text label;
    uint8_t n=4;
    int n_x,n_y;
  };

  Adjustable octave, voice;
  uint16_t pc_backup;
  uint16_t *pc_ptr;
  int scancode=0;

  enum modes 
  { 
    MODE_NAV=0,
  };
  int mode=MODE_NAV;
  enum submodes
  {
    NONE=0,
  };
  int submode=NONE;
  
  bool is_first_run=true;
};