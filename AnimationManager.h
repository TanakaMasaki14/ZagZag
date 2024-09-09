#pragma once
#include <vector>

// アニメーションの種類を定義する列挙型
enum AnimationType
{
	BOUNCE,// バウンドアニメーション
	SWAY,// 左右に揺れるアニメーション
	NONE// アニメーションなし
};

class AnimationManager
{
private:

	struct ImageDate {
		int imageHandle; // 画像ハンドル
		float posX, posY; // 画像の位置
		float imageSpeedX, imageSpeedY; // 画像のXY方向の速度
		float gravity; // 重力
		float groundY; // 地面のY座標
		float bounceFactor; // 反発係数
		AnimationType animationType; // アニメーションの種類
		float swayAmplitude; // 揺れ幅(左右の揺れ用)
		float swaySpeed; // 揺れる速度(左右の揺れ用)
		float swayAngle; // 現在の角度(左右の揺れ用)
	};

	std::vector<ImageDate> images;// 画像とアニメーションのリスト

public:
	AnimationManager();

	// 画像のロード
	//void loadImage(const char* filePath);

	// 画像を追加する関数
	void BounceImage(const char* filePath, float startX, float startY, float gravity, float bounceFactor, float groundY);
	void SwayImage(const char* filePath, float startX, float startY, float swayAmplitude, float swaySpeed);
	void NormalImage(const char* filePath, float startX, float startY);

	// 画像のアニメーション
	void update();

	// 描画処理
	void draw();
};