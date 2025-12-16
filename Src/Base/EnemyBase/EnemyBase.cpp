#include "EnemyBase.h"

void EnemyBase::InputBlackBoard()
{
	blackBoard.current_hp = current_hp;
	blackBoard.attack = attack;
	blackBoard.defence = defence;

	if (max_hp > 0.0f)
	{
		blackBoard.hp_percent = current_hp / max_hp * 100.0f;
	}
	else
	{
		blackBoard.hp_percent = 0.0f;
	}
}

void EnemyBase::OutputBlackBoard()
{
	current_hp = blackBoard.current_hp;
}

void EnemyBase::ReceiveDamage(float damage_)
{
	float recieve_damage = damage_ - defence;
	if (recieve_damage > 0.0f)
	{
		current_hp -= recieve_damage;
	}
	else
	{
		// もしダメージが防御力を下回っていたら
		// 最大HPの1%のダメージを受ける
		current_hp -= one_percent_of_total_hp;
	}
}



void EnemyBase::ShootBullet()
{

}