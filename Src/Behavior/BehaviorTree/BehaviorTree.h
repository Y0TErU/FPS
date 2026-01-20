#pragma once

#include <string>
#include <memory>

#include "../BehaviorConstants/BehaviorConstants.h"
#include  "../BehaviorNode/BehaviorNode.h"
#include "../../Object/BlackBoard/BlackBoard.h"
#include "../../AI/Action/ActionBase/Actionbase.h"
#include "../../AI/Judge/JudgeBase/JudgeBase.h"


using namespace std;

class BehaviorTree
{
public:
	BehaviorTree()
	{
	}

	// ノード追加
	void AddNode(string search_name_, string entry_name_, int priority_, SelectRule select_rule_, JudgeBase* judge_, ActionBase* action_);
	// 実行ノードを推論する
	shared_ptr<BehaviorNode> Inference(BlackBoard& black_board_);
	// シーケンスノードから推論開始
	shared_ptr<BehaviorNode> SequenceBack(shared_ptr<BehaviorNode> sequence_node_, BlackBoard& black_board_);
	// 実行
	shared_ptr<BehaviorNode> Update(shared_ptr<BehaviorNode> action_node_, BlackBoard& black_board_);
	// ツリー構造を表示
	void PrintTree();

private:
	shared_ptr<BehaviorNode> root{ nullptr };	// ルートノード

};