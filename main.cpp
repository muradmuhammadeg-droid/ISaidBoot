#include <windows.h>
#include <string>

#define IDC_VIRTUAL_FLASH  1001
#define IDC_PHYSICAL_FLASH 1002

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE: {
            // Button 1: Safe Sandboxed Virtual Flash
            CreateWindowW(L"BUTTON", L"Virtual Flash (Safe Sandbox VM)", 
                          WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                          20, 30, 340, 40, hWnd, (HMENU)IDC_VIRTUAL_FLASH, NULL, NULL);

            // Button 2: High-Risk Direct Physical Flash
            CreateWindowW(L"BUTTON", L"Physical Flash (Direct Hardware Write)", 
                          WS_VISIBLE | WS_CHILD, 
                          20, 90, 340, 40, hWnd, (HMENU)IDC_PHYSICAL_FLASH, NULL, NULL);
            break;
        }
        case WM_COMMAND: {
            switch (LOWORD(wp)) {
                case IDC_VIRTUAL_FLASH: {
                    MessageBoxW(hWnd, 
                                L"Launching Isolated Sandbox...\n\nThis will safely mount the ISO inside a local virtual instance without altering your host hardware configurations.", 
                                L"ISaidBoot!! - Virtual Flash Mode", 
                                MB_OK | MB_ICONINFORMATION);
                    break;
                }
                case IDC_PHYSICAL_FLASH: {
                    int response = MessageBoxW(hWnd, 
                                               L"CRITICAL WARNING:\n\nPhysical flashing writes data blocks directly to raw storage sectors, destroying all pre-existing partitions.\n\nOne incorrect targeted drive index can permanently wipe your host operating system.\n\nAre you absolutely certain you want to proceed?", 
                                               L"ISaidBoot!! - DANGER ZONE", 
                                               MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2);
                    if (response == IDYES) {
                        // Hardware flashing execution goes here
                    }
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
    wc.lpszClassName = L"ISaidBootGuiClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) return -1;

    HWND hWnd = CreateWindowW(L"ISaidBootGuiClass", L"ISaidBoot!! Deployment Engine", 
                              WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, 
                              CW_USEDEFAULT, CW_USEDEFAULT, 400, 190, NULL, NULL, hInst, NULL);
    
    ShowWindow(hWnd, ncmdshow);
    UpdateWindow(hWnd);

    MSG msg = {0};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
