//=============================================================================
//
// カメラ処理 [camera.cpp]
// Author : 李尚ミン
//
//=============================================================================
#include "camera.h"
#include "input.h"
#include "debugproc.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	VIEW_ANGLE			(D3DXToRadian(45.0f))	// 視野角
#define	VIEW_ASPECT			((float)SCREEN_WIDTH / (float)SCREEN_HEIGHT)	// ビュー平面のアスペクト比
#define	VIEW_NEAR_Z			(10.0f)					// ビュー平面のNearZ値
#define	VIEW_FAR_Z			(1000.0f)				// ビュー平面のFarZ値

//=============================================================================
// カメラの初期化(から宣言)
//=============================================================================
Camera::Camera()
{
}

//=============================================================================
// カメラの初期化
//=============================================================================
Camera::Camera(CameraData initData)
{
	posEye = initData.posEye;
	posAT = initData.posAT;
	vecUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	float vx, vz;
	vx = posEye.x - posAT.x;
	vz = posEye.z - posAT.z;
	lengthInterval = sqrtf(vx * vx + vz * vz);
}

//=============================================================================
// カメラの更新処理
//=============================================================================
void Camera::Update()
{

}

//=============================================================================
// カメラの設定処理
//=============================================================================
void Camera::Set(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ビューマトリックスの初期化
	D3DXMatrixIdentity(&mtxView);

	// ビューマトリックスの作成
	D3DXMatrixLookAtLH(&mtxView,
		&posEye,		// カメラの視点
		&posAT,		// カメラの注視点
		&vecUp);		// カメラの上方向

	// ビューマトリックスの設定
	device->SetTransform(D3DTS_VIEW, &mtxView);


	// プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&mtxProjection);

	// プロジェクションマトリックスの作成
	D3DXMatrixPerspectiveFovLH(&mtxProjection,
		VIEW_ANGLE,			// 視野角
		VIEW_ASPECT,		// アスペクト比
		VIEW_NEAR_Z,		// ビュー平面のNearZ値
		VIEW_FAR_Z);		// ビュー平面のFarZ値

	// プロジェクションマトリックスの設定
	device->SetTransform(D3DTS_PROJECTION, &mtxProjection);
}

//*****************************************************************************
// カメラ視点のゲット関数
//*****************************************************************************
D3DXVECTOR3 Camera::GetPosEye()
{
	return posEye;
}

//*****************************************************************************
// ビュー行列のゲット関数
//*****************************************************************************
D3DXMATRIX Camera::GetMtxView()
{
	return mtxView;
}

//*****************************************************************************
// プロジェクション行列のゲット関数
//*****************************************************************************
D3DXMATRIX Camera::GetMtxProjection()
{
	return mtxProjection;
}