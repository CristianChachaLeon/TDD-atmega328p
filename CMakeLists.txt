cmake_minimum_required(VERSION 3.10)

project(TestUnity)
set(PROGRAM Test)
add_executable(${PROGRAM} 
                test/AllTests.c 
                test/LedDriver/ledTests.c 
                test/CircularBuffer/CircularBuffer.c
                test/CircularBuffer/CircularBufferRunner.c 
                test/LedDriver/ledTestsRunner.c 
                ./Unity/extras/fixture/src/unity_fixture.c 
                ./Unity/src/unity.c)

#add_executable(${PROGRAM} AllTests.c ledTests.c ledTestsRunner.c ./Unity/extras/fixture/src/unity_fixture.c ./Unity/src/unity.c)
#add_executable(Test AllTests.c ledTestsRunner.c ledTests.c)

include_directories(./Unity/extras/fixture/src)
include_directories(./Unity/extras/memory/src)
include_directories(./Unity/src)
#include_directories(./Modules/LedDriver/include)
add_subdirectory(Modules/LedDriver)

target_link_libraries(${PROGRAM} PUBLIC LedDriver)

target_include_directories(${PROGRAM}  PUBLIC
                        "${PROJECT_SOURCE_DIR}/Modules/LedDriver/include"
                          )
                          
##############################################################
#SUPPORT for toolchain
##############################################################

# GENERATION of HEX file
if(GENERATE_HEX_FILE)
        add_custom_command(TARGET ${PROGRAM} 
                POST_BUILD 
                COMMAND ${CMAKE_OBJCOPY} -j .text -j .data -O ihex ${PROGRAM} ${PROGRAM}.hex)

endif()

# Add feature to flash
if(ENABLE_FLASH)
        add_custom_target(flash
                COMMAND ${CMAKE_FLASH} -v -c ${PROGRAMMER} -p atmega328p -P ${PORT} -b 115200 -U flash:w:${PROGRAM}.hex:i
        )

endif()

