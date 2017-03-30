// ConsoleApplication1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "ConsoleApplication1.h"
#include "mainProc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �B��̃A�v���P�[�V���� �I�u�W�F�N�g�ł��B

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC �����������āA�G���[�̏ꍇ�͌��ʂ�������܂��B
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            wprintf(L"�v���I�ȃG���[: MFC �̏��������ł��܂���ł����B\n");
            nRetCode = 1;
        }
        else
        {
			mainProc proc;
//			proc.execute();
			proc.execute_array();
			//���s���ʊm�F�p�Ɉ�U�~�߂Ă���
			printf("���s�����B �L�[���͂ŏI��...\n");
			getchar();
        }
    }
    else
    {
        wprintf(L"�v���I�ȃG���[: GetModuleHandle �����s���܂���\n");
        nRetCode = 1;
    }

    return nRetCode;
}
