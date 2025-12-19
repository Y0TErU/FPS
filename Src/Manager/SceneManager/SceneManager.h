#pragma once

#include "../../Scene/SceneBase/SceneBase.h"
#include "../../Factory/SceneFactory/SceneFactory.h"

class SceneManager
{
public:
	SceneManager(SceneBase::Type first_type_) :
		currentScene(nullptr)
	{

		currentScene = SceneFactory::CreateScene(first_type_, loadingHandle);
	}

	void Main();

private:
	SceneBase* currentScene{ nullptr };
	int loadingHandle{ -1 };				// ロード画面用ハンドル

};