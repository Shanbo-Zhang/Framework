#include"Escapist/General.h"
#include"Escapist/GUI/Application.h"

int Main(int argc, Char** argv) {
	MessageBox(0, L"123456", L"7890", MB_OK);
	int rtn = ::GetLastError();
	return 0;
}