#pragma once

#include <Dxlib.h>

#include "../../Transform/Tramsform.h"

class Camera
{
public:
	void SetTarget(const Transform* target_);
	void Update();
	void Apply();		// DxLibのカメラ設定関係

private:
	const Transform* target = nullptr;	//	カメラが追従するトランスフォーム
	VECTOR offset{};	// カメラを所持しているオブジェクトのトランスフォーム座標からのオフセット
	float pitch = 0.0f;   // 上下視点
	float yaw = 0.0f;   // 左右視点

};