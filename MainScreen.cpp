#include "MainScreen.h"
MainScreen::MainScreen()
{
    MainSet = new StudentDataSet();
    string input;
    do
    {
        system("cls");
        cout<<"========================================================="<<endl;
        cout<<"               学生信息管理系统                          "<<endl;
        cout<<"========================================================="<<endl;
        cout<<"1、增加学生信息"<<endl;
        cout<<"2、按学号查找学生信息"<<endl;
        cout<<"3、删除学生信息"<<endl;
        cout<<"4、将信息按学号排序"<<endl;
        cout<<"5、输出所有学生信息"<<endl;
        cout<<"6、保存学生信息到文件"<<endl;
        cout<<"                              当前共有学生"<<MainSet->GetSize()<<"个"<<endl;
        cout<<"请输入所需要的操作序号并回车进入，输入quit退出系统：";
        cin>>input;
        if (input == "quit")
        {
            break;
        }
        else if (input == "1")
        {
            AddStudent();
        }
        else if (input == "2")
        {
            FindStudent();
        }
        else if (input == "3")
        {
            DelStudent();
        }
        else if (input == "4")
        {
            SortStudent();
        }
        else if (input == "5")
        {
            DisplayAllStudent();
        }
        else if (input == "6")
        {


            SaveStudent();

        }
    }
    while(1);
}
void MainScreen::AddStudent()
{
    system("cls");
    string name,num;
    short sex,age;
    cout<<"========================================================="<<endl;
    cout<<"               学生信息管理系统                          "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"请输入学生姓名，按回车键结束：";
    cin>>name;
    cout<<"请输入学生学号，按回车键结束：";
    cin>>num;
    cout<<"请输入学生性别（0为女性，1为男性），按回车键结束：";
    cin>>sex;
    cout<<"请输入学生年龄，按回车键结束：";
    cin>>age;
    MainSet->AddStudent(name,num,sex,age);
}
void MainScreen::DisplayAllStudent()
{
    system("cls");
    cout<<"========================================================="<<endl;
    cout<<"               学生信息管理系统                          "<<endl;
    cout<<"========================================================="<<endl;
    MainSet->Display();
    system("pause");
}
void MainScreen::FindStudent()
{
    string num;
    system("cls");
    cout<<"========================================================="<<endl;
    cout<<"               学生信息管理系统                          "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"请输入学生学号，按回车键结束：";
    cin>>num;
    if(NULL !=  MainSet->GetStudentByNum(num))
    {
        MainSet->GetStudentByNum(num)->Display();
    }
    system("pause");
}
void MainScreen::DelStudent()
{
    string num;
    system("cls");
    cout<<"========================================================="<<endl;
    cout<<"               学生信息管理系统                          "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"请输入学生学号，按回车键结束：";
    cin>>num;
    MainSet->DelStudentByNum(num);
    system("pause");
}
void MainScreen::SortStudent()
{
    system("cls");
    cout<<"========================================================="<<endl;
    cout<<"               学生信息管理系统                          "<<endl;
    cout<<"========================================================="<<endl;
    MainSet->SortByNum();
    cout<<"排序完毕"<<endl;
    system("pause");
}
void MainScreen::SaveStudent()
{
    system("cls");
    cout<<"========================================================="<<endl;
    cout<<"               学生信息管理系统                          "<<endl;
    cout<<"========================================================="<<endl;
    MainSet->SaveToFile();
    cout<<"保存到out.txt"<<endl;
    system("pause");
}
MainScreen:: ~MainScreen()
{
    delete MainSet;
}
