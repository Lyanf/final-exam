#include "mainwindow.h"
#include <QApplication>
#include "file.h"
#include "people.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Student::in_student(Student("liyanfeng","123",123,100,100,100));
    Teacher::in_teacher(Teacher("xiaowangba","123",123));
    open_file(Student::get_student_vec(),Teacher::get_teacher_vec());
    MainWindow w;
    w.show();
    save_file(Student::get_student_vec(),Teacher::get_teacher_vec());

    return a.exec();
}
