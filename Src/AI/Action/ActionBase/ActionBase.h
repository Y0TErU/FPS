#pragma once

#include "../../../BlackBoard/BlackBoard.h"

// 行動処理基底クラス
class ActionBase
{
public:
	// 実行情報
	enum class State
	{
		Execute,	// 実行中
		Failure,	// 実行失敗
		Complete,	// 実行成功
	};

	// 実行処理
	virtual State Update(BlackBoard& black_board_) = 0;

};