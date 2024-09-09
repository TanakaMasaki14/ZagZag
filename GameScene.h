#ifndef GAME_SCENE_H
#define GAME_SCENE_H

// �Q�[���V�[�����Ǘ�����N���X
class GameScene {
public:
    // �R���X�g���N�^
    GameScene();

    // �V�[���̍X�V����
    void Update(char* keys, char* oldkeys);

    // �V�[���̕`�揈��
    void Draw();

private:
    int scene;
    //���y
    int titleBgm;
    int stageBgm;
    int clearBgm;
    int overBgm;
    //int actionBgm;
      //�摜
    int clearImage;
    int overImage;
};

#endif // GAME_SCENE_H
