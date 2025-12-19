#pragma once

#include <memory>
#include <vector>

#include "../../Object/Enemy/EnemyBase/EnemyBase.h"

using namespace std;

class EnemyManager
{
private:
	static EnemyManager* GetInstance()
	{
		static EnemyManager instance;
		return &instance;
	}

	EnemyManager() = default;
	~EnemyManager()
	{
	}

	EnemyManager(const EnemyManager&) = delete;
	EnemyManager& operator = (const EnemyManager&) = delete;

public:
	void Entry(shared_ptr<EnemyBase> enemy_);	// “o˜^—\–ñ
	void Register();							// “o˜^‘Ò‚¿‚ÌˆêÄ“o˜^
	
	void Update();								// XV
	void Draw();								// •`‰æ

	void Delete();								// íœ
	void AllDelete();							// ‘Síœ

	vector<shared_ptr<EnemyBase>> GetInstance(string tag_);

private:
	vector<shared_ptr<EnemyBase>> entry_enemies;	// “o˜^‘Ò‚¿
	vector<shared_ptr<EnemyBase>> enemies;			// “o˜^Ï‚İ

};