#include "AnimationManager.h"
#include "Terrain.h"
#include "Player.h"

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
    int titleBgm,stageBgm,clearBgm,overBgm;

    int clearImage;

    AnimationManager animation;
    Terrain terrain;
    Player player;
};