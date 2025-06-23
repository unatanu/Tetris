#include "DxLib.h"
#include "window.h"
#include "wall.h"
#include "mino.h"
#include "game.h"
#include "ui.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    InitWindow();
    if (DxLib_Init() == -1) return -1;

    InitField();
    Mino currentMino, nextMino;
    InitMino(currentMino);
    InitMino(nextMino);

    int frameCounter = 0;

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
        ClearDrawScreen();

        KeyInput(currentMino);
        Update(currentMino, nextMino, frameCounter);

        DrawField();
        DrawGhostMino(currentMino);
        DrawMino(currentMino);
        DrawNextMino(nextMino, (GAME_X + INFO_X/2 -1) * (BLOCK_MARGIN + BLOCK_SIZE), INFO_X);
        DrawUIBox(GAME_WIDTH, 0, UI_MINO_WIDTH, UI_MINO_HEIGHT, "NEXT");
        DrawUIBox(GAME_WIDTH, GAME_HEIGHT + UI_MINO_HEIGHT, UI_SCORE_WIDTH, UI_SCORE_HEIGHT, "SCORE");
        DrawUIBox(GAME_WIDTH, GAME_HEIGHT + UI_MINO_HEIGHT + UI_SCORE_HEIGHT, UI_MINO_WIDTH, UI_MINO_HEIGHT, "HOLD");
        ScreenFlip();

        frameCounter++;
    }

    DxLib_End();
    return 0;
}