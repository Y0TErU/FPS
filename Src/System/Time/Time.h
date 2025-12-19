#pragma once

#include <DxLib.h>

// 時間を計測する為のシステム
class Time
{
public:
	Time()
	{
	}

	~Time()
	{
	}

public:
	/*
		時間計測開始
			引数無しの場合は無限に計測する(経過時間を取得する)

			引数ありの場合は引数で指定した秒数を数える
	*/
	void Start();
	void Start(float time_);

	/*
		タイマーを更新する
			経過時間を測っている場合は時間経過後にtrueを返す
			それ以外の場合はfalseを返す
	*/
	bool Update();
	void Stop();			// タイマーを止める
	bool IsRunning() const;	// タイマーが動作中か

	// 経過時間を取得(ミリ秒)
	float GetElapsedTime() const;


private:
	bool isStarted{ false };	// タイマーが起動中かどうかを判定
	bool haveLimit{ false };	// タイマーが計測時間を所持しているか
	int start_count{ 0 };	// windows起動時からタイマーを起動した時までの時間を保存する
	int limit_time{ 0 };	// 制限時間

};