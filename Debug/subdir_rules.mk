################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
assmbly.obj: ../assmbly.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="assmbly.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ceil.obj: ../ceil.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="ceil.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

division.obj: ../division.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="division.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

floor.obj: ../floor.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="floor.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

imresize.obj: ../imresize.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="imresize.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

multiply32.obj: ../multiply32.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="multiply32.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

rounding.obj: ../rounding.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="F:/software/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="rounding.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


