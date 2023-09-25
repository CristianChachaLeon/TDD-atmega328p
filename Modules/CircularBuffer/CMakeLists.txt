add_library(CircularBuffer src/CircularBuffer.c)
target_include_directories(CircularBuffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
