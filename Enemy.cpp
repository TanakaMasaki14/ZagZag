#include "Enemy.h"
#include <cmath>

Enemy::Enemy(int startX, int startY, int speed, int patern) :x(startX), y(startY), speed(speed), chaseTimer(0), stopTimer(0),
chaseDuration(300), stopDuration(200), isChasing(true), angle(0.0f), circleRadius(100.0f), isPatern(patern) {
    enemyImage = LoadGraph("Resource/Enemy.png");
}

void Enemy::Update(const Player* player) {
    // �v���C���[�̈ʒu���擾
    int playerX = player->GetX();
    int playerY = player->GetY();

    if (isChasing)
    {
        if (isPatern == 0)
        {
            // �v���C���[��ǔ�
            ChasePlayer(playerX, playerY);
        }
        if (isPatern == 1)
        {
            ChaseLinePlayer(playerX, playerY);
        }
        // �ǔ��^�C�}�[�̍X�V
        chaseTimer++;

        // ��莞�Ԓǔ��������~��Ԃɂ���
        if (chaseTimer >= chaseDuration) {
            isChasing = false;
            chaseTimer = 0;  // �^�C�}�[���Z�b�g
        }
    }
    else
    {
        // ��~�^�C�}�[�̍X�V
        stopTimer++;

        // ��莞�Ԓ�~������ǔ���Ԃɖ߂�
        if (stopTimer >= stopDuration)
        {
            isChasing = true;
            stopTimer = 0;  // �^�C�}�[���Z�b�g
        }
    }

}

void Enemy::ChaseLinePlayer(int playerX, int playerY)
{
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

void Enemy::ChasePlayer(int playerX, int playerY) {

    // �v���C���[�𒆐S�Ƃ�����荞�݂̈ʒu���v�Z
    angle += 0.05f;  // ��]���x
    float offsetX = circleRadius * std::cos(angle);
    float offsetY = circleRadius * std::sin(angle);

    // �v���C���[�̈ʒu�𒆐S�ɉ�荞�݂Ȃ���ړ�
    float targetX = playerX + offsetX;
    float targetY = playerY + offsetY;

    // ���݂̈ʒu����^�[�Q�b�g�ʒu�Ɍ������Ĉړ�
    float dx = targetX - x;
    float dy = targetY - y;
    float distance = std::sqrt(dx * dx + dy * dy);

    // �v���C���[�Ɍ������Ă̈ړ��ʂ��v�Z
    if (distance > 0) {
        x += static_cast<int>(dx / distance * speed);
        y += static_cast<int>(dy / distance * speed);
    }

    // ��荞�݂̔��a�����X�Ɍ��������ăv���C���[�ɋ߂Â�
    circleRadius -= 0.1f;
    if (circleRadius < 20.0f) {
        circleRadius = 20.0f;  // �ŏ����a
    }
}

void Enemy::Draw() {
    // �G�̕`�揈��
    DrawGraph(x, y, enemyImage, true);
    // �f�o�b�O������ʂɕ\��
    DrawFormatString(10, 50, GetColor(255, 255, 255), "Enemy Position: (%d, %d)", x, y);
}