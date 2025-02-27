cmake_minimum_required(VERSION 3.19)
project(icg_filter LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
message(STATUS "Using Qt version: ${Qt6_VERSION}")

qt6_add_resources(RESOURCES resources.qrc)

qt_standard_project_setup()

qt_add_executable(icg_filter
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    ${RESOURCES}
)

target_link_libraries(icg_filter
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        mainwindow
        help_lib
        about
        spinslider
    PUBLIC
        common_lib
)

include(GNUInstallDirs)

install(TARGETS icg_filter
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET icg_filter
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

add_subdirectory(lib/common)
add_subdirectory(lib/mainwindow)
add_subdirectory(lib/about)
add_subdirectory(lib/help)
add_subdirectory(lib/spinslider)

