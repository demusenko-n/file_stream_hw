#pragma once
#include <string>

class student
{
	std::string name_;
	std::string surname_;
	float average_mark_;
	int attended_lessons_;

public:
	student(std::string name, std::string surname, float average_mark, int attended_lessons);
	student();

	void set_name(std::string name);

	void set_surname(std::string surname);

	void set_average_mark(float av_mark);

	void set_attended_lessons(int at_lessons);

	std::string get_name() const;

	std::string get_surname() const;

	float get_average_mark() const;

	int get_attended_lessons() const;

	bool is_succeeded() const;
};
