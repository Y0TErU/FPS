#pragma once

class ObjectManager
{
public:
	static ObjectManager* GetInstance()
	{
		static ObjectManager instance;
		return &instance;
	}

	ObjectManager() = default;
	~ObjectManager()
	{
	}

	ObjectManager(const ObjectManager&) = delete;
	ObjectManager& operator = (const ObjectManager&) = delete;

public:



};