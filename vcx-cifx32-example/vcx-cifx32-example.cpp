// vcx-cifx32-example.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <wtypes.h>
#include <atlstr.h>

#pragma comment (lib, "vcx-cifX32.lib")   // dll을 추가하면 lib가 아니라 제대로 참조되지 않음.

int main()
{
    typedef int (*addNumber)(int, int);
    HMODULE hmodl = LoadLibraryA("vcx-cifX32.dll");

    if (hmodl == NULL)
    {
        std::cout << "LoadLobrary failed" << std::endl;
    }
    else {
        addNumber add = (int(*)(int, int))GetProcAddress(hmodl, "sum");    // GetProcAddress: 찾고 싶은 함수의 이름을 문자열로 찾으면 해당 함수의 주소 반환
        printf("10 + 20 = %d \n", add(10, 20));
    }

    FreeLibrary(hmodl);
}