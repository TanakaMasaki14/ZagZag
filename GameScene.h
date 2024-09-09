#include "AnimationManager.h"

// �Q�[���V�[�����Ǘ�����N���X
class GameScene {
public:
    // �R���X�g���N�^
    GameScene();

    // �V�[���̍X�V����
    void Update(char* keys, char* oldkeys);

    // �V�[���̕`�揈��
    void Draw();

private:
    int scene; // ���݂̃V�[��
    int titleBgm;
    int stageBgm;
    int clearBgm;
    int overBgm;

    AnimationManager animation;

    //int actionBgm;
};