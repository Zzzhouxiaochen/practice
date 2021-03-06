#include <Windows.h> 
#include <tchar.h>

////消息回调函数 
//LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {    
//	switch (message)    
//	{    
//	case WM_CLOSE:        
//		if (IDOK == MessageBox(hWnd, _T("你确定退出？"), _T("退出"), MB_OKCANCEL))        
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
//	//Step1:注册一个窗口类    
//	HWND hwnd; //窗口的句柄    
//	WNDCLASSEX wc; //窗口类结构    
//	wc.cbSize = sizeof(WNDCLASSEX);
//	wc.style = CS_VREDRAW | CS_HREDRAW;
//	wc.lpszMenuName = 0;
//	wc.lpszClassName = _T("Win32");
//	wc.lpfnWndProc = WinProc; //消息回调函数    
//	wc.hInstance = hInstance;
//	wc.hIcon = NULL;
//	wc.hCursor = NULL;
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wc.cbWndExtra = 0;
//	wc.cbClsExtra = 0;
//	wc.hIconSm = NULL;
//	RegisterClassEx(&wc); //注册窗口       
//	//Step2:创建一个窗口   
//	hwnd = CreateWindow(
//		_T("Win32"), //窗口的类名，也就是上面我们自定义的窗口类的名字        
//		_T("我的第一个Win32程序"), //窗口的标题     
//		WS_OVERLAPPEDWINDOW, //窗口style      
//		500, //窗口位置x坐标       
//		300, //窗口位置y坐标        
//		800, //窗口宽度      
//		600, //窗口高度      
//		NULL, //父窗口句柄       
//		NULL, //菜单句柄      
//		hInstance, //实例句柄    
//		NULL //创建数据      
//		);
//	if (!hwnd)
//	{
//		return FALSE;
//	}
//	ShowWindow(hwnd, SW_SHOW); //显示窗口 
//	UpdateWindow(hwnd); //刷新
//
//
//	//Step3:消息循环    
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
//			pWnd->SetText(_T("Hello World"));   // 设置文字
//			pWnd->SetBkColor(0xFFFFFF00);       // 设置背景色
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
				::MessageBox(NULL, _T("我是按钮"), _T("点击了按钮"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetName(_T("btnHello"));      // 设置控件的名称，这个名称用于标识每一个控件，必须唯一，相当于MFC里面的控件ID
			pWnd->SetText(_T("Hello World"));   // 设置文字
			pWnd->SetBkColor(0xFF00FF00);       // 设置背景色

			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理
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
