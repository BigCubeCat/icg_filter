qt_add_library(common_lib STATIC
  e_filter.hpp
  i_filter.hpp
  i_factory.hpp

  state.hpp
  state.cpp

  fileprocessor.hpp
  fileprocessor.cpp

  imageprocessor.hpp
  imageprocessor.cpp

  utils.hpp
)

target_link_libraries(common_lib 
PUBLIC
    Qt6::Core
    Qt6::Widgets
    PRIVATE
    signalcontroller
)

target_include_directories(common_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

