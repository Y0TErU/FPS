#include "Camera.h"

#include <cmath>

#include "../../Manager/InputManager/InputManager.h"

void Camera::SetTarget(const Transform* target_)
{
	if (target) return;

	target = target_;

}

void Camera::SetMode(Camera::CameraMode mode_)
{
	current_mode = mode_;
}

void Camera::Update()
{
	if (!target) return;
	switch (current_mode)
	{
	case CameraMode::Fixed:
		UpdateFixedCamera();
		break;
	case CameraMode::FPS:
		UpdateFPSCamera();
		break;
	case CameraMode::TPS:
		UpdateTPSCamera();
		break;
	}
}

void Camera::Apply()
{
	if (!target) return;
	switch (current_mode)
	{
	case CameraMode::Fixed:
		UpdateFixedCamera();
		break;
	case CameraMode::FPS:
		UpdateFPSCamera();
		break;
	case CameraMode::TPS:
		UpdateTPSCamera();
		break;
	}
}

void Camera::UpdateFPSCamera()
{
	// 左右回転
	yaw += InputManager::GetInstance()->GetMouseDeltaX();
	// 上下回転
	pitch -= InputManager::GetInstance()->GetMouseDeltaY();

	if (pitch > limit)
	{
		pitch = limit;
	}
	if (pitch < limit)
	{
		pitch = -limit;
	}

}

void Camera::UpdateTPSCamera()
{

}

void Camera::UpdateFixedCamera()
{

}

void Camera::ApplyFPSCamera()
{
	// プレイヤーの位置
	const VECTOR& target_pos = target->GetPosition();

	// カメラ位置(オフセット反映)
	VECTOR camera_pos = VAdd(target_pos, offset);

	// 視線方向ベクトル
	VECTOR forward;
	forward.x = cosf(pitch) * sinf(yaw);
	forward.y = sinf(pitch);
	forward.z = cosf(pitch) * cosf(yaw);
	// 正規化
	forward = VNorm(forward);

	// 注視点
	VECTOR lookAt = VAdd(camera_pos, forward);

	// DxLib に反映
	SetCameraPositionAndTarget_UpVecY(
		camera_pos,
		lookAt
	);

	// マウス座標を中央に戻す
	SetMousePoint(640, 360);
}

void Camera::ApplyTPSCamera()
{

}

void Camera::ApplyFixedCamera()
{

}

