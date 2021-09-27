#include "student.h"

student::student(std::string name, std::string surname, float average_mark, int attended_lessons): name_(move(name)),
	surname_(move(surname)),
	average_mark_(average_mark),
	attended_lessons_(attended_lessons)
{}

void student::set_name(std::string name)
{
	this->name_ = move(name);
}

void student::set_surname(std::string surname)
{
	this->surname_ = move(surname);
}

void student::set_average_mark(float av_mark)
{
	average_mark_ = av_mark;
}

void student::set_attended_lessons(int at_lessons)
{
	attended_lessons_ = at_lessons;
}

std::string student::get_name() const
{
	return name_;
}

std::string student::get_surname() const
{
	return surname_;
}

float student::get_average_mark() const
{
	return average_mark_;
}

int student::get_attended_lessons() const
{
	return attended_lessons_;
}

bool student::is_succeeded() const
{
	return average_mark_ > 4 && attended_lessons_ > 5;
}

student::student()
{
	average_mark_ = 0;
	attended_lessons_ = 0;
}
