#pragma once
#include <string>
#include <vector>

#include "student.h"

class student_table_printer
{
	class column_table
	{

	public:
		column_table(size_t size);

		std::vector<std::string> data;
		size_t max_symbols{};
	};
	static constexpr size_t cols_size = 5;
	static constexpr size_t column_offset = 2;
	column_table cols_[cols_size];

public:
	student_table_printer(const std::vector<student>& students, const std::string header[cols_size]);


	void add_student(const student& student);


	std::string to_string();
};
