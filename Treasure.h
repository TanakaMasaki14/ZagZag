#pragma once

class Treasure {
private:
    int x;   // 宝箱のx座標
    int y;   // 宝箱のy座標
    int treasureImage;  // 宝箱の画像ハンドル

public:
    // コンストラクタ
    Treasure();

    // 宝箱をランダムに生成する関数
    void GenerateRandomPosition();

    // 宝箱の描画
    void Draw();

    // 宝箱のx座標を取得
    int GetX() const;

    // 宝箱のy座標を取得
    int GetY() const;
};
