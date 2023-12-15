################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../custom/App/Relay_Control/RelayControl.c 

OBJS += \
./custom/App/Relay_Control/RelayControl.o 

C_DEPS += \
./custom/App/Relay_Control/RelayControl.d 


# Each subdirectory must supply rules for building sources it contributes
custom/App/Relay_Control/%.o: ../custom/App/Relay_Control/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Windows GCC C Compiler (Sourcery Lite Bare)'
	arm-none-eabi-gcc -D__OCPU_COMPILER_GCC__ -D__CUSTOMER_CODE__ -I"${GCC_PATH}\arm-none-eabi\include" -I"C:\Users\Admin\Documents\Quectel\M66_OpenCPU_GS3_SDK_V2.4_Eclipse\include" -I"C:\Users\Admin\Documents\Quectel\M66_OpenCPU_GS3_SDK_V2.4_Eclipse\ril\inc" -I"C:\Users\Admin\Documents\Quectel\M66_OpenCPU_GS3_SDK_V2.4_Eclipse\custom\config" -I"C:\Users\Admin\Documents\Quectel\M66_OpenCPU_GS3_SDK_V2.4_Eclipse\custom\fota\inc" -I"C:\Users\Admin\Documents\Quectel\M66_OpenCPU_GS3_SDK_V2.4_Eclipse\custom\App" -I"C:\Users\Admin\Documents\Quectel\M66_OpenCPU_GS3_SDK_V2.4_Eclipse\custom\App\Charger_Configuration" -I"C:\Users\Admin\Documents\Quectel\M66_OpenCPU_GS3_SDK_V2.4_Eclipse\custom\App\cJSON" -I"C:\Users\Admin\Documents\Quectel\M66_OpenCPU_GS3_SDK_V2.4_Eclipse\custom\App\Bluetooth_Configuration" -I"C:\Users\Admin\Documents\Quectel\M66_OpenCPU_GS3_SDK_V2.4_Eclipse\custom\App\RGB-Control" -O2 -Wall -std=c99 -c -fmessage-length=0 -mlong-calls -Wstrict-prototypes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -march=armv5te -mthumb-interwork -mfloat-abi=soft -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


