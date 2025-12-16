#pragma once

#include <Dxlib.h>
#include <string>

// Object基底クラス
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

protected:
	VECTOR positioin{};			// 座標
	VECTOR direction{};			// 向き
	VECTOR scale{};				// 拡大率
	VECTOR rotation{};			// 三軸角度
	std::string tag{};			// 自身のタグ

	bool isActive{ false };		// 生存フラグ

};