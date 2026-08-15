<h1 align="center">
	42 Cursus' Libft
</h1>

<p align="center">
	<b><i>My very own C library: A foundational toolkit for high-performance C programming.</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/carolinecbahia/libft?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/carolinecbahia/libft?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/carolinecbahia/libft?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/carolinecbahia/libft?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/carolinecbahia/libft?color=green" />
</p>

<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#modules">Modules</a>
	<span> · </span>
	<a href="#integration">Integration</a>
	<span> · </span>
	<a href="#installation">Installation</a>
	<span> · </span>
	<a href="#usage">Usage</a>
</h3>

---

## 💡 About the Project

> _"Don't reinvent the wheel? At 42, we build the wheel first so we can drive later."_

**Libft** is the first project at 42 School, requiring students to recreate essential functions from the C standard library (`libc`).

However, this repository is more than just an assignment. It is a **living project**. It serves as the backbone for all my advanced C projects within the curriculum, providing reusable, memory-safe tools for tasks ranging from algorithmic sorting to shell implementation.

---

## 🧩 Modules & Features

This library is modular and currently supports the following capabilities:

### 1. Libc Re-implementation
Standard C functions re-written from scratch for deep understanding of memory manipulation.
* **String Operations:** `ft_strlen`, `ft_strjoin`, `ft_strdup`...
* **Memory Operations:** `ft_memset`, `ft_memcpy`, `ft_calloc`...
* **Type Checks:** `ft_isalnum`, `ft_isdigit`, `ft_atoi`...

### 2. Data Structures
Full implementation of **Linked Lists** utilities to manage nodes dynamically. Crucial for stack manipulation.
* `ft_lstnew`, `ft_lstadd_front`, `ft_lstiter`, `ft_lstmap`...

### 3. Extended Tools
Custom tools added during my journey through the circles:
* **Get_Next_Line:** Efficiently reads content from File Descriptors line-by-line using static buffers.
* **Ft_Printf:** A custom implementation of `printf` handling variadic arguments (`va_list`).

---

## 🔄 Project Integration

This library is actively used in my other repositories to solve complex engineering problems:

| Project | Role of Libft |
| :--- | :--- |
| **Minishell** (In Progress) | Heavy string parsing, environment variable management (Linked Lists), and memory cleanup. |
| **Push_swap** | Used linked lists to implement Stacks (A/B) and helper functions for the sorting algorithm. |
| **Minitalk** | Provided `ft_atoi` and string utils to handle PID parsing and message reconstruction via UNIX Signals. |
| **So_long** | Map parsing (reading 2D arrays) and error management for the graphical game engine. |

---

## 🛠️ Technical Implementation

### Robustness & Stability
Unlike the standard library, where behaviors can sometimes be undefined, this library focuses on stability. Every function includes protection against `NULL` pointers and memory allocation failures.

### Memory Management
**Zero memory leaks policy.** All heap allocations are carefully tracked. The library is designed to be included in long-running processes (like Shells or Daemons) without causing memory bloat.

### Compilation
The project uses a `Makefile` to compile the source files into a static library (`libft.a`).
* `make`: Compiles the core library.
* `make bonus`: Includes linked list functions.
* `make clean/fclean`: Removes object files and binaries.

---

## 💻 Installation

To use this library in your code, clone the repository into your project folder:

```bash
git clone [https://github.com/carolinecbahia/libft.git](https://github.com/carolinecbahia/libft.git) libft
cd libft
make
