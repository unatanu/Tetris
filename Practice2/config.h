#pragma once

// ブロックサイズと隙間 (boxes)
const int BLOCK_SIZE = 20;
const int BLOCK_MARGIN = 2;

// フィールドサイズ (boxes)
const int GAME_X = 12;
const int GAME_Y = 20;
const int INFO_X = 8;
const int INFO_Y_MINO = 8;
const int INFO_Y_SCORE = 10;

// ゲーム画面のサイズを計算 (pixel)
const int GAME_WIDTH = GAME_X * (BLOCK_MARGIN + BLOCK_SIZE);
const int GAME_HEIGHT = GAME_Y * (BLOCK_MARGIN + BLOCK_SIZE);

// ウィンドウサイズの計算 (pixel)
const int WINDOW_WIDTH = (GAME_X + INFO_X) * (BLOCK_MARGIN + BLOCK_SIZE);
const int WINDOW_HEIGHT = GAME_Y * (BLOCK_MARGIN + BLOCK_SIZE);

// 各UIボックスのサイズ (pixel)
const int UI_MINO_WIDTH = INFO_X * (BLOCK_MARGIN + BLOCK_SIZE);
const int UI_MINO_HEIGHT = INFO_Y_MINO * (BLOCK_MARGIN + BLOCK_SIZE);

const int UI_SCORE_WIDTH = INFO_X * (BLOCK_MARGIN + BLOCK_SIZE);
const int UI_SCORE_HEIGHT = INFO_Y_SCORE * (BLOCK_MARGIN + BLOCK_SIZE);
