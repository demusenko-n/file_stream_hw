#pragma once
#include "field.h"
#include <sstream>


template<class TypeClass, class TypeField>
using getter_t = TypeField(TypeClass::*)()const;

template<class TypeClass, class TypeField>
class field_typed : public field<TypeClass>
{
	getter_t<TypeClass, TypeField> getter_;
	std::string get_as_string(const TypeClass& obj)const override
	{
		std::stringstream stream;
		stream << (obj.*getter_)();
		return stream.str();
	}
public:
	explicit field_typed(getter_t<TypeClass, TypeField> getter, std::string header) : field<TypeClass>(header), getter_(getter) {}
};
