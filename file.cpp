#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include<fstream>
#include"people.h"
using namespace std;
void save_file(vector<Student>* s,vector<Teacher>* t)
{
    ofstream out("data_s.txt");
    auto temp=s->begin();
    for (temp=s->begin(); temp<s->end(); temp++)
    {

        out<<' '<<temp->get_num()<<' '
           <<temp->get_password()<<' '
           <<temp->get_name()<<' '
           <<temp->get_score(1)<<' '
           <<temp->get_score(2)<<' '
           <<temp->get_score(3)<<' ';
    }
    out.close();
    ofstream out2("data_t.txt");
    auto temp2=t->begin();
    for (temp2=t->begin(); temp2<t->end(); temp2++)
    {

        out2<<' '<<temp2->get_num()<<' '
            <<temp2->get_password()<<' '
            <<temp2->get_name()<<' ';

    }
    out2.close();
}
void open_file(vector<Student>* s,vector<Teacher>* t)
{
    ifstream in("data_s.txt");
    //auto temp=s->begin();
    while (in.eof()==false)
    {
        string iname,ipassword;
        float iscore1,iscore2,iscore3;
        long long int inum;
        if (in>>inum>>ipassword>>iname>>iscore1>>iscore2
                >>iscore3)
        {
            auto x=Student(iname,ipassword,inum,iscore1,iscore2,iscore3);
            s->push_back(x);
        }
        else break;
    }
    in.close();
    ifstream in2("data_t.txt");
    //vector<Teacher>::iterator temp2=t->begin();
    while (in2.eof()==false)
    {
        string iname,ipassword;
        long long int inum;
        if (in2>>inum>>ipassword>>iname)
        {
            auto x=Teacher(iname,ipassword,inum);
            t->push_back(x);
        }
        else break;
    }
    in2.close();
}


#endif // FILE_H_INCLUDED
