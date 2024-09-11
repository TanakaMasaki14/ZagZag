#include "FadeOut.h"
#include "DxLib.h"  // DXライブラリの関数を使用するためにインクルード

// コンストラクタ
FadeOut::FadeOut(int fadeSpeed) : alpha(0), speed(fadeSpeed) {}

// フェードアウト処理を更新
bool FadeOut::Update() {
    if (alpha < 255) {
        alpha += speed;
        if (alpha > 255) {
            alpha = 255;
        }
        return false;  // まだフェードアウト中
    }
    return true;  // フェードアウト完了
}

// フェードアウトの描画
void FadeOut::Draw() const {
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    DrawBox(0, 0, 800, 980, GetColor(0, 0, 0), TRUE);  // 画面全体を黒くする
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// フェードアウトのリセット
void FadeOut::Reset() {
    alpha = 0;
}
