#include"../../../General.h"
#include <tchar.h>
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

#ifdef ESCAPIST_OS_WINDOWS

extern int Main(int argc, Char **argv);

int WINAPI _tWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPTSTR, _In_ int) {
    int argc = 0;
    wchar_t** origArgv = ::CommandLineToArgvW(::GetCommandLineW(), &argc);
#ifdef ESCAPIST_32BITS
    char** argv = new char* [argc];
    for (int i = 0; i < argc; ++i) {
        int length = ::WideCharToMultiByte(CP_ACP, 0, origArgv[i], -1, nullptr, 0, nullptr, nullptr);
        argv[i] = new char[length + 1];
        ::WideCharToMultiByte(CP_ACP, 0, origArgv[i], -1, argv[i], length, nullptr, nullptr);
        argv[i][length] = 0;
    }
    int returnCode = Main(argc, argv);
#else
    int returnCode = Main(argc, origArgv);
#endif
#ifdef ESCAPIST_32BITS
    for (int i = 0; i < argc; ++i) {
        delete[] argv[i];
    }
    delete[] argv;
#endif
    ::LocalFree(origArgv);
    return returnCode;
}

#endif