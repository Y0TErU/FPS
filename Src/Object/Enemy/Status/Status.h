#pragma once

// Enemyのステータス用構造体
struct Status
{
public:
	void Initialize(float max_hp_,float move_speed_,float attack_,float defence_)
	{
		max_hp = max_hp_;
		current_hp = max_hp;
		move_speed = move_speed_;
		attack = attack_;
		defence = defence_;
		OnePercentTotalHp();
	}

	// ダメージを受ける処理
	void ReceiveDamage(float damage_)
	{
		float recieve_damage = damage_ - defence;
		if (recieve_damage > 0.0f)
		{
			current_hp -= recieve_damage;
		}
		else
		{
			// もしダメージが防御力を下回っていたら
			// 最大HPの1%のダメージを受ける
			current_hp -= one_percent_of_total_hp;
		}
	}

	// ゲッター
	bool IsDead() const
	{
		return current_hp <= 0.0f;
	}

	float GetHpRate() const
	{
		return current_hp / max_hp;
	}

	float GetCurrentHP() const { return current_hp; }
	float GetMoveSpeed() const { return move_speed;	}
	float GetAttack() const { return attack; }
	float GetDefence() const { return defence; }

	// セッター
	void SetCurrentHp(float current_hp_)
	{
		current_hp = current_hp_;
	}

private:
	void OnePercentTotalHp()	// 最大HPの1%を計算
	{
		one_percent_of_total_hp = 100.0f / max_hp;
	}

private:
	float max_hp{};				// 最大Hp
	float current_hp{};			// 現在のHP
	float move_speed{};			// 移動速度
	float attack{};				// 攻撃力
	float defence{};			// 防御力

	float one_percent_of_total_hp{};	// 最大HPの1%の値

};