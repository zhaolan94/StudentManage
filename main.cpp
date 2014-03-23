#include <iostream>
#include "Student.h"
#include "MainScreen.h"
using namespace std;

int main()
{
    MainScreen *Screen = new MainScreen();//初始化主界面
    delete Screen;
    return 0;
}
