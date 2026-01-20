#include "GameScene.h"

#include <Dxlib.h>

#include "../../Manager/InputManager/InputManager.h"

#include "../../Object/Player/Player.h"
#include "../../Object/Transform/Tramsform.h"

// ‰¼“®ìŠm”F—p
Transform transform;

Player player{ VGet(0.0f,0.0f,0.0f),VGet(0.0f,0.0f,0.0f) };

SceneBase::Type GameScene::GetType()
{
	return Type::Game;
}

void GameScene::Draw()
{
	if (currentStep != Step::Execute) return;
	ClearDrawScreen();




	ScreenFlip();
}

void GameScene::EntryLoadFiles()
{

}

void GameScene::Init()
{
	camera.SetMode(Camera::CameraMode::FPS);
	camera.SetTarget(&player.GetTransform());

	currentStep = Step::Execute;
}

void GameScene::Execute()
{
	camera.Update();
	player.Update();


	camera.Apply();

	if (InputManager::GetInstance()->IsKeyPushed(KEY_INPUT_Q))
	{
		currentStep = Step::Finish;
	}
}

SceneBase::Type GameScene::Finish()
{

	return Type::Game;
}