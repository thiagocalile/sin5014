if(NOT ESP_PLATFORM)
    add_executable(native_test main_native.c)
    
    # Link the modular algorithm libraries
    target_link_libraries(native_test PRIVATE common pdif starburst else excuse)
    
    # Inject architecture-specific SIMD flags for desktop testing
    target_compile_options(native_test PRIVATE -march=native -O3 -Wall -Wextra)
endif()
