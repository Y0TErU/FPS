#pragma once

#include <vector>
#include <stack>
#include <map>

#include "../BehaviorConstants/BehaviorConstants.h"

// Behavior保存データ
struct BehaviorContext
{
public:
	BehaviorContext()
	{
		Init();
	}

	// シーケンスノードのプッシュ
	void PushSequenceNode(unsigned int id_)
	{
		sequenceStacks.push(id_);
	}

	// シーケンスノードのポップ
	unsigned int PopSequenceNode()
	{
		if (sequenceStacks.empty() == true)
		{
			return NodeInvalId;
		}

		unsigned int id = sequenceStacks.top();
		// 取り出したデータを削除
		sequenceStacks.pop();
		return id;
	}

	// ノード使用判定
	bool IsNodeUsed(unsigned int id_)
	{
		// 使用してなかったらfalse
		if (usedNodes.count(id_) == 0)
		{
			return false;
		}

		return usedNodes[id_];
	}

	// 使用済みノードに登録
	void EntryUsedNode(unsigned int id_)
	{
		usedNodes[id_] = true;
	}

	// シーケンスステップのゲッター
	int GetSequenceStep(unsigned int id_)
	{
		if (sequenceSteps.count(id_) == 0)
		{
			sequenceSteps[id_] = 0;	// 開始
		}

		return sequenceSteps[id_];
	}

	// シーケンスステップのセッター
	void SetSequenceStep(unsigned int id_, int step_)
	{
		sequenceSteps[id_] = step_;
	}

	// 初期化
	void Init()
	{
		sequenceSteps.clear();
		while (sequenceStacks.size() > 0)
		{
			sequenceStacks.pop();
		}
	}

	// 使用済みノードのリセット
	void ResetNodeUsed(std::vector<unsigned int>& reset_hierachy_nodes_)
	{
		for (auto& node_id : reset_hierachy_nodes_)
		{
			usedNodes[node_id] = false;
		}
	}

private:
	std::stack<unsigned int> sequenceStacks{};		// シーケンスノードスタック
	std::map<unsigned int, int> sequenceSteps{};	// 実行シーケンスのステップ
	std::map<unsigned int, bool> usedNodes{};		// ノードの使用記録

};