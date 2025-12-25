#pragma once

class InputManager
{
	static InputManager* GetInstance()
	{
		static InputManager instance;
		return &instance;
	}

	InputManager() = default;
	~InputManager()
	{
	}

	InputManager(const InputManager&) = delete;
	InputManager& operator = (const InputManager&) = delete;

public:


};