################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PathPlanning/PathPlanner.cpp \
../PathPlanning/Plan.cpp \
../PathPlanning/WaypointManager.cpp 

OBJS += \
./PathPlanning/PathPlanner.o \
./PathPlanning/Plan.o \
./PathPlanning/WaypointManager.o 

CPP_DEPS += \
./PathPlanning/PathPlanner.d \
./PathPlanning/Plan.d \
./PathPlanning/WaypointManager.d 


# Each subdirectory must supply rules for building sources it contributes
PathPlanning/%.o: ../PathPlanning/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


