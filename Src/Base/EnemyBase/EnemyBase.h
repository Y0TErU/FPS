#pragma once

#include "../ObjectBase/ObjectBase.h"
#include "../../Behavior/BehaviorTree/BehaviorTree.h"
#include "../../BlackBoard/BlackBoard.h"
#include "../../Behavior/BehaviorNode/BehaviorNode.h"

class EnemyBase : public ObjectBase
{
public:
	~EnemyBase() = default;
	EnemyBase(BehaviorTree* behavior_tree_, float max_hp_, float move_speed_, float defence_,
		std::string tag_) :
		behaviorTree{ behavior_tree_ },max_HP{ max_hp_ },move_speed{move_speed_},defence{defence_},
		ObjectBase(tag_)
	{
	}

public:
	// ダメージを受ける処理
	void ReceiveDamage(float damage_);

private:
	// BlackBoard入出力
	void InputBlackBoard();
	void OutputBlackBoard();

	void ShootBullet();		// 弾を撃つ

protected:
	float max_HP{};				// 最大Hp
	float current_HP{};			// 現在のHP
	float move_speed{};			// 移動速度
	float defence{};			// 防御力

protected:
	BehaviorTree* behaviorTree{ nullptr };					// ビヘイビアツリー
	std::shared_ptr<BehaviorNode> currentNode{ nullptr };	// 実行中ノード
	BlackBoard blackBoard{};								// ビヘイビアデータ

};