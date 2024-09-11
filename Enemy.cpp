#include "Enemy.h"

Enemy::Enemy(int startX, int startY, int speed):x(startX), y(startY), speed(speed){

}

void Enemy::Update(const Player& player) {
    // �v���C���[�̈ʒu���擾
    int playerX = player.GetX();
    int playerY = player.GetY();

    // �v���C���[��ǔ�
    ChasePlayer(playerX, playerY);
}

void Enemy::ChasePlayer(int playerX, int playerY) {
    // X���̕����Ƀv���C���[�Ɍ������Ĉړ�
    if (x < playerX) {
        x += speed;  // �E�Ɉړ�
    }
    else if (x > playerX) {
        x -= speed;  // ���Ɉړ�
    }

    // Y���̕����Ƀv���C���[�Ɍ������Ĉړ�
    if (y < playerY) {
        y += speed;  // ���Ɉړ�
    }
    else if (y > playerY) {
        y -= speed;  // ��Ɉړ�
    }
}

void Enemy::Draw() {
    // �G�̕`�揈�� (��`�Ƃ��ĕ`��)
    DrawBox(x, y, x + 32, y + 32, GetColor(255, 0, 0), TRUE); // �Ԃ���`�ŕ\��
    // �f�o�b�O������ʂɕ\��
    DrawFormatString(10, 50, GetColor(255, 255, 255), "Enemy Position: (%d, %d)", x, y);
}