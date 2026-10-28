#include "thresholding.h"

void thresholding(bool** return_mask, unsigned char **arr, int height, int width,
                    unsigned char min_val) {

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      return_mask[i][j] = arr[i][j] < min_val ? false : true;
    }
  }
  
}
