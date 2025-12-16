#include "BehaviorTree.h"

#include "../BehaviorNode/BehaviorNode.h"

void BehaviorTree::AddNode(std::string search_name_, std::string entry_name_, int priority_, SelectRule select_rule_, JudgeBase* judge_, ActionBase* action_)
{
	if (search_name_ != "")
	{
		std::shared_ptr<BehaviorNode> search_node = root->SearchNode(search_name_);

		if (search_node != nullptr)
		{
			std::shared_ptr<BehaviorNode> sibling = search_node->GetLastChild();
			std::shared_ptr<BehaviorNode> add_node = std::make_shared<BehaviorNode>(entry_name_, search_node, sibling, priority_, select_rule_, judge_, action_, search_node->GetHirerchyNo() + 1);

			search_node->AddChild(add_node);
		}
	}
	else
	{
		if (root == nullptr)
		{
			root = std::make_shared<BehaviorNode>(entry_name_, nullptr, nullptr, priority_, select_rule_, judge_, action_, 1);
		}
	}
}

void BehaviorTree::PrintTree()
{
	if (root != nullptr)
	{
		root->PrintName();
	}
}

// 推論
std::shared_ptr<BehaviorNode> BehaviorTree::Inference(BlackBoard& black_board_)
{
	// データをリセットして開始
	black_board_.behaviorContextCmd.Init();
	return root->Inference(black_board_);
}

// シーケンスノードからの推論開始
std::shared_ptr<BehaviorNode> BehaviorTree::SequenceBack(std::shared_ptr<BehaviorNode> sequence_node_, BlackBoard& black_board_)
{
	return sequence_node_->Inference(black_board_);
}

// ノード実行
std::shared_ptr<BehaviorNode> BehaviorTree::Update(std::shared_ptr<BehaviorNode> action_node_, BlackBoard& black_board_)
{
	// ノード実行
	ActionBase::State state = action_node_->Update(black_board_);

	// 正常終了
	if (state == ActionBase::State::Complete)
	{
		// シーケンスの途中かを判断
		unsigned int id = black_board_.behaviorContextCmd.PopSequenceNode();

		std::shared_ptr<BehaviorNode> node = root->SearchNode(id);
		// 途中じゃないなら終了
		if (node == nullptr)
		{
			return nullptr;
		}
		else
		{
			// 途中ならそこから始まる
			return SequenceBack(node, black_board_);
		}
	// 失敗は終了
	}
	else if (state == ActionBase::State::Failure)
	{
		return nullptr;
	}
	// 現状維持
	return action_node_;
}