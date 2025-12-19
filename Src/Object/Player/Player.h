#pragma once

#include "../ObjectBase/ObjectBase.h"

class Player : public ObjectBase
{
public:
	Player(VECTOR position_,VECTOR direction_,VECTOR rotation_) :
		ObjectBase("Player")
	{
	}

public:
	void Update() override;
	void Draw() override;

private:



};