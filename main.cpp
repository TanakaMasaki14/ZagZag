#include "DxLib.h"
#include "AnimationManager.h"
#include <math.h>

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "4047_ZagZag";

// �E�B���h�E����
const int WIN_WIDTH = 800;

// �E�B���h�E�c��
const int WIN_HEIGHT = 980;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0xA9, 0xCE, 0xEC);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// AnimationManager�N���X�̃C���X�^���X���쐬
	AnimationManager animation;

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	animation.BounceImage("Resouse/TitleName.png",270,100,0.5f,0.7f,200);
	animation.SwayImage("Resouse/Icon.png", 100, 500, 1.0f,0.05f);

	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	//�V�[���Ǘ�
	int scene = 0;

	// �V�[���̐i�s�t���O
	bool spaceKeyPressed = false; // SPACE�L�[����x�����ꂽ���ǂ����𔻒肷��t���O

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = {0};

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = {0};

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		switch (scene)
		{
		// �^�C�g��
		case 0:

			animation.update();

			DrawFormatString(100, 100, GetColor(255, 255, 255), "Title");
			DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH SPACE");

			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				scene = 1;
			}
			break;

		// �X�e�[�W1
		case 1:
			DrawFormatString(100, 100, GetColor(255, 255, 255), "Stage1");
			DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH C");

			if (keys[KEY_INPUT_C] == 1 && oldkeys[KEY_INPUT_C] == 0) {
				scene = 2;
			}
			break;

		// �N���A
		case 2:
			DrawFormatString(100, 100, GetColor(255, 255, 255), "Clear");
			DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH T");

			if (keys[KEY_INPUT_T] == 1 && oldkeys[KEY_INPUT_T] == 0) {
				scene = 0;
			}
			break;
		}

		// �`�揈��
		animation.draw();

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
