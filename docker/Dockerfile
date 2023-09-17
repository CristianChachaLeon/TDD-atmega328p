# Use the latest version of Ubuntu as the base image
FROM ubuntu:latest

# Set the working directory
WORKDIR /workspace

# Update package lists and install necessary packages
RUN apt-get update &&   \
    apt-get install -y  \
	build-essential     \
	cmake               \
	gcc-avr 			\
	avr-libc			\
	avrdude				\
	minicom
