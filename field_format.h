#pragma once
#include "field_typed.h"

enum format_alignment
{
	ALIGN_CENTER,
	ALIGN_LEFT
};

template<class TypeClass>
class field_format
{
public:
	field<TypeClass>* field_;
	format_alignment alignment_;
	field_format(field<TypeClass>* field, format_alignment alignment)
	{
		field_ = field;
		alignment_ = alignment;
	}
};
