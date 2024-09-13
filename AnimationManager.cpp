#include "DxLib.h"
#include <cmath>
#include "AnimationManager.h"

// コンストラクタ
AnimationManager::AnimationManager() {}

// バウンドの関数
void AnimationManager::BounceImage(const char* filePath, float startX, float startY, float gravity, float bounceFactor, float groundY)
{
	ImageDate imageData;
	imageData.imageHandle = LoadGraph(filePath);
	imageData.posX = startX;
	imageData.posY = startY;
	imageData.imageSpeedY = 0;
	imageData.gravity = gravity;
	imageData.bounceFactor = bounceFactor;
	imageData.groundY = groundY;
	imageData.animationType = BOUNCE;
	images.push_back(imageData);
}

// 左右に揺れる関数
void AnimationManager::SwayImage(const char* filePath, float startX, float startY, float swayAmplitude, float swaySpeed)
{
	ImageDate imageData;
	imageData.imageHandle = LoadGraph(filePath);
	imageData.posX = startX;
	imageData.posY = startY;
	imageData.imageSpeedX = 0;
	imageData.swaySpeed = swaySpeed;
	imageData.swayAngle = 0.0f;
	imageData.swayAmplitude = swayAmplitude;
	imageData.animationType = SWAY;
	images.push_back(imageData);
}

// アニメーションのない画像の関数
void AnimationManager::NormalImage(const char* filePath, float startX, float startY)
{
	ImageDate imageData;
	imageData.imageHandle = LoadGraph(filePath);
	imageData.posX = startX;
	imageData.posY = startY;
	imageData.animationType = NONE;
	images.push_back(imageData);
}

// アニメーションの更新処理
void AnimationManager::update()
{
	for (auto& image : images)
	{
		if (image.animationType == BOUNCE)
		{
			// 重力を適用して速度を更新
			image.imageSpeedY += image.gravity;
			// 画像のY座標を更新
			image.posY += image.imageSpeedY;

			// 地面に衝突した場合
			if (image.posY >= image.groundY)
			{
				image.posY = image.groundY; // 地面で位置を固定
				image.imageSpeedY = -image.imageSpeedY * image.bounceFactor; // 反発する速度を軽減

				// 一定の低速になったら停止(バウンドしない)
				if (fabs(image.imageSpeedY) < 1.0f)
				{
					image.imageSpeedY = 0.0f;
				}
			}
		}

		else if (image.animationType == SWAY)
		{
			// 左右に揺れるアニメーション
			image.swayAngle += image.swaySpeed; // 揺れる角度更新
			image.posX += sin(image.swayAngle) * image.swayAmplitude; // X方向に揺れる
		}

	}

}

//　画像を描画する関数
void AnimationManager::draw()
{
	for (const auto& image : images)
	{
		if (image.imageHandle != -1)
		{
			DrawGraph(static_cast<int>(image.posX), static_cast<int>(image.posY - 100), image.imageHandle, TRUE);
		}
	}
}