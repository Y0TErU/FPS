#pragma once

#include "../../Base/SceneBase/SceneBase.h"

class TitleScene : public SceneBase
{
public:
	TitleScene(int handle_) :
		SceneBase(handle_)
	{
	}

	~TitleScene() override
	{
	}

	void Draw() override;
	Type GetType() override;

private:
	void EntryLoadFiles() override;
	void Init() override;
	void Execute() override;
	Type Finish() override;


};