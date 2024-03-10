# CS204-PROJECT
  
## INTRODUCTION :
This repository contains the source code and documentation for a simple assembler developed in C++. 
The assembler is designed to translate assembly language code into machine code for a 32 bit ISA.
It contains one main file, i.e., code.cpp.
It includes file handling and handles the input of assembly code.
This file includes all other six header files, which were made separately.
This assembler supports six different instruction formats: I, R, S, SB, J, and UJ.
Collectively 31 instructions are identified in all.
Any other instruction will not be identified and lead to an error. 

## Instruction Formats
- I: Immediate instructions.
- R: Register instructions.
- S: Store instructions.
- SB: Branch instructions with signed offset.
- J: Jump instructions.
- UJ: Jump instructions with immediate values.
  ## LANGUAGE USED - C++.
  
  ## Usage
To use the assembler:
1. Write your assembly language code in a text file named `assembly_code.asm`.
2. Then, we need to include all six header files (`I.h`, `S.h`, `U.h`, `SB.h`, `J.h`, `R.h`) and the text file containing assembly code (`assembly_code.asm`) in the folder where `code.cpp` is located.
3. Provide the path to your assembly code (`assembly_code.asm`) as input to the assembler program called code.cpp.
4. Compile and execute the assembler program.
5. It will generate the corresponding machine code, typically outputting it to another file named as `ans.mc`.
6. Hence, the code in 'ans.mc' will be your desired output for given assembly code.
   
## Verification
To verify your machine code , you can use "Venus Simulator" and match it with the machine code generated by simulator. It should match the code generated in 'ans.mc' file.
## Assumption
1. The .data attribute has to be in a separate line.
2. The .text attribute should also be in a separate line.
3. Label should be in different line than instruction.
4. There would not be any instructions in front of a label; instructions should be on the next line after the label.
5. Comment should also be in separate line than instruction.
This Project is contributed by-
  
## Hemlata Gautam -2022CSB1084
## Shaikh Asra Swaleh-2022CSB1121
## Smriti Gupta -2022CSB1128
   
   


