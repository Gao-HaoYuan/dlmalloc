aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
add_library(dlmalloc STATIC ${SRC_LIST})
target_include_directories(dlmalloc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
