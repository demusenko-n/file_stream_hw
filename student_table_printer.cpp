#include "student_table_printer.h"

student_table_printer::column_table::column_table(size_t size)
{
	data.reserve(size);
}

student_table_printer::student_table_printer(const std::vector<student>& students, const std::string header[cols_size]): cols_
	{ column_table(1 + students.size()), column_table(1 + students.size()) , column_table(1 + students.size())  , column_table(1 + students.size()) , column_table(1 + students.size()) }
{

	for (size_t i = 0; i < cols_size; ++i)
	{
		cols_[i].data.push_back(header[i]);
		cols_[i].max_symbols = std::max(cols_[i].max_symbols, header[i].length());
	}

	for (auto& element : students)
	{
		add_student(element);
	}
}



void student_table_printer::add_student(const student& student)
{
	const std::string _columns[5] = {
		(student.is_succeeded() ? "    +" : "    -"),
		student.get_name(),
		student.get_surname(),
		std::to_string(student.get_average_mark()),
		std::to_string(student.get_attended_lessons()) };

	for (size_t i = 0; i < cols_size; ++i)
	{
		cols_[i].data.push_back(_columns[i]);
		cols_[i].max_symbols = std::max(cols_[i].max_symbols, _columns[i].length());
	}
}

std::string student_table_printer::to_string()
{
	std::string result;

	const size_t rows_amount = cols_[0].data.size();

	for (size_t i = 0; i < rows_amount; ++i)
	{
		for (auto& col : cols_)
		{
			result.append(col.data[i]);
			result.append(std::string(col.max_symbols + 2 - col.data[i].length(), ' '));
		}
		result.append("\n");
	}

	return result;
}
