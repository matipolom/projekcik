﻿#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include<cstdlib>
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
#define TMR_1 1


bool isTimerrunning=0;
char kierunek;
int value=0;
RECT drawArea = {230,20,370,700};
HPEN	pen = CreatePen(PS_SOLID, 10, 0X000000);
HPEN	penW = CreatePen(PS_SOLID, 10, 0xFFFFFF);


 


VOID OnPaint(HDC hdc,bool direction,int y,int &yl,int &yr)
{
	if (direction == 1) {

		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			yl=y-160 - value,
			360,
			yr=y - value
		);
		Sleep(100);
		SelectObject(hdc, penW);
		Rectangle(
			hdc,
			230,
			y-160 - value,
			360,
			y - value
		);

	}
	else {
		SelectObject(hdc, pen);
		Rectangle(
			hdc,
			230,
			yl=y -160+ value,
			360,
			yr=y + value
		);
		Sleep(100);
		SelectObject(hdc, penW);
		Rectangle(
			hdc,
			230,
			y-160 + value,
			360,
			y + value
		);
		
	}
	value++;
}

void Background(HDC hdc) {
	Graphics graphics(hdc);
	Pen      pen(Color(255, 0, 0, 0), 10);
	graphics.DrawLine(&pen, 0, 180, 200, 180);
	graphics.DrawLine(&pen, 0, 330, 200, 330);
	graphics.DrawLine(&pen, 0, 480, 200, 480);
	graphics.DrawLine(&pen, 0, 630, 200, 630);
	graphics.DrawRectangle(&pen, 210, 10, 170, 700);
	graphics.DrawRectangle(&pen, 230, 470, 129, 159);
}

	int t;
	int pietro;
	bool direction=0;
	int yl;
	int yr=630;

	
void repaintWindow(HWND hWnd, HDC& hdc, PAINTSTRUCT& ps,RECT *drawArea)
{
	
	
	
	

	hdc = GetDC(hWnd);
	
	OnPaint(hdc,direction,t,yl,yr);
	ReleaseDC(hWnd, hdc);
	
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
	static HWND hwndTextButton1;
	static HWND hwndTextButton2;
	static HWND hwndTextButton3;
	static HWND hwndTextButton4;
	static HWND hwndTextOut;
	TCHAR val[4] = { 0 };
	switch (message)
	{
	case WM_CREATE:
		hwndTextOut = CreateWindowEx(0, L"Static", TEXT("0"),WS_CHILD | WS_VISIBLE | SS_CENTER, 500, 50, 20, 20, hWnd, NULL, NULL, NULL);
		hwndTextButton1 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
			WS_CHILD | WS_VISIBLE, 75, 500, 40,
			20, hWnd, NULL, NULL, NULL);

		hwndTextButton2 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
			WS_CHILD | WS_VISIBLE, 75, 350, 40,
			20, hWnd, NULL, NULL, NULL);

		hwndTextButton3 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
			WS_CHILD | WS_VISIBLE, 75, 200, 40,
			20, hWnd, NULL, NULL, NULL);

		hwndTextButton4 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
			WS_CHILD | WS_VISIBLE, 75, 50, 40,
			20, hWnd, NULL, NULL, NULL);
		
		break;
	case WM_COMMAND:
	switch(wParam){
	case ID_PRZYCISK1_2: {
		if (isTimerrunning || yr!=630  )
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);
		
		t = 630;
		pietro= 150;
		direction = 1;
		GetWindowText(hwndTextButton1, val, 4);
		SetWindowText(hwndTextOut,val) ;
		}
		
	
	break;
	case ID_PRZYCISK1_3: {
		if (isTimerrunning || yr != 630)
			break;

		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 630;
		pietro = 300;
		direction = 1;
		GetWindowText(hwndTextButton1, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK1_4: {
		if (isTimerrunning || yr != 630)
			break;

		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 630;
		pietro = 430;
		direction = 1;
		GetWindowText(hwndTextButton1, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK2_1: {
		if (isTimerrunning || yr != 480)
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 480;
		pietro = 150;
		direction = 0;
		GetWindowText(hwndTextButton2, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK2_3: {
		if (isTimerrunning || yr != 480)
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 480;
		pietro = 150;
		direction = 1;
		GetWindowText(hwndTextButton2, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK2_4: {
		if (isTimerrunning || yr != 480)
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 480;
		pietro = 300;
		direction = 1;
		GetWindowText(hwndTextButton2, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK3_1: {
		if (isTimerrunning || yr != 330)
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 330;
		pietro = 300;
		direction = 0;
		GetWindowText(hwndTextButton3, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK3_2: {
		if (isTimerrunning || yr != 330)
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 330;
		pietro = 150;
		direction = 0;
		GetWindowText(hwndTextButton3, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK3_4: {
		if (isTimerrunning || yr != 330)
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 330;
		pietro = 150;
		direction = 1;
		GetWindowText(hwndTextButton3, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK4_1: {
		if (isTimerrunning || yr != 180)
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 180;
		pietro = 450;
		direction = 0;
		GetWindowText(hwndTextButton4, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK4_2: {
		if (isTimerrunning || yr != 180)
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 180;
		pietro = 300;
		direction = 0;
		GetWindowText(hwndTextButton4, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	case ID_PRZYCISK4_3: {
		if (isTimerrunning || yr != 180)
			break;
		isTimerrunning=SetTimer(hWnd, TMR_1, 25, NULL);

		t = 180;
		pietro = 150;
		direction = 0;
		GetWindowText(hwndTextButton4, val, 4);
		SetWindowText(hwndTextOut, val);
	}


					   break;
	}
	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			
			repaintWindow(hWnd, hdc, ps, &drawArea);
			if (value >= pietro) {
				hdc = GetDC(hWnd);
				SelectObject(hdc, pen);
				Rectangle(hdc, 230, yl, 360, yr);
				ReleaseDC(hWnd, hdc);
				value = 0;
				KillTimer(hWnd, TMR_1);
				isTimerrunning = 0;
				SetWindowText(hwndTextOut, TEXT("0"));
				break;
			}
			value++;
			break;
		}

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Background(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
} // WndProc