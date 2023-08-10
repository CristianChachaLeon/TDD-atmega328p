set(CMAKE_VERBOSE_MAKEFILE ON)

#name of target

set(CMAKE_SYSTEM_NAME Generic)

#Specify cross-compiler
set(CMAKE_C_COMPILER	avr-gcc) 
set(CMAKE_CXX_COMPILER	avr-g++)

set(CMAKE_OBJCOPY		avr-objcopy)
set(CMAKE_FLASH			avrdude)

# Define programmer and Port to flash
set(PROGRAMMER			arduino)
set(PORT				/dev/ttyACM0)

set(CMAKE_SYSTEM_PROCESSOR avr)

#Compiler flags
set(CMAKE_C_FLAGS "-mmcu=atmega328p -Os")
set(CMAKE_CXX_FLAGS "-mmcu=atmega328p -Os")

#Set MACROS
add_compile_definitions(ATMEGA_328P)
add_definitions(-DF_CPU=16000000)

set(GENERATE_HEX_FILE TRUE)
set(ENABLE_FLASH TRUE) 


#add_executable(Demo main.c)
