qt_add_library(about STATIC
    about.cpp
    about.hpp
    about.ui
)

target_link_libraries(about
PUBLIC
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickWidgets
    Qt6::QuickControls2
PRIVATE
    common_lib
)

target_include_directories(about PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

