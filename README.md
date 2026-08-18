# 💻 Stack Machine Simulator

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen.svg)

A lightweight, interactive **Stack Machine Simulator** built in C. This project implements a **0-operand (stack-based) Instruction Set Architecture (ISA)**, where arithmetic and logic operations are performed entirely on the data stack.

Developed as a project for **CSE360** (Computer Architecture).

---

## 📑 Table of Contents
- [Features](#-features)
- [Supported Instructions (ISA)](#-supported-instructions-isa)
- [Getting Started](#-getting-started)
- [Example Usage](#-example-usage)
- [Project Structure](#-project-structure)
- [Contributing](#-contributing)

---

## ✨ Features
- **0-Operand ISA**: True stack machine architecture where instructions rely implicitly on the stack.
- **Interactive REPL**: A shell-like command-line interface that allows step-by-step program entry.
- **Robust Error Handling**: Gracefully catches stack overflows, underflows, and division by zero.
- **Modular Codebase**: Separated into clear source and header files for easy maintenance and expansion.

---

## 🛠️ Supported Instructions (ISA)

| Instruction | Operands | Description |
| :--- | :--- | :--- |
| `PUSH n` | `1` | Pushes the integer value `n` onto the top of the stack. |
| `POP` | `0` | Removes the top value from the stack and prints it. |
| `ADD` | `0` | Pops the top two values, adds them, and pushes the result. |
| `SUB` | `0` | Pops the top two values, subtracts the top from the second-top value, and pushes the result. |
| `MUL` | `0` | Pops the top two values, multiplies them, and pushes the result. |
| `DIV` | `0` | Pops the top two values, divides the second-top value by the top value, and pushes the result. |
| `DUP` | `0` | Duplicates the top value on the stack. |
| `SWAP` | `0` | Swaps the positions of the top two values on the stack. |
| `HALT` | `0` | Stops the input phase and begins executing the entered program. |

---

## 🚀 Getting Started

### Prerequisites
You need a C compiler installed on your system (e.g., `gcc` or `clang`).

### Compilation
Clone the repository and compile the code:
```bash
git clone https://github.com/yourusername/stack-machine-simulator.git
cd stack-machine-simulator
gcc project_c.c -o stack_machine
```

### Execution
Run the compiled binary:
```bash
# On Windows
.\stack_machine.exe

# On Linux / macOS
./stack_machine
```

---

## 💡 Example Usage

Unlike standard architectures, a stack machine requires you to push operands to the stack **before** applying an operation (similar to Reverse Polish Notation). 

To calculate `(5 + 10) * 2`:

```text
Enter your program (type 'HALT' to execute):
> PUSH 5
> PUSH 10
> ADD
> PUSH 2
> MUL
> HALT

========================================
              EXECUTION
========================================

Executing: PUSH 5
Stack: [5]
Executing: PUSH 10
Stack: [5, 10]
Executing: ADD
Stack: [15]
Executing: PUSH 2
Stack: [15, 2]
Executing: MUL
Stack: [30]
Executing: HALT

========================================
Final Result: 30
========================================
```

---

## 📂 Project Structure

```text
├── project_c.c   # Main simulator loop, stack logic, and instruction execution
├── project_c.h   # Function prototypes and definitions
└── README.md     # Project documentation
```

---

## 🤝 Contributing
Contributions are always welcome! 
1. Fork the project.
2. Create your feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.
