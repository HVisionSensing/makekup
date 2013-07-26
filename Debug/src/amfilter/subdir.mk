################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/amfilter/adaptive_manifold_filter.cpp 

OBJS += \
./src/amfilter/adaptive_manifold_filter.o 

CPP_DEPS += \
./src/amfilter/adaptive_manifold_filter.d 


# Each subdirectory must supply rules for building sources it contributes
src/amfilter/%.o: ../src/amfilter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


