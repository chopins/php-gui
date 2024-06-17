#define WINAPI __stdcall
#define WS_OVERLAPPED 0x00000000L
#define WS_CAPTION 0x00C00000L
#define WS_SYSMENU 0x00080000L
#define WS_MINIMIZEBOX 0x00020000L
#define WS_MAXIMIZEBOX 0x00010000L
#define WS_THICKFRAME 0x00040000L
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED |  \
                             WS_CAPTION |     \
                             WS_SYSMENU |     \
                             WS_THICKFRAME |  \
                             WS_MINIMIZEBOX | \
                             WS_MAXIMIZEBOX)
// Show window commands
#define SW_HIDE 0
#define SW_SHOWNORMAL 1
#define SW_NORMAL 1
#define SW_SHOWMINIMIZED 2
#define SW_SHOWMAXIMIZED 3
#define SW_MAXIMIZE 3
#define SW_SHOWNOACTIVATE 4
#define SW_SHOW 5
#define SW_MINIMIZE 6
#define SW_SHOWMINNOACTIVE 7
#define SW_SHOWNA 8
#define SW_RESTORE 9
#define SW_SHOWDEFAULT 10
#define SW_FORCEMINIMIZE 11
#define SW_MAX 11
#define GCLP_HICON -14   // 替换与 类关联的图标的句柄
#define GCLP_HICONSM -34 // 检索与 类关联的小图标的句柄。

#if defined(_WIN64)
typedef int64_t INT_PTR;
typedef int64_t LONG_PTR;
typedef uint64_t UINT_PTR;
typedef uint64_t ULONG_PTR;
#else
typedef int INT_PTR;
typedef long LONG_PTR;
typedef unsigned int UINT_PTR;
typedef unsigned long ULONG_PTR;
#endif

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

HWND CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle,
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
