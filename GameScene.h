#ifndef GAME_SCENE_H
#define GAME_SCENE_H

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
    int titleBgm;
    int stageBgm;
    int clearBgm;
    int overBgm;
    //int actionBgm;
};

#endif // GAME_SCENE_H
