cmake_minimum_required(VERSION 3.5)
project(knowrob_bank)

find_package(catkin REQUIRED COMPONENTS nodelet)

find_package(PkgConfig)

pkg_check_modules(SWIPL REQUIRED swipl)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

include_directories(include ${SWIPL_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS})
add_library(bank SHARED src/bank.cpp src/include/header/Matrix4.h src/include/resouce/Matrix4.cpp src/include/header/Bankhelper.h src/include/header/buildparams.h src/include/header/Config.h src/include/header/Misc.h src/include/header/Mutex.h src/include/header/Resources.h src/include/header/SphereNode.h src/include/header/SphereTree.h src/include/header/test.h src/include/header/Vec3.h src/include/resouce/Config.cpp src/include/resouce/SphereNode.cpp src/include/resouce/SphereTree.cpp src/include/resouce/Vec3.cpp)
target_link_libraries(bank ${SWIPL_LIBRARIES} ${catkin_LIBRARIES})
add_dependencies(bank ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
  
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch)
  
install(DIRECTORY prolog/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/prolog)
