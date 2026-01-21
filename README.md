
# Cub3D - Raycasting 3D Engine

> A mini 3D graphics engine in C, using **MLX42** (MiniLibX) for real-time rendering. Developed as part of the **42 School** curriculum to master graphics programming, parsing, raycasting, and game architecture.

[![Language](https://img.shields.io/badge/language-C-blue.svg)]()
[![Graphics](https://img.shields.io/badge/graphics-MLX42-purple.svg)]()
[![Project](https://img.shields.io/badge/project-Cub3D-orange.svg)]()
[![Status](https://img.shields.io/badge/status-fully%20functional-success.svg)]()

## 📋 Table of Contents

- [Overview](#overview)
- [Mechanics](#mechanics)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Architecture](#architecture)
- [Controls](#controls)
- [Testing](#testing)
- [Technical Highlights](#technical-highlights)
- [Author](#author)

## 🎮 Overview

**Cub3D** is a "raycasting" project that simulates a 3D environment from 2D maps, inspired by the classic Wolfenstein 3D. The goal is to explore a maze rendered in real time, with free movement and first-person view.

**Key achievements:**
- ✅ 3D rendering based on raycasting
- ✅ Robust .cub map parsing
- ✅ Wall and floor texturing
- ✅ Smooth camera and movement control
- ✅ No memory leaks

## 🕹️ Mechanics

### Gameplay
1. **Goal:** Navigate the map, exploring the 3D environment
2. **Controls:** WASD to move, arrows to rotate
3. **Win condition:** Free exploration (can be expanded)
4. **Error conditions:** Invalid map, wall collision

### Game Elements
- **Player:** Initial position defined in the map
- **Walls:** Defined by '1' in the map
- **Free space:** '0' in the map
- **Textures:** XPM files for walls, floor, ceiling
- **Map:** .cub file, rectangular, surrounded by walls

### Game Loop
```
Initialize engine
   ↓
Load and validate map
   ↓
Load textures
   ↓
[Main Loop - 60 FPS]
   ├─ Read keyboard input
   ├─ Update position/camera
   ├─ Raycasting and rendering
   └─ Check collisions
   ↓
Free resources and exit
```

## ✨ Features

### Mandatory
- ✅ **3D rendering** via raycasting
- ✅ **.cub map parsing**
- ✅ **Wall textures**
- ✅ **Player movement and rotation**
- ✅ **Minimap** (if implemented)
- ✅ **Map validation**
- ✅ **Clean exit** (ESC or close window)

### Bonus (if implemented)
- ✅ Doors, sprites, HUD
- ✅ Lighting effects
- ✅ Sounds
- ✅ Mouse look

## 📦 Requirements

- **OS:** Linux (with X11 support)
- **Compiler:** GCC/Clang with `-Wall -Wextra -Werror`
- **C Standard:** C99+
- **Libraries:**
  - MLX42 (MiniLibX)
  - Custom libft
- **Dependencies:**
  - X11 development files
  - For MLX42: OpenGL, GLFW, etc.

### Dependencies on Ubuntu/Debian
```bash
sudo apt-get install libx11-dev libxext-dev libxrandr-dev \
  libxrender-dev libxinerama-dev libxcursor-dev libglfw3-dev libgl1-mesa-dev
```

## 🚀 Installation

```bash
# Clone the repository
cd /home/carol/42cursus/04/Cub3D

# Build the project
make

# Run
./cub3D maps/map.cub
```

## 💻 Usage

### Syntax
```bash
./cub3D <map.cub>
```

### Map Format
`.cub` files contain:
- Texture definitions (NORTH, SOUTH, EAST, WEST)
- Floor/ceiling colors
- 2D map (1 = wall, 0 = free space, N/S/E/W = player)

Example:
```
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,30,0
111111
100001
1000N1
111111
```

### Controls

| Key | Action |
|-----|--------|
| **W** | Move forward |
| **S** | Move backward |
| **A** | Move left |
| **D** | Move right |
| **←/→** | Rotate camera |
| **ESC** | Exit |
| **X** (window) | Exit |

## 🏗️ Project Structure

```
Cub3D/
├── src/
│   ├── main.c                # Main entry point
│   ├── parsing/              # Map parsing and validation
│   ├── raycasting/           # Raycasting algorithm
│   ├── rendering/            # Rendering functions
│   └── utils/                # Utilities
├── inc/
│   ├── Cub3D.h               # Main header
│   └── types.h               # Types and structs
├── maps/                     # Example maps (.cub)
├── textures/                 # XPM textures
├── MLX42/                    # MiniLibX 42
├── libft/                    # Custom C library
├── Makefile                  # Build
└── README.md
```

## 🎨 Graphics & Rendering

- Raycasting to simulate 3D from a 2D map
- Wall texturing
- Efficient rendering (60 FPS)
- Minimap (optional)

## 🧪 Testing

### Test Cases
```bash
# Valid map
./cub3D maps/map.cub

# Invalid maps (should show error)
./cub3D maps/no_wall.cub
./cub3D maps/no_player.cub
./cub3D maps/invalid_colors.cub
```

### Validation Checklist
- ✅ Rectangular map
- ✅ Surrounded by walls
- ✅ Only one player
- ✅ Valid textures and colors
- ✅ Valid path

## 🔧 Build Commands

```bash
make              # Compile (creates ./cub3D)
make clean        # Remove object files
make fclean       # Remove binaries
make re           # Rebuild
```

## 🎓 Technical Highlights

### 1. Raycasting
- Algorithm for 3D rendering from a 2D grid
- Distance, angle, and texture calculation per column

### 2. Robust Parsing
- Reading and validating .cub files
- Error checking and clear messages

### 3. Memory Management
- No leaks (valgrind)
- Resource freeing on exit

### 4. Modular Organization
- Clear separation: parsing, rendering, logic
- Small, well-defined functions

## 🐛 Common Issues & Solutions

| Issue | Solution |
|-------|----------|
| "Cannot connect to display" | Check X11 and DISPLAY variable |
| Texture not loading | Invalid file/texture path |
| Movement stuck | Check collision and map parsing |
| Memory leak | Use valgrind to identify |

## 📄 License

Academic project 42. Free for educational use.

## ✍️ Author

**[Your Name]**
- 42SP: [your-login]
- GitHub: [@your-username]

---

**⭐ Cub3D Project - 42SP**
**Evaluation date:** [Fill in]
**Repository:** [Link]
**Status:** Mandatory and bonus implementation (if applicable)
