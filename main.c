#include "resource.h"
#include <windows.h>

char* titleprocess(int leng1, HWND hwnd);
char* stringprocess(int leng2, HWND hwnd);
 
BOOL CALLBACK DlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    int len;
	int len1;

	char* buf = NULL;
	char* buf1 = NULL;
	
	switch(Message)
    {
        case WM_INITDIALOG:
		{
			SetDlgItemText(hwnd, IDC_TITLE, "Enter string");
			SetDlgItemText(hwnd, IDC_STRING, "Enter string");
		}
		return TRUE;

		case WM_COMMAND:
		{
			len = GetWindowTextLength(GetDlgItem(hwnd, IDC_TITLE));
			len1 = GetWindowTextLength(GetDlgItem(hwnd, IDC_STRING));
    		if(len > 0 && len1 > 0)
			{
				buf = titleprocess(len, hwnd);
				buf1 = stringprocess(len1, hwnd);
			}
			switch(LOWORD(wParam))
            {
                case IDC_EXCLA:
				{
					MessageBox(NULL, buf1, buf, MB_OK | MB_ICONEXCLAMATION);
				}
                break;

				case IDC_INFO:
				{
					MessageBox(NULL, buf1, buf, MB_OK | MB_ICONINFORMATION);
				}
                break;

                case IDC_QUES:
				{
					MessageBox(NULL, buf1, buf, MB_OK | MB_ICONQUESTION);
				}
                break;

                case IDC_STOP:
				{
					MessageBox(NULL, buf1, buf, MB_OK | MB_ICONSTOP);
				}
                break;
			}
		}
        break;
		
		case WM_CLOSE:
        	GlobalFree(buf);
			GlobalFree(buf1);
			EndDialog(hwnd, 0);
		break;
        default:
            return FALSE;
    }
    return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, DlgProc);
}

char* titleprocess(int leng1, HWND hwnd)
{
 	char* buf;

    buf = (char*)GlobalAlloc(GPTR, leng1 + 1);
    GetDlgItemText(hwnd, IDC_TITLE, buf, leng1 + 1);

	return buf;
}
char* stringprocess(int leng2, HWND hwnd)
{
	char* buf;

    buf = (char*)GlobalAlloc(GPTR, leng2 + 1);
    GetDlgItemText(hwnd, IDC_STRING, buf, leng2 + 1);

	return buf;
}

