#include "DxLib.h"
#include <math.h>

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "4047_ZagZag";

// ウィンドウ横幅
const int WIN_WIDTH = 800;

// ウィンドウ縦幅
const int WIN_HEIGHT = 980;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0xA9, 0xCE, 0xEC);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み
	int TitleName = LoadGraph("Resouse/TitleName.png");


	// ゲームループで使う変数の宣言

	// タイトル画像の初期Y座標
	float imagePosY = 100.0f; // 初期位置
	// タイトル画像の速度
	float imageSpeedY = 0.0f; // 初期速度
	// 重力加速度
	const float gravity = 0.5f;
	// 反発係数(1より小さい値にするたびに勢いが弱くなる)
	const float bounceFactor = 0.7f;
	// 地面のY座標
	const int groundY = 200; // ウィンドウの下に地面を設定

	//シーン管理
	int scene = 0;

	// シーンの進行フラグ
	bool spaceKeyPressed = false; // SPACEキーが一度押されたかどうかを判定するフラグ

	// 最新のキーボード情報用
	char keys[256] = {0};

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = {0};

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		switch (scene)
		{
		// タイトル
		case 0:

			// 重力を適用して速度を更新
			imageSpeedY += gravity;
			// 画像のY座標を更新
			imagePosY += imageSpeedY;

			// 地面に衝突した場合
			if (imagePosY >= groundY)
			{
				imagePosY = groundY; // 地面で位置を固定
				imageSpeedY = -imageSpeedY * bounceFactor; // 反発する速度を軽減
				
				// 一定の低速になったら停止(バウンドしない)
				if (fabs(imageSpeedY) < 1.0f)
				{
					imageSpeedY = 0.0f;
				}
			}

			DrawFormatString(100, 100, GetColor(255, 255, 255), "Title");
			DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH SPACE");

			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				scene = 1;
			}
			break;

		// ステージ1
		case 1:
			DrawFormatString(100, 100, GetColor(255, 255, 255), "Stage1");
			DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH C");

			if (keys[KEY_INPUT_C] == 1 && oldkeys[KEY_INPUT_C] == 0) {
				scene = 2;
			}
			break;

		// クリア
		case 2:
			DrawFormatString(100, 100, GetColor(255, 255, 255), "Clear");
			DrawFormatString(100, 150, GetColor(255, 255, 255), "PUSH T");

			if (keys[KEY_INPUT_T] == 1 && oldkeys[KEY_INPUT_T] == 0) {
				scene = 0;
			}
			break;
		}

		// 描画処理
		DrawGraph(270, (int)imagePosY - 100, TitleName, TRUE);

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
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
