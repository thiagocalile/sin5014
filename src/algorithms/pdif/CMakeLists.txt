if(ESP_PLATFORM)
    idf_component_register(
        SRCS "kernels.c"
        INCLUDE_DIRS "."
        REQUIRES common
    )
else()
    add_library(pdif STATIC kernels.c)
    target_include_directories(pdif PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(pdif PUBLIC common)
endif()
