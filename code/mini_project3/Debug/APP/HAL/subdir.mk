################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/HAL/DCmotor.c \
../APP/HAL/LCD.c \
../APP/HAL/LM35.c 

OBJS += \
./APP/HAL/DCmotor.o \
./APP/HAL/LCD.o \
./APP/HAL/LM35.o 

C_DEPS += \
./APP/HAL/DCmotor.d \
./APP/HAL/LCD.d \
./APP/HAL/LM35.d 


# Each subdirectory must supply rules for building sources it contributes
APP/HAL/%.o: ../APP/HAL/%.c APP/HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


