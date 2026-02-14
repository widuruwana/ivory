# 🌿 Ivory (v1.0.0)

**Ivory** is a Turing-complete, esoteric programming language (esolang) and Ahead-of-Time (AOT) compiler suite. Originally conceived as a romantic gesture for Valentine's Day 2026, Ivory reimagines the classic tape-memory computational model by introducing a hybrid Tape/Stack architecture, temporal constraints, and hardware entropy through a lexicon of devotion.

## Philosophy
Programs in Ivory are designed to read like stream-of-consciousness prose or avant-garde poetry. Unlike traditional languages that prioritize brevity and execution speed, Ivory enforces the **"Whisper Constraint"**—a hardcoded 50ms thread delay on standard output—ensuring a deliberate, human pace for every character printed to the terminal.

## Architecture
Ivory utilizes a **Single-pass Ahead-of-Time (AOT) Transpiler** architecture.

* **Frontend**: The `ivoryc` compiler lexes `.ivy` source files. Unrecognized tokens are intentionally ignored, allowing for the inclusion of natural language comments directly within the logical flow.
* **Intermediate Representation (IR)**: Ivory code is transpiled into a temporary C++ representation of a Hybrid Virtual Machine (featuring a 30,000-cell primary tape and an infinite LIFO memory stack).
* **Backend**: The compiler forks a system process, invoking the local GCC toolchain (`g++`) to perform high-level optimizations (`-O3`) and link the IR into a standalone, native machine-code binary (ELF for Linux, PE for Windows).

## Instruction Set
Ivory extends standard Trivial Brainfuck Substitution (TBS) by implementing 19 distinct opcodes, organized into logical sub-systems:

### 1. Core Turing Machine Operations
| Keyword | Action | Description |
| :--- | :--- | :--- |
| `adore` | `+` | Increment the value at the current memory cell. |
| `miss` | `-` | Decrement the value at the current memory cell. |
| `hold` | `>` | Move the data pointer one cell to the right. |
| `release` | `<` | Move the data pointer one cell to the left. |

### 2. I/O & Control Flow
| Keyword | Action | Description |
| :--- | :--- | :--- |
| `whisper` | `.` | Output current cell's ASCII value (enforces 50ms thread delay). |
| `listen` | `,` | Accept a single character of input into the current cell. |
| `promise` | `[` | Begin a loop (Jump forward if the cell value is 0). |
| `always` | `]` | End a loop (Jump back if the cell value is non-zero). |

### 3. Memory Stack (LIFO)
| Keyword | Action | Description |
| :--- | :--- | :--- |
| `cherish` | `push()` | Push the value of the current tape cell onto the memory stack. |
| `reminisce`| `pop()` | Pop the top value from the stack and overwrite the current tape cell. |

### 4. Temporal & Environment Control
| Keyword | Action | Description |
| :--- | :--- | :--- |
| `breathe` | `sleep()` | Suspend host thread execution for exactly 1000ms. |
| `clear` | `\033[2J` | Clear the terminal screen using ANSI escape sequences. |

### 5. Developer Quality of Life (QoL)
| Keyword | Action | Description |
| :--- | :--- | :--- |
| `passion` | `+= 10` | Add 10 to the current memory cell (Bulk Arithmetic). |
| `heartbreak`| `-= 10` | Subtract 10 from the current memory cell (Bulk Arithmetic). |
| `forget` | `= 0` | Instantly zero out the current memory cell (State Reset). |
| `confess` | `print(int)`| Output the raw integer value of the current cell for debugging. |

### 6. Architectural Power Features
| Keyword | Action | Description |
| :--- | :--- | :--- |
| `destiny` | `p = tape[p]` | Absolute pointer dereferencing (teleports pointer to address). |
| `wonder` | `rand()` | Hardware entropy injection (assigns a random 8-bit integer). |
| `fade` | `exit(0)` | Graceful process termination / hardware interrupt. |

## Hello, World!

Below is a standard "Hello, World!" program. 

```text
passion passion passion passion passion passion passion
adore adore whisper passion passion adore adore adore
adore adore adore adore adore adore whisper adore
adore adore adore adore adore adore whisper whisper
adore adore adore whisper forget passion passion passion
passion adore adore adore adore whisper heartbreak miss
miss whisper passion passion passion passion passion adore
adore adore adore adore whisper passion passion adore
adore adore adore whisper adore adore adore whisper
miss miss miss miss miss miss whisper miss
miss miss miss miss miss miss miss whisper
forget passion passion passion adore adore adore whisper
fade
```

## Getting Started

### Prerequisites
* A C++ compiler (GCC/MinGW recommended) installed in your system PATH.

### Installation
Clone the repository and compile the Ivory compiler suite:
```bash
g++ -O3 ivoryc.cpp -o ivoryc
```

### Usage
To compile an Ivory source file into a native executable:

```bash
# Explicit output name
./ivoryc script.ivy love_letter.exe

# Defaulting to a.out (Linux) or a.exe (Windows)
./ivoryc script.ivy
```

## Example: The Valentine Payload
The repository includes `poem.ivy`, a source file initially generated via a Python-based ASCII-offset calculator and heavily augmented with Ivory's temporal opcodes (`breathe`, `clear`). When compiled and executed, it outputs a multi-line message dynamically, demonstrating the language's capacity for complex string manipulation, thread blocking, and memory-tape arithmetic.

**Author: Kavindu Widyarathne.**

**Dedicated to: My beautiful girlfriend.**


**Date: February 14, 2026.**
