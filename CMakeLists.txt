cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=armv8.2-a+fp16")

# 设置项目名称
project(MyProject)

# 添加宏定义 HOOK_MMAP
add_definitions(-DUSE_DL_PREFIX)
add_definitions(-DHOOK_MMAP)
add_definitions(-DHOOK_MUNMAP)
add_subdirectory(dlmalloc)

# 添加可执行文件
add_executable(main test.c)
target_link_libraries(main PRIVATE dlmalloc)
