#pragma once
#include "Player.h"
#include "Enemy.h"
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

    void PlayerTreasureCollision();

    void PlayerEnemyCollision();

    void PlayerAttackEnemyCollision();
    // �폜����
    void Delete();
    void spawn();

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
    int ruleImage;
    int missionImage;
    int hpImage;
    int hp1Image;
    int hp2Image;
    int stageImage;
    int clearImage;
    int overImage;
    int treasureImage;

    int timer = 60 * 3;

    int const spawnX_patern1 = -10;
    int const spawnY_patern1 = 400;

    int const spawnX_patern2 = -10;
    int const spawnY_patern2 = 900;

    int const spawnX_patern3 = 810;
    int const spawnY_patern3 = 400;

    int spawn_patern = 0;

    AnimationManager animation;

    FadeOut fadeOut;      
    bool isFadingOut;
    void PlaySceneBGM(int currentScene);
};