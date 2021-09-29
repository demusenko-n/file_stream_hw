#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "field.h"
#include "field_format.h"
#include "field_typed.h"
#include "student.h"
#include "object_stream_reader.h"
#include "table_printer.h"
using namespace std;



bool try_open_file(const char* dir, ifstream& destination)
{
	destination.open(dir);
	return destination.is_open();
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

	const vector<student*> students = reader.get_instances();

	const vector<field_format<student>> fields =
	{
		field_format <student>(new field_typed<student, char>(&student::is_succeeded, "Succeeded"), ALIGN_CENTER),
		field_format <student>(new field_typed<student, string>(&student::get_name, "Name"),ALIGN_LEFT),
		field_format <student>(new field_typed<student, string>(&student::get_surname, "Surname"),ALIGN_LEFT),
		field_format <student>(new field_typed<student, float>(&student::get_average_mark, "Avg mark"),ALIGN_LEFT),
		field_format <student>(new field_typed<student, int>(&student::get_attended_lessons, "Attended"), ALIGN_LEFT)
	};

	table_printer<student> printer(fields, students);
	cout << printer.to_string() << endl;

	return EXIT_SUCCESS;
}