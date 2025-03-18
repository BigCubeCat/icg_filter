qt_add_library(worker STATIC
    processing_worker.cpp
    processing_worker.hpp
)

target_link_libraries(worker
PUBLIC
    Qt6::Core
    Qt6::Widgets
    common_lib
)

target_include_directories(worker PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

