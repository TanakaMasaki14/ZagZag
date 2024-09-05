#include "DxLib.h"
#include "GameScene.h"

GameScene::GameScene() {
    scene = 0;
}

// シーンの更新処理
void GameScene::Update(char* keys, char* oldkeys) {
    switch (scene) {
        // タイトル
    case 0:
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            scene = 1;
        }
        break;

        // ステージ1
    case 1:
        if (keys[KEY_INPUT_C] == 1 && oldkeys[KEY_INPUT_C] == 0) {
            scene = 2;
        }
        break;

        // クリア
    case 2:
        if (keys[KEY_INPUT_T] == 1 && oldkeys[KEY_INPUT_T] == 0) {
            scene = 0;
        }
        break;
    }
}

// シーンの描画処理
void GameScene::Draw() {
    switch (scene) {
        // タイトル
    case 0:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Title");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH SPACE");
        break;

        // ステージ1
    case 1:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Stage1");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH C");
        break;

        // クリア
    case 2:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Clear");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH T");
        break;
    }
}
