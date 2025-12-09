#pragma once

#include "../../Base/SceneBase/SceneBase.h"

class SceneFactory
{
public:
	// ƒV[ƒ“‚Ìì¬
	static SceneBase* CreateScene(SceneBase::Type type_, int handle_);
};