#ifndef FADEOUT_H
#define FADEOUT_H

class FadeOut {
private:
    int alpha;  // �A���t�@�l�i�����x�j
    int speed;  // �t�F�[�h�̑��x

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

#endif // FADEOUT_H
