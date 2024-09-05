#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "Player.h"
#include "Enemy.h"
#include "Treasure.h"
#include "Terrain.h"
#include <list>

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
    Player* player = nullptr;
};

#endif // GAME_SCENE_H
