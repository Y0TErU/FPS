#include <iostream>
#include "BehaviorNode.h"

// ノード検索
std::shared_ptr<BehaviorNode> BehaviorNode::SearchNode(std::string search_name_)
{
	// 名前が一致
	if (name == search_name_)
	{
		return shared_from_this();
	}
	else
	{
		// 子ノードで検索
		for (auto itr = children.begin(); itr != children.end(); itr++)
		{
			std::shared_ptr<BehaviorNode> result = (*itr)->SearchNode(search_name_);

			if (result != nullptr)
			{
				return result;
			}
		}
	}
	return nullptr;
}

std::shared_ptr<BehaviorNode> BehaviorNode::SearchNode(unsigned int search_id_)
{
	// 名前が一致
	if (id == search_id_)
	{
		return shared_from_this();
	}
	else
	{
		// 子ノードで検索
		for (auto itr = children.begin(); itr != children.end(); itr++)
		{
			std::shared_ptr<BehaviorNode> result = (*itr)->SearchNode(search_id_);

			if (result != nullptr)
			{
				return result;
			}
		}
	}
}

// 名前表示
void BehaviorNode::PrintName()
{
	std::cout << name << std::endl;

	for (auto itr = children.begin(); itr != children.end(); itr++)
	{
		(*itr)->PrintName();
	}
}

// ノード推論
std::shared_ptr<BehaviorNode> BehaviorNode::Inference(BlackBoard& black_board_)
{
	std::vector<std::shared_ptr<BehaviorNode>> list{};

	// 子ノードで実行可能なノードを探す
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i]->judge != nullptr)
		{
			if (children[i]->judge->IsConditionMet(black_board_) == true)
			{
				list.push_back(children[i]);
			}
		}
		else
		{
			// 判定クラスが無ければ無条件に追加
			list.push_back(children[i]);
		}
	}
	return Select(list, black_board_);
}

// 優先順位選択
std::shared_ptr<BehaviorNode> BehaviorNode::SelectPriority(std::vector<std::shared_ptr<BehaviorNode>>& list_)
{
	std::shared_ptr<BehaviorNode> select_node = nullptr;

	unsigned int priority = 0;

	// 一番優先順位が高いノードを探す
	for (auto& node : list_)
	{
		if (priority < node->GetPriority())
		{
			select_node = node;
			priority = node->GetPriority();
		}
	}
	return select_node;
}

// オンオフ
std::shared_ptr<BehaviorNode> BehaviorNode::SelectOnOff(std::vector<std::shared_ptr<BehaviorNode>>& list_, BlackBoard& black_board_)
{
	std::vector<std::shared_ptr<BehaviorNode>> off_list;

	// 使用済みノードをリストアップする
	for (auto& node : list_)
	{
		if (black_board_.behaviorContextCmd.IsNodeUsed(node->GetId()) == false)
		{
			off_list.push_back(node);
		}
	}

	// リストアップした数チェック
	if (off_list.size() == 0)
	{
		std::vector<unsigned int> id_list{};
		for (auto& child : children)
		{
			id_list.push_back(child->GetId());
		}

		// ノードを全てリセット
		black_board_.behaviorContextCmd.ResetNodeUsed(id_list);
		off_list = list_;
	}

	// 使用したノードを登録
	black_board_.behaviorContextCmd.EntryUsedNode(off_list[0]->GetId());

	// リストの先頭が決定ノードとなる
	return off_list[0];
}

// ランダム
std::shared_ptr<BehaviorNode> BehaviorNode::SelectRandom(std::vector<std::shared_ptr<BehaviorNode>>& list_)
{
	int select_no = rand() % list_.size();

	return list_[select_no];
}

// シーケンス
std::shared_ptr<BehaviorNode> BehaviorNode::SelectSequence(std::vector<std::shared_ptr<BehaviorNode>>& list_, BlackBoard& black_board_)
{
	// 今のノードのシーケンスステップを取得
	int step = black_board_.behaviorContextCmd.GetSequenceStep(GetId());

	// シーケンスが終わっていたら終了
	if (step >= children.size())
	{
		if (selectRule != SelectRule::SequentialLooping)
		{
			return nullptr;
		}
		else
		{
			// Loopingの場合は頭から実行

			step = 0;
		}
	}

	// 順番のノードが実行出来るかのチェック
	for (auto& node : list_)
	{
		if (children[step]->GetName() == node->GetName())
		{
			// シーケンスノードを記録
			black_board_.behaviorContextCmd.PushSequenceNode(GetId());
			// シーケンスステップを更新
			black_board_.behaviorContextCmd.SetSequenceStep(GetId(), step + 1);
			return children[step];
		}
	}
	return nullptr;
}

// 判定
bool BehaviorNode::Judge(BlackBoard& black_board_)
{
	// 判定クラスを持っていれば実行なければtrue扱い
	if (judge != nullptr)
	{
		return judge->IsConditionMet(black_board_);
	}
	return true;
}

// ノード実行
ActionBase::State BehaviorNode::Update(BlackBoard& black_board_)
{
	if (action != nullptr)
	{
		return action->Update(black_board_);
	}
	return ActionBase::State::Failure;
}

std::shared_ptr<BehaviorNode> BehaviorNode::Select(std::vector<std::shared_ptr<BehaviorNode>> list_, BlackBoard& black_board_)
{
	std::shared_ptr<BehaviorNode> result = nullptr;

	// 選択ノードでルール決め
	switch (selectRule)
	{
		// 優先順位
	case SelectRule::Priority:
		result = SelectPriority(list_);
		break;
		// オン・オフ
	case SelectRule::OnOrOff:
		result = SelectOnOff(list_,black_board_);
		break;
		// ランダム
	case SelectRule::Random:
		result = SelectRandom(list_);
		break;
		// シーケンス
	case SelectRule::Sequence:
	case SelectRule::SequentialLooping:
		result = SelectSequence(list_, black_board_);
		break;
	}

	if (result != nullptr)
	{
		// 行動があれば終了
		if (result->HasAction() == true)
		{
			return result;
		}
		else
		{
			// 決まったノードで推論開始
			result = result->Inference(black_board_);
		}
	}
	return result;
}