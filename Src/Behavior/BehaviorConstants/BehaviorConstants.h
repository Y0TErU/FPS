#pragma once

// 選択ルール
enum class SelectRule
{
	None,
	Priority,			// 優先順位
	Sequence,			// シーケンス
	SequentialLooping,	// シーケンシャルルーピング
	Random,				// ランダム
	OnOrOff,			// オン・オフ
};
const unsigned int NodeInvalId{ 0 };