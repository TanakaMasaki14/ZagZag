#pragma once
class AnimationManager
{
	float posX, posY;// 画像の位置
	float imageSpeedY;	// 画像のY方向の速度
	int imageHandle;// 画像データ
	const float gravity = 0.5f;// 重力
	const int groundY = 200;// 地面のY座標
	const float bounceFactor = 0.7f;// 反発係数

public:
	AnimationManager();

	// 画像のロード
	void loadImage(const char* filePath);

	// 画像のアニメーション
	void update();

	// 描画処理
	void draw();
};

