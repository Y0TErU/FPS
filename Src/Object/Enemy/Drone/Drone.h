#pragma once

#include "../EnemyBase/EnemyBase.h"

class Drone : public EnemyBase
{
public:
	/*
		ステータス
			name:Drone
			HP:100
			speed:20
			attack:20
			defence:5
	*/
	Drone(BehaviorTree* ai_tree_, Transform transform_):
		EnemyBase(ai_tree_, transform_,"Drone", 100.0f, 20.0f, 20.0f, 5.0f)
	{
		SetIsActive(true);
	}

	~Drone()
	{
	}

public:
	void Update() override;
	void Draw() override;

private:


};