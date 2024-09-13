#include "DxLib.h"
#include "Player.h"  // プレイヤーのクラスを参照
#include <vector>

class Enemy {
public:
    Enemy(int startX, int startY, int speed, int patern);  // コンストラクタ
    void Update(const Player* player);  // 更新処理（追尾）
    void Draw();  // 描画処理

	float GetLeftX() {
		return x - sizeX;
	}
	float GetRightX() {
		return x + sizeX;
	}

	float GetUpY() {
		return y - sizeY;
	}
	float GetDownY() {
		return y + sizeY;
	}

	void Hit() {
		hit = true;
	}

	bool GetIsHit() {
		return hit;
	}

private:
    void ChasePlayer(int playerX, int playerY);  // プレイヤーを追尾する関数
    void ChaseLinePlayer(int playerX, int playerY);

    int x, y;  // 敵の位置
    int speed;  // 敵の移動速度
    int enemyImage;  // 敵の画像
    int chaseTimer;
    int stopTimer;
    int chaseDuration;
    int stopDuration;
    bool isChasing;
    float angle;
    float circleRadius;
    int isPatern;

	float sizeX = 0;
	float sizeY = 0;

	bool hit = false;
};