#include "FadeOut.h"
#include "DxLib.h"  // DXライブラリの関数を使用するためにインクルード

// コンストラクタ
FadeOut::FadeOut(int fadeSpeed) : alpha(0), speed(fadeSpeed), increasing(true), flashCount(0) {}

// フラッシュ処理を更新（フラッシュを2回までに制限）
bool FadeOut::Update() {
    if (flashCount >= 2) {
        return true;  // 2回のフラッシュが完了したら終了
    }

    if (increasing) {
        alpha += 35;
        if (alpha >= 200) {
            alpha = 200;
            increasing = false;  // アルファ値が最大に達したら減少フェーズに移行
        }
    }
    else {
        alpha -= 25;
        if (alpha <= 0) {
            alpha = 0;
            increasing = true;  // アルファ値が最小に達したら増加フェーズに移行
            flashCount++;  // フラッシュの回数をカウント
        }
    }

    return false;  // まだフラッシュ中
}

// フラッシュの描画
void FadeOut::Draw() const {
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    DrawBox(0, 0, 800, 980, GetColor(255, 255, 255), TRUE);  // 画面全体を白くフラッシュさせる
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// リセット
void FadeOut::Reset() {
    alpha = 0;
    increasing = true;  // フェードインから開始するようにリセット
    flashCount = 0;     // フラッシュの回数もリセット
}
