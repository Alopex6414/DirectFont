/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DirectFont.cpp
* @brief	This File is DirectFont DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2017-12-16	v1.00a	alopex	Create This File
*/
#include "DirectCommon.h"
#include "DirectFont.h"

//DirectFont主要用于2D/3D文字绘制

//------------------------------------------------------------------
// @Function:	 DirectFont()
// @Purpose: DirectFont构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
DirectFont::DirectFont()
{
	m_pD3D9Device = NULL;			//IDirect3DDevice9接口指针初始化(NULL)
	m_pD3D9Font = NULL;				//IDirect3DFont9接口指针初始化(NULL)
}

//------------------------------------------------------------------
// @Function:	 ~DirectFont()
// @Purpose: DirectFont析构函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
DirectFont::~DirectFont()
{
	SAFE_RELEASE(m_pD3D9Font);		//IDirect3DFont9接口指针释放
}

//------------------------------------------------------------------
// @Function:	 DirectFont(IDirect3DDevice9* pD3D9Device)
// @Purpose: DirectFont构造函数
// @Since: v1.00a
// @Para: IDirect3DDevice9* pD3D9Device	//D3D9绘制设备
// @Return: None
//------------------------------------------------------------------
DirectFont::DirectFont(IDirect3DDevice9* pD3D9Device)
{
	m_pD3D9Device = pD3D9Device;	//IDirect3DDevice9接口指针初始化(NULL)
	m_pD3D9Font = NULL;				//IDirect3DFont9接口指针初始化(NULL)
}

//------------------------------------------------------------------
// @Function:	 DirectFontGetDevice(void) const
// @Purpose: DirectFont获取D3D9设备
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
IDirect3DDevice9* WINAPI DirectFont::DirectFontGetDevice(void) const
{
	return m_pD3D9Device;
}

//------------------------------------------------------------------
// @Function:	 DirectFontGetFont(void) const
// @Purpose: DirectFont获取D3D9字体
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
ID3DXFont* WINAPI DirectFont::DirectFontGetFont(void) const
{
	return m_pD3D9Font;
}

//------------------------------------------------------------------
// @Function:	 DirectFontSetDevice(IDirect3DDevice9* pD3D9Device)
// @Purpose: DirectFont设置D3D9设备
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void WINAPI DirectFont::DirectFontSetDevice(IDirect3DDevice9* pD3D9Device)
{
	m_pD3D9Device = pD3D9Device;
}

//------------------------------------------------------------------
// @Function:	 DirectFontSetFont(ID3DXFont* pD3DXFont)
// @Purpose: DirectFont设置D3D9字体
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void WINAPI DirectFont::DirectFontSetFont(ID3DXFont* pD3DXFont)
{
	m_pD3D9Font = pD3DXFont;
}

//------------------------------------------------------------------
// @Function:	 DirectFontReset(void)
// @Purpose: DirectFont重置D3D9字体
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void WINAPI DirectFont::DirectFontReset(void)
{
	SAFE_RELEASE(m_pD3D9Font);
}

//------------------------------------------------------------------
// @Function:	 DirectFontInit(void)
// @Purpose: DirectFont初始化D3D9字体
// @Since: v1.00a
// @Para: int nFontSize
// @Para: LPWSTR lpszFontType
// @Return: None
//------------------------------------------------------------------
HRESULT WINAPI DirectFont::DirectFontInit(void)
{
	VERIFY(D3DXCreateFont(m_pD3D9Device, 12, 0, 0, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, _T("Consolas"), &m_pD3D9Font));

	return S_OK;
}

//------------------------------------------------------------------
// @Function:	 DirectFontInit(int nFontSize)
// @Purpose: DirectFont初始化D3D9字体
// @Since: v1.00a
// @Para: int nFontSize
// @Para: LPWSTR lpszFontType
// @Return: None
//------------------------------------------------------------------
HRESULT WINAPI DirectFont::DirectFontInit(int nFontSize)
{
	VERIFY(D3DXCreateFont(m_pD3D9Device, nFontSize, 0, 0, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, _T("Consolas"), &m_pD3D9Font));

	return S_OK;
}

//------------------------------------------------------------------
// @Function:	 DirectFontInit(int nFontSize, LPWSTR lpszFontType)
// @Purpose: DirectFont初始化D3D9字体
// @Since: v1.00a
// @Para: int nFontSize
// @Para: LPWSTR lpszFontType
// @Return: None
//------------------------------------------------------------------
HRESULT WINAPI DirectFont::DirectFontInit(int nFontSize, LPWSTR lpszFontType)
{
	VERIFY(D3DXCreateFont(m_pD3D9Device, nFontSize, 0, 0, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, lpszFontType, &m_pD3D9Font));
	
	return S_OK;
}

//---------------------------------------------------------------------------------------------------
// @Function:	 DirectFontDrawText(HWND hWnd, LPCWSTR lpcszStr, DWORD Format, D3DCOLOR Color)
// @Purpose: DirectFont初始化D3D9字体
// @Since: v1.00a
// @Para: int nFontSize
// @Para: LPWSTR lpszFontType
// @Return: None
//---------------------------------------------------------------------------------------------------
void WINAPI DirectFont::DirectFontDrawText(HWND hWnd, LPCWSTR lpcszStr, DWORD Format, D3DCOLOR Color)
{
	RECT Rect;

	GetClientRect(hWnd, &Rect);
	m_pD3D9Font->DrawText(NULL, lpcszStr, -1, &Rect, Format, Color);
}