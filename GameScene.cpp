#include "DxLib.h"
#include "GameScene.h"
#include "AnimationManager.h"
#include "Treasure.h"

GameScene::GameScene() {
    scene = 0;
    player = new Player(300, 100);
    treasure = new Treasure();
    for (int i = 0; i < 39; i++) {
        for (int j = 0; j < 41; j++) {
            terrainlist.push_back(new Soil(10 + j * 20, 210 + i * 20, true));
        }
    }
    // 音楽のロード
    titleBgm = LoadSoundMem("Sound/title.mp3");
    stageBgm = LoadSoundMem("Sound/stage.mp3");
    clearBgm = LoadSoundMem("Sound/clear.mp3");
    overBgm = LoadSoundMem("Sound/over.mp3");
    // 画像ロード
    clearImage = LoadGraph("Resource/clear.png");
    overImage = LoadGraph("Resource/over.png");
    treasureImage = LoadGraph("Resource/treasure.png");

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
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            scene = 1;
            StopSoundMem(titleBgm);
            PlaySoundMem(stageBgm, DX_PLAYTYPE_LOOP);
        }
        break;

        // ステージ1 (Scene 1)
    case 1:
        player->Update();

        for (auto enemyitr = enemylist.begin(); enemyitr != enemylist.end(); ++enemyitr) {
            (*enemyitr)->Update();
        }
        for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end(); ++terrainitr) {
            (*terrainitr)->Update();
        }

        if (keys[KEY_INPUT_RETURN] == 1 && oldkeys[KEY_INPUT_RETURN] == 0) {
            scene = 2;
            StopSoundMem(stageBgm);
            PlaySoundMem(clearBgm, DX_PLAYTYPE_BACK);
        }

        Collision();
        Delete();
        break;

        // クリア (Scene 2)
    case 2:
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            scene = 3;
            StopSoundMem(clearBgm);
            PlaySoundMem(overBgm, DX_PLAYTYPE_BACK);
        }
        break;

        // オーバー (Scene 3)
    case 3:
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
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
        break;

    case 1:
        treasure->Draw();
        player->Draw();
        for (auto enemyitr = enemylist.begin(); enemyitr != enemylist.end(); ++enemyitr) {
            (*enemyitr)->Draw();
        }
        for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end(); ++terrainitr) {
            (*terrainitr)->Draw();
        }
        break;

    case 2:
        DrawGraph(0, 0, clearImage, TRUE);
        break;

    case 3:
        DrawGraph(0, 0, overImage, TRUE);
        break;
    }
}

void GameScene::Delete()
{
    for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end();) {
        if ((*terrainitr)->GetIsDig() == true) {
            terrainitr = terrainlist.erase(terrainitr);
        }
        else
        {
            ++terrainitr;
        }
    }
}

void GameScene::Collision()
{
    for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end(); ++terrainitr) {
        if (Collision::SquareToSquare(player->GetDigPointLeftX(), player->GetDigPointUpY(),
            player->GetDigPointRightX(), player->GetDigPointDownY(),
            (*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(),
            (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY())) {
            //掘られる
            (*terrainitr)->Diged();
        }
    }
}