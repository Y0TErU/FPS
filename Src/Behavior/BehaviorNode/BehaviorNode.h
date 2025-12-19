#pragma once

#include <vector>
#include <string>
#include <memory>
#include "../BehaviorConstants/BehaviorConstants.h"
#include "../../AI/Action/ActionBase/ActionBase.h"
#include "../../AI/Judge/JudgeBase/JudgeBase.h"

class BehaviorNode : public std::enable_shared_from_this<BehaviorNode>
{
public:
	BehaviorNode(std::string name_, std::shared_ptr<BehaviorNode>parent_, std::shared_ptr<BehaviorNode> sibling_,
		unsigned int priority_, SelectRule select_rule_, JudgeBase* judge_, ActionBase* action_, int hierarchy_no_) :
		name{ name_ },
		parent{ parent_ },
		sibling{ sibling_ },
		priority{ priority_ },
		selectRule{ select_rule_ },
		judge{ judge_ },
		action{ action_ },
		hierarchyNo{ hierarchy_no_ }
	{
		static unsigned int createId{ 1 };
		id = createId;
		createId++;
	}

	// ゲッター
	unsigned int GetId()
	{
		return id;
	}

	std::string GetName()
	{
		return name;
	}

	// 親ノードゲッター
	std::shared_ptr<BehaviorNode> GetParent()
	{
		return parent;
	}

	// 子ノードゲッター
	std::shared_ptr<BehaviorNode> GetChild(int idx_)
	{
		if (children.size() >= idx_)
		{
			return nullptr;
		}
		return children[idx_];
	}

	// 子ノードゲッター(末尾)
	std::shared_ptr<BehaviorNode> GetLastChild()
	{
		if (children.size() == 0)
		{
			return nullptr;
		}
		return children[children.size() - 1];
	}
	// 子ノードゲッター(先頭)
	std::shared_ptr<BehaviorNode> GetTopChild()
	{
		if (children.size() == 0)
		{
			return nullptr;
		}
		return children[0];
	}
	// 兄弟ノードゲッター
	std::shared_ptr<BehaviorNode> GetSibling(void)
	{
		return sibling;
	}
	// 階層番号ゲッター
	int GetHirerchyNo()
	{
		return hierarchyNo;
	}
	// 優先順位ゲッター
	unsigned int GetPriority()
	{
		return priority;
	}
	// 親ノードセッター
	void SetParent(std::shared_ptr<BehaviorNode> parent_)
	{
		parent = parent_;
	}
	// 子ノード追加
	void AddChild(std::shared_ptr<BehaviorNode> child_)
	{
		children.push_back(child_);
	}
	// 兄弟ノードセッター
	void SetSibling(std::shared_ptr<BehaviorNode> sibling_)
	{
		sibling = sibling_;
	}
	// 行動データを持っているか
	bool HasAction()
	{
		return action != nullptr ? true : false;
	}

	// 実行可否判定
	bool Judge(BlackBoard& black_board_);

	// 優先順位選択
	std::shared_ptr<BehaviorNode> SelectPriority(std::vector<std::shared_ptr<BehaviorNode>>& kist_);
	// ランダム選択
	std::shared_ptr<BehaviorNode> SelectRandom(std::vector<std::shared_ptr<BehaviorNode>>& list_);
	// オン・オフ選択
	std::shared_ptr<BehaviorNode> SelectOnOff(std::vector<std::shared_ptr<BehaviorNode>>& list_, BlackBoard& black_board_);
	// シーケンス選択
	std::shared_ptr<BehaviorNode> SelectSequence(std::vector<std::shared_ptr<BehaviorNode>>& list_, BlackBoard& black_board_);
	// 検索
	std::shared_ptr<BehaviorNode> SearchNode(std::string search_name_);
	std::shared_ptr<BehaviorNode> SearchNode(unsigned int search_id_);
	// 推論
	std::shared_ptr<BehaviorNode> Inference(BlackBoard& blaack_board_);
	
	// 名前表示
	void PrintName();
	// 実行
	ActionBase::State Update(BlackBoard& black_board_);

private:
	std::shared_ptr<BehaviorNode> Select(std::vector<std::shared_ptr<BehaviorNode>> list_, BlackBoard& black_board_);

	private:
		unsigned int id{ 0 };
		std::string name{ "" };									// 名前
		SelectRule selectRule;									// 選択ルール
		JudgeBase* judge{ nullptr };							// 判定クラス
		ActionBase* action{ nullptr };							// 実行クラス
		unsigned int priority{ 0 };								// 優先順位
		std::shared_ptr<BehaviorNode> parent{ nullptr };		// 親ノード
		std::vector<std::shared_ptr<BehaviorNode>> children{};	// 子ノード
		std::shared_ptr<BehaviorNode> sibling{ nullptr };		// 兄弟ノード
		int hierarchyNo{ 0 };									// 階層番号

};