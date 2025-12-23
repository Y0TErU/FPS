#pragma once

#include <vector>
#include <map>
#include "../Behavior/BehaviorContext/BehaviorContext.h"
#include "../Transform/Tramsform.h"

// Behavior保存でデータ
struct BlackBoard
{
	// Behavior側
	BehaviorContext behaviorContextCmd{};	// Behavior状況

	// Enemyのパラメータ
	Transform transform;

	float current_hp{ 0.0f };		// HP
	float attack{ 0.0f };			// 攻撃力
	float defence{ 0.0f };			// 防御力

	float hp_rate{ 0.0f };		// HP割合

};
