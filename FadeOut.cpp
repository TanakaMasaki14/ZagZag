#include "FadeOut.h"
#include "DxLib.h"  // DX���C�u�����̊֐����g�p���邽�߂ɃC���N���[�h

// �R���X�g���N�^
FadeOut::FadeOut(int fadeSpeed) : alpha(0), speed(fadeSpeed), increasing(true), flashCount(0) {}

// �t���b�V���������X�V�i�t���b�V����2��܂łɐ����j
bool FadeOut::Update() {
    if (flashCount >= 2) {
        return true;  // 2��̃t���b�V��������������I��
    }

    if (increasing) {
        alpha += 35;
        if (alpha >= 200) {
            alpha = 200;
            increasing = false;  // �A���t�@�l���ő�ɒB�����猸���t�F�[�Y�Ɉڍs
        }
    }
    else {
        alpha -= 25;
        if (alpha <= 0) {
            alpha = 0;
            increasing = true;  // �A���t�@�l���ŏ��ɒB�����瑝���t�F�[�Y�Ɉڍs
            flashCount++;  // �t���b�V���̉񐔂��J�E���g
        }
    }

    return false;  // �܂��t���b�V����
}

// �t���b�V���̕`��
void FadeOut::Draw() const {
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    DrawBox(0, 0, 800, 980, GetColor(255, 255, 255), TRUE);  // ��ʑS�̂𔒂��t���b�V��������
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// ���Z�b�g
void FadeOut::Reset() {
    alpha = 0;
    increasing = true;  // �t�F�[�h�C������J�n����悤�Ƀ��Z�b�g
    flashCount = 0;     // �t���b�V���̉񐔂����Z�b�g
}
