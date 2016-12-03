################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
StopWatchMode.obj: ../StopWatchMode.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/Users/aaronewing/Desktop/SVN Repo/OutOfBox_MSP430FR6989/driverlib/MSP430FR5xx_6xx" --include_path="C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR6989__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="StopWatchMode.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

TempSensorMode.obj: ../TempSensorMode.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/Users/aaronewing/Desktop/SVN Repo/OutOfBox_MSP430FR6989/driverlib/MSP430FR5xx_6xx" --include_path="C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR6989__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="TempSensorMode.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

hal_LCD.obj: ../hal_LCD.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/Users/aaronewing/Desktop/SVN Repo/OutOfBox_MSP430FR6989/driverlib/MSP430FR5xx_6xx" --include_path="C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR6989__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="hal_LCD.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/Users/aaronewing/Desktop/SVN Repo/OutOfBox_MSP430FR6989/driverlib/MSP430FR5xx_6xx" --include_path="C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR6989__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


