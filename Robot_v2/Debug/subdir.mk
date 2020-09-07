################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prog.c \
../EXT_INT0.c \
../EXT_INT1.c \
../EXT_INT2.c \
../EXT_INT_ISR0.c \
../EXT_INT_ISR1.c \
../EXT_INT_ISR2.c \
../LCD_Prog.c \
../Program.c \
../Timer0_PWM_Prog.c \
../Timer2_PWM_Prog.c \
../app.c 

OBJS += \
./DIO_prog.o \
./EXT_INT0.o \
./EXT_INT1.o \
./EXT_INT2.o \
./EXT_INT_ISR0.o \
./EXT_INT_ISR1.o \
./EXT_INT_ISR2.o \
./LCD_Prog.o \
./Program.o \
./Timer0_PWM_Prog.o \
./Timer2_PWM_Prog.o \
./app.o 

C_DEPS += \
./DIO_prog.d \
./EXT_INT0.d \
./EXT_INT1.d \
./EXT_INT2.d \
./EXT_INT_ISR0.d \
./EXT_INT_ISR1.d \
./EXT_INT_ISR2.d \
./LCD_Prog.d \
./Program.d \
./Timer0_PWM_Prog.d \
./Timer2_PWM_Prog.d \
./app.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


