#include "blur.h"

int gaussian_blur(unsigned char** arr) {

  int accumulator = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      accumulator += arr[i][j] * gaussian_filter[i][j];
    }
  }

  return accumulator / gaussian_division;
  
}
