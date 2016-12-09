#include <string>
#include <regex>
#include "people.h"
using namespace std;


//People
People::People(int itype,string iname,string ipassword,long long int inum)
    :
        type(itype),name(iname),password(ipassword),num(inum)
        {
        }

bool People::set_password(string ipassword)
{
    if (judge_password(ipassword))
    {
        password=ipassword;
        return true;
    }
    else return false;
}

bool People::judge_password(string ipassword)
{
    if (regex_match(ipassword,regex("^\\w{6,12}$")))
    {
        return true;
    }
    else return false;
}

string People::get_name(void)
{
    return name;

}
string People::get_password(void)
{
    return password;
}
long long int People::get_num(void)
{
    return num;
}



//Teacher

vector<Teacher> Teacher::teacher;

Teacher::Teacher(string iname,string ipassword,long long int inum):
        People(tea,iname,ipassword,inum)  {}

vector<Teacher>* Teacher::get_teacher_vec(void)
{
    return &teacher;
}
vector<Teacher>::iterator Teacher::find_tea(vector<Teacher>* t,long long int num)
{
    vector<Teacher>::iterator cur=t->begin();
    for (cur;cur<t->end();cur++)
    {
        if (cur->num==num)
            return cur;
    }
    return t->end();
}
vector <Teacher>::iterator Teacher::in_teacher(Teacher temp)
{
    teacher.push_back(temp);
    return teacher.begin();
}

//Student

vector<Student> Student::student;

Student::Student(string iname,string ipassword,long long int inum,float iscore1,float iscore2
            ,float iscore3)
        :People(stu,iname,ipassword,inum),score1(iscore1),score2(iscore2),score3(iscore3),
         average((iscore1+iscore2+iscore3)/3) {}

Student::Student(string iname,string ipassword,long long int inum)
        :People(stu,iname,ipassword,inum) {}



bool Student::set_score(int which,float score)
{
    switch (which)
    {
        case 1:score1=score;break;
        case 2:score2=score;break;
        case 3:score3=score;break;
        default:return false;
    }
    return true;
}
bool Student::set_test(float itest)
{
    test=itest;
    return true;
}
bool Student::set_extra(float e)
{
    if(e<=4)
    {
        extra=e;
        return true;
    }
    else
        return false;
}
bool Student::set_s_sum(float s)
{
    s_sum=s;
    return true;
}
bool Student::set_s_rank(float s)
{
    s_rank=s;
    return true;
}
float Student::get_score(int which)
{
    switch (which)
    {
        case 1:return score1;break;
        case 2:return score2;break;
        case 3:return score3;break;
        default:return 0;
    }
}
float Student::get_test(void)
{
    return test;
}
vector<Student>::iterator Student::find_stu(vector<Student>* s,long long int num)
{
    vector<Student>::iterator cur=s->begin();
    for (cur;cur<s->end();cur++)
    {
        if (cur->num==num)
            return cur;
    }
    return s->end();
}
vector<Student>* Student::get_student_vec(void)
{
    return &student;
}
float Student::get_s_sum(void)
{
    return s_sum;
}
float Student::get_extra(void)
{
    return extra;
}
float Student::get_average(void)
{
    return (score1+score2+score3)/3;
}
int Student::get_s_rank(void)
{
    return s_rank;
}
vector <Student>::iterator Student::in_student(Student temp)
{
    student.push_back(temp);
    return student.begin();
}
//Salary

float Salary::s1=0;
float Salary::s2=0;
float Salary::s3=0;
float Salary::test=0;
float Salary::extra=0;

float Salary::get_s1(void)
{
    return s1;
}
float Salary::get_s2(void)
{
    return s2;
}
float Salary::get_s3(void)
{
    return s3;
}
float Salary::get_test(void)
{
    return test;
}
float Salary::get_extra(void)
{
    return extra;
}
bool Salary::set_salary(float a1,float a2,float a3,float a4,float a5)
{
    if (a1+a2+a3+a4+a5!=1)
    {
        return false;
    }
    else
    {
        s1=a1;
        s2=a2;
        s3=a3;
        test=a4;
        extra=a5;

        return true;
    }
}




