#pragma once

class ring_buffer
{
public:
	static constexpr int _size = 77;

public:
	ring_buffer(void) noexcept;

public:
	inline void clear(void) noexcept
	{
		_free = _size;
		_front = 0;
		_back = 0;
	}

	inline int use_size(void) const noexcept
	{
		return _size - _free;
	}

	inline int free_size(void) const noexcept
	{
		return _free;
	}

	inline int direct_enqueue_size(void) const noexcept
	{
		if (_free <= 0)			return 0;

		if (_front <= _back)	return _size  - _back;
		else					return _front - _back;
	}

	inline int direct_dequeue_size(void) const noexcept
	{
		if (_front == _back)
		{
			if (_free == _size)	return 0;
			else				return _size - _front;
		}

		if (_front < _back)		return _back - _front;
		else					return _size - _front;
	}

	inline char* front(void) const noexcept
	{
		return (char*)(_data + _front);
	}

	inline char* back(void) const noexcept
	{
		return (char*)(_data + _back);
	}

	inline void move_front(int size) noexcept
	{
		_front = remain(_front + size);
		_free += size;
	}

	inline void move_back(int size) noexcept
	{
		_back = remain(_back + size);
		_free -= size;
	}

public:
	int enqueue(const char* ptr, int size) noexcept;
	int dequeue(char* ptr, int size) noexcept;
	int peek(char* ptr, int size) noexcept;

	// Test
	void print(void) const noexcept;

private:
	inline int remain(int index) const noexcept
	{
		return index % _size;
	}

private:
	int _free;

	int _front;
	int _back;

	char _data[_size];

};
