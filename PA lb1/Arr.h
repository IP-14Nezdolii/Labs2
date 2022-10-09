#pragma once
#include <algorithm>
#include <fstream>

class Arr //клас буферного масиву
{
private:
	size_t _max_size;
	size_t _size;
	__int64* arr;

	friend __int64 block_size(FILE* stream);//повертає розмір файла, починаючи з позиції файлового показчика

public:
	Arr(__int64 size) //залежно від вхідного (розміру в байтах) виділяє пам'ять
	{
		__int64 k = 1024;

		if (size >= 4 * k * k * k)
		{
			_max_size = k * 131072;
		}
		else if (size < 4 * k * k * k && size >= k)
		{
			_max_size = size/16;
		}
		else _max_size = 5;

		_size = 0;

		arr = (__int64*)malloc(_max_size * sizeof(__int64));
	};

	~Arr() { free(arr); };

	__int64& operator[] (size_t index)
	{	
		try
		{
			return arr[index];
		}
		catch (const std::exception&)
		{
			if (index >= _max_size) 
			{
				return arr[_max_size - 1];
			}
			else return arr[0];			
		}		
	}
	
	friend int fread(Arr& array, FILE* stream);
	friend int fwrite(Arr& array, FILE* stream);

	void sort() {
		std::sort(arr, arr + _size);
	}

	size_t size() {return _size;}
	size_t max_size() {return _max_size; }
	__int64 size_of_buff() { return __int64(_max_size) * sizeof(__int64); }

	void append(__int64 numb)
	{
		if (_size < _max_size) 
		{
			arr[_size] = numb;
			_size++;
		}	
	}

	void clear(){ _size = 0; }
};

__int64 block_size(FILE* stream)//зчитує розмір потенційного блоку даних для зчитування
{
	__int64 pos_cur = _ftelli64(stream);
	__int64 pos_end;

	_fseeki64(stream, 0, SEEK_END);
	pos_end = _ftelli64(stream);
	_fseeki64(stream, pos_cur, SEEK_SET);

	return pos_end - pos_cur;
}

int fread(Arr& array, FILE* stream)
{
	int numb;
	__int64 size = block_size(stream);

	if (size >= _msize(array.arr))
	{
		numb = fread(*&array.arr, _msize(array.arr), 1 , stream); // sizeof(__int64)
		array._size = array._max_size;
	}
	else 
	{
		numb = fread(*&array.arr, size , 1 , stream);
		array._size = size / sizeof(__int64);
	}
	return numb;
}

int fwrite(Arr& array, FILE* stream)
{
	int numb = fwrite(*&array.arr, array._size*sizeof(__int64), 1, stream);
	return numb;
}