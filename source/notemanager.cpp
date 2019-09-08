//=============================================================================
//
// ノーツ処理 [notes.cpp]
// Author : GP12A332_25_染矢晃介
//
//=============================================================================
#include "notemanager.h"
#include "lane.h"
#include "assert.h"
//*****************************************************************************
// マクロ定義
//*****************************************************************************
// ノーツの初期位置
#define NOTE_INIT_POS_X		(0.0f)
#define NOTE_INIT_POS_Y		(50.0f)
#define NOTE_INIT_POS_Z		(100.0f)
#define NOTE_MAX			(50)
// ノーツ発生位置
#define NOTE_SET_POS_X		(50.0f)
#define NOTE_SET_POS_Y		(50.0f)
#define NOTE_SET_POS_Z		(1000.0f)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************

//=============================================================================
// コンストラクタ
//=============================================================================
NoteManager::NoteManager()
{
	note = new Note[NOTE_MAX];

	for (int i = 0; i < LANE_NUM_MAX; i++)
	{
		lanePos[i].x = -NOTE_SET_POS_X + (LANE_SPACE* i);
		lanePos[i].y = NOTE_SET_POS_Y;
		lanePos[i].z = NOTE_SET_POS_Z;
	}
}

//=============================================================================
// 終了処理
//=============================================================================
NoteManager::~NoteManager()
{
	delete[] note;
}

//=============================================================================
// 更新処理
//=============================================================================
void NoteManager::Update(void)
{
	for (int i = 0; i < NOTE_MAX; i++)
	{
		if (note[i].use)
		{
			note[i].pos.z -= note[i].move;
			note[i].Update();
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void NoteManager::Draw(void)
{
	for (int i=0; i < NOTE_MAX; i++)
	{
		if (note[i].use)
		{
			note[i].Draw();
		}
	}
}

//=============================================================================
// ノーツの設置関数
//=============================================================================
void NoteManager::SetNote(int laneNum, float scrSpeed)
{
	for (int i = 0; i < NOTE_MAX; i++)
	{
		if (SetNoteLane(laneNum, i, scrSpeed)) return;
	}
}

//=============================================================================
// ノーツのレーンへの設置関数
//=============================================================================
bool NoteManager::SetNoteLane(int laneNum, int noteNum, float scrSpeed)
{
	if (!note[noteNum].use)
	{
		switch (laneNum)
		{
		case LEFT_LANE:
			note[noteNum].pos = lanePos[LEFT_LANE];
			break;
		case CENTER_LANE:
			note[noteNum].pos = lanePos[CENTER_LANE];
			break;
		case RIGHT_LANE:
			note[noteNum].pos = lanePos[RIGHT_LANE];
			break;
		default:
			assert(laneNum > 2);
			break;
		}

		note[noteNum].move = scrSpeed;
		note[noteNum].use = true;

		return true;
	}

	return false;
}
