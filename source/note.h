//==================================================
//　ノーツ処理[note.h]
//  Author : 染矢　晃介
//==================================================
#ifndef _NOTE_H_
#define _NOTE_H_

#include "main.h"
#include "noteview.h"
#include "notecontroller.h"

//==================================================
//マクロ定義
//==================================================
#define NOTE_SCALE_X		(8.5f)		//ノーツサイズのX
#define NOTE_SCALE_Y		(8.5f)		//ノーツサイズのY
#define NOTE_SCALE_Z		(8.5f)		//ノーツサイズのZ

//==================================================
//クラス定義
//==================================================
class Note
{
	//メンバー変数
public:
	NoteView * view;			//viewのポインタ変数
	NoteController *ctrl;		//controllerのポインタ変数
	D3DXVECTOR3 pos;			//座標(コンストラクタ内で値の仮初期化）
	D3DXVECTOR3 scl;			//大きさ(コンストラクタ内で値の仮初期化）
	D3DXMATRIX	mtxWorld;		//ワールドマトリクス
	float		move;			//移動量
	bool		use;			//使用状態
private:

	//メンバー関数
public:
	 Note();					//コンストラクタ
	 ~Note();					//デストラクタ
	 void Update();				//更新処理を呼ぶ
	 void Draw();				//描画処理を呼ぶ
	 D3DXVECTOR3 GetPos();		//posを取得
	 D3DXVECTOR3 GetScl();		//sclを取得
	 D3DXMATRIX  GetMtxWorld();	//mtxWorldを取得


private:
};

#endif

