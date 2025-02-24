qt_add_library(common_lib STATIC
  i_tool.hpp
  e_tool.hpp
  state.hpp
  state.cpp
  utils.hpp
  polygon_config.hpp
)

target_link_libraries(common_lib 
PUBLIC
    Qt6::Core
    Qt6::Widgets
)

target_include_directories(common_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
