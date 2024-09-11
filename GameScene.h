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

// ゲームシーンを管理するクラス
class GameScene {
public:
    // コンストラクタ
    GameScene();

    // シーンの更新処理
    void Update(char* keys, char* oldkeys);

    // シーンの描画処理
    void Draw();

    // シーン遷移時のフェードアウトを開始
    void StartFadeOut(int targetScene);

    // 衝突処理
    void Collision();

    void PlayerSoilCollision();

    void DigSoilCollision();

    // 削除処理
    void Delete();

private:
    int scene;
    int nextScene;
    Treasure* treasure;
    Player* player = nullptr;
    std::list<Enemy*> enemylist;
    std::list<Terrain*> terrainlist;
    //音楽
    int titleBgm;
    int stageBgm;
    int clearBgm;
    int overBgm;
    //画像
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