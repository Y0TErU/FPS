#include "TitleScene.h"
#include <Dxlib.h>

SceneBase::Type TitleScene::GetType()
{
	return Type::Title;
}

void TitleScene::Draw()
{
	if (currentStep != Step::Execute) return;
	ClearDrawScreen();

	
	ScreenFlip();
}

void TitleScene::EntryLoadFiles()
{

}

void TitleScene::Init()
{


	currentStep = Step::Execute;
}

void TitleScene::Execute()
{


	currentStep = Step::Finish;
}

SceneBase::Type TitleScene::Finish()
{


	return Type::Game;
}