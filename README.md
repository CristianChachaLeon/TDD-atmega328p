# TDD-atmega328p
Implementation of TDD philosophy in avr micro-controller, this repository test the unitary test tools



# Compilation process
## Host

```
mkdir build-host
cd build-host
cmake ..
cmake --build .
```

## Atmega 328p

```
mkdir build-atmega328p
cd build-atmega328p
cmake -D_CMAKE_TOOLCHAIN_FILE=../toolchain-atmega328p.cmake ..
cmake --build .
```
### Flash and open terminal
```
make flash

sudo minicom -D <PORT>
```
