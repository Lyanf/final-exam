#ifndef INCLUDE_MYIO
#define INCLUDE_MYIO
#include <iostream>
#include "people.h"
using namespace std;
class Event
{
private:
    float score1=-1,score2=-1,score3=-1,average=-1;
    float test=-1;
    float extra=-1;
    float score1_proportion=-1,score2_proportion=-1,score3_proportion=-1,test_proportion=-1,extra_proportion=-1;
   // int Rank=-1;
    //lesson表示的是要查看某门课的所有学生成绩
    int lesson=-1;
    string password,name;
    long long int num;
    int type;
public:
    static string t;
    static string f;
    static int SetStudentPassword;
    static int SetTeacherPassword;
    static int SetScore;
    static int SetSalaryProportion;
    static int SetSalary;
    static int SetRank;
    static int GetStudentScore;
    static int GetRank;
   // static int InputScore;
    static int GetLessonScore;
    static int GetSalary;
    static int InTeacher;
    static int InStudent;
    Event(string iname,string ipassword,long long inum);
    Event()=default;
    Event(vector<Student>::iterator s);
    Event(vector<Teacher>::iterator t);
    bool set_score(int which,float s);
    bool set_test(float t);
    bool set_password(string p);
    bool set_num(long long int n);
    bool set_lesson(int);
    bool set_extra(float);
    bool set_proportion(float s1,float s2,float s3,float t,float e);
    string solveset(int flag);

};

#endif // INCLUDE_MYIO
