cmake_minimum_required(VERSION 3.16)

if(DEFINED ENV{IDF_PATH})
    # --- ESP-IDF Compilation Path ---
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    
    # Expose algorithm and common directories as ESP-IDF components
    list(APPEND EXTRA_COMPONENT_DIRS 
        "src/common"
        "src/algorithms/pdif"
        "src/algorithms/starburst"
        "src/algorithms/else"
        "src/algorithms/excuse"
    )
    
    project(gaze_tracker_esp)
else()
    # --- Arch Linux Desktop Compilation Path ---
    project(gaze_tracker_desktop C)
    set(CMAKE_C_STANDARD 11)
    
    # Traverse subdirectories for desktop libraries and executables
    add_subdirectory(src/common)
    add_subdirectory(src/algorithms/pdif)
    add_subdirectory(src/algorithms/starburst)
    add_subdirectory(src/algorithms/else)
    add_subdirectory(src/algorithms/excuse)
    
    add_subdirectory(src/desktop/native_test)
endif()
