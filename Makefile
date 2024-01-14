#************************************************************************************
#********************    @file   Makefile                  **************************
#********************    @author Ehab Magdy Abdallah      ***************************
#************************************************************************************

# Text Replacement ($(ToolChain) -> arm-none-eabi-) 
ToolChain := arm-none-eabi-
# Text Replacement ($(Target) -> -mcpu=cortex-m4 -mthumb) 
Target 	  := -mcpu=cortex-m4 -mthumb
# Text Replacement ($(LR) -> LinkerScript.ld) 
LR		  := LinkerScript.ld
# Text Replacement ($(SRC_FILES) -> "all .c files")
SRC_FILES := $(wildcard *.c)
# Text Replacement ($(OBJ_FILES) -> "all .o files")
OBJ_FILES := $(SRC_FILES:.c=.o)

all : app.hex
	@echo ".hex file generated successfully!"

# %.o -> $@    %.c -> $<

# Compile all C files
%.o : %.c
	@$(ToolChain)gcc -c $(Target) $< -o $@

# Get .elf file
app.elf : $(OBJ_FILES)
	@$(ToolChain)ld -Map app.map -T $(LR) $(OBJ_FILES) -o $@ 

# Get .hex file from .elf file
app.hex : app.elf
	@$(ToolChain)objcopy -O ihex $< $@

# delete all(.o, .elf, .hex, .map, .asm)
clean :
	@-del *.o *.elf *.hex *.map *.asm