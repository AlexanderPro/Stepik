#include <iostream>
using namespace std;

template <typename T>
class Array
{
public:
	//explicit Array(size_t size = 0, const T& value = T())
	//{
	//	size_ = size;
	//	data_ = new T[size];
	//	for (size_t i = 0; i < size; i++)
	//	{
	//		data_[i] = value;
	//	}
	//}

	//Array(const Array & arr)
	//{
	//	size_ = arr.size_;
	//	data_ = new T[arr.size_];
	//	for (size_t i = 0; i < arr.size_; i++)
	//	{
	//		data_[i] = arr.data_[i];
	//	}
	//}

	//~Array()
	//{
	//	delete[] data_;
	//}


	explicit Array(size_t size = 0, const T& value = T())
	{
		size_ = size;
		data_ = static_cast<T*>(operator new[](size * sizeof(T)));
		for (size_t i = 0; i < size; i++)
		{
			new (data_ + i) T(value);
		}
	}

	Array(const Array & arr)
	{
		size_ = arr.size_;
		data_ = static_cast<T*>(operator new[](arr.size_ * sizeof(T)));
		for (size_t i = 0; i < arr.size_; i++)
		{
			new (data_ + i) T(arr.data_[i]);
		}
	}

	~Array()
	{
		while (size_)
		{
			data_[--size_].~T();
		}
		operator delete[](data_);
	}

	Array& operator= (Array const& arr)
	{
		if (this != &arr)
		{
			while (size_)
			{
				data_[--size_].~T();
			}
			operator delete[](data_);

			size_ = arr.size_;
			data_ = static_cast<T*>(operator new[](arr.size_ * sizeof(T)));
			for (size_t i = 0; i < arr.size_; i++)
			{
				new (data_ + i) T(arr.data_[i]);
			}
		}
		return *this;
	}

	size_t size() const
	{
		return size_;
	}

	T& operator[](size_t i)
	{
		return data_[i];
	}

	const T& operator[](size_t i) const
	{
		return data_[i];
	}

private:
	T* data_;
	size_t size_;
};


struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable
{
	ValueHolder(const T& data) : data_(data)
	{
	}

	ValueHolder* clone() const
	{
		return new ValueHolder(*this);
	}

	T data_;
};

bool lesss(int a, int b) { return a < b; }

template <typename T, typename C>
T minimum(Array <T> & data, C func)
{
	T min = data[0];

	for (size_t i = 1; i < data.size(); i++)
	{
		if (func(data[i], min))
		{
			min = data[i];
		}
	}

	return min;
}

template <typename T>
void flatten(const T & value, std::ostream& out)
{
	out << value << " ";
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		flatten(array[i], out);
	}
}


int main()
{
	Array<int> ints(3);
	ints[0] = 10;
	ints[1] = 2;
	ints[2] = 15;
	Array< Array<int> > array_of_ints(2, ints);
	int min = minimum(ints, lesss);
	flatten(array_of_ints, cout);
	return 0;
}