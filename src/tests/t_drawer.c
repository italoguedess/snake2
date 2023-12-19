#include "tests.h"
#include "../drawer/drawer.h"
#include <stdio.h>

void test_drawer() {
  Drawer *d = drawer_create(DT_DRAWER);

  printf("******************\n");
  printf("Testing the drawer\n");
  printf("******************\n");

  printf("Font size: %d\n", drawer_font_size_get(d));
  printf("Header font size: %d\n", drawer_font_size_header_get(d));
  printf("Screen element size: %d\n", drawer_screen_elements_size_get(d));
  
  drawer_destroy(d);
}
