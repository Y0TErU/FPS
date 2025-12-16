#pragma once

#include "../ObjectBase/ObjectBase.h"
#include "../../Behavior/BehaviorTree/BehaviorTree.h"
#include "../../BlackBoard/BlackBoard.h"
#include "../../Behavior/BehaviorNode/BehaviorNode.h"

class EnemyBase : public ObjectBase
{
public:
	~EnemyBase() = default;
	EnemyBase(BehaviorTree* behavior_tree_, float max_hp_, float move_speed_, float attack_, float defence_,
		std::string tag_) :
		behaviorTree{ behavior_tree_ }, max_hp{ max_hp_ }, move_speed{ move_speed_ }, attack{ attack }, defence{ defence_ },
		ObjectBase(tag_)
	{
		current_hp = max_hp;
		OnePercentTotalHp();
	}

public:
	// ダメージを受ける処理
	void ReceiveDamage(float damage_);

private:
	void ShootBullet();		// 弾を撃つ
	void OnePercentTotalHp()	// 最大HPの1%を計算
	{
		one_percent_of_total_hp = 100.0f / max_hp;
	}

private:
	// BlackBoard入出力
	void InputBlackBoard();
	void OutputBlackBoard();
	

protected:
	float max_hp{};				// 最大Hp
	float current_hp{};			// 現在のHP
	float move_speed{};			// 移動速度
	float attack{};				// 攻撃力
	float defence{};			// 防御力

	float one_percent_of_total_hp{};	// 最大HPの1%の値

protected:
	BehaviorTree* behaviorTree{ nullptr };					// ビヘイビアツリー
	std::shared_ptr<BehaviorNode> currentNode{ nullptr };	// 実行中ノード
	BlackBoard blackBoard{};								// ビヘイビアデータ

};