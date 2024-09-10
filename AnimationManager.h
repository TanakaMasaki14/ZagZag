#pragma once
#include <vector>

// �A�j���[�V�����̎�ނ��`����񋓌^
enum AnimationType
{
	BOUNCE,// �o�E���h�A�j���[�V����
	SWAY,// ���E�ɗh���A�j���[�V����
	FADE,// ���X�ɏ������茻�ꂽ�肷��A�j���[�V����
	NONE// �A�j���[�V�����Ȃ�
};

class AnimationManager
{
private:

	struct ImageData {
		int imageHandle; // �摜�n���h��
		float posX, posY; // �摜�̈ʒu
		float imageSpeedX,imageSpeedY; // �摜��XY�����̑��x
		float gravity; // �d��
		float groundY; // �n�ʂ�Y���W
		float bounceFactor; // �����W��
		AnimationType animationType; // �A�j���[�V�����̎��
		float swayAmplitude; // �h�ꕝ(���E�̗h��p)
		float swaySpeed; // �h��鑬�x(���E�̗h��p)
		float swayAngle; // ���݂̊p�x(���E�̗h��p)
		float alpha; // �摜�̃A���t�@�l
		float alphaSpeed; // �A���t�@�l�̕ω��X�s�[�h 
	};

	std::vector<ImageData> images;// �摜�ƃA�j���[�V�����̃��X�g

public:
	AnimationManager();

	// �摜�̃��[�h
	//void loadImage(const char* filePath);

	// �摜��ǉ�����֐�
	void BounceImage(const char* filePath, float startX, float startY, float gravity, float bounceFactor, float groundY);
	void SwayImage(const char* filePath, float startX, float startY, float swayAmplitude, float swaySpeed);
	void FadeImage(const char* filePath, float startX, float startY, float alphaSpeed);
	void NormalImage(const char* filePath, float startX, float startY);

	// �摜�̃A�j���[�V����
	void update();

	// �`�揈��
	void draw();
};

