#include <stdint.h>

#include "image.h"
#include "histogram.h"

void equalize(uint8_t *image, Histogram *histogram);

void mean_equalize(uint8_t* image, Histogram* histogram);
