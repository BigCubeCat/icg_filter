qt_add_library(common_lib STATIC
        e_filter.hpp
        i_filter.hpp
        i_factory.hpp

        fileprocessor.hpp
        fileprocessor.cpp

        imageprocessor.hpp
        imageprocessor.cpp

        Convolution.hpp
        Convolution.cpp

        MedianFinder.cpp
        MedianFinder.h

        utils.hpp
)

target_link_libraries(common_lib
        PUBLIC
        Qt6::Core
        Qt6::Widgets
        Qt6::Gui
        PRIVATE
        signalcontroller
)

target_include_directories(common_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${OpenCV_INCLUDE_DIRS})

target_link_libraries(common_lib PUBLIC ${OpenCV_LIBRARIES})