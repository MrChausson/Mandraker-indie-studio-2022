# Usage:
#FIND_PACKAGE(jsoncpp REQUIRED)
# [...]
#TARGET_LINK_LIBRARIES(target_name jsoncpp)
CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

if (NOT jsoncpp_FOUND)
    INCLUDE(FetchContent)

    FetchContent_Declare(jsoncpp URL https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.9.5.tar.gz)
    FetchContent_GetProperties(jsoncpp)
    if (NOT jsoncpp_POPULATED)
        SET(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(jsoncpp)
        SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        #ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
        SET(jsoncpp_FOUND TRUE)
    endif()
endif()