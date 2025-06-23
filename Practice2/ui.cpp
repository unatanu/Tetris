#include "DxLib.h"
#include "ui.h"

void DrawUIBox(int x, int y, int width, int height, const std::string& label) {
    DrawBox(x, y, x + width, y + height,GetColor(255, 255, 255), FALSE);
    setMessage(x + width/2, y - 20, label);
}

void setMessage(int x, int y, const std::string& message) {
    DrawString(x, y, message.c_str(), GetColor(255, 255, 255));
}