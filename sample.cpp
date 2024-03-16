#include <windows.h>

// window class name
#define MYWNDCLSNAME L"MyWindowClass"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wndcls;
	HWND hWnd;
	MSG msg;

	// register window class
	ZeroMemory(&wndcls, sizeof(wndcls));
	wndcls.lpfnWndProc = WndProc;
	wndcls.hInstance = hInst;
	wndcls.hIcon = LoadIcon(0, IDI_APPLICATION);
	wndcls.hCursor = LoadCursor(0, IDC_ARROW);
	wndcls.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	wndcls.lpszClassName = MYWNDCLSNAME;
	if (RegisterClass(&wndcls) == 0) return -1;

	// create main window
	hWnd = CreateWindowW(MYWNDCLSNAME, L"My Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, hInst, NULL);
	if (hWnd == 0) return -2;

	// design initial window state
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// message loop
	while (GetMessage(&msg, 0, 0, 0)) {
		DispatchMessage(&msg);
	}

	// wParam with WM_QUIT message to end code
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
		Sleep(60 * 1000);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}