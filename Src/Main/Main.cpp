#include <Dxlib.h>

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(800, 600, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// カメラの設定
	SetCameraPositionAndTargetAndUpVec(
		VGet(20.0f, 10.0f, 50.0f),	// カメラの座標
		VGet(0.0f, 5.0f, 0.0f),		// 注視点
		VGet(0.0f, 1.0f, 0.0f)		// (0.0f, 1.0f, 0.0f)固定
	);

	// カメラの描画範囲
	SetCameraNearFar(
		1.0f,		// 描画範囲の最短距離(最小は1.0fでそれ未満は描画が壊れる可能性あり)
		1000.0f		// 描画範囲の最長距離
	);


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		

	}

	InitGraph();
	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}