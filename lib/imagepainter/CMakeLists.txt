qt_add_library(imagepainter STATIC
    imagepainter.cpp
    imagepainter.hpp
    imagepainter.ui
)

target_link_libraries(imagepainter
PUBLIC
    Qt6::Core
    Qt6::Widgets
PRIVATE
    common_lib
)

target_include_directories(imagepainter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

