#include "DxLib.h"
#include "GameScene.h"
#include "AnimationManager.h"
#include "Terrain.h"
#include "Player.h"

// マップの初期化(20*20サイズのチップで40*21のマップを作成)

GameScene::GameScene() :terrain(40, 49, 20),player(0,0), fadeAlpha(255), isFadingIn(true), enemy(200, 200, 2) {
    scene = 0;
    
    // 音楽のロード
    titleBgm = LoadSoundMem("Sound/title.mp3");
    stageBgm = LoadSoundMem("Sound/stage.mp3");
    clearBgm = LoadSoundMem("Sound/clear.mp3");
    overBgm = LoadSoundMem("Sound/over.mp3");

    //画像の読み込み
    animation.BounceImage("Resource/TitleName.png", 270, 100, 0.5f, 0.7f, 200);
    animation.SwayImage("Resource/Icon.png", 100, 500, 1.0f, 0.05f);
    animation.FadeImage("Resource/PushSpace.png", 260, 700, 0.02f);
    animation.NormalImage("Resource/GameStart.png", 260, 500);
    clearImage = LoadGraph("Resource/Clear.png");
    terrain.InitializeMap("Resource/Soil.png");

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
            isFadingIn = true; // シーンが切り替わるときにフェードインを開始
            fadeAlpha = 255;   // フェードインの透明度をリセット
        }
        break;

        // ステージ1 (Scene 1)
    case 1:

        player.Update(terrain);
        enemy.Update(player);  // 敵がプレイヤーを追尾

        // フェードイン処理
        if (isFadingIn) {
            fadeAlpha -= 3; // フェードのスピードを調整
            if (fadeAlpha <= 0) {
                fadeAlpha = 0;
                isFadingIn = false;
            }
        }

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

        terrain.Draw();
        animation.draw();

        DrawFormatString(100, 100, GetColor(255, 255, 255), "Title");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH 1");
        break;

    case 1:

        terrain.Draw();
        player.Draw();
        enemy.Draw();

        // フェードイン描画
        if (isFadingIn) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
            DrawBox(0, 0, 800, 980, GetColor(0, 0, 0), TRUE); // 画面全体を覆う黒い矩形
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードをリセット
        }
       
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Stage1");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH 2");
        break;

    case 2:

        DrawGraph(270, 200, clearImage, true);

        DrawFormatString(100, 100, GetColor(255, 255, 255), "Game Clear");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH 3");
        break;

    case 3:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Game Over");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH T");
        break;
    }
}