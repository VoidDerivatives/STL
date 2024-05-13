#include<iostream>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: ostream;

//
// class Node declaration
//

template <typename T>
class List;

template <typename T>
class Node
{
	Node *pPrev;
	T tData;
	Node *pNext;

	public : Node();
		 ~Node();

	template <typename T1>
	friend class List;

	template <typename T1>
 	friend ostream & operator <<(ostream &,List<T1> &);

	template<typename T1>
	friend typename List<T1> :: iterator find(typename List<T1> :: iterator &,typename List<T1> :: iterator &,T1);	
};

//
// class list Declaration  
//
template <typename T>
class List
{
	Node<T> *pDummyNode;
	
	void DeleteAllNode();
	
	public : List();
		 ~List();
	
	template <typename T1>
	friend ostream & operator <<(ostream &,List<T1> &);	

	template<typename T1>
	friend typename List<T1> :: iterator find(typename List<T1> :: iterator &,typename List<T1> :: iterator &,T1);

	bool IsEmpty();	

	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(int,T);

	T DeleteFirst();
	T DeleteLast();
	T DeleteAtPosition(int);
	
	int SearchFirstOccurance(T);
	int SearchLastOccurance(T);
	int SearchAllOccurance(T);
	
	void Display();
	int CountNode();

	// class iterator declration
	class iterator
	{
		Node<T> *pCurrentNode;

		public :
		iterator();
		~iterator();

		void SetPCurrent(Node<T> *);
		Node<T> *GetPCurrent();

		template<typename T1>
		friend typename List<T1> :: iterator find(typename List<T1> :: iterator &,typename List<T1> :: iterator &,T1);
		// opeartor overload

		//template<typename T1>
		//friend void List<T1> :: splice(iterator,List<T1> &);
		
		bool operator !=(iterator &);

		bool operator ==(iterator &);
	
		T operator *();

		iterator & operator ++();	 
	
		iterator operator ++(int);

		iterator & operator --();

		iterator operator --(int);

	};

	private:	
	iterator startiter;  // object
	iterator enditer;    //objet

	public:
	iterator & Begin();
	iterator & End();

	void push_back(T);
	void push_front(T);
	void splice(iterator ,List<T> &);
	void splice(iterator ,List<T> &,iterator);
	void Sort();
	void unique();
	void merge(List<T> &);

	// operator overloading
	void operator =(List<T> &);

	private:
	void ConcatList(List <T> &);


		
};

// class Node
template <typename T>
Node<T> :: Node()
{
	pPrev = NULL;
	tData = (T)0;
	pNext = NULL;
}

template <typename T>
Node<T> :: ~Node()
{
	tData = 0;
	if(pNext != NULL)
		delete pNext;
		
	pNext = NULL;   
	pPrev = NULL;
}

// class list
template <typename T>
List<T> :: List()
{
	pDummyNode = new Node<T>;
	
	if(pDummyNode == NULL)
	{
		cout<<"Memory Allocation Failed"<<endl;
		return;	
	}	
	
	pDummyNode -> tData = 0;
	pDummyNode -> pNext = pDummyNode;
	pDummyNode -> pPrev = pDummyNode;

}

template <typename T>
List<T> :: ~List()
{
	if(pDummyNode != pDummyNode -> pNext)
		DeleteAllNode();
	
	pDummyNode -> pPrev = NULL;
	pDummyNode -> pNext = NULL;

	delete pDummyNode;

	pDummyNode = NULL;
	cout<<endl<<"Deleted ALL Node Successfully"<<endl<<endl;	
}

// class iterator
template <typename T>
List<T> :: iterator :: iterator()
{
	pCurrentNode = NULL; 
}

template <typename T>
List<T> :: iterator :: ~iterator()
{
	pCurrentNode = NULL; 
}

//
// Funtion Definitions of list
//

template <typename T>
typename List<T> :: iterator & List<T> :: Begin()
{
	startiter.SetPCurrent(pDummyNode -> pNext);
	
	return startiter;
} 

template <typename T>
typename List<T> :: iterator & List<T> :: End()
{
	enditer.SetPCurrent(pDummyNode);

	return enditer;
}

// Function definitions of iterator
template <typename T>
void List<T> :: iterator :: SetPCurrent(Node<T> *node)
{
	pCurrentNode = node;
}

template <typename T>
Node<T> * List<T> :: iterator :: GetPCurrent()
{
	return pCurrentNode;
}

//
// operator overloading of iterator class
//
template <typename T>
bool List<T> :: iterator :: operator !=(iterator &Second)
{
	if(pCurrentNode != Second.pCurrentNode)	
		return true;
	
	return false;		
}

template <typename T>
bool List<T> :: iterator :: operator ==(iterator &Second)
{
	return (pCurrentNode == Second.pCurrentNode);			
}

template <typename T>
T List<T> :: iterator :: operator *()
{
	return pCurrentNode -> tData;	
}

template <typename T>
typename List<T> :: iterator & List<T> :: iterator :: operator ++()
{
	pCurrentNode = pCurrentNode -> pNext;

	return *this;
}

template <typename T>
typename List<T> :: iterator List<T> :: iterator :: operator ++(int)
{
	iterator temp = *this;
	pCurrentNode = pCurrentNode -> pNext;
	return temp;
}

template <typename T>
typename List<T> :: iterator & List<T> :: iterator :: operator --()
{
	pCurrentNode = pCurrentNode -> pPrev;

	return *this;
}

template <typename T>
typename List<T> :: iterator List<T> :: iterator :: operator --(int)
{
	iterator temp = *this;
	pCurrentNode = pCurrentNode -> pPrev;

	return temp;
}
//
// operator overloading
//

template <typename T>
void List <T>::operator =(List<T> &list2)
{
	Node<T> *pTemp = list2.pDummyNode -> pNext;
	
	if(pDummyNode != pDummyNode -> pNext)
	{
		DeleteAllNode();
	}
	do	
	{
		InsertLast(pTemp -> tData);
		pTemp = pTemp -> pNext;		
		
	}while(list2.pDummyNode != pTemp);
}
//
// Function definitions of list class
//

template <typename T>
bool List<T> :: IsEmpty()
{
	if(pDummyNode == pDummyNode -> pNext)
		return true;
	return false;
}	

template <typename T>
void List<T> :: InsertFirst(T tNo)
{
	Node<T> *pNewNode = NULL;
	
	pNewNode = new Node<T>;

	if(pNewNode == NULL)
	{	
		cout<<"Memory Allocation Failed "<<endl;
		return ;
	}
	
	pNewNode -> tData = tNo;

	if(pDummyNode -> pNext == pDummyNode)
	{
		pNewNode -> pNext = pDummyNode;  // Circular Effect
		pDummyNode -> pPrev = pNewNode;  
	}	
	else
	{
		pNewNode -> pNext = pDummyNode -> pNext;
		pDummyNode -> pNext -> pPrev = pNewNode;
	}
	pDummyNode -> pNext = pNewNode;
	pNewNode -> pPrev = pDummyNode;

	pNewNode = NULL;	
}

template <typename T>
void List<T> :: InsertLast(T tNo)
{
	Node<T> *pNewNode = NULL;
	
	pNewNode = new Node<T>;

	if(pNewNode == NULL)
	{	
		cout<<"Memory Allocation Failed "<<endl;
		return ;
	}
	
	pNewNode -> tData = tNo;

	if(pDummyNode -> pNext == pDummyNode)
	{	
		pDummyNode -> pNext = pNewNode;
		pNewNode -> pPrev = pDummyNode;
	}
	else
	{
		pDummyNode -> pPrev -> pNext = pNewNode;
		pNewNode -> pPrev = pDummyNode -> pPrev;
	}	
	
	pNewNode -> pNext = pDummyNode;  // Circular Effect
	pDummyNode -> pPrev = pNewNode;

	pNewNode = NULL;
}

template <typename T>
void List<T> :: InsertAtPosition(int iPos,T tNo)
{
	Node<T> *pNewNode = NULL;
	Node<T> *pTemp = NULL;
	int iCount ;
	 
	iCount = CountNode();
	if(iPos <= 0  || iCount + 1 < iPos)
	{
		cout<<"Position is Invaild"<<endl<<endl;
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(tNo);
		return ;
	}

	//if(iPos == iCount + 1)
	//{
	//	InsertLast(iNo);
	//	return ;
	//}

	pNewNode = new Node<T>;
	if(NULL == pNewNode)
	{
		cout<<"Memory allocation failed"<<endl;
		return ;
	}
	pNewNode -> tData = tNo;

	pTemp = pDummyNode -> pNext;
	iCount = 1;

	while(iCount < iPos - 1 )
	{
		iCount++;
		pTemp = pTemp -> pNext;
	}

	pNewNode -> pNext = pTemp -> pNext;
	pTemp -> pNext -> pPrev = pNewNode;
	pTemp -> pNext = pNewNode;
	pNewNode -> pPrev = pTemp;

	//sanskar
	pNewNode = NULL;
	pTemp = NULL;
}

template <typename T>
T List<T> :: DeleteFirst()
{
	T tDelData;

	if(pDummyNode -> pNext == pDummyNode)
	{
		cout<<"List is Empty";
		return -1;			
	}	

	tDelData = pDummyNode -> pNext -> tData;

	if(pDummyNode -> pPrev == pDummyNode -> pNext)  // only One node
	{
		pDummyNode -> pNext -> pPrev = NULL;
		pDummyNode -> pNext -> pNext = NULL;
		delete pDummyNode -> pNext;
		
		pDummyNode -> pNext = pDummyNode;
		pDummyNode -> pPrev = pDummyNode; 
	}	
	else          // More than one node 
	{
		pDummyNode -> pNext = pDummyNode -> pNext -> pNext;
		pDummyNode -> pNext -> pPrev -> pNext = NULL;
		pDummyNode -> pNext -> pPrev -> pPrev = NULL;
		
		delete pDummyNode -> pNext -> pPrev;
	
		pDummyNode -> pNext -> pPrev = pDummyNode;
	}
	
	return tDelData;	
}

template <typename T>
T List<T> :: DeleteLast()
{
	T tDelData;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty";
		return -1;			
	}	

	tDelData = pDummyNode -> pPrev -> tData;
	
	if(pDummyNode -> pPrev == pDummyNode -> pNext)  // only One node
	{ 		
		pDummyNode -> pNext -> pPrev = NULL;
		pDummyNode -> pNext -> pNext = NULL;
		delete pDummyNode -> pNext;
		
		pDummyNode -> pNext = pDummyNode;
		pDummyNode -> pPrev = pDummyNode; 
		 	
	}	
	else
	{
		pDummyNode -> pPrev = pDummyNode -> pPrev -> pPrev;
		pDummyNode -> pPrev -> pNext -> pNext = NULL;
		pDummyNode -> pPrev -> pNext -> pPrev = NULL;
				
		delete pDummyNode -> pPrev -> pNext;

		pDummyNode -> pPrev -> pNext = pDummyNode; 
	}

	return tDelData;
}

template <typename T>
T List<T> :: DeleteAtPosition(int iPos)
{
	T tDelData;
	int iCount;	
	Node<T> *pTemp = NULL;
	
	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty"<<endl;
		return -1;
	}
	
	iCount = CountNode();
	if(iPos <= 0  || iCount < iPos)
	{
		cout<<"Position is Invaild"<<endl<<endl;
		return 0;
	}

	if(iPos == 1)  // One node
	{
		return(DeleteFirst());
	}

	pTemp = pDummyNode -> pNext;
	iCount = 1;

	while(iCount < iPos)
	{
		iCount++;
		pTemp = pTemp -> pNext;
	}
	tDelData = pTemp -> tData;
	
	pTemp -> pPrev -> pNext = pTemp -> pNext;
	pTemp -> pNext -> pPrev = pTemp -> pPrev;

	pTemp -> pPrev = NULL;	
	pTemp -> pNext = NULL;

	delete pTemp;
	
	pTemp = NULL;
	return tDelData;	
			
}

template <typename T>
int List<T> :: SearchFirstOccurance(T tNo)
{
	int iPos = 0;
	Node<T> *pTemp = pDummyNode -> pNext;		

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty"<<endl;
		return iPos;
	}	
	
	do
	{
		iPos++;
		if(pTemp -> tData == tNo)
			return iPos;
		
		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);	
	
	return 0;	
}

template <typename T>
int List<T> :: SearchLastOccurance(T tNo)
{
	int iPos = 0;
	int iRemember = 0;	
	Node<T> *pTemp = pDummyNode -> pNext;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty"<<endl;
		return iPos;
	}
	
	do
	{
		iPos++;		
		if(pTemp -> tData == tNo)
			iRemember = iPos;

		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);	
	
	return iRemember;
}

template <typename T>
int List<T> :: SearchAllOccurance(T tNo)
{
	int iCount = 0;	
	Node<T> *pTemp = pDummyNode -> pNext;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty"<<endl;
		return iCount;
	}
	
	do
	{
		if(pTemp -> tData == tNo)
			iCount++;
	
		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);	
	
	return iCount;
}

template <typename T>
int List<T> :: CountNode()
{
	int iCount = 0;
	Node<T> *pTemp = pDummyNode -> pNext;

	if(pDummyNode -> pNext == pDummyNode)
		return iCount;
	do
	{
		iCount++;
		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);
	
	return iCount;
} 

template <typename T>
void List<T> :: Display()
{
	Node<T> *pTemp = pDummyNode -> pNext;

	cout<<endl<<endl<<"-----Doubly Circular Linked List-----"<<endl<<endl;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty "<<endl;
		return;		
	}

	do
	{
		cout<<" <-|"<< pTemp -> tData <<"|-> ";
		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);
}

template <typename T>
void List<T> :: DeleteAllNode()
{
					
	if(pDummyNode -> pNext == pDummyNode)
	{
		cout<<endl<<"List is Empty"<<endl;
		return ;
	}
	do
	{				
		pDummyNode -> pNext -> pPrev = NULL;
		pDummyNode -> pNext = pDummyNode -> pNext -> pNext;
		pDummyNode -> pNext -> pPrev -> pNext = NULL;
		
		delete pDummyNode -> pNext -> pPrev;
		
		pDummyNode -> pNext -> pPrev = pDummyNode;	
		
		
	}while(pDummyNode != pDummyNode -> pNext);	
	
}

template<typename T>
void List<T> :: push_back(T tNo)
{
	InsertLast(tNo);
}

template<typename T>
void List<T> :: push_front(T tNo)
{
	InsertFirst(tNo);
}

template<typename T>
void List<T> :: splice(typename List<T> :: iterator DestinationPos,List<T> &SourceList)
{
	Node<T> *pTemp1 = DestinationPos.GetPCurrent();
	Node<T>	*pTemp2 = SourceList.pDummyNode;	

	pTemp1 -> pPrev -> pNext = pTemp2 -> pNext; 
	pTemp2 -> pNext -> pPrev = pTemp1 -> pPrev;
	
	pTemp1 -> pPrev = pTemp2 -> pPrev;
	pTemp2 -> pPrev -> pNext = pTemp1;

	pTemp2 -> pPrev = pTemp2; // only DummpyNode
	pTemp2 -> pNext = pTemp2;
}

template<typename T>
void List<T> :: splice(typename List<T> :: iterator DestinationPos,List<T> &SourceList,typename List<T> :: iterator SourcePos)
{
	Node<T> *pTemp1 = SourceList.pDummyNode;  // DummyNode
	Node<T> *pTemp2 = DestinationPos.GetPCurrent();	   // Destination node	
	Node<T> *pTemp3 = SourcePos.GetPCurrent();         // Source node

	if(SourceList.pDummyNode == SourceList.pDummyNode -> pNext)
	{
		cout<<"Source List is Empty";
		return;
	}

	pTemp2 -> pNext = pTemp3 -> pNext;
	pTemp3 -> pNext -> pPrev = pTemp2 -> pNext;
	pTemp3 -> pPrev = pTemp2 -> pPrev;
	pTemp3 -> pNext = pTemp2; 
	pTemp2 -> pPrev = pTemp3;
	pTemp3 -> pPrev -> pNext = pTemp3;
	
}

template<typename T>	
void List<T> :: Sort()
{
	int icounter;
	Node<T> *pTemp1 = pDummyNode -> pNext;
	Node<T> *pTemp2 = pDummyNode -> pNext -> pNext;
	int swap = 0;
	int iCount;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty:"<<endl;
		return;
	}

	iCount = CountNode();
	do
	{
		swap = 0;
		
		for(icounter = 0;icounter < iCount;icounter++)
		{
			if(pTemp1 -> tData > pTemp2 -> tData)
			{

				pTemp2 -> pNext -> pPrev = pTemp1;
				pTemp1 -> pPrev -> pNext = pTemp2;
				
				pTemp2 -> pPrev = pTemp1 -> pPrev;
				pTemp1 -> pNext = pTemp2 -> pNext;
		
				pTemp2 -> pNext = pTemp1;
				pTemp1 -> pPrev = pTemp2;

				pTemp1 = pTemp1 -> pPrev;
				pTemp2 = pTemp2 -> pNext;

				swap++;
	
			}
					
			pTemp1 = pTemp1 -> pNext;
			pTemp2 = pTemp1 -> pNext;

		}
	
		iCount--;
		pTemp1 = pDummyNode -> pNext;
		pTemp2 = pTemp1 -> pNext;
	}while(swap != 0);

}

template<typename T>
void List<T> ::unique()
{	
	Node<T> *pTemp1 = pDummyNode -> pNext;
	Node<T> *pTemp2 = pDummyNode -> pNext -> pNext;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty"<<endl;
		return ;
	}
	
	Sort();	 // for  optimise Unique code
	do
	{	
		while(pDummyNode != pTemp2)
		{
			if(pTemp1 -> tData == pTemp2 -> tData)
			{
				pTemp1 -> pNext = pTemp2 -> pNext;
				pTemp2 -> pNext -> pPrev = pTemp1;

				pTemp2 -> pNext = NULL;
				pTemp2 -> pPrev = NULL;

				delete pTemp2;

				pTemp2 = pTemp1 -> pNext; 				
			}
			else
			{
				break;
				//pTemp2 = pTemp2 -> pNext;
			}
		}

		pTemp1 = pTemp1 -> pNext;
		pTemp2 = pTemp1 -> pNext;
	}while(pDummyNode != pTemp1);	
	
}

template<typename T>
void List<T> :: merge(List<T> &list2)
{
	ConcatList(list2);
	Sort();	
}

template<typename T>
void List<T> :: ConcatList(List <T> &list2)
{
	if(list2.pDummyNode == list2.pDummyNode-> pNext)
		return ;

	if(pDummyNode == pDummyNode -> pNext)
	{
		pDummyNode = list2.pDummyNode;
		list2.DeleteAllNode();
	}

	pDummyNode -> pPrev -> pNext = list2.pDummyNode -> pNext;
	list2.pDummyNode-> pNext -> pPrev = pDummyNode -> pPrev;
	
	pDummyNode -> pPrev = list2.pDummyNode -> pPrev;
	list2.pDummyNode -> pPrev -> pNext = pDummyNode;

	list2.pDummyNode -> pPrev = list2.pDummyNode;
	list2.pDummyNode -> pNext = list2.pDummyNode; 
}
//
// Necked functions
//
template <typename T>
ostream & operator <<(ostream &out,List<T> &RefObj)
{
	Node<T> *pTemp = RefObj.pDummyNode->pNext;
 
	out<<endl<<endl<<"-----Doubly Circular Linked List-----"<<endl;
	
	if(RefObj.pDummyNode == RefObj.pDummyNode -> pNext)
	{
		out<<"List is Empty";
		return out;
	}
			
	do
	{
		out<<" <- |"<<pTemp -> tData<<"| -> ";
		pTemp = pTemp -> pNext;	
	}while(pTemp != RefObj.pDummyNode);

	return out;
}

template<typename T>
typename List<T> :: iterator find(typename List<T> :: iterator &BeginObj , typename List<T> :: iterator &EndObj,T tNo)
{
	typename List<T> :: iterator temp = BeginObj;
	Node<T> *pTemp = BeginObj.pCurrentNode;
	
	if(BeginObj.pCurrentNode == EndObj.pCurrentNode)
		return temp;

	do
	{
		if(pTemp -> tData == tNo)
		{ 	
			temp.pCurrentNode = pTemp;
			return temp;
		}
		pTemp = pTemp -> pNext;	

	}while(EndObj.pCurrentNode != pTemp);

	temp.pCurrentNode = pTemp;
	return temp;
}
