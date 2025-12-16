#pragma once

#include "../../../Base/ObjectBase/ObjectBase.h"

class Bullet : public ObjectBase
{
public:
	Bullet(VECTOR position_, VECTOR direction_) :
		ObjectBase("Bullet")
	{
	}

	~Bullet()
	{
	}

public:
	void Update() override;
	void Draw() override;

private:
	float speed{ 1.0f };	// ’e‘¬
	bool isHit{ false };	// ‰½‚©‚É“–‚½‚Á‚½‚©‚Ç‚¤‚©
	

};