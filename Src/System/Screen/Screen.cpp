#include "Screen.h"

bool Screen::Initialize()
{
	SetWindowMode(Screen::WindowMode::FullScreen);	// 初期設定でフルスクリーンへ
	SetGraphMode(window_size_width, window_size_height, color_bit);

	SetDrawScreen(DX_SCREEN_BACK);
	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);
	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	return true;
}

void Screen::SetWindowMode(Screen::WindowMode mode_)
{
	if (mode_ == Screen::WindowMode::Window)
	{
		ChangeWindowMode(false);
	}
	else
	{
		ChangeWindowMode(true);
	}
}