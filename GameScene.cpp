#include "DxLib.h"
#include "GameScene.h"

GameScene::GameScene() {
    scene = 0;
}

// �V�[���̍X�V����
void GameScene::Update(char* keys, char* oldkeys) {
    switch (scene) {
        // �^�C�g��
    case 0:
        if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
            scene = 1;
        }
        break;

        // �X�e�[�W1
    case 1:
        if (keys[KEY_INPUT_C] == 1 && oldkeys[KEY_INPUT_C] == 0) {
            scene = 2;
        }
        break;

        // �N���A
    case 2:
        if (keys[KEY_INPUT_T] == 1 && oldkeys[KEY_INPUT_T] == 0) {
            scene = 0;
        }
        break;
    }
}

// �V�[���̕`�揈��
void GameScene::Draw() {
    switch (scene) {
        // �^�C�g��
    case 0:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Title");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH SPACE");
        break;

        // �X�e�[�W1
    case 1:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Stage1");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH C");
        break;

        // �N���A
    case 2:
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Clear");
        DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH T");
        break;
    }
}
