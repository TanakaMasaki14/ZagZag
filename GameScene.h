#include "AnimationManager.h"
#include "Terrain.h"
#include "Player.h"

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

    AnimationManager animation;
    Terrain terrain;
    Player player;
};