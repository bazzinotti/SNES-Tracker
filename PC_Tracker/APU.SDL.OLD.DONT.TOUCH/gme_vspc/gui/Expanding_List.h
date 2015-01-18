#pragma once

#include "gui/Context_Menu.h"

/*struct Expanding_List_Item
{
  Expanding_List_Item(const char *str, int (*action)(void *)=NULL, void *data=NULL);
  Clickable_Text clickable_text;
};*/


struct Expanding_List : public Context_Menu
{
  void do_thing(void *data=NULL);
  void preload(int &x, int &y, bool use_cache=false);

  Expanding_List(Context_Menu_Item *array,  bool isActive=false);
  void draw(SDL_Surface *screen);
  bool receive_event(SDL_Event &ev);
  Context_Menu_Item *currently_selected_item=NULL;
  int currently_selected_item_index=0, highlighted_item_index=0;
  SDL_Rect single_item_rect;
};