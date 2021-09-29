#pragma once
#include <vector>
#include <fstream>

template<class T>
class object_stream_reader
{
	std::vector<T*> instances_;
	std::ifstream* stream_;
public:
	explicit object_stream_reader(std::ifstream& stream);

	void read_all_objects();

	const std::vector<T*>& get_instances();
};

template <class T>
object_stream_reader<T>::object_stream_reader(std::ifstream& stream)
{
	stream_ = &stream;
}

template <class T>
void object_stream_reader<T>::read_all_objects()
{
	try
	{
		while (true)
		{
			T* instance = new T();
			(*stream_) >> (*instance);
			instances_.push_back(instance);
		}
	}
	catch (std::exception&)
	{
	}
}

template <class T>
const std::vector<T*>& object_stream_reader<T>::get_instances()
{
	return instances_;
}
