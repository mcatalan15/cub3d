# cub3D Project - My First RayCaster with miniLibX

## Overview

This project is inspired by the world-famous Wolfenstein 3D game, the first true First-Person Shooter (FPS) ever created. The goal was to build a dynamic 3D maze using ray-casting techniques, where players can navigate from a first-person perspective.

## Project Requirements

### Mandatory Part
- Create a realistic 3D graphical representation of a maze using ray-casting
- Implement smooth window management (minimizing, switching windows, etc.)
- Display different wall textures based on orientation (North, South, East, West)
- Set distinct floor and ceiling colors
- Implement player controls:
  - W, A, S, D keys for movement
  - Left/Right arrow keys for looking around
  - ESC key and window close button to exit cleanly
- Parse `.cub` map files with specific format requirements
- Validate map structure (must be closed/surrounded by walls)

### Bonus Part (Completed)
- **Wall collisions**: Implemented proper collision detection with walls

## Technical Specifications

- Written in C following strict Norm requirements
- Uses miniLibX for graphics rendering
- Implements ray-casting mathematics
- Proper memory management (no leaks)
- Makefile with standard rules (`all`, `clean`, `fclean`, `re`)
- Handles map parsing with error checking

## How to Use

1. Clone the repository
2. Compile with `make`
3. Run with a valid `.cub` map file: `./cub3D map.cub`

### Controls
- **WASD**: Move forward/backward/left/right
- **Arrow keys**: Look left/right
- **ESC**: Quit the game

## Map File Format Example

```
NO ./path_to_north_texture.png
SO ./path_to_south_texture.png
WE ./path_to_west_texture.png
EA ./path_to_east_texture.png
F 220,100,0    # Floor color (RGB)
C 225,30,0     # Ceiling color (RGB)

11111111111
10000000001
10110000001
100100N0001
11111111111
```

## Project Structure

```
cub3D/
├── Makefile
├── includes/       # Header files
├── srcs/           # Source files
│   ├── main.c
│   ├── parsing/    # Map parsing logic
│   ├── graphics/   # Rendering code
│   ├── raycasting/ # Ray-casting implementation
│   └── bonus/      # Collision detection code
├── textures/       # Wall textures
└── maps/           # Sample .cub maps
```

## Key Features

- Efficient ray-casting implementation
- Texture mapping for walls
- Smooth movement and rotation
- Proper error handling
- Wall collision detection (bonus)

This project demonstrates strong skills in C programming, mathematical algorithms, graphics programming, and game development fundamentals. The ray-casting implementation provides a performant 3D rendering solution without relying on complex 3D libraries.

## 📧 Contact Us
This project was a team effort, and my awesome mates at 42 Barcelona helped make it happen! Reach out to us for questions, collabs, or just to chat about coding! 😸
- **Jon Paul Kruger**: [jpaul-kr (GitHub)](https://github.com/jpaul-kr) | [jpaul-kr@student.42barcelona.com](mailto:jpaul-kr@student.42barcelona.com)
- **Marc Catalán Sánchez**: [mcatalan15 (GitHub)](https://github.com/mcatalan15) | [mcatalan@student.42barcelona.com](mailto:mcatalan@student.42barcelona.com)
