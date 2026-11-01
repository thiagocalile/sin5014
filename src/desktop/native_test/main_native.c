#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Pull in your shared algorithm headers
#include "../../common/image.h"
#include "../../common/histogram.h"
#include "../../common/equalize.h"

// stb_image.h implementation is handled by src/common/stb_image.c
#include "../../common/stb_image.h" 

// Implement the writer directly inside the test executable
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char **argv) {
    if (argc < 2) return 1;

    int loaded_w, loaded_h, channels;
    uint8_t *image_data = stbi_load(argv[1], &loaded_w, &loaded_h, &channels, STBI_grey);
    
    // Safety check: ensure the loaded CASIA image matches your image.h static constants
    if (loaded_w != IMAGE_WIDTH || loaded_h != IMAGE_HEIGHT) {
        printf("Resolution mismatch. Expected %dx%d\n", IMAGE_WIDTH, IMAGE_HEIGHT);
        return 1;
    }

    Histogram hist = {0}; 
    
    // Assuming you have a function to populate the histogram first
    // build_histogram(image_data, &hist);

    // Call your exact signature
    mean_equalize(image_data, &hist);

    stbi_write_jpg("equalized_output.jpg", IMAGE_WIDTH, IMAGE_HEIGHT, 1, image_data, 95);

    stbi_image_free(image_data);
    return 0;
}
