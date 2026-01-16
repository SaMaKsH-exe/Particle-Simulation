#include "raylib.h"
#include <time.h>
#include <stdio.h>
#include <math.h>

#define num_particles 100
#define screenWidth 800
#define screenHeight 600
#define MAX_PARTICLES 200
#define MIN_PARTICLES 10

int currentParticles = 100;

typedef struct {
    float x, y, r, vx, vy;
} Particle;

Particle particles[MAX_PARTICLES];

void UpdateParticle(Particle *particle){
    particle->x += particle->vx;
    particle->y += particle->vy;

    if (particle->x - particle->r < 0) {
    particle->x = particle->r;
    particle->vx = -particle->vx;
}
    if (particle->x + particle->r > screenWidth) {
    particle->x = screenWidth - particle->r;
    particle->vx = -particle->vx;
}

     if(particle->y - particle->r < 0){
        particle->y = particle->r;
        particle->vy = -particle->vy;
    }

    if(particle->y + particle->r > screenHeight){
        particle->y = screenHeight - particle->r;
        particle->vy = -particle->vy;
    }
    Particle otherParticle;
    for (int i = 0; i < num_particles; i++){
        otherParticle = particles[i];
    }
    }

void DrawParticle(Particle *particle){
    DrawCircle(particle->x, particle->y, particle->r, SKYBLUE);
    DrawCircleLines(particle->x, particle->y, particle->r, DARKBLUE);
}



void DrawParticles(){
    for (int i = 0; i < currentParticles; i++)
    {
        DrawParticle(particles + i);
    }
}



void UpdateParticles(){
    for (int i = 0; i < currentParticles; i++)
    {
        UpdateParticle(particles + i);
    }
}

void CollideAllParticles(){
    for (int i = 0; i < currentParticles; i++){
        for (int j = i+1; j < currentParticles; j++){
            Particle p1 = particles[i];
            Particle p2 = particles[j];

            Vector2 c1 = {p1.x, p1.y};
            Vector2 c2 = {p2.x, p2.y};

            bool collide = CheckCollisionCircles(c1, p1.r, c2, p2.r);
            
            if(collide == true){
                float dx = (p1.x - p2.x);
                float dy = (p1.y-p2.y);
                float abs_d = sqrt(pow(dx, 2) + pow(dy, 2));
                float nx = dx / abs_d;
                float ny = dy / abs_d;

                float overlap = (p2.r + p1.r)-abs_d;
                particles[i].x  += nx*overlap/2;
                particles[i].y  += ny*overlap/2;
                particles[j].x  += -nx*overlap/2;
                particles[j].y  += -ny*overlap/2;

                float tx = -ny;
                float ty = nx;

                float v1t = p1.vx * tx + p1.vy * ty;
                float v2t = p2.vx * tx + p2.vy * ty;

                float v1n = p1.vx * nx + p1.vy * ny;
                float v2n = p2.vx * nx + p2.vy * ny;

                float vflip = v2n;
                v2n = v1n;
                v1n = vflip;

                particles[i].vx = v1t * tx + v1n * nx;
                particles[i].vy = v1t * ty + v1n * ny;
                particles[j].vx = v2t * tx + v2n * nx;
                particles[j].vy = v2t * ty + v2n * ny;
            }
        }
    }
}

void InitParticles(){

    SetRandomSeed(time(NULL));


    for (int i = 0; i < currentParticles; i++)
    {
        particles[i].r = (float)GetRandomValue(10, 13);
        particles[i].x = (float)GetRandomValue((int)particles[i].r, screenWidth - (int)particles[i].r);
        particles[i].y = (float)GetRandomValue((int)particles[i].r, screenHeight - (int)particles[i].r);
        particles[i].vx = (float)GetRandomValue(-8, 8);
        particles[i].vy = (float)GetRandomValue(-8, 8);
    }
}

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Particle Simulation - Physics Engine");
    InitParticles();
    SetTargetFPS(60);
    SetConfigFlags(FLAG_MSAA_4X_HINT);

   
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_B)) {
            if (currentParticles + 10 <= MAX_PARTICLES) {
                currentParticles += 10;
                InitParticles();
            }
        }
        if (IsKeyPressed(KEY_N)) {
            if (currentParticles - 10 >= MIN_PARTICLES) {
                currentParticles -= 10;
                InitParticles();
            }
        }

        BeginDrawing();
            ClearBackground((Color){15, 20, 40, 255});
            
            DrawText("Particle Collision Simulator", 10, 10, 20, LIGHTGRAY);
            DrawText(TextFormat("Particles: %d", currentParticles), 10, 40, 16, LIGHTGRAY);
            DrawText("B: +10 | N: -10", 10, 70, 14, GRAY);
            
            CollideAllParticles();
            DrawParticles();
            UpdateParticles();
            DrawFPS(screenWidth - 100, 10);
            
            DrawRectangleLines(0, 0, screenWidth, screenHeight, SKYBLUE);
        EndDrawing();
    }

    
    CloseWindow();

    return 0;
}
