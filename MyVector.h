template<class Type>
class Vector{
	int _capacity, _size;
	Type *start, *mid, *end;
public:
	Vector():start(NULL), mid(NULL), end(NULL), _capacity(0), _size(0){}
	void push_back(Type t){
		if(mid == end){
			//need to allocate more memory
			allocate();
			//then we will have a new set of start, mid, end;
		}
		*mid++ = t;
	}
	void allocate(){
		int newSize = end==start?1:((end-start)*2);
		Type * newStart = new Type[newSize]; //use [] to apply for a block of memory
		Type * p = start, *q = newStart;
		while(p!=end){
			*q++=*p++;
		}

		delete[] start;	//use [] to delete the memory applied with []
		start = newStart;
		mid = q;
		end = start + newSize;
		_capacity = end-start; //for pointer, just do the minus to get the number of elements
		_size = mid-start;
	}
	Type get(int index){
		return *(start+index);
	}
	int size(){
		return end - start;
	}
	int capacity(){
		return mid - start;
	}
};
