#pragma once

// キーコード一覧
/*
	KEY_INPUT_(A~Z)	//A～Zのキー
	KEY_INPUT_(0~9)	//0～9のキー
	KEY_INPUT_BACK	// バックスペースキー
	KEY_INPUT_TAB	// タブキー
	KEY_INPUT_RETURN	// エンターキー

	KEY_INPUT_LSHIFT	// 左シフトキー
	KEY_INPUT_RSHIFT	// 右シフトキー
	KEY_INPUT_LCONTROL	// 左コントロールキー
	KEY_INPUT_RCONTROL	// 右コントロールキー
	KEY_INPUT_ESCAPE	// エスケープキー
	KEY_INPUT_SPACE	// スペースキー
	KEY_INPUT_PGUP	// ＰａｇｅＵＰキー
	KEY_INPUT_PGDN	// ＰａｇｅＤｏｗｎキー
	KEY_INPUT_END	// エンドキー
	KEY_INPUT_HOME	// ホームキー
	KEY_INPUT_LEFT	// 左キー
	KEY_INPUT_UP	// 上キー
	KEY_INPUT_RIGHT	// 右キー
	KEY_INPUT_DOWN	// 下キー
	KEY_INPUT_INSERT	// インサートキー
	KEY_INPUT_DELETE	// デリートキー

	KEY_INPUT_MINUS	// －キー
	KEY_INPUT_YEN	// ￥キー
	KEY_INPUT_PREVTRACK	// ＾キー
	KEY_INPUT_PERIOD	// ．キー
	KEY_INPUT_SLASH	// ／キー
	KEY_INPUT_LALT	// 左ＡＬＴキー
	KEY_INPUT_RALT	// 右ＡＬＴキー
	KEY_INPUT_SCROLL	// ScrollLockキー
	KEY_INPUT_SEMICOLON	// ；キー
	KEY_INPUT_COLON	// ：キー
	KEY_INPUT_LBRACKET	// ［キー
	KEY_INPUT_RBRACKET	// ］キー
	KEY_INPUT_AT	// ＠キー
	KEY_INPUT_BACKSLASH	// ＼キー
	KEY_INPUT_COMMA	// ，キー
	KEY_INPUT_CAPSLOCK	// CaspLockキー
	KEY_INPUT_PAUSE	// PauseBreakキー

	KEY_INPUT_NUMPAD0	// テンキー０
	KEY_INPUT_NUMPAD1	// テンキー１
	KEY_INPUT_NUMPAD2	// テンキー２
	KEY_INPUT_NUMPAD3	// テンキー３
	KEY_INPUT_NUMPAD4	// テンキー４
	KEY_INPUT_NUMPAD5	// テンキー５
	KEY_INPUT_NUMPAD6	// テンキー６
	KEY_INPUT_NUMPAD7	// テンキー７
	KEY_INPUT_NUMPAD8	// テンキー８
	KEY_INPUT_NUMPAD9	// テンキー９
	KEY_INPUT_MULTIPLY	// テンキー＊キー
	KEY_INPUT_ADD	// テンキー＋キー
	KEY_INPUT_SUBTRACT	// テンキー－キー
	KEY_INPUT_DECIMAL	// テンキー．キー
	KEY_INPUT_DIVIDE	// テンキー／キー
	KEY_INPUT_NUMPADENTER	// テンキーのエンターキー

	KEY_INPUT_F1	// Ｆ１キー
	KEY_INPUT_F2	// Ｆ２キー
	KEY_INPUT_F3	// Ｆ３キー
	KEY_INPUT_F4	// Ｆ４キー
	KEY_INPUT_F5	// Ｆ５キー
	KEY_INPUT_F6	// Ｆ６キー
	KEY_INPUT_F7	// Ｆ７キー
	KEY_INPUT_F8	// Ｆ８キー
	KEY_INPUT_F9	// Ｆ９キー
	KEY_INPUT_F10	// Ｆ１０キー
	KEY_INPUT_F11	// Ｆ１１キー
	KEY_INPUT_F12	// Ｆ１２キー

*/

class InputManager
{
public:
	static InputManager* GetInstance()
	{
		static InputManager instance;
		return &instance;
	}

	InputManager() = default;
	~InputManager()
	{
	}

	InputManager(const InputManager&) = delete;
	InputManager& operator = (const InputManager&) = delete;

public:
	void SetDisplayMouseCursol(bool set_);	// マウスカーソル表示設定
	bool IsKeyCheck(int key_);				// 正常かどうかのチェック
	void InitInput();						// キー状態の初期化
	void UpdateInput();						// 入力されているキー情報を更新する
	bool IsMouseClick(int button_);			// マウスクリック情報を取得
	bool IsKeyPress(int key_);				// キーが押されているかを取得する
	bool IsKeyPushed(int key_);				// キーが押された瞬間を取得する
	bool IsKeyReleased(int key_);			// 押されていたキーが離された瞬間を取得する

	// マウスの位置座標のゲッター
	int GetMousePosX() const { return mousePosX; }
	int GetMousePosY() const { return mousePosY; }

	// マウス移動差分のゲッター
	int GetMouseDeltaX() const { return mouseDeltaX; }
	int GetMouseDeltaY() const { return mouseDeltaY; }

private:
	//現在のフレームのキー入力状況
	char currentKeyBuffer[256]{};
	//1つ前のフレームのキー入力状況
	char prevKeyBuffer[256]{};

	int clickType{};		// クリックの状態
	int clickButton{};		// クリックされたボタン
	// マウスカーソルの絶対座標
	int mousePosX{ 0 };
	int mousePosY{ 0 };
	// 前フレームのマウスの位置
	int prevMouseX{ 0 };
	int prevMouseY{ 0 };
	// マウス移動量
	int mouseDeltaX{ 0 };
	int mouseDeltaY{ 0 };
};