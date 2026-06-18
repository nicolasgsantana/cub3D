> *This project was created as part of the 42 curriculum by **nde-sant** and **aletude-***

---

## Description
The goal of this project is to build a small raycasting graphics engine, in the style of
the classic Wolfenstein 3D. From a map described in a configuration file (`.cub`), the
program renders a 3D scene in real time, allowing the player to move and look around
inside the maze. For this implementation we used the
[MLX42](https://github.com/codam-coding-college/MLX42) graphics library.

## Available Features
- Full parsing and validation of `.cub` files (textures, floor/ceiling colors, map grid);
- Raycasting via DDA (Digital Differential Analysis) for wall rendering;
- Distinct textures for each wall orientation (North, South, East, West);
- Player movement (forward, backward, strafe left/right);
- Camera rotation via keyboard and mouse;
- Real-time minimap;
- Collision detection against the map's walls.

## Instructions
Clone the repository and enter the folder:
``` bash
git clone https://github.com/nicolasgsantana/cub3D.git
cd cub3D
```
Build and run the program, passing a `.cub` map as argument:
``` bash
make
./cub3D maps/map.cub
```

### Feel free to test it out!
A few sample maps are already available in the `maps/` folder:
```bash
./cub3D maps/map_subject.cub
```
```bash
./cub3D maps/maze.cub
```
```bash
./cub3D maps/rooms.cub
```

### Controls
- `W` `A` `S` `D`: movement;
- `←` `→` or mouse: camera rotation;
- `ESC`: quit the game.

## Resources
References used during development:

- [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html);
- [MLX42 Documentation](https://github.com/codam-coding-college/MLX42);
- [3D Sage's Make your own Raycaster series](https://youtu.be/gYRrGTC7GtA);
- [Daniel Hirsch's Raycasting in C - from Scratch video](https://youtu.be/2IEUa2gYJHQ);
- AI was used to:
  - perform isolated tests
  - debugging

*English* | [Português](https://github.com/nicolasgsantana/cub3D/blob/main/README_pt.md)
