################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../environmental/LocalizationManager.cpp \
../environmental/Map.cpp \
../environmental/Particle.cpp 

OBJS += \
./environmental/LocalizationManager.o \
./environmental/Map.o \
./environmental/Particle.o 

CPP_DEPS += \
./environmental/LocalizationManager.d \
./environmental/Map.d \
./environmental/Particle.d 


# Each subdirectory must supply rules for building sources it contributes
environmental/%.o: ../environmental/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


