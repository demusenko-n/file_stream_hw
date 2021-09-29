#pragma once
#include <string>

template <class TypeClass>
class field
{
protected:
	std::string header_;
	field(std::string header) :header_(std::move(header)) {}
public:
	std::string get_header()const
	{
		return header_;
	}
	virtual ~field() = default;
	virtual std::string get_as_string(const TypeClass& obj)const = 0;
};