# cub3D TODO

> Deadline: 14/07/2026
>
> Contributors:
>
> - ccavalca
> - <partner_login>

---

# Git Workflow

## Branch Strategy

```text
master
└── develop
    ├── feature/parsing
    ├── feature/validation
    ├── feature/mlx
    ├── feature/rendering
    ├── feature/player
    ├── feature/raycasting
    ├── feature/textures
    └── feature/tests
```

## Rules

- Never commit directly to `master`
- All development happens in `develop`
- One feature = one branch
- Merge only after testing
- Pull before starting work
- Resolve conflicts immediately
- No direct pushes to another person's branch

## Workflow Example

```bash
git checkout develop
git pull origin develop

git checkout -b feature/parsing

# work

git add .
git commit -m "feat: implement texture parser"

git push origin feature/parsing
```

Merge:

```bash
git checkout develop
git merge feature/parsing
git push origin develop
```

## Commit Convention

```bash
feat: add texture parser
fix: resolve flood fill edge case
refactor: simplify map validation
test: add invalid map cases
docs: update README
```

---

# Repository Structure

```text
cub3D/
├── include/
├── src/
│   ├── parsing/
│   ├── validation/
│   ├── rendering/
│   ├── raycasting/
│   ├── player/
│   ├── textures/
│   └── utils/
├── maps/
├── textures/
├── tests/
├── docs/
├── libft/
├── Makefile
└── README.md
```

---

# Mandatory Subject Checklist

## Window

- [ ] Window opens correctly
- [ ] Window remains responsive
- [ ] ESC closes program
- [ ] Window close button closes program

## Rendering

- [ ] Ceiling color
- [ ] Floor color
- [ ] North texture
- [ ] South texture
- [ ] East texture
- [ ] West texture

## Controls

- [ ] W movement
- [ ] A movement
- [ ] S movement
- [ ] D movement
- [ ] Left arrow rotation
- [ ] Right arrow rotation

## Parsing

- [ ] Read .cub file
- [ ] Parse textures
- [ ] Parse colors
- [ ] Parse map
- [ ] Parse player

## Validation

- [ ] Extension validation
- [ ] Texture validation
- [ ] RGB validation
- [ ] Character validation
- [ ] Single player validation
- [ ] Closed map validation

## General

- [ ] No memory leaks
- [ ] No segfaults
- [ ] Proper error messages
- [ ] Norminette OK

---

# One Tasks

## Parsing

- [ ] check_file_extension()
- [ ] read_file()
- [ ] parse_texture_identifiers()
- [ ] parse_colors()
- [ ] parse_map()
- [ ] parse_player()

## Validation

- [ ] validate_textures()
- [ ] validate_rgb()
- [ ] validate_characters()
- [ ] validate_single_player()
- [ ] validate_map_dimensions()

## Flood Fill

- [ ] flood_fill()
- [ ] map_closure_check()

## Error Handling

- [ ] error_exit()
- [ ] cleanup_exit()
- [ ] stderr output

## Tests

- [ ] invalid extension
- [ ] invalid texture path
- [ ] invalid RGB
- [ ] multiple players
- [ ] missing player
- [ ] invalid character
- [ ] open map

---

# Other Tasks

## MiniLibX

- [ ] mlx_init()
- [ ] window creation
- [ ] image creation
- [ ] image buffer
- [ ] hooks
- [ ] clean shutdown

## Rendering

- [ ] put_pixel()
- [ ] render_background()
- [ ] render_frame()

## Texture Loading

- [ ] load north texture
- [ ] load south texture
- [ ] load east texture
- [ ] load west texture

## Player

- [ ] movement
- [ ] rotation
- [ ] collision detection

---

# Shared Tasks

## Raycasting

### Foundations

- [ ] player direction vector
- [ ] camera plane
- [ ] ray direction

### DDA

- [ ] delta distance
- [ ] side distance
- [ ] step_x
- [ ] step_y
- [ ] wall hit detection

### Projection

- [ ] perpendicular wall distance
- [ ] wall height calculation
- [ ] draw start
- [ ] draw end

### Texture Mapping

- [ ] wall side detection
- [ ] texture coordinate calculation
- [ ] texture sampling

---

# Integration Milestones

## Milestone 1 — Parsing Complete

Target: 22/06

### Parsing

- [ ] check_file_extension()
- [ ] read_file()
- [ ] parse textures
- [ ] parse colors
- [ ] parse map
- [ ] parse player

### Validation

- [ ] texture validation
- [ ] RGB validation
- [ ] character validation
- [ ] single player validation
- [ ] map dimensions

### Flood Fill

- [ ] map closure validation

### Result

- [ ] valid maps accepted
- [ ] invalid maps rejected

---

## Milestone 2 — MLX Foundation

Target: 29/06

### Window

- [ ] mlx_init()
- [ ] create window
- [ ] image buffer

### Events

- [ ] ESC
- [ ] window close

### Rendering

- [ ] floor color
- [ ] ceiling color

### Result

- [ ] window stable
- [ ] rendering background

---

## Milestone 3 — First Raycaster

Target: 06/07

### Raycasting

- [ ] ray direction
- [ ] DDA algorithm
- [ ] wall hit detection
- [ ] wall distance

### Projection

- [ ] wall height
- [ ] draw vertical strips

### Result

- [ ] walls visible in 3D

---

## Milestone 4 — Playable Game

Target: 10/07

### Controls

- [ ] W
- [ ] A
- [ ] S
- [ ] D

### Rotation

- [ ] left arrow
- [ ] right arrow

### Textures

- [ ] north
- [ ] south
- [ ] east
- [ ] west

### Result

- [ ] playable cub3D

---

## Milestone 5 — Evaluation Ready

Target: 13/07

### Stability

- [ ] no segfaults
- [ ] no invalid reads
- [ ] no leaks

### Norm

- [ ] norminette clean

### Tests

- [ ] valid maps
- [ ] invalid maps
- [ ] texture errors
- [ ] RGB errors

### Documentation

- [ ] README complete

### Result

- [ ] ready for defense

---

# Test Maps

## Valid Maps

- [ ] Small map
- [ ] Large map
- [ ] Spaces inside map
- [ ] N player
- [ ] S player
- [ ] E player
- [ ] W player

## Invalid Maps

- [ ] Open top
- [ ] Open bottom
- [ ] Open left
- [ ] Open right
- [ ] Invalid texture path
- [ ] Missing texture
- [ ] Invalid RGB
- [ ] Multiple players
- [ ] Missing player
- [ ] Invalid character

---

# README

## Required by Subject

- [ ] English only
- [ ] First line with contributors
- [ ] Description
- [ ] Instructions
- [ ] Resources
- [ ] AI usage declaration

## Additional

- [ ] Project architecture
- [ ] Parsing explanation
- [ ] Flood fill explanation
- [ ] DDA explanation
- [ ] Raycasting explanation
- [ ] Texture mapping explanation
- [ ] Screenshots
- [ ] Build instructions
- [ ] Testing instructions

---

# Final Evaluation Checklist

## Build

- [ ] make
- [ ] make clean
- [ ] make fclean
- [ ] make re

## Runtime

- [ ] No crashes
- [ ] No segfaults
- [ ] No invalid reads
- [ ] No leaks

## Features

- [ ] Parsing
- [ ] Validation
- [ ] Rendering
- [ ] Textures
- [ ] Movement
- [ ] Rotation

## Defense

- [ ] Explain parser
- [ ] Explain map validation
- [ ] Explain flood fill
- [ ] Explain DDA
- [ ] Explain raycasting
- [ ] Explain texture mapping
- [ ] Explain MLX usage

---

# Nice To Have (Only After Mandatory Is 100%)

## Bonus

- [ ] Minimap
- [ ] Mouse rotation
- [ ] Doors
- [ ] Animated sprites

⚠️ Do not start bonus before mandatory is fully validated, leak-free, and norm-compliant.
