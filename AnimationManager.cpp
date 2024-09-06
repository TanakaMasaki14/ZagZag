#include "DxLib.h"
#include <cmath>
#include "AnimationManager.h"

// �R���X�g���N�^
AnimationManager::AnimationManager():posX(270),posY(100),imageSpeedY(0),imageHandle(-1){}

// �摜�����[�h����֐�
void AnimationManager::loadImage(const char* filePath)
{
	imageHandle = LoadGraph(filePath);
}

// �A�j���[�V�����̍X�V����
void AnimationManager::update()
{
	// �d�͂�K�p���đ��x���X�V
	imageSpeedY += gravity;
	// �摜��Y���W���X�V
	posY += imageSpeedY;

	// �n�ʂɏՓ˂����ꍇ
	if (posY >= groundY)
	{
		posY = groundY; // �n�ʂňʒu���Œ�
		imageSpeedY = -imageSpeedY * bounceFactor; // �������鑬�x���y��

		// ���̒ᑬ�ɂȂ������~(�o�E���h���Ȃ�)
		if (fabs(imageSpeedY) < 1.0f)
		{
			imageSpeedY = 0.0f;
		}
	}
}

//�@�摜��`�悷��֐�
void AnimationManager::draw()
{
	if (imageHandle != -1)
	{
		DrawGraph(posX, posY, imageHandle, TRUE);
	}
}