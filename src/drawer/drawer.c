#include "drawer.h"
#include "d_internal.h"
#include <assert.h>
#include <raylib.h>
#include <stddef.h>
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

void drawer_draw_logo(DrawerHandler *drawer, size_t screen_width,
                      size_t screen_height) {
  ClearBackground(RAYWHITE);
  char *logo = "Snake Game";
  char *author = "Italo Guedes @github.com/italoguedess";

  drawer_draw_text_centralized(logo, drawer_font_size_header_get(drawer), 0, 0,
                               screen_width, screen_height);

  drawer_draw_text_centralized(author, drawer_font_size_get(drawer), 0, 50,
                               screen_width, screen_height);
}

void drawer_draw_title(DrawerHandler *drawer, int hover, size_t screen_width,
                       size_t screen_height) {
  const int num_menu_rects = 2;
  const char *buttons_text[] = {"Start Game", "Credits"};
  Rectangle menu_rects[num_menu_rects];
  ClearBackground(LIGHTGRAY);
  // Draw buttons
  for (int i = 0; i < num_menu_rects; i++) {
    drawer_draw_button_centralized(buttons_text[i],
                                   drawer_font_size_get(drawer),
                                   (i == hover) ? true : false, 0, 50 * (i + 1),
                                   screen_width, screen_height);
  }
}

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

void drawer_draw_text_centralized(const char *text, size_t font_size,
                                  int x_offset, int y_offset,
                                  size_t screen_width, size_t screen_height) {

  Vector2 text_size = MeasureTextEx(GetFontDefault(), text, font_size, 1);

  DrawText(text, (screen_width - text_size.x) / 2 + x_offset,
           (screen_height - text_size.y) / 2 + y_offset, font_size, BLACK);
}

void drawer_draw_button_centralized(const char *text, size_t font_size,
                                    bool hover, int x_offset, int y_offset,
                                    size_t screen_width, size_t screen_height) {

  Vector2 text_size = MeasureTextEx(GetFontDefault(), text, font_size, 1);

  size_t button_width = 200;
  size_t button_height = text_size.y + 10;
  Rectangle button_background = {
      (float)(screen_width) / 2 + x_offset - (float)button_width / 2,
      (float)screen_height / 2 + y_offset - (float)button_height / 2,
      button_width, button_height};

  DrawRectangleRec(button_background, (hover) ? SKYBLUE : GRAY);
  DrawRectangleLinesEx(button_background, 1, DARKGRAY);
  DrawText(text, (screen_width - text_size.x) / 2 + x_offset,
           (screen_height - text_size.y) / 2 + y_offset, font_size, BLACK);
}
