# Fetch and patch idax to avoid duplicate find_package(idasdk)
include(FetchContent)

set(idax_PATCHED_DIR "${CMAKE_CURRENT_BINARY_DIR}/idax-patched")

if(NOT EXISTS "${idax_PATCHED_DIR}/CMakeLists.txt")
    message(STATUS "Fetching idax...")
    FetchContent_Populate(idax_fetch
        GIT_REPOSITORY https://github.com/19h/idax.git
        GIT_TAG master
        GIT_SHALLOW ON
        SOURCE_DIR "${idax_PATCHED_DIR}"
    )
    
    message(STATUS "Patching idax CMakeLists.txt...")
    file(READ "${idax_PATCHED_DIR}/CMakeLists.txt" IDAX_CMAKELISTS)
    string(REPLACE "find_package(idasdk REQUIRED)" "# find_package(idasdk REQUIRED) # patched" IDAX_CMAKELISTS "${IDAX_CMAKELISTS}")
    file(WRITE "${idax_PATCHED_DIR}/CMakeLists.txt" "${IDAX_CMAKELISTS}")
endif()

# Add the patched idax
add_subdirectory("${idax_PATCHED_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/idax-build")
