#include "Time.h"

void Time::Start()
{
	if (isStarted) return;

	start_count = GetNowCount();
	isStarted = true;
	haveLimit = false;
}

void Time::Start(float time_)
{
	if (isStarted) return;

	start_count = GetNowCount();
	limit_time = static_cast<int>(time_ * 1000.0f);

	isStarted = true;
	haveLimit = true;
}

bool Time::Update()
{
	if (!isStarted || !haveLimit) return false;

	if (haveLimit == true)
	{
		int now_count = GetNowCount();
		if (now_count - start_count >= limit_time)
		{
			return true;
		}
	}

	return false;
}

void Time::Stop()
{
	isStarted = false;
	haveLimit = false;
	start_count = 0;
	limit_time = 0;
}

float Time::GetElapsedTime() const
{
	if (isStarted == false)
	{
		// もしタイマーが開始されていなかったら0.0秒を返す
		return 0.0f;
	}
	int now_count = GetNowCount();
	float elapsedTime = 0.0f;
	
	elapsedTime = static_cast<float>(now_count - start_count);
	elapsedTime /= 1000.0f;

	return elapsedTime;

}

bool Time::IsRunning() const
{
	return isStarted;
}
