#include "DxLib.h"
#include "Player.h"  // プレイヤーのクラスを参照

class Enemy {
public:
    Enemy(int startX, int startY, int speed);  // コンストラクタ

    void Update(const Player& player);  // 更新処理（追尾）
    void Draw();  // 描画処理

private:
    int x, y;  // 敵の位置
    int speed;  // 敵の移動速度
    int enemyImage;  // 敵の画像

    void ChasePlayer(int playerX, int playerY);  // プレイヤーを追尾する関数
};