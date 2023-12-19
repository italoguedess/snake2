#include "drawer.h"
#include <assert.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DrawerHandler *drawer_create(DrawerType t) {
  void *object = NULL;
  switch (t) {
  case DT_DRAWER:
    object = malloc(sizeof(Drawer));
    // GetFontDefault() apparently does not pass the font to the Drawer
    Drawer tmp = {GetFontDefault(), .font_size = 20, .font_size_header = 60,
                  .screen_elements_size = 40, .type = DT_DRAWER};
    memcpy(object, &tmp, sizeof(tmp));
    break;
  default:
    assert("Non existent drawer type!" && 0);
  }
  return object;
}

void drawer_draw_logo(DrawerHandler *drawer, int screen_width,
                      int screen_height) {
  ClearBackground(RAYWHITE);
  char *logo = "Snake Game";
  char *author = "Italo Guedes @github.com/italoguedess";
  // Getting the logo and author text sizes for centralizing purposes
  Vector2 logo_size = MeasureTextEx(GetFontDefault(), logo,
                                    drawer_font_size_header_get(drawer), 1);
  Vector2 author_size =
      MeasureTextEx(GetFontDefault(), author, drawer_font_size_get(drawer), 1);

  DrawText(logo, (screen_width - logo_size.x) / 2,
           (screen_height - logo_size.y) / 2 -
               drawer_font_size_header_get(drawer),
           drawer_font_size_header_get(drawer), BLACK);

  DrawText(author, (screen_width - author_size.x) / 2,
           (screen_height - author_size.y) / 2 + drawer_font_size_get(drawer),
           drawer_font_size_get(drawer), BLACK);
}

void drawer_draw_title(DrawerHandler *drawer) {}
void drawer_draw_actor(DrawerHandler *drawer, ActorHandler *actor);
void drawer_draw_scenario(DrawerHandler *drawer, ScenarioHandler *scenario);
void drawer_draw_end(DrawerHandler *drawer);
void drawer_destroy(DrawerHandler *drawer) { free(drawer); };

Font drawer_font_get(DrawerHandler *drawer) { return ((Drawer *)drawer)->font; }
void drawer_font_set(DrawerHandler *drawer, Font f) {
  ((Drawer *)drawer)->font = f;
}

unsigned int drawer_font_size_get(DrawerHandler *drawer) {
  return ((Drawer *)drawer)->font_size;
}

void drawer_font_size_set(DrawerHandler *drawer, unsigned int size) {
  ((Drawer *)drawer)->font_size = size;
}

unsigned int drawer_font_size_header_get(DrawerHandler *drawer) {
  return ((Drawer *)drawer)->font_size_header;
}

void drawer_font_size_header_set(DrawerHandler *drawer, unsigned int size) {
  ((Drawer *)drawer)->font_size_header = size;
}

unsigned int drawer_screen_elements_size_get(DrawerHandler *drawer) {
  return ((Drawer *)drawer)->screen_elements_size;
}

void drawer_screen_elements_size_set(DrawerHandler *drawer, unsigned int size) {
  ((Drawer *)drawer)->screen_elements_size = size;
}
