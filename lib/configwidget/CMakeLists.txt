qt_add_library(configwidget STATIC
    configwidget.cpp
    configwidget.hpp
    configwidget.ui
)

target_link_libraries(configwidget
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
)

target_include_directories(configwidget PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

