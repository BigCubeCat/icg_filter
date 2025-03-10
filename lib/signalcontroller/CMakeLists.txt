qt_add_library(signalcontroller STATIC
    signalcontroller.cpp
    signalcontroller.hpp
)

target_link_libraries(signalcontroller
PUBLIC
    Qt6::Core
    Qt6::Widgets
    common_lib
)

target_include_directories(signalcontroller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

