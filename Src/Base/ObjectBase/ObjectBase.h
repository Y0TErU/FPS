#pragma once

#include <Dxlib.h>
#include <string>

class ObjectBase
{
public:
	virtual ~ObjectBase() = default;
	ObjectBase(std::string tag_)
	{
		tag = tag_;
		isActive = true;
	}

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;

public:
	bool GetIsActive()
	{
		return isActive;
	}
	std::string GetTag()
	{
		return tag;
	}

protected:
	VECTOR positioin{};
	VECTOR direction{};
	VECTOR scale{};
	VECTOR rotation{};
	std::string tag{};

	bool isActive{ false };

};