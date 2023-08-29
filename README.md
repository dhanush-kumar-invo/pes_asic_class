# pes_asic_class

## VLSI ASIC Physical Design Course
## Objectives
The goal of the VLSI ASIC Physical Design course is to transform a logical RTL design into a practical physical layout suitable for manufacturing. This process ensures that the circuit's functionality aligns with design constraints, performance objectives, and manufacturing standards.

## Skill Outcomes
Participants in this course will develop expertise in the following areas:

- Architectural Design: Understanding the overall structure and organization of integrated circuits.
- RTL Design / Behavioral Modeling: Creating a Register Transfer Level (RTL) description of a digital circuit's behavior.
- Floorplanning: The initial phase of physical design where major component locations are planned.
- Placement: Determining precise cell or module locations on the chip.
- Clock Tree Synthesis: Constructing a clock distribution network to ensure synchronous operation.
- Routing: Establishing interconnections between different parts of the design.

## Installation Instructions
To initiate the VLSI Physical Design for ASICs workshop, follow these steps:

1. Download the 'installation.sh' script from the GitHub repository.
2. Open a terminal on your system.
3. Navigate to the directory containing the downloaded 'run.sh' script (e.g., use 'cd Downloads').
4. Execute the script using the command: './run.sh'
   This will set up the necessary environment and start the installation process.

## Table of Contents
### Day 1
- Introduction to RISC-V ISA and GNU Compiler Toolchain
- Introduction to Basic Keywords
  - Introduction
  - Transition from Applications to Hardware
- Detailed Course Content Description
- Labwork for RISC-V Toolchain
  - C Program
  - RISC-V GCC Compiler and Disassembly
  - Spike Simulation and Debugging
- Integer Number Representation
  - 64-bit Unsigned Numbers
  - 64-bit Signed Numbers
- Labwork for Signed and Unsigned Numbers

### Day 2
- Introduction to ABI and Basic Verification Flow
  - Application Binary Interface (ABI)
  - Memory Allocation for Double Words
  - Load, Add, and Store Instructions
  - 32-Registers and their ABI Names
- Labwork using ABI Function Calls
  - Algorithm for C Program using ASM
  - Review of ASM Function Calls
  - Simulation of C Program using Function Calls
- Introduction to ISA (Instruction Set Architecture)
- Overview of RISC-V (Reduced Instruction Set Computing - Five)
  - Transition from Applications to Hardware
- Definitions:
  - Apps (Application Software)
  - System Software
  - Operating System
  - Compiler
  - Assembler
  - RTL (Register Transfer Level)
  - Hardware

### Detailed Course Content
#### Pseudo Instructions
Pseudo-instructions simplify programming, enhance code readability, and reduce the explicit instructions needed. They are particularly useful for common programming patterns involving multiple instructions (e.g., 'li', 'mv').

#### Base Integer Instructions
These fundamental instructions form the core for basic arithmetic, logical, and data movement operations. Examples include 'add', 'sub', 'and', 'or', 'xor', and 'sll'.

#### Multiply Extension Instructions
The RISC-V architecture includes instructions for efficient multiplication and multiply-accumulate operations, such as 'mul', 'mulh', 'mulhu', 'mulhsu'.

#### Single and Double Precision Floating Point Extension
Support for single-precision (32-bit) and double-precision (64-bit) floating-point arithmetic operations is provided by the 'F' and 'D' extensions, respectively.

#### Application Binary Interface (ABI)
ABI defines rules for software components' binary-level interactions. It covers aspects like function calls, parameter passing, memory allocation, and management.

#### Memory Allocation and Stack Pointer
Memory allocation assigns and manages memory segments for program data structures. The stack pointer tracks the program's execution position on the call stack.

#### Labwork for RISCV Toolchain
C Program:
A C program '1ton.c' was created to calculate the sum from 1 to 'n' using a text editor like gedit.

```c
#include <stdio.h>
int main() {
    int i, sum = 0, n = 5;
    for (i = 1; i <= n; i++) {
        sum = sum + i;
    }
    printf("Sum of numbers from 1 to %d is %d \n", n, sum);
    return 0;
}
```

The program was compiled using the GCC compiler to obtain the output."
```
gcc 1ton.c
./a.out
```
![p1](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/e050f42c-3117-44dd-a37e-fdbdb83c9e1f)

##RISCV GCC Compiler and Disassemble
Using the RISC-V GCC compiler, we compiled the C program.

```c
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.c 1ton.c
```

Using ls -ltr 1ton.c we can check that the object file is created. 2
![ls -ltr](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/4f1651a4-88bf-451b-a451-5528b53b1316)

To get the dissembled ALP code for the C program,
```
riscv64-unknown-elf-objdump -d sum1ton.c | less 
```
In order to view the main section, type /main 4
![Screenshot from 2023-08-21 19-11-17](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/70ca1873-e085-47fc-b08f-b3aa1725811c)

Here, since we used -O1 optimisation, the number of instructions are 26.


## Spike Simulation and Debugging

In the context of this workshop, the `spike` tool is utilized for simulation and debugging purposes:

- To verify whether the produced instructions yield the expected output, execute `spike pk sum1ton.c`.

- For debugging purposes, utilize `spike -d pk 1ton.c`.

You can also view the register contents during debugging:

- Press ENTER: To display the first line, then successive ENTER for subsequent lines.
- `reg 0 a2`: To examine the content of register `a2` of the 0th core.
- `q`: To exit the debugging process.

## Integer Number Representation

### Unsigned Numbers
Unsigned numbers, also referred to as non-negative numbers, represent magnitudes without sign or direction. They fall within the range: [0, (2^n) - 1].


### Labwork


### Program: unsigned.c - Maximum and Minimum Values of 64-bit Unsigned Numbers
```c
#include <stdio.h>
#include <math.h>

int main() {
    unsigned long long int a;
    long long int b_max, b_min;

    a = (unsigned long long int)(pow(2, 64) - 1);
    b_max = (long long int)(pow(2, 63) - 1);
    b_min = (long long int)(pow(2, 63) * (-1));

    printf("Max value of 64-bit unsigned number: %llu\nMax value of 64-bit signed number: %lld\nMin value of 64-bit signed number: %lld\n", a, b_max, b_min);

    return 0;
}
```
![Unsigned Numbers](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/e32dbadb-460f-4ac8-aff0-e9f58dbec94f)

For more details, refer to the respective code files in the [`unsigned.c`](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/unsigned.c) 



# Application Binary Interface (ABI)

## Introduction to ABI
An **Application Binary Interface (ABI)** comprises a set of regulations and principles that define how binary code interacts and communicates with other binary code, typically at the level of machine code or compiled code. Put simply, it establishes the interface between two software components or systems that are composed in different programming languages, compiled by diverse compilers, or operating on varying hardware architectures.

The ABI is of utmost importance in facilitating interoperability between distinct software components, such as different libraries, object files, or even entire programs. By adhering to a common set of rules for communication and data representation, it enables components compiled independently and potentially on different platforms to seamlessly collaborate.

## Memory Allocation for Multi-Byte Values
When dealing with a 64-bit number or any multi-byte value, its storage in memory can follow either a little-endian or big-endian byte order. This involves understanding the arrangement of bytes based on their significance.

- **Little-Endian**: In this representation, the least significant byte (LSB) is stored at the lowest memory address, while the most significant byte (MSB) is placed at the highest memory address.
- **Big-Endian**: In contrast, the most significant byte (MSB) is stored at the lowest memory address, and the least significant byte (LSB) is situated at the highest memory address.


## Load, Add, and Store Instructions
Load, Add, and Store instructions constitute fundamental operations in computer architecture and assembly programming. They are essential for manipulating data within a computer's memory and registers.

- **Load Instructions**: These instructions transfer data from memory to registers. They fetch data from a specified memory address and place it into a register for further processing. For example: `ld x6, 8(x5)` where `ld` is the load double-word instruction, `x6` is the destination register, and `8(x5)` is the memory address accessed through register `x5` (base address + offset).

- **Store Instructions**: Store instructions, on the other hand, are employed to write data from registers into memory. They store register values into designated memory addresses. For instance: `sd x8, 8(x9)` where `sd` signifies the store double-word instruction, `x8` is the source register, and `8(x9)` is the memory address accessed via register `x9` (base address + offset).

- **Add Instructions**: Add instructions are used to perform addition operations on registers. They add the values of two source registers and store the result in a destination register. For example: `add x9, x10, x11` where `add` is the add instruction, `x9` is the destination register, and `x10` and `x11` are the source registers.

## 32 Registers and Their ABI Names
The choice of the number of registers in a processor's architecture, such as the RISC-V RV64 architecture with its 32 general-purpose registers, involves a trade-off between various factors. While modern processors could have more registers, increasing their count might lead to larger instructions, potentially consuming more memory and impacting instruction fetch and decode speed.

ABI names for registers play a pivotal role in standardizing the purpose and usage of specific registers within a software ecosystem. These names aid in maintaining compatibility, optimizing code generation, and facilitating communication between different software components.

<img width="430" alt="API" src="https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/507379c1-b0d9-436b-8f03-d111491b3231">


## Labwork using ABI Function Calls
### Algorithm for Incorporating ASM into C Program

Incorporating assembly language code into a C program can be achieved through inline assembly or by linking separate assembly files with your C code. When you invoke an assembly function from your C code, the C calling convention is followed. This involves pushing arguments onto the stack or passing them in registers as necessary.

The program subsequently executes the assembly function, following the assembly instructions provided by you.

### Review of ASM Function Calls

For the purpose of integrating assembly code with C code, two distinct files were used. The C code was written in one file, while the assembly code was contained in a separate file.

In the assembly file, assembly functions were declared with appropriate signatures that align with the calling conventions of the specific platform.

## C Program: `1to9_custom.c`

```c
#include <stdio.h>

extern int load(int x, int y);

int main()
{
  int result = 0;
  int count = 9;
  result = load(0x0, count + 1);
  printf("Sum of numbers from 1 to 9 is %d\n", result);
}
```

## Assembly Code: `load.s`

```assembly
.section .text
.global load
.type load, @function

load:
   add a4, a0, zero
   add a2, a0, a1
   add a3, a0, zero

loop:
   add a4, a3, a4
   addi a3, a3, 1
   blt a3, a2, loop
   add a0, a4, zero
   ret
```

## Simulating the C Program using Function Call

### Compilation:

To compile the C code and assembly file, use the following command:

```bash
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o 1to9_custom.o 1to9_custom.c load.s
```

This command will generate the object file `1to9_custom.o`.

### Execution:

To execute the object file using the Spike RISC-V simulator, run the command:

```bash
spike $(which pk) 1to9_custom.o
```
![day2](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/7013a12f-a532-46f6-8fe5-8ac945dde85b)

This will simulate the execution of the program and provide you with the corresponding output.








# Labs using iVerilog and GTKwave

## Introduction to Lab

1. Create a directory named `vsd`:
   ```
   mkdir vsd
   cd vsd
   ```

2. Clone the GitHub repository containing the lab materials:
   ```
   git clone https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git
   ```

   This creates a folder named `sky130RTLDesignAndSynthesisWorkshop` within the `vsd` directory.

   

- `my_lib`: Contains all the library files
- `lib`: Contains the sky130 standard cell library used for synthesis
- `verilog_model`: Contains standard cell Verilog modules from the standard cell library
- `verilog_files`: Contains Verilog source files and testbench files required for labs

## iVerilog GTKwave Part-1

1. Navigate to the verilog_files directory:
   ```
   cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
   `![1](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/4b9d7e44-72b9-4609-823d-2deec04af282)
``

2. Load the source code and testbench code into the iVerilog simulator:
   ```
   iverilog good_mux.v tb_good_mux.v
   ```

   This command compiles the code, and an output file `a.out` is generated.

3. Run the compiled program:
   ```
   ./a.out
   ```

4. The output of iVerilog is a VCD file, which can be loaded into the GTKwave simulator:
   ```
   gtkwave tb_good_mux.vcd
   ```



## iVerilog GTKwave Part-2

To view the contents of files:

 Use a text editor like `gvim` to open files:
   ```
   gvim tb_good_mux.v -o good_mux.v
   ```
![2](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/ba8316e6-8d85-4091-b9be-4601bb35df5b)





# Labs using Yosys and Sky130 PDKs

## Yosys - Synthesizing the "good_mux" Module

1. Navigate to the verilog_files directory:
   ```
   cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
   ```

2. Invoke Yosys:
   ```
   yosys
   ```![3](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/240892b3-5930-4fb1-977f-9f7a7454b4c6)



3. Read the library:
   ```
   read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   ```

4. Read the design source file:
   ```
   read_verilog good_mux.v
   ```

5. Perform synthesis for the specified module:
   ```
   synth -top good_mux
   ```
![4](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/5c25baf6-c1b4-461d-8d32-bdcb8de8a721)

![synth](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/ce61835d-e03a-4ee5-a5b9-b541411fd64d)



6. Generate the netlist using ABC:
   ```
   abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   ```![generate](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/c8e3ec48-c3f0-46c3-b74b-5b8b8607cf97)



7. Examine the used cells, input and output signals:
   ```
   show
   ```

   ![Show Logic](link_to_image4)

8. The multiplexer design is realized using sky130 library cells.

9. Write the netlist to a file:
   ```
   write_verilog good_mux_netlist.v
   ```

   Open the netlist in a text editor:
   ```
   gvim good_mux_netlist.v
   ```

10. To view a simplified netlist:
    ```
    write_verilog -noattr good_mux_netlist.v
    ```

    Open the simplified netlist in a text editor:
    ```
    gvim good_mux_netlist.v
    ```
![write the netlist_code](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/76595eb2-558b-45d5-b775-eff801ca2363)
![write the netlist](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/5d15e36a-dfae-495c-842b-e02ac612eedf)

```

