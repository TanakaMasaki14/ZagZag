#include "DxLib.h"
#include "GameScene.h"
#include "AnimationManager.h"

GameScene::GameScene() {
    scene = 0;

    // 音楽のロード
    titleBgm = LoadSoundMem("Sound/title.mp3");
    stageBgm = LoadSoundMem("Sound/stage.mp3");
    clearBgm = LoadSoundMem("Sound/clear.mp3");
    overBgm = LoadSoundMem("Sound/over.mp3");

    animation.BounceImage("Resource/TitleName.png", 270, 100, 0.5f, 0.7f, 200);
    animation.SwayImage("Resource/Icon.png", 100, 500, 1.0f, 0.05f);
    animation.NormalImage("Resource/GameStart.png", 260, 500);

    if (scene == 0) {
        PlaySoundMem(titleBgm, DX_PLAYTYPE_LOOP);
    }
    if (scene == 1) {
        PlaySoundMem(stageBgm, DX_PLAYTYPE_LOOP);
    }
    if (scene == 2) {
        PlaySoundMem(clearBgm, DX_PLAYTYPE_BACK);
    }
    if (scene == 3) {
        PlaySoundMem(overBgm, DX_PLAYTYPE_BACK);
    }
}

// シーンの更新処理
void GameScene::Update(char* keys, char* oldkeys) {

    switch (scene) {
        // タイトル (Scene 0)
    case 0:

        animation.update();

        if (keys[KEY_INPUT_1] == 1 && oldkeys[KEY_INPUT_1] == 0) {
            scene = 1;
            StopSoundMem(titleBgm);
            PlaySoundMem(stageBgm, DX_PLAYTYPE_LOOP);
        }
        break;

        // ステージ1 (Scene 1)
    case 1:
        if (keys[KEY_INPUT_2] == 1 && oldkeys[KEY_INPUT_2] == 0) {
            scene = 2;
            StopSoundMem(stageBgm);
            PlaySoundMem(clearBgm, DX_PLAYTYPE_BACK);
        }
        break;

        // クリア (Scene 2)
    case 2:
        if (keys[KEY_INPUT_3] == 1 && oldkeys[KEY_INPUT_3] == 0) {
            scene = 3;
            StopSoundMem(clearBgm);
            PlaySoundMem(overBgm, DX_PLAYTYPE_BACK);
        }
        break;

        // オーバー (Scene 3)
    case 3:
        if (keys[KEY_INPUT_T] == 1 && oldkeys[KEY_INPUT_T] == 0) {
            scene = 0;
            StopSoundMem(overBgm);
            PlaySoundMem(titleBgm, DX_PLAYTYPE_LOOP);
        }
        break;
    }
}

// シーンの描画処理
void GameScene::Draw() {
    switch (scene) {
        // タイトル (Scene 0)
    case 0:

        animation.draw();

        DrawFormatString(100, 100, GetColor(255, 255, 255), "Title");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH 1");
        break;

    case 1:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Stage1");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH 2");
        break;

    case 2:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Game Clear");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH 3");
        break;

    case 3:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Game Over");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH T");
        break;
    }
}