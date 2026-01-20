#include "EnemyBase.h"


void EnemyBase::InputBlackBoard()
{
	blackBoard.status.current_hp = status.current_hp;
	blackBoard.status.attack = status.attack;
	blackBoard.status.defence = status.defence;
}

void EnemyBase::OutputBlackBoard()
{
	status.current_hp = blackBoard.status.current_hp;
}

// ダメージを受ける処理
void EnemyBase::ReceiveDamage(float damage_)
{
	float recieve_damage = damage_ - status.defence;
	if (recieve_damage > 0.0f)
	{
		status.current_hp -= recieve_damage;
	}
	else
	{
		// もしダメージが防御力を下回っていたら
		// 1ダメージを受ける
		status.current_hp -= 1.0f;
	}
}
