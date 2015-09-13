
class AveragingBuffer
{
	public:
		AveragingBuffer(int size);
		
		void Push(int val);
		
		int Average();
		
	private:
		int _size;
		int _buff[];
		int *_index;
		int *_tail;
};