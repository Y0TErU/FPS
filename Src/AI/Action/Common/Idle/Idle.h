#pragma once

#include "../../ActionBase/ActionBase.h"

class ActionIdle : public ActionBase
{
public:
	State Update(BlackBoard&) override
	{
		return State::Complete;
	}
};