#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Treasure.h"
#include "Terrain.h"
#include "Soil.h"
#include "AnimationManager.h"
#include <list>
#include "Collision.h"


// �Q�[���V�[�����Ǘ�����N���X
class GameScene {
public:
    // �R���X�g���N�^
    GameScene();

    // �V�[���̍X�V����
    void Update(char* keys, char* oldkeys);

    // �V�[���̕`�揈��
    void Draw();

    void Delete();

    void Collision();

private:
    int scene;
    Treasure* treasure;
    Player* player = nullptr;
    std::list<Enemy*> enemylist;
    std::list<Terrain*> terrainlist;
    //���y
    int titleBgm;
    int stageBgm;
    int clearBgm;
    int overBgm;
    //int actionBgm;
    //�摜
    int titleImage;
    int clearImage;
    int overImage;
    int treasureImage;

    AnimationManager animation;
};

#endif // GAME_SCENE_H
