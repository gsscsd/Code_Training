cmake_minimum_required(VERSION 3.9)

##设置环境变量
set(PROJECT_NAME HashWordCut)
set(INCLUDE include)


##添加源码
aux_source_directory(src DIR_SRC)
##头文件库
include_directories(${INCLUDE})
include_directories(${CMAKE_C_INCLUDE_WHAT_YOU_USE})
##链接库,暂时不需要
##target_link_libraries()
##添加执行文件
add_executable(${PROJECT_NAME} ${DIR_SRC} src/main.cpp)

##输出信息
message(STATUS "projec name is ${PROJECT_NAME}")
message(STATUS "src is ${DIR_SRC}")
message(STATUS "include is ${INCLUDE}")