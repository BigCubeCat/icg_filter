# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/icg_filter_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/icg_filter_autogen.dir/ParseCache.txt"
  "icg_filter_autogen"
  "lib/about/CMakeFiles/about_autogen.dir/AutogenUsed.txt"
  "lib/about/CMakeFiles/about_autogen.dir/ParseCache.txt"
  "lib/about/about_autogen"
  "lib/common/CMakeFiles/common_lib_autogen.dir/AutogenUsed.txt"
  "lib/common/CMakeFiles/common_lib_autogen.dir/ParseCache.txt"
  "lib/common/common_lib_autogen"
  "lib/components/CMakeFiles/component_models_autogen.dir/AutogenUsed.txt"
  "lib/components/CMakeFiles/component_models_autogen.dir/ParseCache.txt"
  "lib/components/component_models_autogen"
  "lib/filters/CMakeFiles/filters_autogen.dir/AutogenUsed.txt"
  "lib/filters/CMakeFiles/filters_autogen.dir/ParseCache.txt"
  "lib/filters/filters_autogen"
  "lib/help/CMakeFiles/help_lib_autogen.dir/AutogenUsed.txt"
  "lib/help/CMakeFiles/help_lib_autogen.dir/ParseCache.txt"
  "lib/help/help_lib_autogen"
  "lib/imageview/CMakeFiles/imageview_autogen.dir/AutogenUsed.txt"
  "lib/imageview/CMakeFiles/imageview_autogen.dir/ParseCache.txt"
  "lib/imageview/imageview_autogen"
  "lib/mainwindow/CMakeFiles/mainwindow_autogen.dir/AutogenUsed.txt"
  "lib/mainwindow/CMakeFiles/mainwindow_autogen.dir/ParseCache.txt"
  "lib/mainwindow/mainwindow_autogen"
  "lib/signalcontroller/CMakeFiles/signalcontroller_autogen.dir/AutogenUsed.txt"
  "lib/signalcontroller/CMakeFiles/signalcontroller_autogen.dir/ParseCache.txt"
  "lib/signalcontroller/signalcontroller_autogen"
  )
endif()
