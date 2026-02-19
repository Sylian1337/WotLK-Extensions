# Dll
file(GLOB_RECURSE WOTLK_EXTENSIONS_SOURCES CONFIGURE_DEPENDS "*.cpp" "*.h")

add_library(WotLKExtensions SHARED ${WOTLK_EXTENSIONS_SOURCES})
set_property(TARGET WotLKExtensions PROPERTY CXX_STANDARD 17)

set_property(TARGET WotLKExtensions PROPERTY USE_FOLDERS true)

# --- ADD THIS SECTION FOR VISUAL STUDIO FOLDERS ---
# Create filters based on actual directory structure
foreach(source IN LISTS WOTLK_EXTENSIONS_SOURCES)
    # Get the relative path from CMAKE_CURRENT_SOURCE_DIR
    file(RELATIVE_PATH relative_path "${CMAKE_CURRENT_SOURCE_DIR}" "${source}")
    
    # Get directory part (for filter grouping)
    get_filename_component(source_dir "${relative_path}" DIRECTORY)
    
    # Convert directory separators to Visual Studio filter separators
    if(source_dir)
        string(REPLACE "/" "\\" vs_filter "${source_dir}")
        source_group("${vs_filter}" FILES "${source}")
    else()
        # Files in root go to root filter
        source_group("" FILES "${source}")
    endif()
endforeach()

target_include_directories(WotLKExtensions PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Add MinHook include directory – note the extra "WotLKExtensions"
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/minhook/include)

# Add MinHook library – same correction
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(MINHOOK_LIB ${CMAKE_CURRENT_SOURCE_DIR}/deps/minhook/lib/libMinHook.x64.lib)
else()
    set(MINHOOK_LIB ${CMAKE_CURRENT_SOURCE_DIR}/deps/minhook/lib/libMinHook.x86.lib)
endif()

# Link it to your project (after add_subdirectory)
target_link_libraries(WotLKExtensions ${MINHOOK_LIB})

set(LOG_LEVELS DEBUG INFO WARN ERROR NONE)
set(LOG_LEVEL DEBUG CACHE STRING "Logging level")
set_property(CACHE LOG_LEVEL PROPERTY STRINGS ${LOG_LEVELS})

if(LOG_LEVEL STREQUAL "DEBUG")
    target_compile_definitions(WotLKExtensions PRIVATE LOG_LEVEL=4)
elseif(LOG_LEVEL STREQUAL "INFO")
    target_compile_definitions(WotLKExtensions PRIVATE LOG_LEVEL=3)
elseif(LOG_LEVEL STREQUAL "WARN")
    target_compile_definitions(WotLKExtensions PRIVATE LOG_LEVEL=2)
elseif(LOG_LEVEL STREQUAL "ERROR")
    target_compile_definitions(WotLKExtensions PRIVATE LOG_LEVEL=1)
elseif(LOG_LEVEL STREQUAL "NONE")
    target_compile_definitions(WotLKExtensions PRIVATE LOG_LEVEL=0)
else()
    message(FATAL_ERROR "Invalid LOG_LEVEL ${LOG_LEVEL}")
endif()

# Optional: Auto-copy DLL to WoW client directory (same folder as Wow.exe)
if(WOW_CLIENT_PATH AND EXISTS "${WOW_CLIENT_PATH}")
    add_custom_command(TARGET WotLKExtensions POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:WotLKExtensions>
            "${WOW_CLIENT_PATH}/WotLKExtensions.dll"
        COMMENT "Copying WotLKExtensions.dll to ${WOW_CLIENT_PATH}"
    )
    message(STATUS "DLL auto-copy enabled: WotLKExtensions.dll will be copied to ${WOW_CLIENT_PATH}")
endif()