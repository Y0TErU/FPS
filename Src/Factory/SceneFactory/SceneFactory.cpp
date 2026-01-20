#include "SceneFactory.h"

#include "../../Scene/Title/TitleScene.h"
#include "../../Scene/Game/GameScene.h"

SceneBase* SceneFactory::CreateScene(SceneBase::Type type_, int handle_)
{
	SceneBase* new_scene = nullptr;

	switch (type_)
	{
	case SceneBase::Type::Title:
		new_scene = new TitleScene(handle_);
		break;
	case SceneBase::Type::Game:
		new_scene = new GameScene(handle_);
		break;
	}

	return new_scene;
}