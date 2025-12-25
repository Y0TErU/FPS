#include "EnemyManager.h"

void EnemyManager::Entry(shared_ptr<EnemyBase> enemy_)
{
	entry_enemies.push_back(enemy_);
}

void EnemyManager::Register()
{
	for (auto& enemy : entry_enemies)
	{
		enemies.push_back(enemy);
	}
	entry_enemies.clear();
}


void EnemyManager::Delete()
{
	for (auto itr = enemies.begin(); itr != enemies.end();)
	{
		if (!(*itr)->GetIsActive())
		{
			itr = enemies.erase(itr);
		}
		else
		{
			++itr;
		}
	}
}