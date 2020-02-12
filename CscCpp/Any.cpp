#include <typeinfo>
#include <iostream>

class Any
{
public:
	Any()
	{
		data_ = 0;
	}

	template <class T>
	Any(T const& value)
	{
		data_ = new Holder<T>(value);
	}

	Any(Any const& value)
	{
		BaseHolder* clone = (BaseHolder*)value.data_;
		if (clone)
		{
			data_ = clone->clone();
		}
		else
		{
			data_ = 0;
		}
	}

	~Any()
	{
		delete data_;
	}

	Any& operator= (Any const& value)
	{
		if (this != &value)
		{
			delete data_;
			BaseHolder* clone = (BaseHolder*)value.data_;
			if (clone)
			{
				data_ = clone->clone();
			}
			else
			{
				data_ = 0;
			}
		}
		return *this;
	}

	template <class T>
	T* cast()
	{
		Holder<T>* result = (Holder<T>*)data_;
		if (result && result->type_info() == typeid(T))
		{
			return &(result->data_);
		}
		else
		{
			return (T*)NULL;
		}
	}

private:
	void* data_;

	struct BaseHolder
	{
		virtual BaseHolder* clone() const = 0;
		virtual ~BaseHolder() { }
		virtual const std::type_info& type_info() const = 0;
	};

	template <typename T>
	struct Holder : BaseHolder
	{
		Holder(const T& data) : data_(data)
		{
		}

		Holder* clone() const
		{
			return new Holder(*this);
		}

		const std::type_info& type_info() const
		{
			return typeid(data_);
		}

		T data_;
	};
};

int main()
{
	Any i(10);
	Any copy(i);
	Any empty;
	i = copy; 
	empty = 0; 
	int *iptr = i.cast<int>();
	char *cptr = i.cast<char>();
	Any empty2;
	int *p = empty2.cast<int>();
	return 0;
}