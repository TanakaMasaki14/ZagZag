#include "DxLib.h"
#include "GameScene.h"
#include "AnimationManager.h"
#include "Treasure.h"

// �t�F�[�h�A�E�g�p�̃N���X�C���X�^���X�ǉ�
FadeOut fadeOut;
bool isFadingOut = false;  // �t�F�[�h�A�E�g�����ǂ���
int nextScene = -1;        // ���̃V�[���̎w��

GameScene::GameScene() {
    scene = 0;
    player = new Player(300, 100);
    treasure = new Treasure();
    for (int i = 0; i < 39; i++) {
        for (int j = 0; j < 41; j++) {
            terrainlist.push_back(new Soil((float)10 + (float)j * 20, (float)210 + (float)i * 20, true));
        }
    }
    // ���y�̃��[�h
    titleBgm = LoadSoundMem("Sound/title.mp3");
    stageBgm = LoadSoundMem("Sound/stage.mp3");
    clearBgm = LoadSoundMem("Sound/clear.mp3");
    overBgm = LoadSoundMem("Sound/over.mp3");
    // �摜���[�h
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

// �V�[���̍X�V����
void GameScene::Update(char* keys, char* oldkeys) {
    // �t�F�[�h�A�E�g���̏ꍇ
    if (isFadingOut) {
        if (fadeOut.Update()) {
            scene = nextScene;
            isFadingOut = false;
            fadeOut.Reset();
            PlaySceneBGM(scene);
        }
        return;  // �t�F�[�h�A�E�g���͑��̏��������Ȃ�
    }

    switch (scene) {
        // �^�C�g�� (Scene 0)
    case 0:
        animation.update();
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            StartFadeOut(1);
        }
        break;

        // �X�e�[�W1 (Scene 1)
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

        // �N���A (Scene 2)
    case 2:
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            StartFadeOut(3);
        }
        break;

        // �I�[�o�[ (Scene 3)
    case 3:
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            StartFadeOut(0);
        }
        break;
    }
}

// �V�[���̕`�揈��
void GameScene::Draw() {
    switch (scene) {
        // �^�C�g�� (Scene 0)
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

    // �t�F�[�h�A�E�g���ł���΃t�F�[�h�A�E�g��`��
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
            //�@����
            (*terrainitr)->Diged();
        }
    }
}

// �t�F�[�h�A�E�g���J�n����
void GameScene::StartFadeOut(int targetScene) {
    isFadingOut = true;
    nextScene = targetScene;
}

// �V�[���ɉ�����BGM���Đ�����
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
