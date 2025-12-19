#include "CoolTime.h"

#include <Dxlib.h>

void CoolTime::Set(float time_)
{
	coolTimeMs = static_cast<int>(time_ * 1000.0f);
}

bool CoolTime::IsReady() const
{
	return (GetNowCount() - lastUseTime) >= coolTimeMs;
}

void CoolTime::Use()
{
	lastUseTime = GetNowCount();
}

float CoolTime::GetRemain() const
{
	int remain = coolTimeMs - (GetNowCount() - lastUseTime);
	return (remain > 0) ? remain / 1000.0f : 0.0f;
}

