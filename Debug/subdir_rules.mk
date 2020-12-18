################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
assmbly.obj: ../assmbly.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="assmbly.pp" --disable_software_pipelining $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ceil.obj: ../ceil.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="ceil.pp" --disable_software_pipelining $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

division.obj: ../division.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="division.pp" --disable_software_pipelining $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

floor.obj: ../floor.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="floor.pp" --disable_software_pipelining $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

imresize.obj: ../imresize.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="imresize.pp" --disable_software_pipelining $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" --disable_software_pipelining $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

multiply32.obj: ../multiply32.sa $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="multiply32.pp" --disable_software_pipelining $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

test_division.obj: ../test_division.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6400 --abi=coffabi -g --include_path="C:/Program Files/ccsv5/tools/compiler/c6000_7.4.4/include" --define=dm642 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="test_division.pp" --disable_software_pipelining $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


