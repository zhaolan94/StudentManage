#include "MainScreen.h"
MainScreen::MainScreen()
{
    MainSet = new StudentDataSet();
    string input;
    do
    {
        system("cls");
        cout<<"========================================================="<<endl;
        cout<<"               ѧ����Ϣ����ϵͳ                          "<<endl;
        cout<<"========================================================="<<endl;
        cout<<"1������ѧ����Ϣ"<<endl;
        cout<<"2����ѧ�Ų���ѧ����Ϣ"<<endl;
        cout<<"3��ɾ��ѧ����Ϣ"<<endl;
        cout<<"4������Ϣ��ѧ������"<<endl;
        cout<<"5���������ѧ����Ϣ"<<endl;
        cout<<"6������ѧ����Ϣ���ļ�"<<endl;
        cout<<"                              ��ǰ����ѧ��"<<MainSet->GetSize()<<"��"<<endl;
        cout<<"����������Ҫ�Ĳ�����Ų��س����룬����quit�˳�ϵͳ��";
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
    cout<<"               ѧ����Ϣ����ϵͳ                          "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"������ѧ�����������س���������";
    cin>>name;
    cout<<"������ѧ��ѧ�ţ����س���������";
    cin>>num;
    cout<<"������ѧ���Ա�0ΪŮ�ԣ�1Ϊ���ԣ������س���������";
    cin>>sex;
    cout<<"������ѧ�����䣬���س���������";
    cin>>age;
    MainSet->AddStudent(name,num,sex,age);
}
void MainScreen::DisplayAllStudent()
{
    system("cls");
    cout<<"========================================================="<<endl;
    cout<<"               ѧ����Ϣ����ϵͳ                          "<<endl;
    cout<<"========================================================="<<endl;
    MainSet->Display();
    system("pause");
}
void MainScreen::FindStudent()
{
    string num;
    system("cls");
    cout<<"========================================================="<<endl;
    cout<<"               ѧ����Ϣ����ϵͳ                          "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"������ѧ��ѧ�ţ����س���������";
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
    cout<<"               ѧ����Ϣ����ϵͳ                          "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"������ѧ��ѧ�ţ����س���������";
    cin>>num;
    MainSet->DelStudentByNum(num);
    system("pause");
}
void MainScreen::SortStudent()
{
    system("cls");
    cout<<"========================================================="<<endl;
    cout<<"               ѧ����Ϣ����ϵͳ                          "<<endl;
    cout<<"========================================================="<<endl;
    MainSet->SortByNum();
    cout<<"�������"<<endl;
    system("pause");
}
void MainScreen::SaveStudent()
{
    system("cls");
    cout<<"========================================================="<<endl;
    cout<<"               ѧ����Ϣ����ϵͳ                          "<<endl;
    cout<<"========================================================="<<endl;
    MainSet->SaveToFile();
    cout<<"���浽out.txt"<<endl;
    system("pause");
}
MainScreen:: ~MainScreen()
{
    delete MainSet;
}
