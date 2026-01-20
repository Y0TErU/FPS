#pragma once

// Enemyのステータス用構造体
struct Status
{
public:
	float max_hp{};				// 最大Hp
	float current_hp{};			// 現在のHP
	float move_speed{};			// 移動速度
	float attack{};				// 攻撃力
	float defence{};			// 防御力

};