﻿#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

#define ID_PRZYCISK1_2 501
#define ID_PRZYCISK1_3 502
#define ID_PRZYCISK1_4 503
#define ID_PRZYCISK2_1 504
#define ID_PRZYCISK2_3 505
#define ID_PRZYCISK2_4 506
#define ID_PRZYCISK3_1 507
#define ID_PRZYCISK3_2 508
#define ID_PRZYCISK3_4 509
#define ID_PRZYCISK4_1 510
#define ID_PRZYCISK4_2 511
#define ID_PRZYCISK4_3 512


VOID OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen      pen(Color(255, 0, 0, 0), 10);
	graphics.DrawLine(&pen, 0, 180, 200, 180);
	graphics.DrawLine(&pen, 0, 330, 200, 330);
	graphics.DrawLine(&pen, 0, 480, 200, 480);
	graphics.DrawLine(&pen, 0, 630, 200, 630 );
	graphics.DrawRectangle(&pen, 210, 10, 170, 700);
	//graphics.DrawRectangle(&pen, 230, 30, 130, 150);
	

}



void movement( HDC &hdc,int current_top, int current_bottom, int target_top, int target_bottom ) {// nie działa, możesz coś ogarnąć z animacją ruchu windy? Może trzeba użyć timera ? 

	while (current_bottom = !target_bottom) {
		Rectangle(
			hdc,
			230,
			current_top++,
			360,
			current_bottom++
		);
	}
	
}


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	
	HWND                hWnd;
	MSG                 msg;
	WNDCLASS            wndClass;
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	Pen      pen(Color(255, 0, 0, 0), 10);
	


	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = TEXT("GettingStarted");

	RegisterClass(&wndClass);

	hWnd = CreateWindow(
		TEXT("GettingStarted"),   // window class name
		TEXT("WINDA"),  // window caption
		WS_OVERLAPPEDWINDOW,      // window style
		CW_USEDEFAULT,            // initial x position
		CW_USEDEFAULT,            // initial y position
		CW_USEDEFAULT,            // initial x size
		CW_USEDEFAULT,            // initial y size
		NULL,                     // parent window handle
		NULL,                     // window menu handle
		hInstance,                // program instance handle
		NULL);                    // creation parameters

	HWND hStaticIcon = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_CENTER, 500, 50, 48, 48, hWnd, NULL, hInstance, NULL);
	SetWindowText(hStaticIcon, L"66");

	HWND hwndButton1_2 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"2",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		550,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK1_2,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndButton1_3 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"3",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		60,         // x position 
		550,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK1_3,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndButton1_4 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"4",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		110,         // x position 
		550,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK1_4,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndTextButton1 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE, 75	, 500, 40,
		20, hWnd, NULL, NULL, NULL);

	//DWORD dlugosc_1 = GetWindowTextLength(hwndTextButton1);
	//LPSTR Bufor_1 = (LPSTR)GlobalAlloc(GPTR, dlugosc_1 + 1);
	//GetWindowText(hwndTextButton1, Bufor_1, dlugosc_1 + 1);


	HWND hwndButton2_1 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"1",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		400,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK2_1,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndButton2_3 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"3",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		60,         // x position 
		400,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK2_3,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndButton2_4 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"4",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		110,         // x position 
		400,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK2_4,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndTextButton2 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE, 75, 350, 40,
		20, hWnd, NULL, NULL, NULL);

	HWND hwndButton3_1 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"1",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		250,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK3_1,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndButton3_2 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"2",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		60,         // x position 
		250,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK3_2,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndButton3_4 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"4",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		110,         // x position 
		250,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK3_4,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndTextButton3 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE, 75, 200, 40,
		20, hWnd, NULL, NULL, NULL);

	HWND hwndButton4_1 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"1",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		100,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK4_1,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndButton4_2 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"2",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		60,         // x position 
		100,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK4_2,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndButton4_3 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"3",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		110,         // x position 
		100,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)ID_PRZYCISK4_3,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndTextButton4 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE, 75, 50, 40,
		20, hWnd, NULL, NULL, NULL);

	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	GdiplusShutdown(gdiplusToken);
	return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC          hdc;
	PAINTSTRUCT  ps;
	HPEN      pen=CreatePen(PS_SOLID, 10,0X000000);

	switch (message)
	{
	case WM_COMMAND:
	switch(wParam){
	case ID_PRZYCISK1_2: {
		
		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		int x = 630;
		int y = 480;
		/* Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);*/
		 movement(hdc,480,630, x, y);
		ReleaseDC(hWnd, hdc);
		}
		
	
	break;
	case ID_PRZYCISK1_3: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK1_4: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK2_1: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK2_3: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK2_4: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK3_1: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK3_2: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK3_4: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK4_1: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK4_2: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	case ID_PRZYCISK4_3: {

		hdc = GetDC(hWnd);
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			450,
			360,
			630
		);

		ReleaseDC(hWnd, hdc);
	}
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		OnPaint(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
} // WndProc