#pragma once

class Treasure {
private:
    int x;   // �󔠂�x���W
    int y;   // �󔠂�y���W
    int treasureImage;  // �󔠂̉摜�n���h��

public:
    // �R���X�g���N�^
    Treasure();

    // �󔠂������_���ɐ�������֐�
    void GenerateRandomPosition();

    // �󔠂̕`��
    void Draw();

    // �󔠂�x���W���擾
    int GetX() const;

    // �󔠂�y���W���擾
    int GetY() const;
};
