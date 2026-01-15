<!-- @format -->

# Particle-Simulation

A basic particle simulation in C using raylib.

Inspired by [this video](https://www.youtube.com/watch?v=7CM0dbib-Jw&t).

## Preview (no build)

Download the latest Windows executable from [Releases](https://github.com/SaMaKsH.exe/Particle-Simulation/releases) for a quick preview, no build needed.

- Prerequisites:

  - gcc
  - raylib

- Run (build and run):

```bash
make
make run
```

- Quick compile (no `make` required):

```bash
gcc -Wall -Wextra -Wpedantic -Wshadow -Wconversion -std=c99 main.c -o particle_sim.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```
