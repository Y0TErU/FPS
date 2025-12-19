#include "SceneBase.h"

#include <Dxlib.h>

SceneBase::Type SceneBase::Main()
{
	switch (currentStep)
	{
	case Step::Load:
		if (isLoadFileRegistered == false)
		{
			isLoadFileRegistered = true;
		}
		else
		{
			Loading();
		}
		break;
	case Step::Init:
		Init();
		break;
	case Step::Execute:
		Execute();
		break;
	case Step::Finish:
		return Finish();
		break;
	}
			
	// 描画処理
	ClearDrawScreen();

	if (currentStep == Step::Execute)
	{
		Draw();
	}
	else if (currentStep == Step::Load)
	{
		DrawLoading();
	}

	ScreenFlip();

	return GetType();

}

void SceneBase::Loading()
{
	loadAnimCounter++;
	debugCounter++;
	// シーンのロードが完了かつローディング最低時間を経過していたら
	if (GetASyncLoadNum() == 0 &&
		debugCounter > loading_min_time)
	{
		currentStep = Step::Init;
	}
}

void SceneBase::DrawLoading()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, loadAnimCounter * 2 % 255);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}