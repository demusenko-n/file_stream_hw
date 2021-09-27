#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define INPUT_FILE_DIR "inputfile.txt"

class student
{
    string name;
    string surname;
    float average_mark;
    int attended_lessons;

public:
    student(string name, string surname, float average_mark, int attended_lessons) : name(move(name)),
                                                                                     surname(move(surname)),
                                                                                     average_mark(average_mark),
                                                                                     attended_lessons(attended_lessons) {}
    student()
    {
        average_mark = attended_lessons = 0;
    }
    void set_name(string name)
    {
        this->name = move(name);
    }
    void set_surname(string surname)
    {
        this->surname = move(surname);
    }
    void set_average_mark(float av_mark)
    {
        average_mark = av_mark;
    }
    void set_attended_lessons(int at_lessons)
    {
        attended_lessons = at_lessons;
    }
    string get_name() const
    {
        return name;
    }
    string get_surname() const
    {
        return surname;
    }
    float get_average_mark() const
    {
        return average_mark;
    }
    int get_attended_lessons() const
    {
        return attended_lessons;
    }
    bool is_succeeded() const
    {
        return average_mark > 4 && attended_lessons > 5;
    }
};
ostream &operator<<(ostream &stream, student &student)
{
    return stream << student.get_name() << ','
                  << student.get_surname() << ','
                  << student.get_average_mark() << ','
                  << student.get_attended_lessons() << endl;
}
istream &operator>>(istream &stream, student &student)
{
    string name, surname, av_mark, at_lessons;
    if (!getline(stream, name, ',') ||
        !getline(stream, surname, ',') ||
        !getline(stream, av_mark, ',') ||
        !getline(stream, at_lessons))
    {
        throw exception();
    }
    student.set_name(name);
    student.set_surname(surname);
    student.set_average_mark(stof(av_mark));
    student.set_attended_lessons(stoi(at_lessons));
    return stream;
}

class student_table_printer
{
    stringstream content;

public:
    student_table_printer()
    {
        content << "Success\tName\tSurname\tAvg mark\tAttended\n";
    }
    void add_student(const student &student)
    {
        content << "   "
                << (student.is_succeeded() ? '+' : '-') << '\t'
                << student.get_name() << '\t'
                << student.get_surname() << '\t'
                << student.get_average_mark() << '\t'
                << student.get_attended_lessons() << endl;
    }

    string to_string()
    {
        return content.str();
    }
};

int main()
{
    ifstream in(INPUT_FILE_DIR);
    if (!in.is_open())
    {
        cout << "Unable to open the file!" << endl;
        exit(EXIT_FAILURE);
    }

    student_table_printer printer;
    try
    {
        while (true)
        {
            student student;
            in >> student;
            printer.add_student(student);
        }
    }
    catch (exception &ex)
    {
        cout << printer.to_string();
    }

    return EXIT_SUCCESS;
}