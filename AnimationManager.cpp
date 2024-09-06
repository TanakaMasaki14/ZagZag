#include "DxLib.h"
#include <cmath>
#include "AnimationManager.h"

// コンストラクタ
AnimationManager::AnimationManager():posX(270),posY(100),imageSpeedY(0),imageHandle(-1){}

// 画像をロードする関数
void AnimationManager::loadImage(const char* filePath)
{
	imageHandle = LoadGraph(filePath);
}

// アニメーションの更新処理
void AnimationManager::update()
{
	// 重力を適用して速度を更新
	imageSpeedY += gravity;
	// 画像のY座標を更新
	posY += imageSpeedY;

	// 地面に衝突した場合
	if (posY >= groundY)
	{
		posY = groundY; // 地面で位置を固定
		imageSpeedY = -imageSpeedY * bounceFactor; // 反発する速度を軽減

		// 一定の低速になったら停止(バウンドしない)
		if (fabs(imageSpeedY) < 1.0f)
		{
			imageSpeedY = 0.0f;
		}
	}
}

//　画像を描画する関数
void AnimationManager::draw()
{
	if (imageHandle != -1)
	{
		DrawGraph(posX, posY, imageHandle, TRUE);
	}
}