#include "raylib.h"

#define MAX_BUILDINGS 100

int main() {
    const int sc_width = 800;
    const int sc_height = 450;
    InitWindow(sc_width, sc_height, "2D CAMERA");

    Rectangle player = { 400, 280, 40, 40 };
    Rectangle buildings[MAX_BUILDINGS] = { 0 };
    Color buildColors[MAX_BUILDINGS] = { 0 };

    int spacing = 0;
    for (int i = 0; i < MAX_BUILDINGS; i++) {
        buildings[i].width = (float)GetRandomValue(50, 200);
        buildings[i].height = (float)GetRandomValue(100, 800);
        buildings[i].y = sc_height - 130.0f - buildings[i].height;
        buildings[i].x = -6000.0f + spacing;

        spacing += (int)buildings[i].width;

        buildColors[i] = (Color){ GetRandomValue(200, 240), GetRandomValue(200, 240), GetRandomValue(200, 250), 255 };
    }
    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.x + 20.0f, player.y + 20.0f };
    camera.offset = (Vector2){ sc_width / 2.0f, sc_height / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) player.x += 2;
        else if (IsKeyDown(KEY_LEFT)) player.x -= 2;

        camera.target = (Vector2){ player.x + 20, player.y + 20 };

        if (IsKeyDown(KEY_A)) camera.rotation--;
        else if (IsKeyDown(KEY_S)) camera.rotation++;

        if (camera.rotation > 40) camera.rotation = 40;
        else if (camera.rotation < -40) camera.rotation = -40;

        camera.zoom += ((float)GetMouseWheelMove() * 0.05);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

        if (IsKeyPressed(KEY_R)) {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);
                for (int i = 0; i < MAX_BUILDINGS; i++) DrawRectangleRec(buildings[i], buildColors[i]);
                DrawRectangleRec(player, RED);

                DrawLine((int)camera.target.x, -sc_height * 10, (int)camera.target.x, sc_height * 10, GREEN);
                DrawLine(-sc_width * 10, (int)camera.target.y, sc_width * 10, (int)camera.target.y, GREEN);
            EndMode2D();

            DrawText("screen area", 640, 10, 20, RED);

            DrawRectangle(0, 0, sc_width, 5, RED);
            DrawRectangle(0, 5, 5, sc_width - 10, RED);
            DrawRectangle(sc_width - 5, 5, 5, sc_height - 10, RED);
            DrawRectangle(0, sc_height - 5, sc_width, 5, RED);

            DrawRectangle(10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines(10, 10, 250, 113, BLUE);

            DrawText("Free 2d camera controls", 20, 20, 10, BLACK);
            DrawText("Right/Left to move Offset", 40, 40, 10, RED);
            DrawText("Mouse wheel to zoom in and out", 40, 60, 10, RED);
            DrawText("A/S to rotate", 40, 80, 10, RED);
            DrawText("R to reset the zoom and rotate", 40, 100, 10, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
