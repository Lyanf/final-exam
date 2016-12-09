#include "myio.h"
#include "people.h"
#include <sstream>

using namespace std;
int Event::SetStudentPassword=0;
int Event::SetTeacherPassword=1;
int Event::SetScore=2;
int Event::SetSalaryProportion=3;
int Event::SetSalary=4;
int Event::SetRank=5;
int Event::GetRank=6;
int Event::GetLessonScore=7;
int Event::GetSalary=8;
int Event::InTeacher=9;
int Event::InStudent=10;
string Event::t="!";
string Event::f="@";
string Event::solveset(int flag)
{
    if (flag==SetStudentPassword)/*0*/
    {

        if ((Student::find_stu(Student::get_student_vec(),num))->set_password(password))
            return t;
        else return f;

    }

    if (flag==SetTeacherPassword)/*1*/
    {
        if ((Teacher::find_tea(Teacher::get_teacher_vec(),num))->set_password(password))
            return t;
        else return f;

    }

    if (flag==SetScore)/*2*/
    {
        if (type==0)
        {
            return f;
        }
        if (Student::find_stu(Student::get_student_vec(),num)->set_score(1,score1)&&
            Student::find_stu(Student::get_student_vec(),num)->set_score(2,score2)&&
            Student::find_stu(Student::get_student_vec(),num)->set_score(3,score3))
        {
            return t;
        }
        else return f;
    }

    if(flag==SetSalaryProportion)/*3      设置奖学金的各项比例*/
    {
        if (type==0)
        {
            return f;
        }
         if (Salary::set_salary(score1_proportion,score2_proportion,score3_proportion,test_proportion,extra_proportion))
        {
            return t;
        }
        else return f;
    }

    if(flag==SetSalary)/*4           给这个学生设置各种额外分*/
    {
        if (type==0)
        {
            return f;
        }
        auto temp=Student::find_stu(Student::get_student_vec(),num);
        if(temp->set_extra(extra)&&temp->set_test(test))
        {
            return t;
        }
        else
            return f;
    }

    if(flag==SetRank)/*5     按照salary的总得分进行排序，在排序之前还把s_sum给赋值了（不然排什么）*/
    {
        auto s=Student::get_student_vec();
        auto cur=s->begin();
        auto temp=s->begin();
        //从大到小进行排序
        for (cur;cur<s->end();cur++)
        {
            float x=cur->get_score(1)*Salary::get_s1()
                    +cur->get_score(2)*Salary::get_s2()
                    +cur->get_score(3)*Salary::get_s2()
                    +cur->get_test()*Salary::get_test();
                    +cur->get_extra()*Salary::get_extra();
            cur->set_s_sum(x);
        }
        cur=s->begin();
        for (cur;cur<s->end();cur++)
        {
            for (temp=s->begin();temp<s->end()-1;temp++)
            {
                if (temp->get_s_sum()<(temp+1)->get_s_sum())
                {
                    auto x=*temp;
                    *temp=*(temp+1);
                    *(temp+1)=x;
                }
            }
        }
        int i=1;
        for (cur=s->begin();cur<s->end();cur++)
        {
            Student::find_stu(Student::get_student_vec(),num)->set_s_rank(i);
            i++;
        }
        return t;
    }

    if (flag==GetRank)
    {
 /*
        auto s=Student::get_student_vec();
        auto cur=s->begin();
        auto temp=s->begin();
        //从大大小进行排序
        for (cur;cur<s->end();cur++)
        {
            for (temp=s->begin();temp<s->end()-1;temp++)
            {
                if (temp->get_s_sum()<(temp+1)->get_s_sum())
                {
                    auto x=*temp;
                    *temp=*(temp+1);
                    *(temp+1)=x;
                }
            }
        }

*/
        /*auto s=Student::get_student_vec();
        int i=1;
        int n;
        n=Student::find_stu(Student::get_student_vec(),num)->get_s_rank;
        auto cur=s->begin();
        for (cur=s->begin();cur<s->end();cur++)
        {
            if (Student::find_stu(Student::get_student_vec(),num)->get_s_sum()==cur->get_s_sum())
              {
                    n=i;
              }
            i++;
        }
        */
     /*   stringstream a;
        a<<"#GetRank# "<<Student::find_stu(Student::get_student_vec(),num)->get_s_rank()<<" "<<Student::find_stu(Student::get_student_vec(),num)->get_s_sum()<<endl;
        string x=a.str();
        return x;
        */
    }
    if (flag==GetLessonScore)
    {
        auto s=Student::get_student_vec();
        auto cur=s->begin();
        stringstream a;
        if(lesson==1)
        {
            a<<"#GetLessonScore1# ";
            for (cur;cur<s->end();s++)
            {
                a<<cur->get_num()<<" "<<cur->get_name()<<" "<<cur->get_score(1)<<endl;
            }
            return a.str();


        }
        else if(lesson==2)
        {
            a.clear();
            a<<"#GetLessonScore2# ";
            cur=s->begin();
            for (cur;cur<s->end();s++)
            {
                a<<cur->get_num()<<" "<<cur->get_name()<<" "<<cur->get_score(2)<<endl;
            }
            return a.str();

        }
        else if(lesson==3)
        {
            a.clear();
            a<<"#GetLessonScore3# ";
            cur=s->begin();
            for (cur;cur<s->end();s++)
            {
                a<<cur->get_num()<<" "<<cur->get_name()<<" "<<cur->get_score(3)<<endl;
            }

        }
        else
        {
            return f;
        }
    }
    if (flag==GetSalary)
    {
        auto st=Student::find_stu(Student::get_student_vec(),num);
        stringstream p;
        p<<"#GetSalary# "<<st->get_s_sum()<<" "<<st->get_s_rank();
        return p.str();

    }
    if (flag==InTeacher)
    {
        //vector<Teacher>* tea=Teacher::get_teacher_vec();
        //vector<Teacher>::iterator cur=tea->begin();
        vector<Teacher>* teach=Teacher::get_teacher_vec();
        vector<Teacher>::iterator cur=teach->begin();
        for (cur;cur<teach->end();cur++)
        {
            if (cur->get_num()==num)
            {
                return f;
            }
        }
        if (!People::judge_password(password))
        {
            return f;
        }
        Teacher::in_teacher(Teacher(name,password,num));
        return t;
    }
    if (flag==InStudent)
    {
        vector<Student>* s=Student::get_student_vec();
        vector<Student>::iterator cur=s->begin();
        for (cur;cur<s->end();cur++)
        {
            if (cur->get_num()==num)
            {
                return f;
            }
        }
        if (!People::judge_password(password))
        {
            return f;
        }
        Student::in_student(Student(name,password,num));
        return t;
    }



}

Event::Event(string iname,string ipassword,long long inum):
    name(iname),password(ipassword),num(inum) {}
Event::Event(vector<Student>::iterator s)
{
    password=s->get_password();
    name=s->get_name();
    num=s->get_num();
    score1=s->get_score(1);
    score2=s->get_score(2);
    score3=s->get_score(3);
    test=s->get_test();
    extra=s->get_extra();
    average=s->get_average();
    type=0;

}
Event::Event(vector<Teacher>::iterator t)
{
    password=t->get_password();
    name=t->get_name();
    num=t->get_num();
    type=1;
}




bool Event::set_score(int which,float s)
{
    switch(which)
    {
        case 1:score1=s;break;
        case 2:score2=s;break;
        case 3:score3=s;break;
        default:return false;
    }
    return true;
}
bool Event::set_test(float t)
{
    test=t;
    return true;
}
bool Event::set_password(string p)
{
    password=p;

    return true;
}
bool Event::set_num(long long int n)
{
    num=n;
    return true;
}
bool Event::set_lesson(int l)
{
    lesson=l;
    return true;
}
bool Event::set_extra(float e)
{
    extra=e;
    return true;
}
bool Event::set_proportion(float s1,float s2,float s3,float t,float e)
{
    if (s1+s2+s3+t+e==1)
    {
        score1_proportion=s1;
        score2_proportion=s2;
        score3_proportion=s3;
        test_proportion=t;
        extra_proportion=e;
        return true;
    }
    else return false;
}






void out(string s)
{
    stringstream io;
    if (s==Event::t)
    {
        cout<<endl<<"操作成功"<<endl;
    }
    else if (s==Event::f)
    {
        cout<<endl<<"操作失败"<<endl;
    }
    else
    {
        string type;
        io>>type;

        if (type=="#GetSalary#")
        {
            float g1;
            int g2;
            io>>g1;
            io>>g2;
            cout<<"您的奖学金测评分数为:"<<g1<<endl
            <<"您的排名为:"<<g2<<endl;
        }
        if (type=="#GetLesson1#")
        {
            float g1;
            io>>g1;
            cout<<"您的科目1成绩为:"<<g1<<endl;
        }
        if (type=="#GetLesson2#")
        {
            float g1;
            io>>g1;
            cout<<"您的科目2成绩为:"<<g1<<endl;
        }
        if (type=="#GetLesson3#")
        {
            float g1;
            io>>g1;
            cout<<"您的科目3成绩为:"<<g1<<endl;
        }



    }

}
