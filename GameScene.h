#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "AnimationManager.h"

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
    int scene;
    //音楽
    int titleBgm;
    int stageBgm;
    int clearBgm;
    int overBgm;
    //int actionBgm;
      //画像
    int clearImage;
    int overImage;

    AnimationManager animation;
};

#endif // GAME_SCENE_H
