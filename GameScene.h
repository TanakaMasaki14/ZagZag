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


// ゲームシーンを管理するクラス
class GameScene {
public:
    // コンストラクタ
    GameScene();

    // シーンの更新処理
    void Update(char* keys, char* oldkeys);

    // シーンの描画処理
    void Draw();

    void Delete();

    void Collision();

private:
    int scene;
    Treasure* treasure;
    Player* player = nullptr;
    std::list<Enemy*> enemylist;
    std::list<Terrain*> terrainlist;
    //音楽
    int titleBgm;
    int stageBgm;
    int clearBgm;
    int overBgm;
    //int actionBgm;
    //画像
    int titleImage;
    int clearImage;
    int overImage;
    int treasureImage;

    AnimationManager animation;
};

#endif // GAME_SCENE_H
