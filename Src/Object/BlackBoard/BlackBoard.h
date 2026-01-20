#pragma once

#include <vector>
#include <map>
#include "../../Behavior/BehaviorContext/BehaviorContext.h"
#include "../Transform/Tramsform.h"
#include "../Status/Status.h"

// Behavior保存でデータ
struct BlackBoard
{
	// Behavior側
	BehaviorContext behaviorContextCmd{};	// Behavior状況
	// トランスフォームパラメータ
	Transform transform;
	// ステータスパラメータ
	Status status;
};
