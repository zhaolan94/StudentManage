#include <iostream>
#include "Student.h"
#include "MainScreen.h"
using namespace std;

int main()
{
    MainScreen *Screen = new MainScreen();//��ʼ��������
    delete Screen;
    return 0;
}
