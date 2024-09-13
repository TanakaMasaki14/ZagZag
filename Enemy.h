#include "DxLib.h"
#include "Player.h"  // �v���C���[�̃N���X���Q��
#include <vector>

class Enemy {
public:
    Enemy(int startX, int startY, int speed, int patern);  // �R���X�g���N�^
    void Update(const Player* player);  // �X�V�����i�ǔ��j
    void Draw();  // �`�揈��

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
    void ChasePlayer(int playerX, int playerY);  // �v���C���[��ǔ�����֐�
    void ChaseLinePlayer(int playerX, int playerY);

    int x, y;  // �G�̈ʒu
    int speed;  // �G�̈ړ����x
    int enemyImage;  // �G�̉摜
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