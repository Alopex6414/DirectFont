/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DirectFont.h
* @brief	This File is DirectFont DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2017-12-16	v1.00a	alopex	Create This File
*/
#pragma once

#ifndef __DIRECTFONT_H_
#define __DIRECTFONT_H_

//Include DirectX Common Header File
#include "DirectCommon.h"

//Macro Definition
#ifdef	DIRECTFONT_EXPORTS
#define DIRECTFONT_API	__declspec(dllexport)
#else
#define DIRECTFONT_API	__declspec(dllimport)
#endif

#define DIRECTFONT_FORMAT_CENTER		(DT_CENTER)
#define DIRECTFONT_FORMAT_TOPLEFT		(DT_TOP | DT_LEFT)
#define DIRECTFONT_FORMAT_TOPRIGHT		(DT_TOP | DT_RIGHT)
#define DIRECTFONT_FORMAT_BOTTOMLEFT	(DT_BOTTOM | DT_LEFT)
#define DIRECTFONT_FORMAT_BOTTOMRIGHT	(DT_BOTTOM | DT_RIGHT)

//Class Definition
class DIRECTFONT_API DirectFont
{
private:
	IDirect3DDevice9* m_pD3D9Device;			//The Direct3D 9 Device(D3D9�����豸)
	ID3DXFont* m_pD3D9Font;						//The Direct3D 9 Font(D3D9��������)

public:
	DirectFont();								//DirectFont Constructor Function(���캯��)
	~DirectFont();								//DirectFont Destructor  Function(��������)

	//����
	DirectFont(IDirect3DDevice9* pD3D9Device);	//DirectFont Constructor Function(���캯��)

	//����
	IDirect3DDevice9* WINAPI DirectFontGetDevice(void) const;			//DirectFont Get D3D9 Device(��ȡD3D9�豸)
	ID3DXFont* WINAPI DirectFontGetFont(void) const;					//DirectFont Get D3D9 Font(��ȡD3D9����)

	//����
	void WINAPI DirectFontSetDevice(IDirect3DDevice9* pD3D9Device);		//DirectFont Set D3D9 Device(����D3D9�豸)
	void WINAPI DirectFontSetFont(ID3DXFont* pD3DXFont);				//DirectFont Set D3DX Font(����D3D9����)

	//����
	virtual void WINAPI DirectFontReset(void);							//DirectFont Reset D3DX Font(����D3DX����)

	//��ʼ��
	virtual HRESULT WINAPI DirectFontInit(void);										//DirectFont Create Font(DirectFont��ʼ��)
	virtual HRESULT WINAPI DirectFontInit(int nFontSize);								//DirectFont Create Font(DirectFont��ʼ��)
	virtual HRESULT WINAPI DirectFontInit(int nFontSize, LPWSTR lpszFontType);			//DirectFont Create Font(DirectFont��ʼ��)

	//����
	virtual void WINAPI DirectFontDrawText(HWND hWnd, LPCWSTR lpcszStr, DWORD Format, D3DCOLOR Color);			//DirectFont Draw Text(DirectFont����)

};

#endif