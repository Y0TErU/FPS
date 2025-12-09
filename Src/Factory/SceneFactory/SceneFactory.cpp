#include "SceneFactory.h"

#include "../../Scene/Title/TitleScene.h"

SceneBase* SceneFactory::CreateScene(SceneBase::Type type_, int handle_)
{
	SceneBase* new_scene = nullptr;

	switch (type_)
	{
	case SceneBase::Type::Title:
		new_scene = new TitleScene(handle_);
		break;


	}

	return new_scene;
}