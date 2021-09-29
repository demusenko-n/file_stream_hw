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

char student::is_succeeded() const
{
	return average_mark_ > 4 && attended_lessons_ > 5 ? '+' : '-';
}

student::student()
{
	average_mark_ = 0;
	attended_lessons_ = 0;
}

std::ostream& operator<<(std::ostream& stream, const student& student)
{
	return stream << student.get_name() << ','
		<< student.get_surname() << ','
		<< student.get_average_mark() << ','
		<< student.get_attended_lessons() << std::endl;
}

std::istream& operator>>(std::istream& stream, student& student)
{
	std::string name, surname, av_mark, at_lessons;
	if (!std::getline(stream, name, ',') ||
		!std::getline(stream, surname, ',') ||
		!std::getline(stream, av_mark, ',') ||
		!std::getline(stream, at_lessons))
	{
		throw std::exception();
	}
	student.set_name(name);
	student.set_surname(surname);
	student.set_average_mark(std::stof(av_mark));
	student.set_attended_lessons(std::stoi(at_lessons));
	return stream;
}