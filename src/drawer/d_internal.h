#ifndef DINTERNAL_H
#define DINTERNAL_H

#include "drawer.h"
#include <stddef.h>
void drawer_draw_text_centralized(const char *text, size_t font_size,
                                  int x_offset, int y_offset,
                                  size_t screen_width, size_t screen_height);

void drawer_draw_button_centralized(const char *text, size_t font_size,
                                    bool hover, int x_offset, int y_offset,
                                    size_t screen_width, size_t screen_height);

#endif
