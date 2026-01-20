#pragma once

#include "../ObjectBase/ObjectBase.h"
#include "../Transform/Tramsform.h"
#include "../Status/Status.h"

class Player : public ObjectBase
{
public:
	/*
		ステータス(初期値)
			name:Player
			HP:1000
			speed:15
			attack:20
			defence:10
	*/
	Player(VECTOR position_,VECTOR rotation_) :
		ObjectBase("Player")
	{
		SetIsActive(true);
		transform.SetPosition(position_);
		transform.SetRotation(rotation_);
		status.max_hp = 1000.0f;
		status.current_hp = status.max_hp;
		status.move_speed = 15.0f;
		status.attack = 20.0f;
		status.defence = 10.0f;
	}

public:
	void Update() override;
	void Draw() override;

public:
	// トランスフォームのゲッター
	const Transform& GetTransform() const
	{
		return transform;
	}

	// トランスフォームのアクセサー
	Transform& AccessTransform()
	{
		return transform;
	}

	// ステータスのゲッター
	const Status& GetStatus() const
	{
		return status;
	}

	// ステータスのアクセサー
	Status& AccessStatus()
	{
		return status;
	}

private:
	Transform transform{};
	Status status{};

};