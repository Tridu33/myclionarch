#include<Windows.h>
#include<iostream>
#include<tchar.h>
#include<string>
using namespace std;

int main()
{
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;


    string cmd = "notepad";//调用的程序：记事本
    TCHAR w[256];
    MultiByteToWideChar(CP_ACP, 0, cmd.c_str(), -1, w, 256);
    //TCHAR szCommandLine[] = TEXT(cmd);

    CreateProcess(NULL, w, NULL, NULL,FALSE, 0, NULL, NULL, &si, &pi); //创建进程
    int signal=WaitForSingleObject(pi.hProcess, 3000);//设置运行时间3s
    if (signal != WAIT_OBJECT_0)//判断是否如果超时
    {
        cout << "time out" << endl;
        TerminateProcess(pi.hProcess, -1);
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

}