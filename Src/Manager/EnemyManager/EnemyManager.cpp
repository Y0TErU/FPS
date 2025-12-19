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

void EnemyManager::Update()
{
	for (auto& enemy : enemies)
	{
		enemy->Update();
	}
}

void EnemyManager::Draw()
{
	for (auto& enemy : enemies)
	{
		if (enemy->GetIsActive())
		{
			enemy->Draw();
		}
	}
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