################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App.c \
../DIO_prog.c \
../KEYPAD_Prog.c \
../LCD_Prog.c \
../Program.c 

OBJS += \
./App.o \
./DIO_prog.o \
./KEYPAD_Prog.o \
./LCD_Prog.o \
./Program.o 

C_DEPS += \
./App.d \
./DIO_prog.d \
./KEYPAD_Prog.d \
./LCD_Prog.d \
./Program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


