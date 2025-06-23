#pragma once

// �u���b�N�T�C�Y�ƌ��� (boxes)
const int BLOCK_SIZE = 20;
const int BLOCK_MARGIN = 2;

// �t�B�[���h�T�C�Y (boxes)
const int GAME_X = 12;
const int GAME_Y = 20;
const int INFO_X = 8;
const int INFO_Y_MINO = 8;
const int INFO_Y_SCORE = 10;

// �Q�[����ʂ̃T�C�Y���v�Z (pixel)
const int GAME_WIDTH = GAME_X * (BLOCK_MARGIN + BLOCK_SIZE);
const int GAME_HEIGHT = GAME_Y * (BLOCK_MARGIN + BLOCK_SIZE);

// �E�B���h�E�T�C�Y�̌v�Z (pixel)
const int WINDOW_WIDTH = (GAME_X + INFO_X) * (BLOCK_MARGIN + BLOCK_SIZE);
const int WINDOW_HEIGHT = GAME_Y * (BLOCK_MARGIN + BLOCK_SIZE);

// �eUI�{�b�N�X�̃T�C�Y (pixel)
const int UI_MINO_WIDTH = INFO_X * (BLOCK_MARGIN + BLOCK_SIZE);
const int UI_MINO_HEIGHT = INFO_Y_MINO * (BLOCK_MARGIN + BLOCK_SIZE);

const int UI_SCORE_WIDTH = INFO_X * (BLOCK_MARGIN + BLOCK_SIZE);
const int UI_SCORE_HEIGHT = INFO_Y_SCORE * (BLOCK_MARGIN + BLOCK_SIZE);
