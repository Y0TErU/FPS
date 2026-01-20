#pragma once

#include <Dxlib.h>

#include "../../Object/Transform/Tramsform.h"

class Camera
{
public:
	enum CameraMode	// カメラモード
	{
		Fixed,		// 固定カメラモード
		FPS,		// 一人称カメラモード
		TPS,		// 三人称カメラモード(念のため用意)
	};

	void SetTarget(const Transform* target_);		// カメラが追従するTransformを取得
	void SetMode(CameraMode mode_);					// カメラモードの設定
	void Update();		// カメラの更新
	void Apply();		// DxLibに結果の適用

private:
	void UpdateFPSCamera();		// FPSカメラの更新
	void UpdateTPSCamera();		// TPSカメラの更新
	void UpdateFixedCamera();	// 固定カメラの更新

	void ApplyFPSCamera();		// FPSカメラの適用
	void ApplyTPSCamera();		// TPSカメラの適用
	void ApplyFixedCamera();	// 固定カメラの適用

private:
	CameraMode current_mode{ Fixed };		// 現状のカメラモード
	const Transform* target{ nullptr };		// カメラが追従するトランスフォーム
	VECTOR offset{ VGet(0.0f,0.0f,0.0f) };	// カメラを所持しているオブジェクトのトランスフォーム座標からのオフセット
	float pitch{ 0.0f };			// 上下視点
	float yaw{ 0.0f };			// 左右視点
	const float sensitivity{ 0.002f };

	// ピッチ制限(上下90°)
	const float limit{ DX_PI_F / 2.0f - 0.01f };

};