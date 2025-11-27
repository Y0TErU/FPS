#pragma once

class ObjectBase
{
public:
	ObjectBase()
	{

	}

	virtual ~ObjectBase()
	{
	}

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;

public:


};