// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "ConsoleApplication1.h"
#include "mainProc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一のアプリケーション オブジェクトです。

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC を初期化して、エラーの場合は結果を印刷します。
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            wprintf(L"致命的なエラー: MFC の初期化ができませんでした。\n");
            nRetCode = 1;
        }
        else
        {
			mainProc proc;
//			proc.execute();
			proc.execute_array();
			//実行結果確認用に一旦止めておく
			printf("実行完了。 キー入力で終了...\n");
			getchar();
        }
    }
    else
    {
        wprintf(L"致命的なエラー: GetModuleHandle が失敗しました\n");
        nRetCode = 1;
    }

    return nRetCode;
}
