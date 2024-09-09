#include "DxLib.h"
#include "treasure.h"
#include <cstdlib>  // ランダム生成に使用
#include <ctime>    // シードの初期化に使用

Treasure::Treasure() {
    // ランダムシードを初期化
    srand(static_cast<unsigned int>(time(nullptr)));

    // 宝箱の画像をロード（"Images"フォルダの"treasure.png"を使用）
    treasureImage = LoadGraph("Resource/treasure.png");

    // ランダム位置に宝箱を生成
    GenerateRandomPosition();
}

// 宝箱を縦400より下にランダム生成
void Treasure::GenerateRandomPosition() {
    x = rand() % 800;          // x座標は0～800の範囲でランダム
    y = 600 + rand() % (980 - 600);  // y座標は400～980の範囲でランダム
}

// 宝箱を描画
void Treasure::Draw() {
    DrawGraph(x, y, treasureImage, TRUE);  // 宝箱画像を描画
}

// 宝箱のx座標を取得
int Treasure::GetX() const {
    return x;
}

// 宝箱のy座標を取得
int Treasure::GetY() const {
    return y;
}
