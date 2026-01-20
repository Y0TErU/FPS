#pragma once

#include <memory>
#include "../../Object/Transform/Transform.h"

class TransformManager
{
public:
	static TransformManager* GetInstance()
	{
		static TransformManager instance;
		return &instance;
	}

	TransformManager() = default;
	~TransformManager()
	{
	}

	TransformManager(const TransformManager&) = delete;
	TransformManager& operator = (const TransformManager&) = delete;

public:
	// 正面ベクトルの作成
	VECTOR GetForward(std::shared_ptr<Transform> transform_);
	// positionの移動
	void TransformPosition(std::shared_ptr<Transform> transform_,const VECTOR& delta_);
	// rotationの更新(幅で更新)
	void RotationDirection(std::shared_ptr<Transform> transform_, const float yaw_, const float pitch_);
	// rotationの更新(ターゲットで更新)
	void RotationDirection(std::shared_ptr<Transform> transform_, const std::shared_ptr<Transform> target_);

};