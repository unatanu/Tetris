#include "DxLib.h"
#include "game.h"
#include "wall.h"
#include "mino.h"

int keyTimer = 0;
int standbyFrame_move = 2;
int standbyFrame_rot = 5;
int standbyFrame_Lock = 10;

bool inputLocked = false;  // 連続したハードドロップを防ぐためのフラグ

void KeyInput(Mino& mino) {
    if (keyTimer > 0) {
        keyTimer--;
        return;
    }

    // 入力ロック中 & キーボード入力が一切ないとき、ロック解除
    if (inputLocked) {
        if (!CheckHitKeyAll()) {
            inputLocked = false;
        }
        else {
            return;
        }
    }

    if (CheckHitKey(KEY_INPUT_LEFT) && !CheckCollision(mino, -1, 0)) {
        mino.x -= 1;
        keyTimer = standbyFrame_move;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) && !CheckCollision(mino, 1, 0)) {
        mino.x += 1;
        keyTimer = standbyFrame_move;
    }
    if (CheckHitKey(KEY_INPUT_DOWN) && !CheckCollision(mino, 0, 1)) {
        mino.y += 1;
    }
    if (CheckHitKey(KEY_INPUT_Z)) {
        RotateMino(mino, false);
        keyTimer = standbyFrame_rot;
    }
    if (CheckHitKey(KEY_INPUT_X)) {
        RotateMino(mino, true);
        keyTimer = standbyFrame_rot;
    }
    if (CheckHitKey(KEY_INPUT_SPACE)) {
        HardDrop(mino);
        FixMinoToField(mino);
        ClearLines();
        InitMino(mino);
        inputLocked = true;  // 次ミノが出現 → 操作ロック
        keyTimer = standbyFrame_Lock;
    }
}

bool Update(Mino& currentMino, Mino& nextMino, int frameCounter) {
    if (frameCounter % 20 == 0) {
        if (!CheckCollision(currentMino, 0, 1)) {
            currentMino.y += 1;
        }
        else {
            FixMinoToField(currentMino);
            ClearLines();
            currentMino = nextMino;
            InitMino(nextMino);
        }
    }
    return true;
}
