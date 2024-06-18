
typedef unsigned long DWORD;
typedef void *LPVOID;
typedef LPVOID HANDLE;
typedef HANDLE HWND;
typedef wchar_t WCHAR;
typedef const WCHAR *LPCWSTR;
typedef HANDLE HMENU;
typedef HANDLE HINSTANCE;
typedef int BOOL;
typedef long LONG;
typedef long LONG_PTR;
typedef unsigned int UINT;
typedef unsigned int UINT_PTR;
typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;
typedef LONG_PTR LRESULT;
typedef HANDLE HICON;

typedef struct _RECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *PRECT, *LPRECT;

WINAPI HWND CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle,
                     int X,
                     int Y,
                     int nWidth,
                     int nHeight,
                     HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
BOOL AdjustWindowRectEx(LPRECT lpRect, DWORD dwStyle, BOOL bMenu, DWORD dwExStyle);
LRESULT SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL SetWindowPos(
    HWND hWnd,
    HWND hWndInsertAfter,
    int X,
    int Y,
    int cx,
    int cy,
    UINT uFlags);
BOOL SetMenu(HWND hWnd, HMENU hMenu);
BOOL ShowWindow(HWND hWnd, int nCmdShow);
BOOL ShowWindowAsync(
  HWND hWnd,
  int  nCmdShow
);
BOOL SetWindowTextW(
    HWND hWnd,
    LPCWSTR lpString);
ULONG_PTR SetClassLongPtrA(
    HWND hWnd,
    int nIndex,
    LONG_PTR dwNewLong);
HANDLE LoadImageW(
    HINSTANCE hInst,
    LPCWSTR name,
    UINT type,
    int cx,
    int cy,
    UINT fuLoad);
HICON LoadIconW(
    HINSTANCE hInstance,
    LPCWSTR lpIconName);
