#include "FadeOut.h"
#include "DxLib.h"  // DX���C�u�����̊֐����g�p���邽�߂ɃC���N���[�h

// �R���X�g���N�^
FadeOut::FadeOut(int fadeSpeed) : alpha(0), speed(fadeSpeed) {}

// �t�F�[�h�A�E�g�������X�V
bool FadeOut::Update() {
    if (alpha < 255) {
        alpha += speed;
        if (alpha > 255) {
            alpha = 255;
        }
        return false;  // �܂��t�F�[�h�A�E�g��
    }
    return true;  // �t�F�[�h�A�E�g����
}

// �t�F�[�h�A�E�g�̕`��
void FadeOut::Draw() const {
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    DrawBox(0, 0, 800, 980, GetColor(0, 0, 0), TRUE);  // ��ʑS�̂���������
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// �t�F�[�h�A�E�g�̃��Z�b�g
void FadeOut::Reset() {
    alpha = 0;
}
