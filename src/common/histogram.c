#include "histogram.h"

void histogram(unsigned char **image, int height, int width,
               int *return_array) {

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      return_array[image[i][j]]++;
    }
  }
  
}
