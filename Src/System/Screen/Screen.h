#pragma once

#include <Dxlib.h>

class Screen
{
public:
	// windowモード
	enum WindowMode
	{
		FullScreen,
		Window
	};

	bool Initialize();		// 設定の初期化
	void SetWindowMode(WindowMode mode_ );	// ウィンドウモードの変更


private:
	// ウィンドウモードの時の画面サイズ
	const int window_size_width{ 1200 };
	const int window_size_height{ 900 };
	const int color_bit{ 32 };

};