#pragma once

class FadeOut {
private:
    int alpha;  // �A���t�@�l�i�����x�j
    int speed;  // �t�F�[�h�̑��x
    int radius;
    int increasing;  // �t�F�[�h�C������J�n����悤�Ƀ��Z�b�g
    int flashCount;

public:
    // �R���X�g���N�^
    FadeOut(int fadeSpeed = 5);

    // �t�F�[�h�A�E�g�������X�V
    bool Update();

    // �t�F�[�h�A�E�g�̕`��
    void Draw() const;

    // �t�F�[�h�A�E�g�̃��Z�b�g
    void Reset();
};
