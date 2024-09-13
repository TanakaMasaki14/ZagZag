#pragma once

class FadeOut {
private:
    int alpha;  // アルファ値（透明度）
    int speed;  // フェードの速度
    int radius;
    int increasing;  // フェードインから開始するようにリセット
    int flashCount;

public:
    // コンストラクタ
    FadeOut(int fadeSpeed = 5);

    // フェードアウト処理を更新
    bool Update();

    // フェードアウトの描画
    void Draw() const;

    // フェードアウトのリセット
    void Reset();
};
