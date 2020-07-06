#pragma once
#include "gui/Clickable_Rect.h"

struct Checkbox : public Clickable_Rect
{
  /* The difference Button from Clickable_Text is as follows:
   * Event handler code that adjusts the drawing when the left mouse
   * button is held down. The adjustments are a slightly lower vertical
   * text position (perhaps also slightly right horiz position), and a
   * darker background color. They also receive a callback function to
   * call when the mouse button is released.*/
  Checkbox(bool *state=NULL, int (*action)(void *data)=NULL, void *data=NULL);
  
  void check_event(const SDL_Event &ev);

  void draw(SDL_Surface *screen);

  SDL_Rect inner;

private:
  /* Based on the below state, alternative colors and positioning will
   * effect in draw() */
  enum
  {
  	OFF=0,
    ON=1,
  };

  bool *state;
  unsigned int almost_clicked :1;
};