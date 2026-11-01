#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <stdint.h>

#include "image.h"

typedef struct {
  uint8_t histogram[MAX_COLOR];
  int cumulative_distribution[MAX_COLOR];
} Histogram;

void make_histogram(uint8_t *image, Histogram *return_histogram);

void make_cdf(Histogram* histogram);

#endif
