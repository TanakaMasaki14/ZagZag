#include "AnimationManager.h"
#include "Terrain.h"
#include "Player.h"
#include "Enemy.h"

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
    int titleBgm,stageBgm,clearBgm,overBgm;

    int clearImage;

    int fadeAlpha; // �t�F�[�h�̓����x
    bool isFadingIn; // �t�F�[�h�C�������ǂ���

    AnimationManager animation;
    Terrain terrain;
    Player player;
    Enemy enemy;
};