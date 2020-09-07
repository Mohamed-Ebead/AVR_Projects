################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prog.c \
../RTO_Prog.c \
../Timer1_prog.c \
../main.c \
../program.c 

OBJS += \
./DIO_prog.o \
./RTO_Prog.o \
./Timer1_prog.o \
./main.o \
./program.o 

C_DEPS += \
./DIO_prog.d \
./RTO_Prog.d \
./Timer1_prog.d \
./main.d \
./program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


