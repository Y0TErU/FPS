#include "EnemyBase.h"


void EnemyBase::InputBlackBoard()
{
	blackBoard.current_hp = status.GetCurrentHP();
	blackBoard.attack = status.GetAttack();
	blackBoard.defence = status.GetDefence();

	if (status.IsDead() == false)
	{
		blackBoard.hp_rate = status.GetHpRate();
	}
	else
	{
		blackBoard.hp_rate = 0.0f;
	}
}

void EnemyBase::OutputBlackBoard()
{
	status.SetCurrentHp(blackBoard.current_hp);
}
