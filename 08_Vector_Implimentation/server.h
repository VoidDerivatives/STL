#include<iostream>
#include<cstring>
using std :: cout;
using std :: endl;
using std :: ostream;

class vector
{
	int *pArray;
	int iSize;

	void memcopy(int * ,int *, int ,int );	
	public: 
	vector();
	~vector();

	vector(int);	
	
	class iterator
	{
		int iIndex;
		int *pPtr;
	
		public:
		iterator();
		~iterator();

		void Set(int,int *);
		int Get();

		bool operator ==(iterator &);
		bool operator !=(iterator &);
		iterator & operator ++();
		iterator operator ++(int);
		int operator *(); 
		iterator & operator --();
		iterator operator --(int);	

	};

	private:
	iterator FirstIndex;
	iterator LastIndex;
	
	public:
	int Size();	
	void swap(vector &);
	void insert(iterator &I, int);

	iterator & begin();
	iterator & end();

	int & operator [](int);
	friend ostream & operator <<(ostream &out,vector &); 
};
// vector constructor & destructor
vector :: vector()
{
	pArray = NULL;
}
vector :: ~vector()
{
	if(pArray != NULL)
	{
		delete []pArray;
	}

	pArray = NULL;
}


vector :: vector(int iParamSize)
{
	pArray = new int[iParamSize];
	
	if(pArray == NULL)
	{
		cout<<"Memory allocation failed"<<endl;
		return ;
	}
	memset(pArray,0,iParamSize * sizeof(int));
	iSize = iParamSize;
		
}	

// iterator constructor & destructor
vector :: iterator :: iterator()
{
	iIndex = 0;
	pPtr = NULL;
}
vector :: iterator ::~iterator()
{
	iIndex = -1;
	pPtr = NULL;
}

// iterator Member Function  
void vector :: iterator :: Set(int iSetParam,int *pPtrParam)
{
	iIndex = iSetParam;	
	pPtr = pPtrParam;	
}

int vector :: iterator :: Get()
{
	return iIndex;
}

// vector opeartor operator Overloading
int & vector :: operator [](int iIndex)
{
	return pArray[iIndex];
} 

// vector Member Function

vector ::iterator & vector :: begin()
{
	FirstIndex.Set(0,pArray);
	return FirstIndex;	
}
vector ::iterator & vector :: end()
{
	LastIndex.Set(iSize,pArray + iSize);
	return LastIndex;
}

void vector :: swap (vector &obj)
{
	int size;

	int *pTemp = pArray;
	pArray = obj.pArray;
	obj.pArray = pTemp;
	
	size = iSize;
	iSize = obj.iSize;
	obj.iSize = size;

}

void vector :: insert(vector :: iterator &I, int iNo)
{
	int * pTemp ;
	int s = I.Get();	

	pTemp = new int[iSize + 1];
	memcopy(pTemp,pArray,0,s);
	pTemp[s] = iNo;
	memcopy(pTemp,pArray,s,iSize);
	
	pArray = pTemp;
	iSize = iSize + 1;		
	
}
	
int vector :: Size()
{
	return iSize;
}

// vector private member function
void vector :: memcopy(int *Old , int *New ,int start,int end)
{
	while(start < end)
	{
		Old[start] = New[start];
		start++;
	}	
}	

// iterator opeartor overloading
bool vector :: iterator :: operator !=(iterator &Second)
{
	if(iIndex != Second.iIndex)
		return true;

	return false;
}

bool vector :: iterator :: operator == (iterator &Second)
{
	return (iIndex == Second.iIndex);			
} 
vector :: iterator & vector :: iterator :: operator ++()
{
	iIndex = iIndex + 1;
	return *this;	
}

vector :: iterator vector ::iterator :: operator ++(int)
{
	 iterator pTemp = *this;
	 iIndex = iIndex + 1;
	 return pTemp;	
}

int vector :: iterator ::operator *()
{
	return pPtr[iIndex];
} 

vector :: iterator & vector :: iterator :: operator --()
{
	iIndex = iIndex - 1;
	return *this;
}
vector :: iterator vector :: iterator :: operator --(int)
{
	iterator pTemp = *this;	
	iIndex = iIndex - 1;
	return *this;
}
// friend Function
ostream & operator <<(ostream &out,vector &obj)
{
	for(size_t i = 0 ; i < obj.iSize ;i++)
		out<<obj.pArray[i]<<' ';		
} 
