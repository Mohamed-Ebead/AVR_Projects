################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/portable/MemMang/heap_3.c 

OBJS += \
./FreeRTOS/Source/portable/MemMang/heap_3.o 

C_DEPS += \
./FreeRTOS/Source/portable/MemMang/heap_3.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/%.o: ../FreeRTOS/Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\IMT\Interfacing\RTOS_0\FreeRTOS\Source\include" -I"E:\IMT\Interfacing\RTOS_0\config" -I"E:\IMT\Interfacing\RTOS_0\FreeRTOS\Source\portable\GCC\ATMega323" -I"E:\IMT\Interfacing\RTOS_0\FreeRTOS\Source\portable\MemMang" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


