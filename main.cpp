#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "student.h"
#include "object_stream_reader.h"
#include "student_table_printer.h"
using namespace std;


ostream& operator<<(ostream& stream, const student& student)
{
	return stream << student.get_name() << ','
		<< student.get_surname() << ','
		<< student.get_average_mark() << ','
		<< student.get_attended_lessons() << endl;
}
istream& operator>>(istream& stream, student& student)
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


bool try_open_file(const char* dir, ifstream& destination)
{
	destination.open(dir);
	return destination.is_open();
}

void main_func(ifstream& in)
{
	object_stream_reader<student> reader(in);
	reader.read_all_objects();
	vector<student> students = reader.get_instances();

}

int main()
{
	constexpr char input_file_dir[] = "inputfile.txt";

	ifstream in;
	if (!try_open_file(input_file_dir, in))
	{
		cout << "Unable to open the file!" << endl;
		return EXIT_FAILURE;
	}

	object_stream_reader<student> reader(in);
	reader.read_all_objects();
	in.close();
	vector<student> students = reader.get_instances();

	string headers[5] = {
		"Succeeded",
		"Name",
		"Surname",
		"Avg mark",
		"Attended"
	};

	student_table_printer printer(students, headers);
	cout << printer.to_string() << endl;
	return EXIT_SUCCESS;
}