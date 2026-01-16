
# Particle Collision Simulator

A particle physics simulation built with C/raylib. 

##  Quick Start

### Try Web Version (No Installation)

https://samaksh-exe.github.io/Particle-Simulation/dist/particle_sim.html

###  Download EXE Version

Download the latest Windows executable from [Releases](https://github.com/SaMaKsH-exe/Particle-Simulation/releases)

##  Build from Source

### Prerequisites

- GCC compiler
- raylib library (included in repo)
- mingw64 (Windows)
- Git

### Clone and Build

```bash
# Clone the repository
git clone https://github.com/SaMaKsH.exe/Particle-Simulation.git
cd Particle-Simulation

# Build and run
make run
```

Or compile manually:

```bash
gcc -Wall -Wextra -Wpedantic -Wshadow -Wconversion -std=c99 main.c -o particle_sim.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

## Controls

| Key   | Action                       |
| ----- | ---------------------------- |
| **B** | Add 10 particles (max 200)   |
| **N** | Remove 10 particles (min 10) |

## Inspired by

[Particle Physics Simulation Video](https://www.youtube.com/watch?v=7CM0dbib-Jw)
