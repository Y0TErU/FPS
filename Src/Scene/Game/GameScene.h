#pragma once

#include "../SceneBase/SceneBase.h"
#include "../../System/Camera/Camera.h"

class GameScene : public SceneBase
{
public:
	GameScene(int handle_) :
		SceneBase(handle_)
	{
	}

	~GameScene() override
	{
	}

	void Draw() override;
	Type GetType() override;

private:
	void EntryLoadFiles() override;
	void Init() override;
	void Execute() override;
	Type Finish() override;

private:
	Camera camera;

};