#include "TransformManager.h"

#include <cmath>

VECTOR TransformManager::GetForward(std::shared_ptr<Transform> transform_)
{
	// 正面ベクトルの作成
	VECTOR forward;

	forward.x = cosf(transform_->rotation.y);
	forward.y = 0.0f;
	forward.z = sinf(transform_->rotation.y);

	return forward;

}

void TransformManager::TransformPosition(std::shared_ptr<Transform> transform_, const VECTOR& delta_)
{
	// positionの移動
	transform_->position = VAdd(transform_->position, delta_);
}

void TransformManager::RotationDirection(std::shared_ptr<Transform> transform_, const float yaw_, const float pitch_)
{
	// rotationの更新(幅で更新)
	transform_->rotation.y += yaw_;     // 左右
	transform_->rotation.x += pitch_;   // 上下

}

void TransformManager::RotationDirection(std::shared_ptr<Transform> transform_, const std::shared_ptr<Transform> target_)
{
	// rotationの更新(ターゲットで更新)
	VECTOR direction = VSub(target_->position, transform_->position);

	float length = sqrtf(direction.x * direction.x + direction.y * direction.y);
	if (length == 0.0f)
	{
		// 同じ位置なら更新不要
		return;
	}

	direction.x /= length;
	direction.y /= length;
	direction.z /= length;

	transform_->rotation.y = atan2f(direction.z, direction.x);
	transform_->rotation.x = -asinf(direction.y);

}