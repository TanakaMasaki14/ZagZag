#include "Enemy.h"

Enemy::Enemy(int startX, int startY, int speed):x(startX), y(startY), speed(speed){

}

void Enemy::Update(const Player& player) {
    // プレイヤーの位置を取得
    int playerX = player.GetX();
    int playerY = player.GetY();

    // プレイヤーを追尾
    ChasePlayer(playerX, playerY);
}

void Enemy::ChasePlayer(int playerX, int playerY) {
    // X軸の方向にプレイヤーに向かって移動
    if (x < playerX) {
        x += speed;  // 右に移動
    }
    else if (x > playerX) {
        x -= speed;  // 左に移動
    }

    // Y軸の方向にプレイヤーに向かって移動
    if (y < playerY) {
        y += speed;  // 下に移動
    }
    else if (y > playerY) {
        y -= speed;  // 上に移動
    }
}

void Enemy::Draw() {
    // 敵の描画処理 (矩形として描画)
    DrawBox(x, y, x + 32, y + 32, GetColor(255, 0, 0), TRUE); // 赤い矩形で表示
    // デバッグ情報を画面に表示
    DrawFormatString(10, 50, GetColor(255, 255, 255), "Enemy Position: (%d, %d)", x, y);
}