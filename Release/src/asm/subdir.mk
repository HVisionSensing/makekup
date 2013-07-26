################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/asm/asm.cpp \
../src/asm/classicdesc.cpp \
../src/asm/convshape.cpp \
../src/asm/err.cpp \
../src/asm/eyedet.cpp \
../src/asm/eyedist.cpp \
../src/asm/faceroi.cpp \
../src/asm/hat.cpp \
../src/asm/hatdesc.cpp \
../src/asm/landmarks.cpp \
../src/asm/minimal.cpp \
../src/asm/misc.cpp \
../src/asm/pinstart.cpp \
../src/asm/print.cpp \
../src/asm/shape17.cpp \
../src/asm/shapehacks.cpp \
../src/asm/shapemod.cpp \
../src/asm/startshape.cpp \
../src/asm/stasm.cpp \
../src/asm/stasm_lib.cpp 

OBJS += \
./src/asm/asm.o \
./src/asm/classicdesc.o \
./src/asm/convshape.o \
./src/asm/err.o \
./src/asm/eyedet.o \
./src/asm/eyedist.o \
./src/asm/faceroi.o \
./src/asm/hat.o \
./src/asm/hatdesc.o \
./src/asm/landmarks.o \
./src/asm/minimal.o \
./src/asm/misc.o \
./src/asm/pinstart.o \
./src/asm/print.o \
./src/asm/shape17.o \
./src/asm/shapehacks.o \
./src/asm/shapemod.o \
./src/asm/startshape.o \
./src/asm/stasm.o \
./src/asm/stasm_lib.o 

CPP_DEPS += \
./src/asm/asm.d \
./src/asm/classicdesc.d \
./src/asm/convshape.d \
./src/asm/err.d \
./src/asm/eyedet.d \
./src/asm/eyedist.d \
./src/asm/faceroi.d \
./src/asm/hat.d \
./src/asm/hatdesc.d \
./src/asm/landmarks.d \
./src/asm/minimal.d \
./src/asm/misc.d \
./src/asm/pinstart.d \
./src/asm/print.d \
./src/asm/shape17.d \
./src/asm/shapehacks.d \
./src/asm/shapemod.d \
./src/asm/startshape.d \
./src/asm/stasm.d \
./src/asm/stasm_lib.d 


# Each subdirectory must supply rules for building sources it contributes
src/asm/%.o: ../src/asm/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


