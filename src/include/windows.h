
#define WINAPI 
#define CALLBACK 

typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef void* LPVOID;
typedef int BOOL;
typedef long LONG;
typedef long LONG_PTR;
typedef unsigned int UINT;
typedef unsigned int UINT_PTR;
typedef wchar_t WCHAR;
typedef char CHAR;
typedef LPVOID HANDLE;
typedef HANDLE HWND;

typedef const WCHAR *LPCWSTR;
typedef HANDLE HMENU;
typedef HANDLE HINSTANCE;

typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;
typedef LONG_PTR LRESULT;
typedef HANDLE HICON;
typedef WORD ATOM;
typedef HICON HCURSOR;
typedef HANDLE HBRUSH;
typedef const CHAR *LPCSTR;
typedef const WCHAR *LPCWSTR;

typedef LRESULT (CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct _RECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *PRECT, *LPRECT;

typedef struct tagWNDCLASSEXA
{
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, *NPWNDCLASSEXA, *LPWNDCLASSEXA;

WINAPI HWND CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X,int Y,int nWidth,int nHeight,HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
WINAPI BOOL AdjustWindowRectEx(LPRECT lpRect, DWORD dwStyle, BOOL bMenu, DWORD dwExStyle);
WINAPI LRESULT SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
WINAPI BOOL SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
WINAPI BOOL SetMenu(HWND hWnd, HMENU hMenu);
WINAPI BOOL ShowWindow(HWND hWnd, int nCmdShow);
WINAPI BOOL ShowWindowAsync(HWND hWnd, int nCmdShow);
WINAPI BOOL SetWindowTextW(HWND hWnd, LPCWSTR lpString);
WINAPI ULONG_PTR SetClassLongPtrA(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
WINAPI HANDLE LoadImageW(HINSTANCE hInst, LPCWSTR name, UINT type, int cx, int cy, UINT fuLoad);
WINAPI HICON LoadIconW(HINSTANCE hInstance, LPCWSTR lpIconName);
WINAPI ATOM RegisterClassExA(const WNDCLASSEXA *unnamedParam1);
