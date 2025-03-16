include(/home/anton/Documents/graphics/icg_filter/cmake-build-debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/icg_filter-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtwebengine;qtwebengine")

qt6_deploy_runtime_dependencies(
    EXECUTABLE /home/anton/Documents/graphics/icg_filter/cmake-build-debug/icg_filter
    GENERATE_QT_CONF
)
