cmake_minimum_required(VERSION 3.8)
project(main)


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)   #导出clangd需要的文件，用于智能提示和基于语议的补全

set(CMAKE_CXX_FLAGS "-std=c++11 -g3 -rdynamic")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

#打印信息
message(STATUS "build type:")
message(STATUS "CXX_FLAGS = ${CMAKE_CXX_FLAGS} ")

#设置库文件输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 遍历项目根目录下所有的 .cpp 文件 https://zhuanlan.zhihu.com/p/277990960
# 好是好，但是我有时候一些cpp不需要执行只是放进来保存编译，只需要compiler部分修改 对应类型文件夹下的 名称更快，更方便我从Debug目录中寻找需要的。
#file (GLOB files *.cpp)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    add_executable (${exe} ${file})
#    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()

#递归目录获取所有h文件
#include_directories(${PROJECT_SOURCE_DIR}/source/add)
#include_directories(${PROJECT_SOURCE_DIR}/source/sub)
#include_directories(${PROJECT_SOURCE_DIR}/source/main)

add_subdirectory(source/DP)
add_subdirectory(source/BinaryTree)
add_subdirectory(source/LinkList)
add_subdirectory(source/StackQueueDeque)
add_subdirectory(source/String)
add_subdirectory(source/backtracking)
add_subdirectory(source/greedy)
add_subdirectory(source/hash)
add_subdirectory(source/others)
add_subdirectory(source/twopoints)
add_subdirectory(source/vector)
add_subdirectory(source/CompleteDebug)
add_subdirectory(source/Graph)
add_subdirectory(source/NewCoderIO)

#cmake中执行shell指令
#execute_process(COMMAND pwd)

#设置需要编译调试和执行的程序
add_executable(arr2linklist arr2linklist.cpp)
add_executable(treeSerilize treeSerilize.cpp)
add_executable(DoubleLink DoubleLink.cpp)
add_executable(tempForNewACM tempForNewACM.cpp)
add_executable(temp temp.cpp)
add_executable(newcoder newcoder.cpp)