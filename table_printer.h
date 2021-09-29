#pragma once
#include <string>
#include <utility>
#include <vector>
#include "field_format.h"

template <class TypeClass>
class table_printer
{
	std::vector<field_format<TypeClass>> fields_;
	std::vector<TypeClass*> instances_;

	static constexpr size_t column_offset = 5;

public:
	table_printer(std::vector<field_format<TypeClass>> view, std::vector<TypeClass*> instances);

	std::string to_string();
};

template <class TypeClass>
table_printer<TypeClass>::table_printer(std::vector<field_format<TypeClass>> view, std::vector<TypeClass*> instances):fields_(std::move(view)), instances_(
	std::move(instances))
{
}

template <class TypeClass>
std::string table_printer<TypeClass>::to_string()
{
	std::string result;

	const size_t fields_amount = fields_.size();
	const size_t rows_amount = instances_.size();

	auto* max_col_len = new size_t[fields_amount]{};

	for (size_t i = 0; i < fields_amount; ++i)
	{
		max_col_len[i] = fields_[i].field_->get_header().length();

		for (TypeClass* instance : instances_)
		{
			max_col_len[i] = std::max(max_col_len[i], fields_[i].field_->get_as_string(*instance).length());
		}
	}


	for (size_t j = 0; j < fields_amount; j++)
	{
		std::string text_to_append = fields_[j].field_->get_header();
		result.append(text_to_append);
		result.append(std::string(max_col_len[j] + this->column_offset - text_to_append.length(), ' '));
	}
	result.append("\n");

	for (TypeClass* instance : instances_)
	{
		for (size_t j = 0; j < fields_amount; j++)
		{
			std::string text_to_append = fields_[j].field_->get_as_string(*instance);

			const size_t spaces_amount = max_col_len[j]/* + this->column_offset*/ - text_to_append.length();

			switch (fields_[j].alignment_)
			{
			case ALIGN_CENTER:
				text_to_append = std::string(spaces_amount / 2, ' ') +
					text_to_append + std::string(spaces_amount + this->column_offset - spaces_amount / 2, ' ');
				break;
			case ALIGN_LEFT:
				text_to_append += std::string(spaces_amount + this->column_offset, ' ');
				break;
			}

			result.append(text_to_append);
		}
		result.append("\n");
	}

	return result;
}
