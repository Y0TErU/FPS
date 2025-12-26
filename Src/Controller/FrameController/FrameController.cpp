#include "FrameController.h"

#include <string>

void FrameController::StartFrame()
{
	// フレーム開始時間を記録
	// ゲームループ先頭で呼び出し
	startFrameTime = GetNowCount();
	++frameCounter;
}

void FrameController::EndFrame()
{
	// フレーム終了時刻
	currentTime = GetNowCount();

	// このフレームでかかった時間
	int frameTime = currentTime - startFrameTime;

	// 実測デルタタイム(s)
	deltaTime = frameTime / 1000.0f;

	// FPS固定処理
	if (frameTime < TargetFrameTimeMs)
	{
		WaitTimer(TargetFrameTimeMs - frameTime);
	}

	// FPS計測
	if (currentTime - prevFPSTime >= 1000)
	{
		prevFPSTime = currentTime;
		fpsFrameCount = frameCounter;
		frameCounter = 0;
	}
}

void FrameController::DebugDrawFPSCountUI()
{
	DrawString(
		20,
		20,
		std::to_string(fpsFrameCount).c_str(),
		GetColor(0, 0, 0)
	);
}