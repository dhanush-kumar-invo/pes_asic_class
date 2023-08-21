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
A C program 'p1.c' was created to calculate the sum from 1 to 'n' using a text editor like gedit.

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
gcc p1.c
./a.out
```
![p1](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/e050f42c-3117-44dd-a37e-fdbdb83c9e1f)

##RISCV GCC Compiler and Disassemble
Using the RISC-V GCC compiler, we compiled the C program.

```c
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o p1.o p1.c
```

Using ls -ltr p1.c we can check that the object file is created. 2
![ls -ltr](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/4f1651a4-88bf-451b-a451-5528b53b1316)

To get the dissembled ALP code for the C program,
```
riscv64-unknown-elf-objdump -d p1.o | less 
```
In order to view the main section, type /main 4
![Screenshot from 2023-08-21 19-11-17](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/70ca1873-e085-47fc-b08f-b3aa1725811c)

Here, since we used -O1 optimisation, the number of instructions are 26.


## Spike Simulation and Debugging

In the context of this workshop, the `spike` tool is utilized for simulation and debugging purposes:

- To verify whether the produced instructions yield the expected output, execute `spike pk p1.o`.

- For debugging purposes, utilize `spike -d pk p1.c`.

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
