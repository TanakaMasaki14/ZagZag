#include "DxLib.h"
#include "Player.h"  // �v���C���[�̃N���X���Q��

class Enemy {
public:
    Enemy(int startX, int startY, int speed);  // �R���X�g���N�^

    void Update(const Player& player);  // �X�V�����i�ǔ��j
    void Draw();  // �`�揈��

private:
    int x, y;  // �G�̈ʒu
    int speed;  // �G�̈ړ����x
    int enemyImage;  // �G�̉摜

    void ChasePlayer(int playerX, int playerY);  // �v���C���[��ǔ�����֐�
};