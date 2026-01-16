#include "raylib.h"
#include <time.h>
#include <stdio.h>

#define num_particles 30
#define screenWidth 800
#define screenHeight 600


typedef struct {
    float x, y, r, vx, vy;
} Particle;

Particle particles[num_particles];

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

    DrawCircle(particle->x, particle->y, particle->r, WHITE);
}

void DrawParticles(){
    for (int i = 0; i < num_particles; i++)
    {
        DrawParticle(particles + i);
    }
}

void UpdateParticles(){
    for (int i = 0; i < num_particles; i++)
    {
        UpdateParticle(particles + i);
    }
}

void CollideAllParticles(){
    for (int i = 0; i < num_particles; i++){
        for (int j = 0; j < num_particles; j++){
            if(i==j)
                break;; // skip self
            

            Particle p1 = particles[i];
            Particle p2 = particles[j];

            Vector2 c1 = {p1.x, p1.y};
            Vector2 c2 = {p2.x, p2.y};

            bool collide = CheckCollisionCircles(c1, p1.r, c2, p2.r);
            
            if(collide == true){
                printf("YOOOOOOO\n");
                fflush(stdout);
            }
        }
    }
}

void InitParticles(){

    SetRandomSeed(time(NULL));


    for (int i = 0; i < num_particles; i++)
    {
        particles[i].r = GetRandomValue(5,20);
        particles[i].x = GetRandomValue(particles[i].r, screenWidth -particles[i].r);
        particles[i].y = GetRandomValue(particles[i].r, screenHeight-particles[i].r);
        particles[i].vx = GetRandomValue(-5,20);
        particles[i].vy = GetRandomValue(-5,20);;
    }
}

int main(void)
    {

    InitWindow(screenWidth, screenHeight, "Particle Simulation");
    InitParticles();
    SetTargetFPS(60);

   
    while (!WindowShouldClose())
    {

     
        BeginDrawing();

            ClearBackground(BLACK);
            CollideAllParticles();
            DrawParticles();
            UpdateParticles();
            DrawFPS(5,5);


            EndDrawing();
    }

    
    CloseWindow();

    return 0;
}
