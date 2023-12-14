#include "raylib.h"

// Custom timing variables
double previousTime = GetTime();    // Previous time measure
double currentTime = 0.0;           // Current time measure
double updateDrawTime = 0.0;        // Update + Draw time
double waitTime = 0.0;              // Wait time (if target fps required)
float position = 0.0f;              // Circle position
int targetFPS = 60;                 // Our initial target fps

// Constants
const int WIDTH = 1200;
const int HEIGHT = 800;
const char* TITLE = "";


int main(int argc, char **argv) {

    InitWindow(WIDTH, HEIGHT, TITLE);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        // Update

        // Draw
        EndDrawing();

        currentTime = GetTime();
        updateDrawTime = currentTime - previousTime;

        if (targetFPS > 0)          // We want a fixed frame rate
        {
            waitTime = (1.0f/(float)targetFPS) - updateDrawTime;
            if (waitTime > 0.0)
            {
                WaitTime((float)waitTime);
                currentTime = GetTime();
            }
        }
        previousTime = currentTime;

    }

    CloseWindow();

    return 0;
}
