#pragma once
class AnimationManager
{
	float posX, posY;// �摜�̈ʒu
	float imageSpeedY;	// �摜��Y�����̑��x
	int imageHandle;// �摜�f�[�^
	const float gravity = 0.5f;// �d��
	const int groundY = 200;// �n�ʂ�Y���W
	const float bounceFactor = 0.7f;// �����W��

public:
	AnimationManager();

	// �摜�̃��[�h
	void loadImage(const char* filePath);

	// �摜�̃A�j���[�V����
	void update();

	// �`�揈��
	void draw();
};

