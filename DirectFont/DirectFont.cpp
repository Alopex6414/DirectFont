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

//DirectFont��Ҫ����2D/3D���ֻ���

//------------------------------------------------------------------
// @Function:	 DirectFont()
// @Purpose: DirectFont���캯��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
DirectFont::DirectFont()
{
	m_pD3D9Device = NULL;			//IDirect3DDevice9�ӿ�ָ���ʼ��(NULL)
	m_pD3D9Font = NULL;				//IDirect3DFont9�ӿ�ָ���ʼ��(NULL)
}

//------------------------------------------------------------------
// @Function:	 ~DirectFont()
// @Purpose: DirectFont��������
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
DirectFont::~DirectFont()
{
	SAFE_RELEASE(m_pD3D9Font);		//IDirect3DFont9�ӿ�ָ���ͷ�
}

//------------------------------------------------------------------
// @Function:	 DirectFont(IDirect3DDevice9* pD3D9Device)
// @Purpose: DirectFont���캯��
// @Since: v1.00a
// @Para: IDirect3DDevice9* pD3D9Device	//D3D9�����豸
// @Return: None
//------------------------------------------------------------------
DirectFont::DirectFont(IDirect3DDevice9* pD3D9Device)
{
	m_pD3D9Device = pD3D9Device;	//IDirect3DDevice9�ӿ�ָ���ʼ��(NULL)
	m_pD3D9Font = NULL;				//IDirect3DFont9�ӿ�ָ���ʼ��(NULL)
}

//------------------------------------------------------------------
// @Function:	 DirectFontGetDevice(void) const
// @Purpose: DirectFont��ȡD3D9�豸
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
// @Purpose: DirectFont��ȡD3D9����
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
// @Purpose: DirectFont����D3D9�豸
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
// @Purpose: DirectFont����D3D9����
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
// @Purpose: DirectFont����D3D9����
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
// @Purpose: DirectFont��ʼ��D3D9����
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
// @Purpose: DirectFont��ʼ��D3D9����
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
// @Purpose: DirectFont��ʼ��D3D9����
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
// @Purpose: DirectFont��ʼ��D3D9����
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