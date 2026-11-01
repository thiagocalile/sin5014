if(ESP_PLATFORM)
    idf_component_register(
        SRCS "blur.c" "equalize.c" "histogram.c" "thresholding.c" "stb_image.c" "image.c"
        INCLUDE_DIRS "."
    )
else()
    add_library(common STATIC blur.c equalize.c histogram.c thresholding.c stb_image.c image.c)
    target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    
    # Optional: Suppress warnings from stb_image.h during desktop builds if needed
    # target_compile_options(common PRIVATE -Wno-unused-parameter)
endif()
