# 3D Renderer using C and SDL2

## Overview
This is a simple 3D graphics engine written in C using SDL2. The engine is designed to load and render `.obj` models while allowing basic camera movement to look around the model. It does not rotate the model itself.

## Features
- Load and parse `.obj` files
- Convert 3D coordinates to 2D screen space
- Render models using SDL2
- Basic camera movement (looking around)

## Requirements
- **C Compiler** (GCC or Clang recommended)
- **SDL2** (Simple DirectMedia Layer)

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/HarshS23/3DEngine.git
   cd 3d-renderer
   ```
2. Install SDL2 (if not already installed):
   ```sh
   sudo apt-get install libsdl2-dev  # Debian-based systems
   brew install sdl2  # macOS
   ```
3. Compile the project:
   ```sh
   gcc main.c -o renderer -lSDL2 -lm
   ```
4. Run the program:
   ```sh
   ./renderer path/to/your/model.obj
   ```

## Usage
- Load any `.obj` model by providing its path as an argument.
- Use the keyboard/mouse to move the camera (implementation details can be added later).

## Future Enhancements
- Implement basic lighting/shading
- Improve rendering performance
- Add more interactive camera controls

## License
This project is open-source under the MIT License.

## Contributions
Feel free to submit issues or pull requests to improve the project!

## Author
[Adharsh Shokkalingam](https://github.com/HarshS23)

