#include "GameScene.h"

SceneBase::Type GameScene::GetType()
{
	return Type::Game;
}

void GameScene::Draw()
{
	if (currentStep != Step::Execute) return;


}

void GameScene::EntryLoadFiles()
{

}

void GameScene::Init()
{
	

	currentStep = Step::Execute;
}

void GameScene::Execute()
{


	currentStep = Step::Finish;
}

SceneBase::Type GameScene::Finish()
{

	return Type::Game;
}