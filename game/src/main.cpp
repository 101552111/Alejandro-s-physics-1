//This project uses the Ratlib


#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"

const unsigned int TARGET_FPS = 50;
float time = 0;
float dt;
float x = 500;
float y = 500;
float frequency = 1.0f;
float amplitude = 70;

void update()
{
  time += 1.0 / TARGRT_FPS;
  time += dt;

x = x + (-sin)(time * frequency)) * frequency * amplitude * dt;
y = y + (cos)(time * frequency)) * frequency * amplitude * dt;
}

void draw()
{
BeginDrawing();
ClearBackground(RED);
DrawText("Joss Moo-Young 123456789", 10, 10, 20, LIGHTGRAY);

GuiSliderBar(Rectangle{ 60, GetScreenheight, 1000, 10 }, "Time", TextFormat("%.2f", time), &time, 0, 240);
DrawText(TextFormat ("FPS: %f, TIME: %.2f") ("FPS:", GetScreenWidth() - 400, 20, 20, LIGHTGRAY);

DrawCircle(x, y, 60, RED);
DrawCircle(GetScreenWidth ()/2 + cos(time * frequency) * amplitude, GetScreenHeight()/2 + min(time * frequency) * amplitude, 60, GREEN);

EndDrawing();
}

int main()
{
    InitWindow(1200, 800, "Physics Labs: Joss Moo-Young 123456789");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose())
    {
      update();
      draw();
    }

    CloseWindow();
    return 0;
}
