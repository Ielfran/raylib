#include "raylib.h"
typedef enum Gamescreen{LOGO=0, TITLE, GAMEPLAY, ENDING}Gamescreen;


int main(){
    const int screenwidth=400;
    const int screenheight=500;

    InitWindow(screenwidth,screenheight,"another window");
    Gamescreen currentscreen=LOGO;
    int framesCounter=0;

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        switch(currentscreen){
            case LOGO:
                framesCounter++;
                if(framesCounter>120){
                    currentscreen=TITLE;
                }break;
            case TITLE:
            {
                if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)){
                    currentscreen=GAMEPLAY;
                }
            }break;
            case GAMEPLAY:
                {
                    if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)){
                        currentscreen=ENDING;
                    }
                }break;
            case ENDING:
            {
                if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)){
                    currentscreen=TITLE;
                }
            }break;
            default:break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch(currentscreen){
            case LOGO:
            {
                DrawText("LOGO SCREEN",20,20,40,RED);
                DrawText("wait for 2 seconds...",290,220,20,RED);
            }break;
            case TITLE:
            {
                DrawRectangle(0,0,screenwidth,screenheight,GREEN);
                DrawText("TITLE SCREEN",20,20,40,DARKGREEN);
                DrawText("Press enter or tap jump to gameplay screen", 120, 220, 20, DARKGREEN);
            }break;
            case GAMEPLAY:
            {
                DrawRectangle(0,0,screenwidth,screenheight,PURPLE);
                DrawText("GAMEPLAY SCREEN",20,20,40,MAROON);
                DrawText("Press enter or tap to jump to ending screen",130,220,20,MAROON);

            }break;
            case ENDING:
            {
                DrawRectangle(0,0,screenwidth,screenheight,BLUE);
                DrawText("ENDING SCREEN",20,20,40,DARKBLUE);
                DrawText("Press enter to return to title screen",120,220,20,DARKBLUE);
            }break;
            default:break;
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;

}