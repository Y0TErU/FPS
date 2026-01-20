#include "ScreenManager.h"

bool ScreenManager::Initialize()
{
	SetWindowMode(ScreenManager::WindowMode::FullScreen);	// 初期設定でフルスクリーンへ
	SetGraphMode(window_size_width, window_size_height, color_bit);

	SetDrawScreen(DX_SCREEN_BACK);
	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);
	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return false;			// エラーが起きたら直ちに終了
	}
	return true;
}

void ScreenManager::SetWindowMode(ScreenManager::WindowMode mode_)
{
	if (mode_ == ScreenManager::WindowMode::Window)
	{
		ChangeWindowMode(false);
	}
	else
	{
		ChangeWindowMode(true);
	}
}

void ScreenManager::GetScreenCenter(int* x_, int* y_)
{
	int screen_width;
	int screen_height;
	int color_bit;

	GetScreenState(&screen_width, &screen_height, &color_bit);

	*x_ = screen_width / 2;
	*y_ = screen_height / 2;
}