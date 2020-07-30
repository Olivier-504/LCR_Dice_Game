################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source\ Files/Dice.cpp \
../Source\ Files/Player.cpp \
../Source\ Files/main.cpp 

OBJS += \
./Source\ Files/Dice.o \
./Source\ Files/Player.o \
./Source\ Files/main.o 

CPP_DEPS += \
./Source\ Files/Dice.d \
./Source\ Files/Player.d \
./Source\ Files/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source\ Files/Dice.o: ../Source\ Files/Dice.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/Olivier/eclipse-workspace/IT-312_LCR_Dice/Header Files" -I"/Users/Olivier/eclipse-workspace/IT-312_LCR_Dice/Source Files" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source Files/Dice.d" -MT"Source\ Files/Dice.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/Player.o: ../Source\ Files/Player.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/Olivier/eclipse-workspace/IT-312_LCR_Dice/Header Files" -I"/Users/Olivier/eclipse-workspace/IT-312_LCR_Dice/Source Files" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source Files/Player.d" -MT"Source\ Files/Player.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/main.o: ../Source\ Files/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/Olivier/eclipse-workspace/IT-312_LCR_Dice/Header Files" -I"/Users/Olivier/eclipse-workspace/IT-312_LCR_Dice/Source Files" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source Files/main.d" -MT"Source\ Files/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


