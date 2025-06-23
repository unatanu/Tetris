#include "DxLib.h"
#include "config.h"
#include "mino.h"
#include "wall.h"
#include <cstdlib>
#include <ctime>

// É~Émå`èÛíËã`Åi7éÌóﬁÅj
const int MINO_SHAPES[MINO_TYPE_COUNT][MINO_SIZE][MINO_SIZE] = {
    // Iå^
    {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // Oå^
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    },
    // Tå^
    {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    },
    // Så^
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    },
    // Zå^
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    },
    // Jå^
    {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
    },
    // Lå^
    {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
    }
};

void InitMino(Mino& mino) {
    srand((unsigned)time(nullptr));
    mino.type = rand() % MINO_TYPE_COUNT;

    // É~ÉmÇÃå`èÛÇÉRÉsÅ[
    for (int y = 0; y < MINO_SIZE; ++y) {
        for (int x = 0; x < MINO_SIZE; ++x) {
            mino.shape[y][x] = MINO_SHAPES[mino.type][y][x];
        }
    }

    // èâä˙à íuÅiíÜâõè„ïîÅj
    mino.x = GAME_X / 2 - 2;
    mino.y = 0;
}

void DrawMino(const Mino& mino) {
    for (int y = 0; y < MINO_SIZE; ++y) {
        for (int x = 0; x < MINO_SIZE; ++x) {
            if (mino.shape[y][x] != 0) {
                int drawX = (mino.x + x) * (BLOCK_SIZE + BLOCK_MARGIN);
                int drawY = (mino.y + y) * (BLOCK_SIZE + BLOCK_MARGIN);
                DrawBox(drawX, drawY, drawX + BLOCK_SIZE, drawY + BLOCK_SIZE, GetColor(0, 255, 0), TRUE);
            }
        }
    }
}

bool CheckCollision(const Mino& mino, int dx, int dy) {
    for (int y = 0; y < MINO_SIZE; ++y) {
        for (int x = 0; x < MINO_SIZE; ++x) {
            if (mino.shape[y][x]) {
                int nx = mino.x + x + dx;
                int ny = mino.y + y + dy;
                if (ny >= GAME_Y || nx < 0 || nx >= GAME_X || field[ny][nx] != 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

void FixMinoToField(const Mino& mino) {
    for (int y = 0; y < MINO_SIZE; ++y) {
        for (int x = 0; x < MINO_SIZE; ++x) {
            if (mino.shape[y][x]) {
                int fx = mino.x + x;
                int fy = mino.y + y;
                if (fx >= 0 && fx < GAME_X && fy >= 0 && fy < GAME_Y) {
                    field[fy][fx] = 1;
                }
            }
        }
    }
}

void RotateMino(Mino& mino, bool clockwise) {
    int temp[MINO_SIZE][MINO_SIZE] = {};

    for (int y = 0; y < MINO_SIZE; ++y) {
        for (int x = 0; x < MINO_SIZE; ++x) {
            if (clockwise)
                temp[x][MINO_SIZE - 1 - y] = mino.shape[y][x];  // éûåvâÒÇË
            else
                temp[MINO_SIZE - 1 - x][y] = mino.shape[y][x];  // îΩéûåvâÒÇË
        }
    }

    // è’ìÀÇ™Ç»ÇØÇÍÇŒâÒì]ÇîΩâf
    Mino test = mino;
    for (int y = 0; y < MINO_SIZE; ++y)
        for (int x = 0; x < MINO_SIZE; ++x)
            test.shape[y][x] = temp[y][x];

    if (!CheckCollision(test, 0, 0)) {
        for (int y = 0; y < MINO_SIZE; ++y)
            for (int x = 0; x < MINO_SIZE; ++x)
                mino.shape[y][x] = temp[y][x];
    }
}

void HardDrop(Mino& mino) {
    while (!CheckCollision(mino, 0, 1)) {
        mino.y += 1;
    }
}

void DrawGhostMino(const Mino& mino) {
    Mino ghost = mino;

    while (!CheckCollision(ghost, 0, 1)) {
        ghost.y += 1;
    }

    for (int y = 0; y < MINO_SIZE; ++y) {
        for (int x = 0; x < MINO_SIZE; ++x) {
            if (ghost.shape[y][x]) {
                int drawX = (ghost.x + x) * (BLOCK_SIZE + BLOCK_MARGIN);
                int drawY = (ghost.y + y) * (BLOCK_SIZE + BLOCK_MARGIN);
                DrawBox(drawX, drawY, drawX + BLOCK_SIZE, drawY + BLOCK_SIZE, GetColor(100, 100, 100), TRUE);
            }
        }
    }
}

void DrawNextMino(const Mino& mino, int offsetX, int offsetY) {
    for (int y = 0; y < MINO_SIZE; ++y) {
        for (int x = 0; x < MINO_SIZE; ++x) {
            if (mino.shape[y][x]) {
                int drawX = offsetX + x * (BLOCK_SIZE + BLOCK_MARGIN);
                int drawY = offsetY + y * (BLOCK_SIZE + BLOCK_MARGIN);
                DrawBox(drawX, drawY, drawX + BLOCK_SIZE, drawY + BLOCK_SIZE, GetColor(255, 0, 0), TRUE);
            }
        }
    }
}
