#include <Dxlib.h>
#include "InputManager.h"

void InputManager::SetDisplayMouseCursol(bool set_)
{
	SetMouseDispFlag(set_);
}

bool InputManager::IsKeyCheck(int key_)
{
	if (key_ >= 0 && key_ < 256)
	{
		return true;
	}
	return false;
}

void InputManager::InitInput()
{
	// キー入力の情報を全て0クリア
	ZeroMemory(currentKeyBuffer, sizeof(char) * 256);
	ZeroMemory(prevKeyBuffer, sizeof(char) * 256);

	// マウスの座標を0クリア
	mousePosX = 0;
	mousePosY = 0;
}

void InputManager::UpdateInput()
{
	//前フレームのキーの入力情報を保存
	memcpy(prevKeyBuffer, currentKeyBuffer, sizeof(char) * 256);
	GetHitKeyStateAll(currentKeyBuffer);

	// マウス座標取得
	prevMouseX = mousePosX;
	prevMouseY = mousePosY;

	GetMousePoint(&mousePosX, &mousePosY);

	mouseDeltaX = mousePosX - prevMouseX;
	mouseDeltaY = mousePosY - prevMouseY;

	GetHitKeyStateAll(currentKeyBuffer);
	GetMouseInputLog2(&clickButton, &mousePosX, &mousePosY, &clickType);

}

bool InputManager::IsMouseClick(int button_)
{
	if (clickButton == button_ &&
		clickType == MOUSE_INPUT_LOG_DOWN)
	{
		return true;
	}
	return false;
}

bool InputManager::IsKeyPress(int key_)
{
	if (IsKeyCheck(key_) == false)
	{
		return false;
	}

	if (prevKeyBuffer[key_] == 1 &&
		currentKeyBuffer[key_] == 1)
	{
		return true;
	}

	return false;
}

bool InputManager::IsKeyPushed(int key_)
{
	if (IsKeyCheck(key_) == false)
	{
		return false;
	}

	if (prevKeyBuffer[key_] == 0 &&
		currentKeyBuffer[key_] == 1)
	{
		return true;
	}

	return false;

}

bool InputManager::IsKeyReleased(int key_)
{
	if (IsKeyCheck(key_) == false)
	{
		return false;
	}
	if (prevKeyBuffer[key_] == 1 &&
		currentKeyBuffer[key_] == 0)
	{
		return true;
	}

	return false;
}