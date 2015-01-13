#pragma once
#include "SDL.h"

#include <nfd.h>

namespace Utility
{
  Uint8 scancode_to_hex(int &scancode);
  bool coord_is_in_rect(int x, int y, SDL_Rect *r);
  int hexchar_to_int(char scancode);
  nfdresult_t get_file_write_handle(nfdchar_t **outPath, SDL_RWops **file);
}