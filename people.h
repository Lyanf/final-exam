#ifndef INCLUDE_PEOPLE
#define INCLUDE_PEOPLE
#define tea 1
#define stu 0
#include <string>
#include <vector>
using namespace std;
class People
{
protected:
    int type;
    string name;
    string password;
    long long int num;
    People()=default;
    People(int itype,string iname,string ipassword,long long int inum);
    //修改密码
    //判断密码是否符合格式，被修改密码函数所调用

public:
    bool set_password(string ipassword);
    static bool judge_password(string ipassword);
    //接口函数，用来获得信息
    string get_name(void);
    string get_password(void);
    long long int get_num(void);
};


class Teacher:public People
{
    //friend int log_in(long long int,string);
    //friend class Student;
private:
    static vector<Teacher> teacher;
public:
    Teacher(string iname,string ipassword,long long int inum);
    Teacher()=default;
    static vector<Teacher>::iterator find_tea(vector<Teacher>* t,long long int num);
    static vector<Teacher>* get_teacher_vec(void);
    static vector <Teacher>::iterator in_teacher(Teacher temp);

};

class Student:public People
{

private:
    float score1=-1,score2=-1,score3=-1;
    float test=-1,extra=-1;
    float average;
    float s_sum=-1;
    int s_rank=-1;
    int type_score=0;
    int type_test=0;
    static vector<Student> student;
public:
    Student()=default;
    Student(string iname,string ipassword,long long int inum,float iscore1,float iscore2
            ,float iscore3);
    Student(string iname,string ipassword,long long int inum);
    //成绩录入
    bool set_score(int which,float score);
    //综合测评分录入
    bool set_test(float itest);
    bool set_extra(float e);
    //salary成绩
    bool set_s_sum(float s);
    bool set_s_rank(float s);
    //成绩查询
    float get_score(int which);
    float get_average(void);
    float get_test(void);
    float get_s_sum(void);
    float get_extra(void);
    int get_s_rank(void);
    static vector<Student>::iterator find_stu(vector<Student>* s,long long int num);
    static vector<Student>* get_student_vec(void);
    static vector <Student>::iterator in_student(Student temp);


};


class Salary
{
private:
    //extra所占的比例要加进去
    static float s1,s2,s3,test,extra;
public:
    static float get_s1(void);
    static float get_s2(void);
    static float get_s3(void);
    static float get_test(void);
    static float get_extra(void);
    static bool set_salary(float a1,float a2,float a3,float a4,float a5);
};


#endif // INCLUDE_PEOPLE
