# TDD-atmega328p
Implementation of TDD philosophy in avr micro-controller, this repository test the unitary test tools

# Run docker container

```
cd docker
docker compose build 
docker compose up -d
docker exec -ti ubuntu-tdd-container bash
```

**NOTE**: All commando shall be execute from docker container, docker container ubuntu-tdd-container has all tool needed for compilation, flashing and comunication 

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
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-atmega328p.cmake ..
cmake --build .
```
### Flash and open terminal
```
make flash

sudo minicom -D /dev/ttyACMO
```
