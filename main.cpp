#include "DxLib.h"
#include "GameScene.h"

const char TITLE[] = "4047_ザグザグ";
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 980;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
    // ウィンドウモードに設定
    ChangeWindowMode(TRUE);

    // ウィンドウサイズを手動では変更させず、かつウィンドウサイズに合わせて拡大できないようにする
    SetWindowSizeChangeEnableFlag(FALSE, FALSE);

    // タイトルを設定
    SetMainWindowText(TITLE);

    // 画面サイズの最大サイズ、カラービット数を設定
    SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

    // 画面サイズを設定
    SetWindowSizeExtendRate(1.0);

    // 背景色を設定
    SetBackgroundColor(0x00, 0x00, 0x00);

    // DXlibの初期化
    if (DxLib_Init() == -1) { return -1; }

    // ダブルバッファ
    SetDrawScreen(DX_SCREEN_BACK);

    // 画像などのリソースデータの変数宣言と読み込み

    // ゲームシーン管理クラスのインスタンス作成
    GameScene gameScene;

    // 最新のキーボード情報用
    char keys[256] = { 0 };
    // 1フレーム前のキーボード情報
    char oldkeys[256] = { 0 };

    // ゲームループ
    while (true) {
        // 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
        memcpy(oldkeys, keys, sizeof(keys));
        // 最新のキーボード情報を取得
        GetHitKeyStateAll(keys);

        // 画面クリア
        ClearDrawScreen();

        // シーンの更新
        gameScene.Update(keys, oldkeys);

        // シーンの描画
        gameScene.Draw();

        // 裏画面を表画面に反映
        ScreenFlip();

        // 20ミリ秒待機(疑似60FPS)
        WaitTimer(20);

        // Windowsシステムからくる情報を処理する
        if (ProcessMessage() == -1) {
            break;
        }

        // ESCキーが押されたらループから抜ける
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
            break;
        }
    }

    // Dxライブラリ終了処理
    DxLib_End();

    // 正常終了
    return 0;
}
