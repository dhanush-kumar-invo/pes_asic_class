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


## DAY 3: Introduction to Verilog RTL Design and Synthesis

- Introduction to Open-Source Simulator iVerilog
- Introduction to iVerilog Design Testbench
- Labs using iVerilog and GTKwave
  - Introduction to Lab
  - iVerilog GTKwave Part-1
  - iVerilog GTKwave Part-2
- Introduction to Yosys and Logic Synthesis
  - Introduction to Yosys
  - Introduction to Logic Synthesis
- Labs using Yosys and Sky130 PDKs
  - Yosys good mux

## DAY 4: Timing Libs, Hierarchical vs Flat Synthesis, and Efficient Flop Coding Styles

- Introduction to Timing Dot Libs
- Introduction to Dot Lib
- Hierarchical vs Flat Synthesis
  - Hierarchical Synthesis
  - Flat Synthesis
- Various Flop Coding Styles and Optimization
  - Why Flops and Flop Coding Styles
- Lab Flop Synthesis Simulations
  - Interesting Optimisations

## DAY 5: Combinational and Sequential Optimizations

- Introduction to Optimisations
- Combinational Logic Optimisations
- Sequential Logic Optimisations
- Sequential Optimisations for Unused Outputs

## DAY 6: GLS, Blocking vs Non-Blocking, and Synthesis-Simulation Mismatch

- GLS Synthesis-Simulation Mismatch and Blocking Non-Blocking Statements
- GLS Concepts and Flow Using iVerilog
- Synthesis Simulation Mismatch
- Blocking And Non-Blocking Statements In Verilog
  - Caveats With Blocking Statements
- Labs on GLS and Synthesis-Simulation Mismatch
- Labs on Synth-Sim Mismatch for Blocking Statement


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




# Introduction to Open-Source Simulator: iVerilog

## Introduction to iVerilog Design Testbench Simulator

A simulator is a crucial tool used to simulate digital circuit designs. It monitors input signal changes to evaluate output behavior. If no input change occurs, the simulator won't evaluate outputs. Simulation verifies whether the RTL (Register-Transfer Level) design adheres to specifications. In this context, we'll be using the iverilog simulator.

## iVerilog: An Open-Source Simulator

iVerilog is an open-source Verilog simulator that facilitates testing and simulation of digital circuit designs described in the Verilog hardware description language (HDL). The simulator takes both the design and testbench as input and generates a vcd (value change dump) file. To visualize the vcd file's waveforms, we utilize a tool called GTKwave.
![image](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/c89005ce-530d-4193-9ebc-479b9f34a686)

## Design: Actual Verilog Code

A design encompasses the actual Verilog code or a collection of codes, embodying the intended functionality aligned with required specifications. Verilog is employed to delineate both the behavior and structure of digital circuits across various levels of abstraction, from high-level system descriptions to low-level gate-level representations.

## Testbench: A Crucial Verification Tool

A testbench is a specialized Verilog module or program employed to validate the functionality and behavior of another Verilog module, circuit, or design. Testbenches play a pivotal role in testing and simulating digital designs before they undergo synthesis or physical chip manufacturing. Testbenches set up a stimulus application to examine the design's functionality.



![image](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/1e5da14a-02d7-40cf-b30f-8e1e3b210058)


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
   ```
   ![1](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/4b9d7e44-72b9-4609-823d-2deec04af282)

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






# Introduction to Yosys and Logic Synthesis

## Introduction to Yosys: The Synthesizer

A synthesizer is a vital tool used to transform RTL (Register Transfer Level) design code into a netlist. In our context, we utilize Yosys as the synthesizer.

## Yosys: An Open-Source Synthesis Framework

Yosys is an open-source framework designed for Verilog RTL synthesis and formal verification. It offers a suite of tools and algorithms that empower designers to convert high-level RTL descriptions of digital circuits into optimized gate-level representations suitable for physical implementation on hardware.


![image](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/512bab8e-e6e8-4368-a2b4-84f42eaab6c3)

During the synthesis process, both the design and .lib files are provided to Yosys, resulting in the creation of a netlist file. A netlist represents the design as standard cells within the .lib.

Commands used to perform different operations include:

- `read_verilog`: Used to read the design.
- `read_liberty`: Used to read the .lib file.
- `write_verilog`: Used to generate the netlist file.

## Verification of Synthesis

![image](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/1478da40-db26-4e26-bc41-555f7c45b81c)


For verification, the netlist is combined with the testbench and fed into the iVerilog simulator. The generated VCD file is then passed to the GTKwave simulator. The simulator's output should match what was observed during RTL simulation. As primary inputs and primary outputs remain consistent between the RTL design and synthesized netlist, the same RTL testbench can be employed.

## Introduction to Logic Synthesis

### Logic Synthesis Process

Logic synthesis is a pivotal step in digital design. It converts a high-level hardware description of a digital circuit, often in a hardware description language (HDL) like Verilog or VHDL, into a lower-level representation composed of logic gates and flip-flops. The aim is to optimize the design considering factors like performance, area, power consumption, and timing.

### The .lib Files

The `.lib` files comprise logical modules such as And, Or, and Not gates. They encompass various versions of the same gate, such as 2-input AND gates and 3-input AND gates, with varying performance speeds.

#### Need for Different Gate Versions

Clock frequency directly influences circuit speed. To enhance circuit speed, a higher clock frequency is desirable, necessitating a shorter clock period.

![image](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/3474b2d2-01d9-42d1-a395-0d31c79c7f4c)


For sequential circuits, clock period is contingent upon:

- Clock to Q of flip-flop A.
- Propagation delay of the combinational circuit.
- Setup time of flip-flop B.
![image](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/3f97237d-ccfc-494e-9444-0fb64ac36016)


#### Fast and Slow Cells

To avoid HOLD issues at flip-flop B, slow cells are needed. Conversely, faster cells are vital for minimized propagation time. The collection of these cells forms the .lib.

### Faster Cells vs. Slower Cells

Load in a digital circuit corresponds to capacitance. Faster charging/discharging of capacitance results in lower cell delay. However, quick charge/discharge necessitates transistors capable of sourcing more current, meaning wider transistors. Wider transistors reduce delay but increase area and power consumption.

![image](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/3f97237d-ccfc-494e-9444-0fb64ac36016)



Faster cells come at the cost of area and power. The choice between narrower and wider transistors involves trade-offs between delay, area, and performance.

### Cell Selection

Synthesizers require guidance to choose the optimal cell version for implementing a logic circuit. Overuse of faster cells leads to undesirable power and area consumption, as well as hold time violations. Conversely, excessive use of slower cells yields sluggish circuits that might not meet performance needs. Constraints are applied to the synthesizer to offer guidance, striking a balance between various factors.




# Labs using Yosys and Sky130 PDKs

## Yosys - Synthesizing the "good_mux" Module

1. Navigate to the verilog_files directory:
   ```
   cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
   ```

2. Invoke Yosys:
   ```
   yosys
   ```
   ![3](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/240892b3-5930-4fb1-977f-9f7a7454b4c6)



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
   ```
   ![generate](https://github.com/dhanush-kumar-invo/pes_asic_class/assets/73644447/c8e3ec48-c3f0-46c3-b74b-5b8b8607cf97)



7. Examine the used cells, input and output signals:
   ```
   show
   ```


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






# Day 4: Introduction to Timing Dot Libs

## Introduction to Dot Lib Files

To explore the contents of the `.lib` file, execute the following command:

```bash
gvim ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```

![Dot Lib](image_link_dotlib)

The first line in the file, "library ("sky130_fd_sc_hd__tt_025C_1v80")," signifies:

- "tt": Represents variations due to process, where "Typical Process" is indicated.
- "025C": Signifies variations due to temperature, specifically the silicon's operating temperature.
- "1v80": Reflects variations due to voltage levels where the silicon operates.
- The file also presents the units for various parameters.

## Viewing Contents and Features

To enable line numbering: `:set nu`

To view all cells: `:g//`

To view a specific instance: `:/instance`

The file details all cells' attributes. For the 32 possible combinations (due to 5 inputs), it provides delay, power, and other parameters for each cell.

![Cell Features](image_link_cell_features)

## Hierarchical vs. Flat Synthesis

### Hierarchical Synthesis

Hierarchical synthesis involves breaking complex designs into smaller modules or sub-circuits, which are synthesized individually. These modules are then integrated back into the overall design hierarchy. This approach aids in managing complexity and enables designers to work independently on different design portions.

The file used in this lab: `multiple_modules.v`

```bash
cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
gvim multiple_modules.v
```

![Hierarchical Synthesis](image_link_hierarchical)

The `multiple_modules` instantiates `sub_module1` and `sub_module2`.

Launch Yosys:

```bash
yosys
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog multiple_modules.v
synth -top multiple_modules
```

### Flattened Synthesis

Flattened synthesis amalgamates all modules and sub-modules into a single, flat representation, eliminating the original hierarchical structure.

```bash
yosys
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog multiple_modules.v
synth -top multiple_modules
flatten
```

## Various Flop Coding Styles and Optimization

### Significance of Flops and Flop Coding Styles

- A flip-flop (flop) is a fundamental digital circuit element.
- It stores binary data (0 or 1) based on clock signals and inputs.
- It prevents glitches during data propagation.
- Flops ensure glitch-free input for subsequent combinational circuits.

### D Flip-Flop with Asynchronous Reset

When the reset is high, the flip-flop's output becomes 0, regardless of the clock. Otherwise, on the positive clock edge, the stored value is updated.

```bash
gvim dff_asyncres_syncres.v
```

![D Flip-Flop with Asynchronous Reset](image_link_dff_asyncres)

### D Flip-Flop with Asynchronous Set

When the set is high, the flip-flop's output becomes 1, regardless of the clock. Otherwise, on the positive clock edge, the stored value is updated.

```bash
gvim dff_async_set.v
```

![D Flip-Flop with Asynchronous Set](image_link_dff_asyncset)

### D Flip-Flop with Synchronous Reset

When the reset is high on the positive clock edge, the flip-flop's output becomes 0. Otherwise, on the positive clock edge, the stored value is updated.

```bash
gvim dff_syncres.v
```

![D Flip-Flop with Synchronous Reset](image_link_dff_syncres)

### D Flip-Flop with Asynchronous and Synchronous Reset

When the asynchronous reset is high, the output is forced to 0. When the synchronous reset is high at the positive clock edge, the output is forced to 0. Otherwise, on the positive clock edge, the stored value is updated.

```bash
gvim dff_asyncres_syncres.v
```

![D Flip-Flop with Asynchronous and Synchronous Reset](image_link_dff_asyncressyncres)

## Lab: Flop Synthesis and Simulations

### D Flip-Flop with Asynchronous Reset

**Simulation:**

```bash
cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
iverilog dff_asyncres.v tb_dff_asyncres.v
./a.out
gtkwave tb_dff_asyncres.vcd
```

**Synthesis:**

```bash
cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
yosys
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_asyncres.v
synth -top dff_asyncres
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

### D Flip-Flop with Asynchronous Set

**Simulation:**

```bash
cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
iverilog dff_async_set.v tb_dff_async_set.v
./a.out
gtkwave tb_dff_async_set.vcd
```

**Synthesis:**

```bash
cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
yosys
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_async_set.v
synth -top dff_async_set
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

### D Flip-Flop with Synchronous Reset

**Simulation:**

```bash
cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
iverilog dff_syncres.v tb_dff_syncres.v
./a.out
gtkwave tb_dff_syncres.vcd
```

**Synthesis:**

```bash
cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
yosys
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_syncres.v
synth -top dff_syncres
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

### Interesting Optimizations

Explore optimization examples by working with Verilog files and Yosys synthesis commands.

Sure, here is the text repeated:

```markdown
# Week 1

## DAY 5: Introduction to Optimisations

- Introduction to Optimisations
- Combinational Optimisation

Combinational logic refers to logic circuits where the outputs depend only on the current inputs and not on any previous states. Combinational optimization is a field of study in computer science and operations research that focuses on finding the best possible solution from a finite set of options for problems that involve discrete variables and have no inherent notion of time. Optimizing the combinational logic circuit is squeezing the logic to get the most optimized digital design so that the circuit finally is area and power efficient.

**Techniques for Optimisations:**

- Constant propagation is an optimization technique used in compiler design and digital circuit synthesis to improve the efficiency of code and circuit implementations by replacing variables or expressions with their constant values where applicable.

- Boolean logic optimization, also known as logic minimization or Boolean function simplification, is a process in digital design that aims to simplify Boolean expressions or logic circuits by reducing the number of terms, literals, and gates required to implement a given logical function.

- Sequential Logic Optimisations

Sequential logic optimizations involve improving the efficiency, performance, and resource utilization of digital circuits that include memory elements like flip-flops and latches. Optimizing sequential logic is crucial in ensuring that digital circuits meet timing requirements, consume minimal power, and occupy the least possible area while maintaining correct functionality.

**Optimization methods:**

- Sequential constant propagation, also known as constant propagation across sequential elements, is an optimization technique used in digital design to identify and propagate constant values through sequential logic elements like flip-flops and registers. This technique aims to replace variable values with their known constant values at various stages of the logic circuit, optimizing the design for better performance and resource utilization.

- State optimization, also known as state minimization or state reduction, is an optimization technique used in digital design to reduce the number of states in finite state machines (FSMs) while preserving the original functionality.

- Sequential logic cloning, also known as retiming-based cloning or register cloning, is a technique used in digital design to improve the performance of a circuit by duplicating or cloning existing registers (flip-flops) and introducing additional pipeline stages. This technique aims to balance the critical paths within a circuit and reduce its overall clock period, leading to improved timing performance and better overall efficiency.

- Retiming is an optimization technique used in digital design to improve the performance of a circuit by repositioning registers (flip-flops) along its paths to balance the timing and reduce the critical path delay. The primary goal of retiming is to achieve a shorter clock period without changing the functionality of the circuit.

- Combinational Logic Optimisations

![opt_check](opt_check.png)

```shell
gvim opt_check.v
```

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog opt_check.v
synth -top opt_check
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![opt_check2](opt_check2.png)

```shell
gvim opt_check2.v
```

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog opt_check2.v
synth -top opt_check2
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![opt_check3](opt_check3.png)

```shell
gvim opt_check3.v
```

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog opt_check3.v
synth -top opt_check3
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![opt_check4](opt_check4.png)

```shell
gvim opt_check4.v
```

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog opt_check4.v
synth -top opt_check4
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![multiple_module_opt](multiple_module_opt.png)

```shell
gvim multiple_module_opt.v
```

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog multiple_module_opt.v
synth -top multiple_module_opt
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

- Sequential Logic Optimisations

![dff_const1](dff_const1.png)

```shell
gvim dff_const1.v
```

**Simulation**

```shell
iverilog dff_const1.v tb_dff_const1.v
./a.out
gtkwave tb_dff_const1.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const1.v
synth -top dff_const1
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![dff_const2](dff_const2.png)

```shell
gvim dff_const2.v
```

**Simulation**

```shell
iverilog dff_const2.v tb_dff_const2.v
./a.out
gtkwave tb_dff_const2.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const2.v
synth -top dff_const2
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![dff_const3](dff_const3.png)

```shell
gvim dff_const3.v
```

**Simulation**

```shell
iverilog dff_const3.v tb_dff_const3.v
./a.out
gtkwave tb_dff_const3.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const3.v
synth -top dff_const3
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![dff_const4

](dff_const4.png)

```shell
gvim dff_const4.v
```

**Simulation**

```shell
iverilog dff_const4.v tb_dff_const4.v
./a.out
gtkwave tb_dff_const4.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const4.v
synth -top dff_const4
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![dff_const5](dff_const5.png)

```shell
gvim dff_const5.v
```

**Simulation**

```shell
iverilog dff_const4.v tb_dff_const4.v
./a.out
gtkwave tb_dff_const4.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const4.v
synth -top dff_const4
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

**Sequential Optimisations for Unused Outputs**

![counter_opt](counter_opt.png)

```shell
gvim counter_opt.v
```

**Simulation**

```shell
iverilog counter_opt.v tb_counter_opt.v
./a.out
gtkwave tb_counter_opt.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog counter_opt.v
synth -top counter_opt
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![counter_opt2](counter_opt2.png)

```shell
gvim counter_opt2.v
```

**Simulation**

```shell
iverilog counter_opt2.v tb_counter_opt2.v
./a.out
gtkwave tb_counter_opt2.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog counter_opt2.v
synth -top counter_opt2
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

## DAY 6: GLS, Blocking vs Non-Blocking, and Synthesis-Simulation Mismatch

- GLS Synthesis-Simulation Mismatch and Blocking Non-blocking Statements
- GLS Concepts And Flow Using Iverilog
- Gate Level Simulation

Gate-level simulation is a technique used in digital design and verification to validate the functionality of a digital circuit at the gate-level implementation. It involves simulating the circuit using the actual logic gates and flip-flops that make up the design, as opposed to higher-level abstractions like RTL (Register Transfer Level) descriptions. This type of simulation is typically performed after the logic synthesis process, where a high-level description of the design is transformed into a netlist of gates and flip-flops. We perform this to verify logical correctness of the design after synthesizing it. Also ensuring the timing of the design is met.

**Synthesis-Simulation Mismatch**

A synthesis-simulation mismatch refers to a situation in digital design where the behavior of a circuit, as observed during simulation, doesn't match the expected or desired behavior of the circuit after it has been synthesized. This discrepancy can occur due to various reasons, such as timing issues, optimization conflicts, and differences in modeling between the simulation and synthesis tools. This mismatch is a critical concern in digital design because it indicates that the actual hardware implementation might not perform as expected, potentially leading to functional or timing failures in the fabricated chip.

**Blocking Statements**

Blocking statements are executed sequentially in the order they appear in the code and have an immediate effect on signal assignments.

Example:

```verilog
module BlockingExample(input A, input B, input C, output Y, output Z);
  wire temp;

  // Blocking assignment
  assign temp = A & B;

  always @(posedge C) begin
      // Blocking assignment
      Y = temp;
      Z = ~temp;
  end
endmodule
```

**Non-Blocking Statements**

Non-blocking assignments are used to model concurrent signal updates, where all assignments are evaluated simultaneously and then scheduled to be updated at the end of the time step.

Example:

```verilog
module NonBlockingExample(input clock, input D, input reset, output reg Q);

 always @(posedge clock or posedge reset) begin
     if (reset)
         Q <= 0;  // Reset the flip-flop
     else
         Q <= D;  // Non-blocking assignment to update Q with D on clock edge
 end
endmodule
```

**Caveats with Blocking Statements**

Blocking statements in hardware description languages like Verilog have their uses, but there are certain caveats and considerations to be aware of when working with them. Here are some important caveats associated with using blocking statements:

- Procedural Execution: Blocking statements are executed sequentially in the order they appear within a procedural block (such as an always block). This can lead to unexpected behavior if the order of execution matters and is not well understood.

- Lack of Parallelism: Blocking statements do not accurately represent the parallel nature of hardware. In hardware, multiple signals can update concurrently, but blocking statements model sequential behavior. As a result, using blocking statements for modeling complex concurrent logic can lead to incorrect simulations.

- Race Conditions: When multiple blocking assignments operate on the same signal within the same procedural block, a race condition can occur. The outcome of such assignments depends on their order of execution, which might lead to inconsistent or unpredictable behavior.

- Limited Representation of Hardware: Hardware systems are inherently concurrent and parallel, but blocking statements do not capture this aspect effectively. Using blocking assignments to model complex combinational or sequential logic can lead to models that are difficult to understand, maintain, and debug.

- Combinatorial Loops: Incorrect use of blocking statements can lead to unintentional combinational logic loops, which can result in simulation or synthesis errors.

- Debugging Challenges: Debugging code with many blocking assignments can be challenging, especially when trying to track down timing-related issues.

- Not Suitable for Flip-Flops: Blocking assignments are not suitable for modeling flip-flop behavior. Non-blocking assignments (<=) are generally preferred for modeling flip-flop updates to ensure accurate representation of concurrent behavior.

- Sequential Logic Misrepresentation: Using blocking assignments to model sequential logic might not capture the intended behavior accurately. Sequential elements like registers and flip-flops are better represented using non-blocking assignments.

- Synthesis Implications: The behavior of blocking assignments might not translate well during synthesis, leading to potential

 mismatches between simulation and synthesis results.

**Labs on GLS and Synthesis-Simulation Mismatch**

![ternary_operator_mux](ternary_operator_mux.png)

```shell
gvim ternary_operator_mux.v
```

**Simulation**

```shell
iverilog ternary_operator_mux.v tb_ternary_operator_mux.v
./a.out
gtkwave tb_ternary_operator_mux.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog ternary_operator_mux.v
synth -top ternary_operator_mux
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![GLS to Gate-Level Simulation](GLS_to_Gate-Level_Simulation.png)

```shell
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v ternary_operator_mux_net.v tb_ternary_operator_mux.v
./a.out
gtkwave tb_ternary_operator_mux.vcd
```

![bad_mux](bad_mux.png)

```shell
gvim bad_mux.v
```

**Simulation**

```shell
iverilog bad_mux.v tb_bad_mux.v
./a.out
gtkwave tb_bad_mux.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog bad_mux.v
synth -top bad_mux
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![GLS to Gate-Level Simulation](GLS_to_Gate-Level_Simulation.png)

```shell
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v bad_mux_net.v tb_bad_mux.v
./a.out
gtkwave tb_bad_mux.vcd
```

**Labs on Synth-Sim Mismatch for Blocking Statement**

![blocking_caveat](blocking_caveat.png)

```shell
gvim blocking_caveat.v
```

**Simulation**

```shell
iverilog blocking_caveat.v tb_blocking_caveat.v
./a.out
gtkwave tb_blocking_caveat.vcd
```

**Synthesis**

```shell
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog blocking_caveat.v
synth -top blocking_caveat
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![GLS to Gate-Level Simulation](GLS_to_Gate-Level_Simulation.png)

```shell
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v blocking_caveat_net.v tb_blocking_caveat.v
./a.out
gtkwave tb_blocking_caveat.vcd
```

## Repeat the same...
```

You can continue the pattern for the remaining content.
