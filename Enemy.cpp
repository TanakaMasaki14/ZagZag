#include "Enemy.h"
#include <cmath>

Enemy::Enemy(int startX, int startY, int speed, int patern) :x(startX), y(startY), speed(speed), chaseTimer(0), stopTimer(0),
chaseDuration(300), stopDuration(200), isChasing(true), angle(0.0f), circleRadius(100.0f), isPatern(patern) {
    enemyImage = LoadGraph("Resource/Enemy.png");
}

void Enemy::Update(const Player* player) {
    // プレイヤーの位置を取得
    int playerX = player->GetX();
    int playerY = player->GetY();

    if (isChasing)
    {
        if (isPatern == 0)
        {
            // プレイヤーを追尾
            ChasePlayer(playerX, playerY);
        }
        if (isPatern == 1)
        {
            ChaseLinePlayer(playerX, playerY);
        }
        // 追尾タイマーの更新
        chaseTimer++;

        // 一定時間追尾したら停止状態にする
        if (chaseTimer >= chaseDuration) {
            isChasing = false;
            chaseTimer = 0;  // タイマーリセット
        }
    }
    else
    {
        // 停止タイマーの更新
        stopTimer++;

        // 一定時間停止したら追尾状態に戻す
        if (stopTimer >= stopDuration)
        {
            isChasing = true;
            stopTimer = 0;  // タイマーリセット
        }
    }

}

void Enemy::ChaseLinePlayer(int playerX, int playerY)
{
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

void Enemy::ChasePlayer(int playerX, int playerY) {

    // プレイヤーを中心とした回り込みの位置を計算
    angle += 0.05f;  // 回転速度
    float offsetX = circleRadius * std::cos(angle);
    float offsetY = circleRadius * std::sin(angle);

    // プレイヤーの位置を中心に回り込みながら移動
    float targetX = playerX + offsetX;
    float targetY = playerY + offsetY;

    // 現在の位置からターゲット位置に向かって移動
    float dx = targetX - x;
    float dy = targetY - y;
    float distance = std::sqrt(dx * dx + dy * dy);

    // プレイヤーに向かっての移動量を計算
    if (distance > 0) {
        x += static_cast<int>(dx / distance * speed);
        y += static_cast<int>(dy / distance * speed);
    }

    // 回り込みの半径を徐々に減少させてプレイヤーに近づく
    circleRadius -= 0.1f;
    if (circleRadius < 20.0f) {
        circleRadius = 20.0f;  // 最小半径
    }
}

void Enemy::Draw() {
    // 敵の描画処理
    DrawGraph(x, y, enemyImage, true);
    // デバッグ情報を画面に表示
    DrawFormatString(10, 50, GetColor(255, 255, 255), "Enemy Position: (%d, %d)", x, y);
}