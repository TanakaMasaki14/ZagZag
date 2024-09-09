#include "DxLib.h"
#include "treasure.h"
#include <cstdlib>  // �����_�������Ɏg�p
#include <ctime>    // �V�[�h�̏������Ɏg�p

Treasure::Treasure() {
    // �����_���V�[�h��������
    srand(static_cast<unsigned int>(time(nullptr)));

    // �󔠂̉摜�����[�h�i"Images"�t�H���_��"treasure.png"���g�p�j
    treasureImage = LoadGraph("Resource/treasure.png");

    // �����_���ʒu�ɕ󔠂𐶐�
    GenerateRandomPosition();
}

// �󔠂��c400��艺�Ƀ����_������
void Treasure::GenerateRandomPosition() {
    x = rand() % 800;          // x���W��0�`800�͈̔͂Ń����_��
    y = 600 + rand() % (980 - 600);  // y���W��400�`980�͈̔͂Ń����_��
}

// �󔠂�`��
void Treasure::Draw() {
    DrawGraph(x, y, treasureImage, TRUE);  // �󔠉摜��`��
}

// �󔠂�x���W���擾
int Treasure::GetX() const {
    return x;
}

// �󔠂�y���W���擾
int Treasure::GetY() const {
    return y;
}
