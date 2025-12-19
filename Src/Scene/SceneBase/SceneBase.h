#pragma once

class SceneBase
{
public:
	enum class Step
	{
		Load,		// 読込
		Init,		// 初期化
		Execute,	// 本編
		Finish		// 終了
	};

	enum class Type
	{
		Title,	// タイトルシーン
		Game,	// ゲームシーン
	};

public:
	SceneBase(int loading_handle) :
		loadingHandle{ loading_handle }
	{
	}

	virtual ~SceneBase() = default;

public:
	Type Main();
	virtual void Draw() = 0;
	virtual Type GetType() = 0;

protected:
	virtual void EntryLoadFiles() = 0;
	virtual void Init() = 0;
	virtual void Execute() = 0;
	virtual Type Finish() = 0;

protected:
	Step currentStep{ Step::Load };

private:
	void Loading();
	void DrawLoading();

protected:
	int loadingHandle{ -1 };				// ロード画面のアニメーションハンドル
	int loadAnimCounter{ 0 };			// ロード画面のアニメーションカウンター
	bool isLoadFileRegistered{ false };		// ローディングのフラグ
	int debugCounter{ 0 };					// ロード画面のデバッグ用カウント

private:
	const int loading_min_time{ 120 };	// ロード画面最低時間

};