#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//Student�� ��Ϊ����Ľڵ�
class Student
{
private:
    string name,num;//������ѧ��
    short age,sex;//���䣬�Ա�0ΪŮ1Ϊ�У�

public:
    Student *next;//����ָ��
    Student *pre;//ǰ��ָ��
    Student(const string _name,const string _num ,const short  _sex,const short _age);
    string  GetName();
    string  GetNum();
    short   GetAge();
    short   GetSex();
    void    Display();//����ڵ���Ϣ

};
//StudentDataSet�� ʵ����������Ĺ���
class StudentDataSet
{
private:
    Student *phead;//ͷָ��
    Student *ptail;//���һ���ڵ��ָ��
    unsigned int size;//�ڵ�����

public:
    StudentDataSet();
    bool AddStudent(const string _name,const string _num ,const short  _sex,const short _age);//����Student�ڵ�
    bool DelStudentByNum(const string _num);//ɾ���ڵ�
    void SortByNum();//���ڵ����ѧ������
    unsigned int GetSize();//��ȡ�ڵ����
    Student* GetStudentByNum(const string _num);//����ѧ�Ż�ȡ�ڵ�
    string GetMinNum(const Student* _phead);//��ȡ��С��ѧ��
    Student* GetHead();//����ͷָ��
    void    Display();//������нڵ�
    void SaveToFile();//�������нڵ����ļ�
    ~StudentDataSet();

};






#endif // _STUDENT_H_
