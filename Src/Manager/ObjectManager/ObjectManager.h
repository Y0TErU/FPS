#pragma once

#include <memory>
#include <vector>

#include "../../Object/ObjectBase/ObjectBase.h"

/*
	ここではObjectが行う共通処理のみを行うこと
	Update(),Draw(),Delete()のみ
*/
class ObjectManager
{
public:
	static ObjectManager* GetInstance()
	{
		static ObjectManager instance;
		return &instance;
	}

	ObjectManager() = default;
	~ObjectManager()
	{
	}

	ObjectManager(const ObjectManager&) = delete;
	ObjectManager& operator = (const ObjectManager&) = delete;

public:
	void Entry(std::shared_ptr<ObjectBase> object_);		// 登録予約
	void Register();	// 登録待ちの一斉登録

	void Update();		// 更新
	void Draw();		// 描画

	void Delete();		// 削除
	void AllDelete();	// 全削除

	std::vector<std::shared_ptr<ObjectBase>> GetInstance(std::string tag_);	// タグのオブジェクトのインスタンスを取得

private:
	std::vector<std::shared_ptr<ObjectBase>> entry_objects;	// 登録待ちのオブジェクト
	std::vector<std::shared_ptr<ObjectBase>> objects;			// 登録済みのオブジェクト 
};