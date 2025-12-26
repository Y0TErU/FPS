#include <Dxlib.h>

#include "../Controller/FrameController/FrameController.h"
#include "../System/Screen/Screen.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Vsyncの停止
	FrameController::StopVSync();

	Screen screen;

	if (!screen.Initialize())
	{
		return false;
	}

	FrameController frame_controller;

	//// カメラの設定
	//SetCameraPositionAndTargetAndUpVec(
	//	VGet(5.0f, 5.0f, 0.0f),	// カメラの座標
	//	VGet(0.0f, 0.0f, 0.0f),		// 注視点
	//	VGet(0.0f, 1.0f, 0.0f)		// (0.0f, 1.0f, 0.0f)固定
	//);

	//// カメラの描画範囲
	//SetCameraNearFar(
	//	1.0f,		// 描画範囲の最短距離(最小は1.0fでそれ未満は描画が壊れる可能性あり)
	//	1000.0f		// 描画範囲の最長距離
	//);

	

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		frame_controller.StartFrame();
		

		frame_controller.DebugDrawFPSCountUI();
		frame_controller.EndFrame();

		
		ScreenFlip();
	}

	InitGraph();
	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}