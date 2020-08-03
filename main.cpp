#include <Windows.h>

bool autoc;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    while (true)
    {
        if (GetAsyncKeyState(0x52) & 0x8000)
        {
            while (GetAsyncKeyState(0x52) & 0x8000);
            autoc = !autoc;
        }
        if (GetAsyncKeyState(0x30) & 0x8000)
        {
            while (GetAsyncKeyState(0x30) & 0x8000);
            exit(0);
        }
        if (autoc)
        {
            Sleep(10);
            mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
            mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
        }
    }

    return 0;
}