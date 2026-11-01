#include <stdint.h>
#include <stddef.h>

#include "histogram.h"

void make_histogram(uint8_t *image, Histogram *return_histogram) {
  for (size_t row = 0; row < IMAGE_HEIGHT; row++) {
    for (size_t column = 0; column < IMAGE_WIDTH; column++) {
      return_histogram->histogram[image[(row * IMAGE_WIDTH) + column]]++;
    }
  }
}

void make_cdf(Histogram *histogram) {
  size_t color = 0;
  int running_total = 0;
  do {
    running_total += histogram->histogram[color];
    histogram->cumulative_distribution[color] = running_total;
    color++;
  } while (color <= MAX_COLOR);
}
