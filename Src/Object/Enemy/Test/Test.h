#pragma once

#include "../EnemyBase/EnemyBase.h"

// テスト用Enemy
class Test : public EnemyBase
{
	/*
		ステータス
			name:Test
			HP:100
			speed:10
			attack:10
			defence:10
	*/
	Test(BehaviorTree* ai_tree_,Transform transform_)

};