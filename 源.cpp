#include <Windows.h> 
#include <tchar.h>

////��Ϣ�ص����� 
//LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {    
//	switch (message)    
//	{    
//	case WM_CLOSE:        
//		if (IDOK == MessageBox(hWnd, _T("��ȷ���˳���"), _T("�˳�"), MB_OKCANCEL))        
//		{            
//			DestroyWindow(hWnd);            
//			return 0;        
//		}    
//	case WM_DESTROY:        
//		PostQuitMessage(0);        
//		return 0;    
//	default:        
//			return DefWindowProc(hWnd, message, wParam, lParam);    
//	} 
//}
//
//int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
//	//Step1:ע��һ��������    
//	HWND hwnd; //���ڵľ��    
//	WNDCLASSEX wc; //������ṹ    
//	wc.cbSize = sizeof(WNDCLASSEX);
//	wc.style = CS_VREDRAW | CS_HREDRAW;
//	wc.lpszMenuName = 0;
//	wc.lpszClassName = _T("Win32");
//	wc.lpfnWndProc = WinProc; //��Ϣ�ص�����    
//	wc.hInstance = hInstance;
//	wc.hIcon = NULL;
//	wc.hCursor = NULL;
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wc.cbWndExtra = 0;
//	wc.cbClsExtra = 0;
//	wc.hIconSm = NULL;
//	RegisterClassEx(&wc); //ע�ᴰ��       
//	//Step2:����һ������   
//	hwnd = CreateWindow(
//		_T("Win32"), //���ڵ�������Ҳ�������������Զ���Ĵ����������        
//		_T("�ҵĵ�һ��Win32����"), //���ڵı���     
//		WS_OVERLAPPEDWINDOW, //����style      
//		500, //����λ��x����       
//		300, //����λ��y����        
//		800, //���ڿ��      
//		600, //���ڸ߶�      
//		NULL, //�����ھ��       
//		NULL, //�˵����      
//		hInstance, //ʵ�����    
//		NULL //��������      
//		);
//	if (!hwnd)
//	{
//		return FALSE;
//	}
//	ShowWindow(hwnd, SW_SHOW); //��ʾ���� 
//	UpdateWindow(hwnd); //ˢ��
//
//
//	//Step3:��Ϣѭ��    
//	MSG msg;
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return 0;
//}

#pragma once
#include <UIlib.h>
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

//1.
//#include <windows.h>
//#include <tchar.h>
//
//int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
//{
//	::MessageBox(NULL, _T("HeHeHe !"), _T("diyici"), NULL);
//	return 0;
//}

//2.
//class CDuiFrameWnd : public CWindowWnd, public INotifyUI
//{
//public:
//	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
//	virtual void    Notify(TNotifyUI& msg) {}
//
//	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
//	{
//		LRESULT lRes = 0;
//
//		if (uMsg == WM_CREATE)
//		{
//			CControlUI *pWnd = new CButtonUI;
//			pWnd->SetText(_T("Hello World"));   // ��������
//			pWnd->SetBkColor(0xFFFFFF00);       // ���ñ���ɫ
//
//			m_PaintManager.Init(m_hWnd);
//			m_PaintManager.AttachDialog(pWnd);
//			return lRes;
//		}
//
//		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
//		{
//			return lRes;
//		}
//
//		return __super::HandleMessage(uMsg, wParam, lParam);
//	}
//
//protected:
//	CPaintManagerUI m_PaintManager;
//};

//3.

class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void    Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			if (msg.pSender->GetName() == _T("btnHello"))
			{
				::MessageBox(NULL, _T("���ǰ�ť"), _T("����˰�ť"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetName(_T("btnHello"));      // ���ÿؼ������ƣ�����������ڱ�ʶÿһ���ؼ�������Ψһ���൱��MFC����Ŀؼ�ID
			pWnd->SetText(_T("Hello World"));   // ��������
			pWnd->SetBkColor(0xFF00FF00);       // ���ñ���ɫ

			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			m_PaintManager.AddNotifier(this);   // ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����
			return lRes;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.ShowModal();
	return 0;
}
