file(GLOB_RECURSE SOURCES *.cpp)
file(GLOB_RECURSE HEADERS *.hpp)

qt_add_library(filters STATIC ${SOURCES} ${HEADERS})

target_link_libraries(filters
PUBLIC
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
PRIVATE
    common_lib
)

target_include_directories(filters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

