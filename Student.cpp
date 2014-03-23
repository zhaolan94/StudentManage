#include "Student.h"
Student::Student(const string _name,const string _num ,const short  _sex,const short _age)
{
    name =_name;
    num = _num;
    sex = _sex;
    age = _age;
    next= nullptr;
    pre = nullptr;
}
string Student:: GetName()
{
    return name;
}
string Student:: GetNum()
{
    return num;
}
short  Student:: GetAge()
{
    return age;
}
short  Student:: GetSex()
{
    return sex;
}
void Student :: Display()
{
    cout << "Name:"<<GetName()<< endl;
    cout <<"Num:"<< GetNum()<< endl;
    cout <<"Sex:"<< GetSex()<< endl;
    cout <<"Age:"<<GetAge()<< endl;
}
StudentDataSet::StudentDataSet()
{
    phead = nullptr;
    ptail = nullptr;
    size = 0;
}
bool StudentDataSet::AddStudent(const string _name,const string _num ,const short  _sex,const short _age)
{
    if (0 == size)
    {
        phead = new Student(_name,_num,_sex,_age);
        ptail = phead;
        size = size + 1;
        return true;
    }
    else
    {
        ptail->next = new Student(_name,_num,_sex,_age);
        ptail->next->pre = ptail;
        ptail = ptail->next;
        size = size + 1;
        return true;
    }
}
Student* StudentDataSet::GetStudentByNum(const string _num)
{
    if (0 == size)
    {
        cout<<"Error:No Student in DataBase!"<<endl;
        return NULL;
    }
    else
    {
        Student *ptemp;
        ptemp = phead;
        while (ptemp != nullptr)
        {
            if (_num == ptemp->GetNum())
            {
                return ptemp;
            }
            ptemp = ptemp->next;
        }
        return NULL;

    }
}
bool StudentDataSet::DelStudentByNum(const string _num)
{
    if (0 == size)
    {
        cout<<"Error:No Student for DataBase!"<<endl;
        return false;
    }
    else
    {
        Student* ptemp;
        ptemp = GetStudentByNum(_num);
        if (NULL == ptemp)
        {
            cout<<"Cannot Found the student"<<endl;
            return false;
        }
        else
        {
            if (ptemp == phead)
            {
                phead = phead->next;


            }
            else if (ptemp == ptail)
            {
                ptail->pre->next = NULL;
                ptail = ptail -> pre;
            }
            else
            {
                ptemp->pre->next = ptemp->next;
                ptemp->next->pre = ptemp -> pre;
            }

            size = size - 1;
            delete ptemp;
            return true;
        }
    }
}
string StudentDataSet::GetMinNum(const Student* _phead)
{
    if (0 == size)
    {
        cout<<"Error:No Student for DataBase!"<<endl;
        return false;
    }
    else
    {
        string sMin;
        Student * ptemp;
        ptemp = phead;
        sMin = phead->GetNum();
        while(ptemp != nullptr)
        {
            if (sMin >ptemp->GetNum())
            {
                sMin = ptemp->GetNum();
            }
            ptemp = ptemp ->next;
        }
        return sMin;
    }

}
void StudentDataSet::SortByNum()
{
    Student *ptempHead,*ptempNode;
    StudentDataSet *pSorted = new StudentDataSet();
    int i,sizeTemp;
    if(0 == size)
    {
        cout<<"Error:No Student for Sort!"<<endl;
    }
    else
    {

        sizeTemp = size;

        for(i=1; i<=sizeTemp; i++)
        {
            ptempNode = GetStudentByNum((GetMinNum(phead)));
            pSorted->AddStudent(ptempNode->GetName(),ptempNode->GetNum(),ptempNode->GetSex(),ptempNode->GetSex());
            DelStudentByNum((GetMinNum(phead)));

        }
        phead = pSorted->GetHead();
        size = sizeTemp;
        delete pSorted;
    }

}
void StudentDataSet:: Display()
{
    if(0 == size)
    {
        cout<<"Error:No Student for DIsplay!"<<endl;
    }
    else
    {
        Student *ptemp;
        ptemp = phead;
        while (ptemp != nullptr)
        {
            cout<<"====================================="<<endl;
            ptemp->Display();
            ptemp = ptemp->next;
        }
    }

}
Student* StudentDataSet:: GetHead()
{
    return phead;
}
unsigned int StudentDataSet:: GetSize()
{
    return size;
}
StudentDataSet:: ~StudentDataSet()
{
    phead = nullptr;
}
void StudentDataSet:: SaveToFile()
{
    if(0 == size)
    {
        cout<<"Error:No Student for Save!"<<endl;
    }
    else
    {


        ofstream outfile("out.txt");
        streambuf *streams=cout.rdbuf();//保存原来的cout对象
        cout.rdbuf(outfile.rdbuf());
        Display();
        cout.rdbuf(streams);
    }
}
