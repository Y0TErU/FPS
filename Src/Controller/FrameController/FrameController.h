#pragma once

#include <Dxlib.h>

class FrameController
{
public:
	// VSyncを取りやめ
	static void StopVSync()
	{
		SetWaitVSyncFlag(false);
	}

public:
	// フレームレート設定
	void SetFPS(const int& fps_)
	{
		FPS = fps_;
	}

	// フレームの時間計測開始
	void StartFrame();
	// フレーム終了
	void EndFrame();
	// 実測デルタタイムを取得
	double GetDeltaTime() const { return deltaTime; }

	// デバッグ用FPS表示
	void DebugDrawFPSCountUI();

private:
	int FPS{ 60 };	// フレームレート(初期値は60)
	int TargetFrameTimeMs = 1000 / FPS;

	int startFrameTime{ 0 };	// フレーム開始時間(ms)
	int currentTime{ 0 };		// 現在時間(ms)

	double deltaTime{ 0.0 };	// 実測デルタタイム(s)

	// FPS計測
	int prevFPSTime{ 0 };		// 前回FPS更新時間
	int frameCounter{ 0 };		// 1秒間のフレーム数カウント
	int fpsFrameCount{ 0 };		// 表示用FPS(デバッグ用)

};