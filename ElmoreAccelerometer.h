
class ElmoreAccelerometer
{
	public:
		ElmoreAccelerometer(int size);
		
		void Push(int val);
		
		int Average();
		
	private:
		int _buff[];
	
		int _size;
		int _count;
		int _total;
		
		int *_index;
		int *_tail;
};