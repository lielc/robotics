################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PathPlanning/PathPlanner.cpp \
../PathPlanning/WaypointManager.cpp \
../PathPlanning/node.cpp 

OBJS += \
./PathPlanning/PathPlanner.o \
./PathPlanning/WaypointManager.o \
./PathPlanning/node.o 

CPP_DEPS += \
./PathPlanning/PathPlanner.d \
./PathPlanning/WaypointManager.d \
./PathPlanning/node.d 


# Each subdirectory must supply rules for building sources it contributes
PathPlanning/%.o: ../PathPlanning/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


