#pragma once

#include <Dxlib.h>
#include <cmath>

// 3D空間座標系トランスフォーム
struct Transform
{
public:
	// ゲッター
	const VECTOR& GetPosition() const { return position; }	// 座標情報
	const VECTOR& GetRotation() const { return rotation; }	// 向き情報
	// 正面ベクトルの作成
	VECTOR GetForward() const
	{
		VECTOR forward;

		forward.x = cosf(rotation.y);
		forward.y = 0.0f;
		forward.z = sinf(rotation.y);

		// 正規化して値を返す
		return VNorm(forward);

	}

	// positionの移動
	void TranslatePosition(const VECTOR& delta_)
	{
		position = VAdd(position, delta_);
	}

	// rotationの更新
	void RotateDirectioin(float delta_yaw_, float delta_pitch)
	{
		VECTOR rot = rotation;
		rot.y += delta_yaw_;     // 左右
		rot.x += delta_pitch;   // 上下

		SetRotation(rot);
	}

private:
	// 向きの変更
	void SetRotation(const VECTOR& rotatioin_)
	{
		rotation = rotatioin_;
	}

private:
	VECTOR position{ VGet(0.0f, 0.0f, 0.0f) };		// 座標
	VECTOR rotation{ VGet(0.0f, 0.0f, 0.0f) };		// 角度(radian)

};