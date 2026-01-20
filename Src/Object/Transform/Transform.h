#pragma once

#include <Dxlib.h>


// 3D空間座標系トランスフォーム
struct Transform
{
	VECTOR position{ VGet(0.0f, 0.0f, 0.0f) };		// 座標
	VECTOR rotation{ VGet(0.0f, 0.0f, 0.0f) };		// 角度(radian)

};