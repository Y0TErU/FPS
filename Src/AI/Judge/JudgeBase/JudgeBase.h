#pragma once

#include "../../../Object/BlackBoard/BlackBoard.h"

// ”»’èˆ—Šî’êƒNƒ‰ƒX
class JudgeBase
{
public:
	// ”»’è
	virtual bool IsConditionMet(BlackBoard& black_board_) = 0;
};