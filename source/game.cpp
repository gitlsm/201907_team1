//=============================================================================
//
// ゲームの処理 [game.cpp]
// Author : 李尚ミン
//
//=============================================================================
#include "game.h"
#include "light.h"
#include "camera.h"
#include "note.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
static const D3DXVECTOR3 INIT_POS_CAMERA = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
static const D3DXVECTOR3 INIT_POS_AT = D3DXVECTOR3(0.0f, 0.0f, 100.0f);


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
void InitCamera();

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static Camera *camera;
Note *note;


//*****************************************************************************
// ゲームの初期化
//*****************************************************************************
void InitGame()
{
	// カメラの初期化
	InitCamera();

	// ライトの初期化
	InitLight();

	//ノーツの初期化
	note = new Note();
}

//*****************************************************************************
// ゲームの終了
//*****************************************************************************
void UninitGame()
{
	// カメラの解放
	delete camera;

	// ライトの終了
	UninitLight();

	//noteの終了
	delete note;
}

//*****************************************************************************
// ゲームの更新
//*****************************************************************************
void UpdateGame()
{
	// カメラの更新
	camera->Update();

	// ライトの更新
	UpdateLight();

	
}

//*****************************************************************************
// ゲーム画面の描画
//*****************************************************************************
void DrawGame()
{
	// カメラのセット
	camera->Set();

	//ノーツの描画
	note->Draw();
}


//*****************************************************************************
// カメラの初期化
//*****************************************************************************
void InitCamera()
{
	CameraData InitData;
	InitData.posEye = INIT_POS_CAMERA;
	InitData.posAT = INIT_POS_AT;

	camera = new Camera(InitData);
}
