#pragma once

// ミノ種類数（7種類）
const int MINO_TYPE_COUNT = 7;

// ミノ1つのサイズ（4x4の正方形で表現）
const int MINO_SIZE = 4;

// ミノ構造体
struct Mino {  // struct: classとほぼ一緒, 宣言しない変数 (関数) のデフォルトの設定が逆
    int type;                    // 0〜6のミノタイプ
    int shape[MINO_SIZE][MINO_SIZE]; // 形状
    int x, y;                    // 描画位置（ブロック座標系）
};

// ミノ管理用関数
void InitMino(Mino& mino);
void DrawMino(const Mino& mino);
bool CheckCollision(const Mino& mino, int dx, int dy);
void FixMinoToField(const Mino& mino);
void RotateMino(Mino& mino, bool clockwise);
void HardDrop(Mino& mino);
void DrawGhostMino(const Mino& mino);
void DrawNextMino(const Mino& mino, int offsetX, int offsetY);