#include <windows.h>
#include <string>
#include "config.h" 

#define IDC_VIRTUAL_FLASH  1001
#define IDC_PHYSICAL_FLASH 1002

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE: {
            CreateWindowW(L"BUTTON", L"Virtual Flash (Safe Sandbox VM)", 
                          WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                          BTN_VIRTUAL_X, BTN_VIRTUAL_Y, BTN_VIRTUAL_W, BTN_VIRTUAL_H, 
                          hWnd, (HMENU)IDC_VIRTUAL_FLASH, NULL, NULL);

            CreateWindowW(L"BUTTON", L"Physical Flash (Direct Hardware Write)", 
                          WS_VISIBLE | WS_CHILD, 
                          BTN_PHYSICAL_X, BTN_PHYSICAL_Y, BTN_PHYSICAL_W, BTN_PHYSICAL_H, 
                          hWnd, (HMENU)IDC_PHYSICAL_FLASH, NULL, NULL);
            break;
        }
        case WM_COMMAND: {
            switch (LOWORD(wp)) {
                case IDC_VIRTUAL_FLASH: {
                    MessageBoxW(hWnd, VIRTUAL_BOX_MSG, APP_TITLE, MB_OK | MB_ICONINFORMATION);
                    break;
                }
                case IDC_PHYSICAL_FLASH: {
                    MessageBoxW(hWnd, PHYSICAL_BOX_MSG, APP_TITLE, MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2);
                    break;
                }
            }
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = APP_CLASS_NAME;
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) return -1;

    HWND hWnd = CreateWindowW(APP_CLASS_NAME, APP_TITLE, 
                              WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
                              CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, 
                              NULL, NULL, hInst, NULL);
    
    ShowWindow(hWnd, ncmdshow);
    UpdateWindow(hWnd);

    MSG msg = {0};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
