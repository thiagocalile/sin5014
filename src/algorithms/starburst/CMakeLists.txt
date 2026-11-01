# Execute Python script to generate LUT headers
add_custom_target(generate_starburst_luts
    COMMAND python3 generate_luts.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating Starburst LUTs"
)

if(ESP_PLATFORM)
    idf_component_register(
        SRCS "starburst.c"
        INCLUDE_DIRS "."
        REQUIRES common
    )
    # Force ESP-IDF to run the Python script before building this component
    add_dependencies(${COMPONENT_LIB} generate_starburst_luts)
else()
    add_library(starburst STATIC starburst.c)
    target_include_directories(starburst PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(starburst PUBLIC common)
    add_dependencies(starburst generate_starburst_luts)
endif()
