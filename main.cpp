#include "DxLib.h"
#include "GameScene.h"

const char TITLE[] = "4047_�U�O�U�O";
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 980;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
    // �E�B���h�E���[�h�ɐݒ�
    ChangeWindowMode(TRUE);

    // �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
    SetWindowSizeChangeEnableFlag(FALSE, FALSE);

    // �^�C�g����ݒ�
    SetMainWindowText(TITLE);

    // ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�
    SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

    // ��ʃT�C�Y��ݒ�
    SetWindowSizeExtendRate(1.0);

    // �w�i�F��ݒ�
    SetBackgroundColor(0x00, 0x00, 0x00);

    // DXlib�̏�����
    if (DxLib_Init() == -1) { return -1; }

    // �_�u���o�b�t�@
    SetDrawScreen(DX_SCREEN_BACK);

    // �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���

    // �Q�[���V�[���Ǘ��N���X�̃C���X�^���X�쐬
    GameScene gameScene;

    // �ŐV�̃L�[�{�[�h���p
    char keys[256] = { 0 };
    // 1�t���[���O�̃L�[�{�[�h���
    char oldkeys[256] = { 0 };

    // �Q�[�����[�v
    while (true) {
        // �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
        memcpy(oldkeys, keys, sizeof(keys));
        // �ŐV�̃L�[�{�[�h�����擾
        GetHitKeyStateAll(keys);

        // ��ʃN���A
        ClearDrawScreen();

        // �V�[���̍X�V
        gameScene.Update(keys, oldkeys);

        // �V�[���̕`��
        gameScene.Draw();

        // ����ʂ�\��ʂɔ��f
        ScreenFlip();

        // 20�~���b�ҋ@(�^��60FPS)
        WaitTimer(20);

        // Windows�V�X�e�����炭�������������
        if (ProcessMessage() == -1) {
            break;
        }

        // ESC�L�[�������ꂽ�烋�[�v���甲����
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
            break;
        }
    }

    // Dx���C�u�����I������
    DxLib_End();

    // ����I��
    return 0;
}
