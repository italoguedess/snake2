#ifndef DRAWER_H
#define DRAWER_H

#include <raylib.h>
#include <stddef.h>

typedef enum {
  DT_DRAWER,
  DT_COUNT

} DrawerType;

typedef struct {
  Font font;
  unsigned int font_size;
  unsigned int font_size_header;
  unsigned int screen_elements_size;
  const DrawerType type;
} Drawer;

typedef void DrawerHandler;
typedef void ActorHandler;
typedef void ScenarioHandler;

DrawerHandler *drawer_create(DrawerType t);
void drawer_draw_logo(DrawerHandler *drawer, size_t screen_width,
                      size_t screen_length);
void drawer_draw_title(DrawerHandler *drawer, int hover, size_t screen_width,
                       size_t screen_height);
void drawer_draw_actor(DrawerHandler *drawer, ActorHandler *actor);
void drawer_draw_scenario(DrawerHandler *drawer, ScenarioHandler *scenario);
void drawer_draw_end(DrawerHandler *drawer);
void drawer_destroy(DrawerHandler *drawer);

Font drawer_font_get(DrawerHandler *drawer);
void drawer_font_set(DrawerHandler *drawer, Font f);
unsigned int drawer_font_size_get(DrawerHandler *drawer);
void drawer_font_size_set(DrawerHandler *drawer, unsigned int size);
unsigned int drawer_font_size_header_get(DrawerHandler *drawer);
void drawer_font_size_header_set(DrawerHandler *drawer, unsigned int size);
unsigned int drawer_screen_elements_size_get(DrawerHandler *drawer);
void drawer_screen_elements_size_set(DrawerHandler *drawer, unsigned int size);

#endif
