#include "DxLib.h"
#include "config.h"
#include "wall.h"

int field[GAME_Y][GAME_X];

void InitField() {
    for (int y = 0; y < GAME_Y; ++y) {
        for (int x = 0; x < GAME_X; ++x) {
            if (x == 0 || x == GAME_X - 1 || y == GAME_Y - 1) {
                field[y][x] = 1; // �ǂ���
            }
            else {
                field[y][x] = 0; // ��
            }
        }
    }
}

void DrawField() {
    for (int y = 0; y < GAME_Y; ++y) {
        for (int x = 0; x < GAME_X; ++x) {
            if (field[y][x] != 0) {
                int left = x * (BLOCK_SIZE + BLOCK_MARGIN);
                int top = y * (BLOCK_SIZE + BLOCK_MARGIN);
                int right = left + BLOCK_SIZE;
                int bottom = top + BLOCK_SIZE;

                DrawBox(left, top, right, bottom, GetColor(255, 255, 255), TRUE); // ���̃u���b�N
            }
        }
    }
}

void ClearLines() {
    for (int y = GAME_Y - 2; y >= 0; --y) { // �ŉ��s�͏��Ȃ̂ŏ��O
        bool filled = true;

        // ��ӏ��ł��u���b�N���Ȃ��}�X�����݂���ꍇ�̓X���[
        for (int x = 1; x < GAME_X - 1; ++x) {
            if (field[y][x] == 0) {
                filled = false;
                break;
            }
        }

        if (filled) {
            // �ォ��l�߂�
            for (int ty = y; ty > 0; --ty) {
                for (int x = 1; x < GAME_X - 1; ++x) {
                    field[ty][x] = field[ty - 1][x];
                }
            }
            // ��ԏ�̍s�����
            for (int x = 1; x < GAME_X - 1; ++x) {
                field[0][x] = 0;
            }
            y++; // �������s���ă`�F�b�N�i�A�������΍�j
        }
    }
}

