#include "DxLib.h"
#include "window.h"
#include "config.h"

void InitWindow() {
    SetMainWindowText("�e�g���X");
    SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
    ChangeWindowMode(TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
}