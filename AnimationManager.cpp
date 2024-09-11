#include "DxLib.h"
#include <cmath>
#include "AnimationManager.h"

// �R���X�g���N�^
AnimationManager::AnimationManager() {}

// �o�E���h�̊֐�
void AnimationManager::BounceImage(const char* filePath, float startX, float startY, float gravity, float bounceFactor, float groundY)
{
	ImageDate imageData;
	imageData.imageHandle = LoadGraph(filePath);
	imageData.posX = startX;
	imageData.posY = startY;
	imageData.imageSpeedY = 0;
	imageData.gravity = gravity;
	imageData.bounceFactor = bounceFactor;
	imageData.groundY = groundY;
	imageData.animationType = BOUNCE;
	images.push_back(imageData);
}

// ���E�ɗh���֐�
void AnimationManager::SwayImage(const char* filePath, float startX, float startY, float swayAmplitude, float swaySpeed)
{
	ImageDate imageData;
	imageData.imageHandle = LoadGraph(filePath);
	imageData.posX = startX;
	imageData.posY = startY;
	imageData.imageSpeedX = 0;
	imageData.swaySpeed = swaySpeed;
	imageData.swayAngle = 0.0f;
	imageData.swayAmplitude = swayAmplitude;
	imageData.animationType = SWAY;
	images.push_back(imageData);
}

// �A�j���[�V�����̂Ȃ��摜�̊֐�
void AnimationManager::NormalImage(const char* filePath, float startX, float startY)
{
	ImageDate imageData;
	imageData.imageHandle = LoadGraph(filePath);
	imageData.posX = startX;
	imageData.posY = startY;
	imageData.animationType = NONE;
	images.push_back(imageData);
}

// �A�j���[�V�����̍X�V����
void AnimationManager::update()
{
	for (auto& image : images)
	{
		if (image.animationType == BOUNCE)
		{
			// �d�͂�K�p���đ��x���X�V
			image.imageSpeedY += image.gravity;
			// �摜��Y���W���X�V
			image.posY += image.imageSpeedY;

			// �n�ʂɏՓ˂����ꍇ
			if (image.posY >= image.groundY)
			{
				image.posY = image.groundY; // �n�ʂňʒu���Œ�
				image.imageSpeedY = -image.imageSpeedY * image.bounceFactor; // �������鑬�x���y��

				// ���̒ᑬ�ɂȂ������~(�o�E���h���Ȃ�)
				if (fabs(image.imageSpeedY) < 1.0f)
				{
					image.imageSpeedY = 0.0f;
				}
			}
		}

		else if (image.animationType == SWAY)
		{
			// ���E�ɗh���A�j���[�V����
			image.swayAngle += image.swaySpeed; // �h���p�x�X�V
			image.posX += sin(image.swayAngle) * image.swayAmplitude; // X�����ɗh���
		}

	}

}

//�@�摜��`�悷��֐�
void AnimationManager::draw()
{
	for (const auto& image : images)
	{
		if (image.imageHandle != -1)
		{
			DrawGraph(static_cast<int>(image.posX), static_cast<int>(image.posY - 90), image.imageHandle, TRUE);
		}
	}
}