
#include "ElmoreAccelerometer.h"

ElmoreAccelerometer::ElmoreAccelerometer(int size)
{
	// store to track how full buffer is
	_size = size;
	// store for averaging
	_count = 0;
	// store running total for faster averaging
	_total = 0;
	// init to all zeros
	_buff[size] = {};
	// set the pointer to the start of buffer
	_index = _buff;
	// set the tail to end of buffer
	_tail = (_buff + size);
}

void ElmoreAccelerometer::Push(int val)
{
	// inc index and remove current value from total
	_total -= *_index++;			
	// add new value to total
	_total += val;		
	// set the buffer element at index to val
	*_index = val;			
	// if the index is now at the tail
	if (_index == _tail) 
	{
		// reset it to the start
		_index = _buff;
	}			
	// if buff isnt full 
	if(_count != _size)
	{
		// increment count
		_count++;
	}
}

int ElmoreAccelerometer::Average()
{
	// total is stored so just divide by the size
	return _total / _count;
}

