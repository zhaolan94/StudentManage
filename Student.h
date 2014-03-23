#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//Student类 作为链表的节点
class Student
{
private:
    string name,num;//姓名，学号
    short age,sex;//年龄，性别（0为女1为男）

public:
    Student *next;//后驱指针
    Student *pre;//前驱指针
    Student(const string _name,const string _num ,const short  _sex,const short _age);
    string  GetName();
    string  GetNum();
    short   GetAge();
    short   GetSex();
    void    Display();//输出节点信息

};
//StudentDataSet类 实现整个链表的管理
class StudentDataSet
{
private:
    Student *phead;//头指针
    Student *ptail;//最后一个节点的指针
    unsigned int size;//节点数量

public:
    StudentDataSet();
    bool AddStudent(const string _name,const string _num ,const short  _sex,const short _age);//增加Student节点
    bool DelStudentByNum(const string _num);//删除节点
    void SortByNum();//将节点根据学号排序
    unsigned int GetSize();//获取节点个数
    Student* GetStudentByNum(const string _num);//根据学号获取节点
    string GetMinNum(const Student* _phead);//获取最小的学号
    Student* GetHead();//返回头指针
    void    Display();//输出所有节点
    void SaveToFile();//保存所有节点至文件
    ~StudentDataSet();

};






#endif // _STUDENT_H_
