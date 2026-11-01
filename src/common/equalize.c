#include <stdint.h>
#include <stddef.h>

#include "image.h"
#include "histogram.h"

#include "equalize.h"

void mean_equalize(uint8_t *image, Histogram *histogram) {

  uint8_t lookup_table[MAX_COLOR + 1];
  size_t index;
  
  for (size_t color = 0; color <= MAX_COLOR; color++) {
    lookup_table[color] = ((histogram->cumulative_distribution[color] * MAX_COLOR) / (IMAGE_WIDTH * IMAGE_HEIGHT) + color) / 2;
  }

  for (size_t row = 0; row < IMAGE_HEIGHT; row++) {
    for (size_t column = 0; column < IMAGE_WIDTH; column++) {
      index = (row * IMAGE_WIDTH) + column;
      image[index] = lookup_table[image[index]];
    }
  }
  
}
