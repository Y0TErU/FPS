#pragma once

#include <Dxlib.h>
#include <string>

// Object基底クラス
class ObjectBase
{
public:
	virtual ~ObjectBase() = default;
	ObjectBase(const std::string tag_)
	{
		tag = tag_;
	}

public:
	virtual void Update() = 0;	// 更新
	virtual void Draw() = 0;	// 描画

public:
	bool GetIsActive()
	{
		return isActive;
	}
	std::string GetTag()
	{
		return tag;
	}

public:
	void SetIsActive(bool active_)
	{
		isActive = active_;
	}

protected:
	std::string tag{};			// 自身のタグ
	bool isActive{ false };		// 生存フラグ

};