#pragma once

class CoolTime
{
public:
	void Set(float time_);	// クールタイム設定
	bool IsReady() const;	// 使用可能か
	void Use();				// 使用する(クール開始)
	float GetRemain() const;	// 残り時間(秒)

private:
	int lastUseTime{ 0 };
	int coolTimeMs{ 0 };

};