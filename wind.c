#include "raylib.h"
int main(){
    const int width=800;
    const int height=900;

    InitWindow(width,height,"raylib example-basic window");

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("You did it!",190,200,24,RED);
        EndDrawing();
    }
    CloseWindow();

    return 0;

}