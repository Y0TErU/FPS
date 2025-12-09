#include "SceneManager.h"

void SceneManager::Main()
{
	SceneBase::Type before = currentScene->GetType();
	SceneBase::Type after = currentScene->Main();

	if (before != after)
	{
		delete(currentScene);

		currentScene = SceneFactory::CreateScene(after, loadingHandle);
	}

}