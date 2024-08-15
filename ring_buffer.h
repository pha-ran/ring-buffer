#pragma once

class ring_buffer
{
public:
	static constexpr int _size = 10;

public:
	ring_buffer(void) noexcept;
	~ring_buffer(void) noexcept;

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

	inline int direct_dequque_size(void) const noexcept
	{
		return 0;
		/*if (_free == _size)		return 0;

		if (_front < _back)		return _back - _front;
		else					return _size - _front;*/
	}

public:
	int enqueue(const char* ptr, int size) noexcept;
	int dequque(const char* ptr, int size) noexcept;
	int peek(const char* ptr, int size) noexcept;

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
