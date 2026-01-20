#pragma once

#include <Dxlib.h>

class ScreenManager
{
public:
	static ScreenManager* GetInstance()
	{
		static ScreenManager instance;
		return &instance;
	}

	ScreenManager() = default;
	~ScreenManager()
	{
	}

	ScreenManager(const ScreenManager&) = delete;
	ScreenManager& operator = (const ScreenManager&) = delete;

public:
	// windowモード
	enum WindowMode
	{
		FullScreen,
		Window
	};

	bool Initialize();		// 設定の初期化
	void SetWindowMode(WindowMode mode_ );	// ウィンドウモードの変更

	// スクリーンの中心の座標を取得
	void GetScreenCenter(int* x_, int* y_);

private:
	// ウィンドウモードの時の画面サイズ
	const int window_size_width{ 1200 };
	const int window_size_height{ 900 };
	const int color_bit{ 32 };

};