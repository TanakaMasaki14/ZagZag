#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "Player.h"
#include "Enemy.h"
#include "Treasure.h"
#include "Terrain.h"
#include <list>

// ゲームシーンを管理するクラス
class GameScene {
public:
    // コンストラクタ
    GameScene();

    // シーンの更新処理
    void Update(char* keys, char* oldkeys);

    // シーンの描画処理
    void Draw();

private:
    int scene; // 現在のシーン
    Player* player = nullptr;
};

#endif // GAME_SCENE_H
