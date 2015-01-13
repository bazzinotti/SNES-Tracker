#include "utility.h"

namespace Utility
{
Uint8 scancode_to_hex(int &scancode)
{
    if ((scancode >= '0') && (scancode <= '9'))
      return scancode - '0';
    else if ((scancode >= 'A') && (scancode <= 'F'))
      return (scancode - 'A') + 0x0a;
    else if ((scancode >= 'a') && (scancode <= 'f'))
      return (scancode - 'a') + 0x0a;

  return 0xff; 
}
bool coord_is_in_rect(int x, int y, SDL_Rect *r)
{
  return (x >= (r->x) && x < (r->x + r->w) &&
      y >= (r->y) && y < (r->y+r->h) ); 
}

int hexchar_to_int(char scancode)
{
  if ((scancode >= '0') && (scancode <= '9'))
    return scancode - '0';
  else if ((scancode >= 'A') && (scancode <= 'F'))
    return (scancode - 'A') + 0x0a;
  else if ((scancode >= 'a') && (scancode <= 'f'))
    return (scancode - 'a') + 0x0a;
}

nfdresult_t get_file_write_handle(nfdchar_t **outPath, SDL_RWops **file)
{
  char tmpbuf[200];
  nfdresult_t result = NFD_SaveDialog( NULL, NULL, outPath );

    if ( result == NFD_OKAY ) {
        //puts("Success!");
        //puts(outPath);
        //SDL_RWops* SDL_RWFromFile(const char* file,
          //                const char* mode)
        *file = SDL_RWFromFile(*outPath, "wb");
        if (*file == NULL)
        {
          sprintf(tmpbuf, "Warning: Unable to open file!\n %s", SDL_GetError() );
          SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                         "Could not open FILE!",
                         tmpbuf,
                         NULL);
          return NFD_ERROR;
        }
        return result;
    }
    else if ( result == NFD_CANCEL ) {
        puts("User pressed cancel.");
        return result;
    }
    else {
        printf("Error: %s\n", NFD_GetError() );
        return NFD_ERROR;
    }
}

}