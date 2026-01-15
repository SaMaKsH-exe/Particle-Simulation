#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Particle Simulation");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Particle Simulation", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    
    CloseWindow();

    return 0;
}
