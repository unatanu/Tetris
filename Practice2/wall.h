#pragma once
#include "config.h"

// フィールド配列（0:空白, 1:壁, 2:床 など）
extern int field[GAME_Y][GAME_X];

// 初期化・描画関数
void InitField();
void DrawField();
void ClearLines();
