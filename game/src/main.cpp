#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"

const unsigned int TARGET_FPS = 50;
float dt = 1.0f / TARGET_FPS;
float time = 0;
float x = 500;
float y = 500;
float frequency = 1;
float amplitude = 100;

// Change the world state
void update()
{
  time += 1.0 / TARGET_FPS;
  time += dt;

  x = x + (-sin(time * frequency)) * frequency * amplitude * dt;
  y = y + (cos(time * frequency)) * frequency * amplitude * dt;
}

// Display the world state
void draw()
{
 BeginDrawing();
 ClearBackground(BLACK);
 DrawText("Alejandro Revollo-Serrano 101552111", 10, float(GetScreenHeight()- 30), 20, LIGHTGRAY);

 GuiSliderBar(Rectangle{ 60, 15, 1000, 20 }, "Time", TextFormat("%.2f", time), &time, 0, 240);
 DrawText(TextFormat ("T: %6.2f", time), GetScreenWidth() - 140, 10, 30, LIGHTGRAY);

 DrawCircle(x, y, 70, RED);
 DrawCircle(500 + cos(time * frequency) * amplitude, 500 + sin (time * frequency) * amplitude, 70, GREEN);

EndDrawing();
}

int main()
{
    InitWindow(1200, 800, "GAME2005: Alejandro Revollo-Serrano 101552111");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose())
    {
      update();
      draw();
    }

    CloseWindow();
    return 0;
}
