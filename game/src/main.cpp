#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"


const unsigned int TARGET_FPS = 50;
float dt = 1.0f / TARGET_FPS;
float time = 0;

float speed = 100;
float angle = 30;

Vector2 position;
Vector2 velocity;
Vector2 gravityAcceleration = { 0, 100 };

// Change world state
void update()
{
  time += 1.0 / TARGET_FPS;
  time += dt;

  if(IsKeyPressed(KEY_SPACE))
  {

      position = { 200, (float)GetScreenHeight() - 200 };
      velocity = { (float)cos(angle * DEG2RAD) * speed, (float) - sin(angle * DEG2RAD) * speed};
  }

  //velocity changes position over time. 
  // velocity = displacement/time   therefore   Displacement = velocity * time
  // Displacement = velocity * time
  position += velocity * dt;

  // acceleration changes velocity over time.
  // deltaV = accel / time therefore  deltaV = accel * time  where deltV is a change in velocity
  velocity += gravityAcceleration * dt;
}

// Display world state
void draw()
{
 BeginDrawing();
 ClearBackground(BLACK);
 DrawText("Alejandro Revollo-Serrano 101552111", 10, float(GetScreenHeight()- 30), 20, LIGHTGRAY);

 GuiSliderBar(Rectangle{ 60, 15, 1000, 20 }, "Time", TextFormat("%.2f", time), &time, 0, 240);
 DrawText(TextFormat ("T: %6.2f", time), GetScreenWidth() - 140, 10, 30, LIGHTGRAY);


 GuiSliderBar(Rectangle{ 10, 80, 200, 100 }, "", TextFormat("%.0f", speed), &speed, -100, 1000);
 GuiSliderBar(Rectangle{ 10, 100, 200, 100 }, "", TextFormat("%.0f", angle), &angle, -180, 180);
 GuiSliderBar(Rectangle{ 10, 120, 200, 100 }, "", TextFormat("G: %.0f", gravityAcceleration.y), &gravityAcceleration.y, -600, 180);

 // Draw circles
 DrawCircle(position.x, position.y, 100, RED);
 

 Vector2 startPos = { 100, GetScreenHeight() - 200 };
 Vector2 velocity = { cos(angle * DEG2RAD) * speed, -sin(angle * DEG2RAD) * speed };
 DrawLineEx(startPos, startPos + velocity, 3, RED);

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
