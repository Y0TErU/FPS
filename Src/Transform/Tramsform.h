#pragma once

#include <Dxlib.h>

// 3D空間座標系トランスフォーム
struct Transform
{
	VECTOR position = VGet(0.0f, 0.0f, 0.0f);			// 座標
	VECTOR rotation = VGet(0.0f, 0.0f, 0.0f);			// 角度(radian)
	VECTOR scale = VGet(1.0f, 1.0f, 1.0f);				// 拡大率

	// 前方向ベクトルを取得
	VECTOR GetForward() const
	{
		VECTOR forward;

		forward.x = cosf(rotation.y);
		forward.y = 0.0f;
		forward.z = sinf(rotation.y);

		return VNorm(forward);
		
	}


};