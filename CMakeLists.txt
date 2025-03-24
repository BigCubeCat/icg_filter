cmake_minimum_required(VERSION 3.19)
project(icg_filter LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
    Widgets
    Gui
    Qml
    Quick
    QuickWidgets
    QuickControls2
    WebEngineWidgets
)

message(STATUS "Using Qt version: ${Qt6_VERSION}")

qt6_add_resources(RESOURCES 
resources.qrc
)

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
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        Qt6::QuickWidgets
        Qt6::QuickControls2
        about
        help_lib
        imagepainter

        mainwindow
        signalcontroller
        filters
        component_models
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

add_subdirectory(lib/about)
add_subdirectory(lib/common)
add_subdirectory(lib/help)
add_subdirectory(lib/imagepainter)
add_subdirectory(lib/mainwindow)
add_subdirectory(lib/signalcontroller)
add_subdirectory(lib/filters)
add_subdirectory(lib/components)

