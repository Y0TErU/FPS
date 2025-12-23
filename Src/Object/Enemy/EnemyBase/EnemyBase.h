#pragma once

#include "../../ObjectBase/ObjectBase.h"
#include "../../../Behavior/BehaviorTree/BehaviorTree.h"
#include "../../../BlackBoard/BlackBoard.h"
#include "../../../Behavior/BehaviorNode/BehaviorNode.h"
#include "../../../Transform/Tramsform.h"
#include "../Status/Status.h"

class EnemyBase : public ObjectBase
{
public:
	~EnemyBase() = default;
	EnemyBase(BehaviorTree* behavior_tree_, const std::string name_, float max_hp_, float move_speed_, float attack_, float defence_) :
		behaviorTree{ behavior_tree_ }, name{ name_ },
		ObjectBase("Enemy")
	{
		status.Initialize(max_hp_, move_speed_, attack_, defence_);
	}

public:
	
public:
	std::string GetName()
	{
		return name;
	}

	void SetTransform(const Transform& transform_)
	{
		transform = transform_;
	}

	// トランスフォームのゲッター
	Transform GetTransform() const
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
	// BlackBoard入出力
	void InputBlackBoard();
	void OutputBlackBoard();

private:
	Status status;				// ステータス情報
	Transform transform;		// 3D座標系情報

protected:
	std::string name{ "" };									// 自身の名前(敵の種類)
	BehaviorTree* behaviorTree{ nullptr };					// ビヘイビアツリー
	std::shared_ptr<BehaviorNode> currentNode{ nullptr };	// 実行中ノード
	BlackBoard blackBoard{};								// ビヘイビアデータ

};