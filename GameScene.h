#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Treasure.h"
#include "Terrain.h"
#include "Soil.h"
#include "AnimationManager.h"
#include <list>
#include "Collision.h"
#include "FadeOut.h"

// �Q�[���V�[�����Ǘ�����N���X
class GameScene {
public:
    // �R���X�g���N�^
    GameScene();

    // �V�[���̍X�V����
    void Update(char* keys, char* oldkeys);

    // �V�[���̕`�揈��
    void Draw();

    // �V�[���J�ڎ��̃t�F�[�h�A�E�g���J�n
    void StartFadeOut(int targetScene);

    // �Փˏ���
    void Collision();

    void PlayerSoilCollision();

    void DigSoilCollision();

    // �폜����
    void Delete();

private:
    int scene;
    int nextScene;
    Treasure* treasure;
    Player* player = nullptr;
    std::list<Enemy*> enemylist;
    std::list<Terrain*> terrainlist;
    //���y
    int titleBgm;
    int stageBgm;
    int clearBgm;
    int overBgm;
    //�摜
    int titleImage;
    int stageImage;
    int clearImage;
    int overImage;
    int treasureImage;

    AnimationManager animation;

    FadeOut fadeOut;      
    bool isFadingOut;
    void PlaySceneBGM(int currentScene);
};