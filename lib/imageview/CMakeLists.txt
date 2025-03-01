qt_add_library(imageview STATIC
    imageview.cpp
    imageview.hpp
    imageview.ui
)

target_link_libraries(imageview
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
)

target_include_directories(imageview PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

