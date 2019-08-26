//==================================================
//　ノーツ描画処理[noteview.h]
//  Author : 染矢　晃介
//==================================================
#ifndef _NOTEVIEW_H_
#define _NOTEVIEW_H_

class Note;					
#include "main.h"


//==================================================
//マクロ定義
//==================================================

//==================================================
//クラス定義
//==================================================
class NoteView
{
	//メンバー変数
public:
	Note * note;		//ノーツのポインタ変数

private:


	//メンバー関数
public:
	NoteView();			//コンストラクタ・モデルの読み込みと初期化
	~NoteView();		//デストラクタ・終了処理
	void Draw();		//描画処理


private:
};


#endif

