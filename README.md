*This project has been created as part of the 42 curriculum by ccavalca and anunes-o.*

# cub3D

A first-person 3D maze renderer written in C with MLX42.

## Description

`cub3D` is inspired by the ray-casting engines used by early first-person games such as *Wolfenstein 3D*. It renders a three-dimensional view from a two-dimensional map by casting one ray for each vertical screen column.

The project combines file parsing, map validation, vector mathematics, DDA ray traversal, texture sampling, collision detection, event handling, and careful resource cleanup.

The mandatory implementation includes:

- `.cub` scene parsing and validation;
- four directional wall textures: north, south, west, and east;
- configurable floor and ceiling RGB colors;
- exactly one player with an initial `N`, `S`, `E`, or `W` orientation;
- closed-map validation using flood fill and boundary checks;
- DDA-based ray casting with perpendicular-distance correction;
- textured wall rendering;
- first-person movement and camera rotation;
- wall collision;
- clean window shutdown through `ESC` or the window close button.

## Instructions

### Requirements

The project targets Linux and requires:

- a C compiler;
- GNU Make;
- CMake;
- GLFW and OpenGL development libraries;
- X11 development libraries.

On Ubuntu or Debian, the required system packages can be installed with:

```bash
sudo apt update
sudo apt install build-essential cmake libglfw3-dev libgl1-mesa-dev \
    libx11-dev libxrandr-dev libxi-dev libxcursor-dev libxinerama-dev
```

### Clone and compile

```bash
git clone https://github.com/carolinecbahia/cub3D.git
cd cub3D
git switch develop
make
```

The build creates the `cub3D` executable. MLX42 and the local `libft` are compiled automatically by the Makefile.

### Run

The program receives exactly one `.cub` scene file:

```bash
./cub3D maps/valid/valid_basic.cub
```

Additional themed maps are available:

```bash
./cub3D maps/valid/valid_arcane.cub
./cub3D maps/valid/valid_crypt.cub
./cub3D maps/valid/valid_hearts.cub
./cub3D maps/valid/valid_infernal.cub
```

The Makefile also provides a configurable run target:

```bash
make run
make run MAP=maps/valid/valid_crypt.cub
```

### Controls

| Key | Action |
| --- | --- |
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `Left Arrow` | Rotate left |
| `Right Arrow` | Rotate right |
| `ESC` | Close the program |

The window close button also exits the program.

### Standard Makefile rules

```bash
make          # Build the mandatory executable
make clean    # Remove object files
make fclean   # Remove object files and executables
make re       # Rebuild the project
```

### Development and test rules

```bash
make help                         # List available rules
make maps_test                    # Run the invalid-map test suite
make norm                         # Run Norminette on src/ and inc/
make debug                        # Build with debug information
make gdb MAP=maps/valid/valid_basic.cub
make valgrind MAP=maps/valid/valid_basic.cub
```

The invalid-map suite is kept under `maps/invalid/`. It covers invalid extensions, RGB values, multiple players, duplicate or missing textures, invalid characters, empty lines inside the map, open walls, and leaks into padded spaces.

## Scene format

A `.cub` file contains four wall texture paths, floor and ceiling colors, and the map. Configuration elements may appear in any order before the map, while the map must remain the final block.

```text
NO ./textures/wall.png
SO ./textures/wall.png
WE ./textures/wall.png
EA ./textures/wall.png

F 220,100,0
C 225,30,0

11111111
10000001
100N0001
10000001
11111111
```

### Identifiers

| Identifier | Meaning |
| --- | --- |
| `NO` | North-facing wall texture |
| `SO` | South-facing wall texture |
| `WE` | West-facing wall texture |
| `EA` | East-facing wall texture |
| `F` | Floor color as `R,G,B` |
| `C` | Ceiling color as `R,G,B` |

The map accepts the following characters:

| Character | Meaning |
| --- | --- |
| `1` | Wall |
| `0` | Walkable space |
| `N`, `S`, `E`, `W` | Player spawn and initial orientation |
| space | Empty area outside the playable map |

The map may be non-rectangular, but every walkable region must be completely enclosed by walls. Exactly one player spawn is required.

## How it works

For every screen column, the engine:

1. calculates a ray direction from the player direction and camera plane;
2. advances through the grid using the Digital Differential Analyzer algorithm;
3. identifies the wall side and hit position;
4. calculates the perpendicular wall distance to avoid fisheye distortion;
5. selects the directional texture and samples the corresponding column;
6. draws the ceiling, textured wall, and floor.

Player movement is calculated with direction and camera-plane vectors. Before applying a new position, collision checks sample the surrounding area so the player cannot cross walls.

## Project structure

```text
.
├── inc/                 Public headers and data structures
├── libft/               Local utility library
├── maps/
│   ├── valid/           Valid scenes and themed maps
│   └── invalid/         Parser and validation test cases
├── MLX42/               Graphics library
├── roadmap/             Sprint and integration documentation
├── src/
│   ├── game/            Initialization and resource destruction
│   ├── hooks/           Input, movement, rotation, and collision
│   ├── parsing/         Scene parsing and map validation
│   ├── raycasting/      Ray setup, DDA, distance, and texture selection
│   ├── rendering/       Frame, background, columns, and texture sampling
│   └── utils/           Errors, cleanup, and shared helpers
├── textures/            Wall texture assets
└── Makefile
```

## Resources

The following resources were used to study the concepts and APIs behind the project:

- [Lode's Computer Graphics Tutorial — Raycasting](https://lodev.org/cgtutor/raycasting.html) — ray directions, camera plane, DDA, perpendicular distance, and wall projection.
- [Lode's Computer Graphics Tutorial — Textured Raycasting](https://lodev.org/cgtutor/raycasting.html#Textured_Raycaster) — wall hit coordinates and texture sampling.
- [MLX42 documentation](https://github.com/codam-coding-college/MLX42) — window creation, images, textures, input hooks, and cleanup.
- [42 Norm](https://github.com/42School/norminette) — source formatting and project conventions.
- [Valgrind documentation](https://valgrind.org/docs/manual/manual.html) — memory, invalid-access, and file-descriptor diagnostics.
- [CMake documentation](https://cmake.org/documentation/) — MLX42 build configuration.

### Use of artificial intelligence

AI tools were used as development support for:

- brainstorming test cases and edge cases for `.cub` parsing;
- reviewing integration plans and debugging hypotheses;
- suggesting refactoring approaches for ray-casting, texture, and cleanup modules;
- generating initial drafts of project documentation and checklists;
- creating original visual texture concepts used as project assets.

AI output was not accepted blindly. Suggestions were reviewed, tested, corrected, and adapted by the authors. The authors are responsible for the final implementation and must be able to explain and modify every part of the submitted project.

## Authors

- Caroline Bahia — `ccavalca`
- Ana Clara Nunes Oliveira — `anunes-o`

This repository was developed for the 42 São Paulo Common Core.