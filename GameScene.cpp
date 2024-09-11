#include "DxLib.h"
#include "GameScene.h"
#include "AnimationManager.h"
#include "Treasure.h"

// フェードアウト用のクラスインスタンス追加
FadeOut fadeOut;
bool isFadingOut = false;  // フェードアウト中かどうか
int nextScene = -1;        // 次のシーンの指定

GameScene::GameScene() {
    scene = 0;
    player = new Player(300, 100);
    treasure = new Treasure();
    for (int i = 0; i < 39; i++) {
        for (int j = 0; j < 41; j++) {
            terrainlist.push_back(new Soil((float)10 + (float)j * 20, (float)210 + (float)i * 20, true));
        }
    }
    // 音楽のロード
    titleBgm = LoadSoundMem("Sound/title.mp3");
    stageBgm = LoadSoundMem("Sound/stage.mp3");
    clearBgm = LoadSoundMem("Sound/clear.mp3");
    overBgm = LoadSoundMem("Sound/over.mp3");
    // 画像ロード
    titleImage = LoadGraph("Resource/title.png");
    stageImage = LoadGraph("Resource/stage.png");
    clearImage = LoadGraph("Resource/clear.png");
    overImage = LoadGraph("Resource/over.png");
    treasureImage = LoadGraph("Resource/treasure.png");

    animation.BounceImage("Resource/TitleName.png", 270, 100, 0.5f, 0.7f, 200);
    animation.SwayImage("Resource/Icon.png", 100, 500, 1.0f, 0.05f);
    animation.NormalImage("Resource/GameStart.png", 260, 500);

    PlaySceneBGM(scene);
}

// シーンの更新処理
void GameScene::Update(char* keys, char* oldkeys) {
    // フェードアウト中の場合
    if (isFadingOut) {
        if (fadeOut.Update()) {
            scene = nextScene;
            isFadingOut = false;
            fadeOut.Reset();
            PlaySceneBGM(scene);
        }
        return;  // フェードアウト中は他の処理をしない
    }

    switch (scene) {
        // タイトル (Scene 0)
    case 0:
        animation.update();
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            StartFadeOut(1);
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

        if (keys[KEY_INPUT_C] == 1 && oldkeys[KEY_INPUT_C] == 0) {
            StartFadeOut(2);
        }

        Collision();
        Delete();
        break;

        // クリア (Scene 2)
    case 2:
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            StartFadeOut(3);
        }
        break;

        // オーバー (Scene 3)
    case 3:
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            StartFadeOut(0);
        }
        break;
    }
}

// シーンの描画処理
void GameScene::Draw() {
    switch (scene) {
        // タイトル (Scene 0)
    case 0:
        DrawGraph(0, 0, titleImage, TRUE);
        animation.draw();
        break;

    case 1:
        DrawGraph(0, 0, stageImage, TRUE);
        player->Draw();
        treasure->Draw();
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

    // フェードアウト中であればフェードアウトを描画
    if (isFadingOut) {
        fadeOut.Draw();
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
    PlayerSoilCollision();
    DigSoilCollision();
}

void GameScene::PlayerSoilCollision()
{
    for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end(); ++terrainitr) {
        if (Collision::SquareToSquare(player->GetPlayerLeftX(), player->GetPlayerUpY(),
            player->GetPlayerRightX(), player->GetPlayerDownY(),
            (*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(),
            (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY())) {

            if (Collision::LineToSquare((*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetLeftX(), (*terrainitr)->GetDownY(),
                (*terrainitr)->GetRightX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY(),
                player->GetPlayerLeftX(), player->GetPlayerDownY(), player->GetPlayerRightX(), player->GetPlayerDownY())) {
                player->SetTrueHitDown();
            }
            if (Collision::LineToSquare((*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetLeftX(), (*terrainitr)->GetDownY(),
                (*terrainitr)->GetRightX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY(),
                player->GetPlayerLeftX(), player->GetPlayerDownY(), player->GetPlayerLeftX(), player->GetPlayerUpY())) {
                player->SetTrueHitLeft();
            }
            if (Collision::LineToSquare((*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetLeftX(), (*terrainitr)->GetDownY(),
                (*terrainitr)->GetRightX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY(),
                player->GetPlayerRightX(), player->GetPlayerDownY(), player->GetPlayerRightX(), player->GetPlayerUpY())) {
                player->SetTrueHitRight();
            }
            if (Collision::LineToSquare((*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetLeftX(), (*terrainitr)->GetDownY(),
                (*terrainitr)->GetRightX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY(),
                player->GetPlayerRightX(), player->GetPlayerUpY(), player->GetPlayerLeftX(), player->GetPlayerUpY())) {
                player->SetTrueHitUp();
            }


            break;
        }
        if (Collision::SquareToSquare(player->GetPlayerLeftX(), player->GetPlayerUpY(),
            player->GetPlayerRightX(), player->GetPlayerDownY(),
            (*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(),
            (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY()) == false) {

            player->SetFailHitLeft();
            player->SetFailHitRight();
            player->SetFailHitUp();
            player->SetFailHitDown();
        }
    }
}

void GameScene::DigSoilCollision()
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

// フェードアウトを開始する
void GameScene::StartFadeOut(int targetScene) {
    isFadingOut = true;
    nextScene = targetScene;
}

// シーンに応じたBGMを再生する
void GameScene::PlaySceneBGM(int currentScene) {
    StopSoundMem(titleBgm);
    StopSoundMem(stageBgm);
    StopSoundMem(clearBgm);
    StopSoundMem(overBgm);

    switch (currentScene) {
    case 0:
        PlaySoundMem(titleBgm, DX_PLAYTYPE_LOOP);
        break;
    case 1:
        PlaySoundMem(stageBgm, DX_PLAYTYPE_LOOP);
        break;
    case 2:
        PlaySoundMem(clearBgm, DX_PLAYTYPE_BACK);
        break;
    case 3:
        PlaySoundMem(overBgm, DX_PLAYTYPE_BACK);
        break;
    }
}
