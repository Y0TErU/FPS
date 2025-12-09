#pragma once

#include "../../../Base/ObjectBase/ObjectBase.h"

class Gun : public ObjectBase
{
public:
	Gun() :
		ObjectBase("Gun")
	{
	}

public:
	void Update() override;
	void Draw() override;

};