#include "ObjectManager.h"

void ObjectManager::Entry(shared_ptr<ObjectBase> object_)
{
	entry_objects.push_back(object_);
}

void ObjectManager::Register()
{
	for (auto& object : entry_objects)
	{
		objects.push_back(object);
	}
	entry_objects.clear();
}

void ObjectManager::Update()
{
	for (auto& object : objects)
	{
		object->Update();
	}
}

void ObjectManager::Draw()
{
	for (auto& object : objects)
	{
		if (object->GetIsActive())
		{
			object->Draw();
		}
	}
}

void ObjectManager::Delete()
{
	for (auto itr = objects.begin(); itr != objects.end();)
	{
		if (!(*itr)->GetIsActive())
		{
			itr = objects.erase(itr);
		}
		else
		{
			++itr;
		}
	}

}

void ObjectManager::AllDelete()
{
	objects.clear();
}

vector<shared_ptr<ObjectBase>> ObjectManager::GetInstance(string tag_)
{
	// 戻り値用vector
	vector<shared_ptr<ObjectBase>> subject_objects;
	for (auto& object : objects)
	{
		if (object->GetTag() == tag_)
		{
			// 対象のインスタンスを戻り値用vectorに保存していく
			subject_objects.push_back(object);
		}
	}
	return subject_objects;
}