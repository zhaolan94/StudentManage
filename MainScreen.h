#ifndef _MAINSCREEN_H_
#define _MAINSCREEN_H_
#include <iostream>
#include <stdlib.h>
#include "Student.h"
using namespace std;
class MainScreen
{
private:
    StudentDataSet* MainSet;
    void AddStudent();
    void FindStudent();
    void DelStudent();
    void SortStudent();
    void DisplayAllStudent();
    void SaveStudent();
public:
    MainScreen();
    ~MainScreen();
};
#endif // _MAINSCREEN_H_
