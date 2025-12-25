#pragma once

#include <memory>
#include <vector>

#include "../../Object/Enemy/EnemyBase/EnemyBase.h"

/*
	Enemy‚ÌŠÇ—‚Ì‚İ‚ğs‚¤
	•`‰æAXV‚ÍObjectManager‚Å‚Ì‚İs‚¤
*/
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
	void Entry(std::shared_ptr<EnemyBase> enemy_);	// “o˜^—\–ñ
	void Register();							// “o˜^‘Ò‚¿‚ÌˆêÄ“o˜^

	void Delete();								// íœ
	void AllDelete();							// ‘Síœ

	std::vector<std::shared_ptr<EnemyBase>> GetInstance(std::string tag_);

private:
	std::vector<std::shared_ptr<EnemyBase>> entry_enemies;	// “o˜^‘Ò‚¿
	std::vector<std::shared_ptr<EnemyBase>> enemies;			// “o˜^Ï‚İ

};