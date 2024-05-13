#include<iostream>
#include<cstring>
using std :: cout;
using std :: endl;
using std :: ostream;

#ifndef _LIST_H
#define _LIST_H
template <typename T>
class vector
{
	T *pArray;
	int iSize;

	void memcopy(T * ,T *, int ,int );	
	public: 
	vector();
	~vector();

	vector(int);	
	
	class iterator
	{
		int iIndex;
		T *pPtr;
	
		public:
		iterator();
		~iterator();

		void Set(int,T *);
		int Get();

		bool operator ==(iterator &);
		bool operator !=(iterator &);
		iterator & operator ++();
		iterator operator ++(int);
		T operator *(); 
		iterator & operator --();
		iterator operator --(int);	
		void operator =(iterator &);

	};

	private:
	iterator FirstIndex;
	iterator LastIndex;
	
	public:
	int Size();	
	void swap(vector &);
	void insert(vector <T> :: iterator &I, T);

	iterator & begin();
	iterator & end();

	T & operator [](int);
	template <typename T1>  
	friend ostream & operator <<(ostream &out,vector<T1> &); 
};
// vector constructor & destructor
template <typename T>
vector<T> :: vector()
{
	pArray = NULL;
	iSize = 0;
}

template <typename T>
vector<T> :: ~vector()
{
	if(pArray != NULL)
	{
		delete []pArray;
	}

	pArray = NULL;
	iSize = 0;
}

template <typename T>
vector<T> :: vector(int iParamSize)
{
	pArray = new T[iParamSize];
	
	if(pArray == NULL)
	{
		cout<<"Memory allocation failed"<<endl;
		return ;
	}
	memset(pArray,0,iParamSize * sizeof(T));
	iSize = iParamSize;
		
}	

// iterator constructor & destructor
template <typename T>
vector<T> :: iterator :: iterator()
{
	iIndex = 0;
	pPtr = NULL;
}

template <typename T>
vector<T> :: iterator ::~iterator()
{
	iIndex = -1;
	pPtr = NULL;
}

// iterator Member Function
template <typename T>  
void vector<T> :: iterator :: Set(int iSetParam,T *pPtrParam)
{
	iIndex = iSetParam;	
	pPtr = pPtrParam;	
}

template <typename T>  
int vector<T> :: iterator :: Get()
{
	return iIndex;
}

// vector opeartor operator Overloading

template <typename T>
T & vector<T> :: operator [](int iIndex)
{
	return pArray[iIndex];
} 

// vector Member Function

template <typename T>  
typename vector<T> ::iterator & vector<T> :: begin()
{
	FirstIndex.Set(0,pArray);
	return FirstIndex;	
}

template <typename T>  
typename vector<T> ::iterator & vector<T> :: end()
{
	LastIndex.Set(iSize,pArray + iSize);
	return LastIndex;
}

template <typename T>  
void vector<T> :: swap (vector<T> &obj)
{
	iterator temp;

	T *pTemp = pArray;
	pArray = obj.pArray;
	obj.pArray = pTemp;

	iSize = iSize + obj.iSize;
	obj.iSize = iSize - obj.iSize;
	iSize = iSize - obj.iSize;

	temp = FirstIndex;
	FirstIndex = obj.FirstIndex;
	obj.FirstIndex = temp;

	temp = LastIndex;
	LastIndex = obj.FirstIndex;
	obj.LastIndex = temp;
	
}

template <typename T>
void vector<T> :: iterator ::operator =(vector :: iterator &iter)
{
	iIndex = iter.iIndex;
	pPtr = iter.pPtr;
}

template <typename T>  
void vector<T> :: insert(vector<T> :: iterator &I, T iNo)
{
	T * pTemp = NULL;
	int s = I.Get();	

	pTemp = new T[iSize + 1];
	if(pTemp == NULL)
	{
		cout<<"Memory allocation failed"<<endl;
		return;
	}	
	memcopy(pTemp,pArray,-1,s);
	pTemp[s] = iNo;
	memcopy(pTemp,pArray,s,iSize);
	
	delete []pArray;
	pArray = pTemp;
	iSize = iSize + 1;
	
	pTemp = NULL;			
}

template <typename T>	
int vector<T> :: Size()
{
	return iSize;
}

// vector private member function
template <typename T>  
void vector<T> :: memcopy(T *Old , T *New ,int start,int end)
{
	int count = start;
	if(count == -1)
		count++;	
	while(start < end)
	{
		Old[start+1] = New[count];
		start++;
		count++;
	}		
}	

// iterator opeartor overloading
template <typename T>  
bool vector<T> :: iterator :: operator !=(iterator &Second)
{
	if(iIndex != Second.iIndex)
		return true;

	return false;
}

template <typename T>  
bool vector<T> :: iterator :: operator == (iterator &Second)
{
	return (iIndex == Second.iIndex);			
}
 
template <typename T>  
typename vector<T> :: iterator & vector<T> :: iterator :: operator ++()
{
	iIndex = iIndex + 1;
	return *this;	
}

template <typename T>  
typename vector<T> :: iterator vector<T> ::iterator :: operator ++(int)
{
	 iterator pTemp = *this;
	 iIndex = iIndex + 1;
	 return pTemp;	
}


template <typename T>  
T vector<T> :: iterator ::operator *()
{
	return pPtr[iIndex];
} 

template <typename T>  
typename vector<T> :: iterator & vector<T> :: iterator :: operator --()
{
	iIndex = iIndex - 1;
	return *this;
}

template <typename T>  
typename vector<T> :: iterator vector<T> :: iterator :: operator --(int)
{
	iterator pTemp = *this;	
	iIndex = iIndex - 1;
	return *this;
}
// friend Function
template <typename T>  
ostream & operator <<(ostream &out,vector<T> &obj)
{
	for(size_t i = 0 ; i < obj.iSize ;i++)
		out<<obj.pArray[i]<<' ';		
} 
#endif
