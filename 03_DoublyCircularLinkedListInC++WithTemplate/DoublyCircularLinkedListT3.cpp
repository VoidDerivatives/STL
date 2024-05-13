#include<iostream>
using std :: cout;
using std :: cin;
using std :: endl; 
using std :: ostream;

template <typename T>
class List;

template <typename T>
class Node
{
	Node *pPrev;
	T tData;
	Node *pNext;

	public:	
	Node()
	{
		pPrev = NULL;
		tData = (T)0;
		pNext = NULL;
	}


	 ~Node()
	{
		tData = 0;
		if(pNext != NULL)
			delete pNext;
		
		pNext = NULL;   
		pPrev = NULL;
	}

	template <typename T1>
	friend class List;

	template <typename T1>	
 	friend ostream & operator <<(ostream &,List<T1> &);	
};

//
// class list Declaration  
//
template <typename T>
class List
{
	Node<T> *pFirst;
	Node<T> *pLast;
	
	public : List()
		{
			pFirst = NULL;
			pLast = NULL;
		}
 		~List()	
		{
			if(pFirst != NULL)
				DeleteAllNode();
	
			pFirst = NULL;
			pLast = NULL;
		}
	
	template <typename T1>
	friend ostream & operator <<(ostream &,List<T1> &);	
	bool IsEmpty()
	{
		if(pFirst == NULL)
			return 1;
		return 0;	
	}	

	void InsertFirst(T tNo)	
	{
		Node<T> *pNewNode = NULL;

		pNewNode = new Node<T>;	
		if(NULL == pNewNode)
		{
			cout<<"Memory allocation Failed";
			return ;
		}
			
		pNewNode -> tData = tNo;	
			
		if(pFirst == NULL)  // pFirst Node
		{
			pFirst = pNewNode;
			pLast = pNewNode;
				
		}	
		else       // More than One Node	
		{
			pNewNode -> pNext = pFirst; 
			pFirst -> pPrev = pNewNode;   	
			pFirst = pNewNode;
		}	
	
		pLast -> pNext = pFirst;
		pFirst -> pPrev = pLast;

		pNewNode = NULL ; // sanskar	
		}
	
		void InsertLast(T tNo)
		{
			Node<T> *pNewNode = NULL;
	
			pNewNode = new Node<T>;
	
			if(NULL == pNewNode)
			{
				cout<<"Memory allocation Failed";
				return ;
			}
		
			pNewNode -> tData = tNo;	
		
			if(pFirst == NULL)  // pFirst Node
			{
				pFirst = pNewNode;
				pLast = pNewNode;			
			}	
			else
			{
				pLast -> pNext = pNewNode;
				pNewNode -> pPrev = pLast;		
				pLast = pNewNode;
			}
	
			pLast -> pNext = pFirst;
			pFirst -> pPrev = pLast;

			pNewNode = NULL;
		}

		void InsertAtPosition(int iPos,T tNo)
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

			if(iPos == iCount + 1)
			{
				InsertLast(tNo);
				return ;
			}	

			pNewNode = new Node<T>;
			if(NULL == pNewNode)
			{
				cout<<"Memory allocation failed"<<endl;
				return ;
			}
			pNewNode -> tData = tNo;
	
			pTemp = pFirst;
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
  		
	T DeleteFirst()
	{
		T tDelData;

		if(NULL == pFirst)
		{
			cout<<"List is Empty";
			return -1;			
		}	
		
		tDelData = pFirst -> tData;
	
		if(pFirst == pLast)  // only One node
		{
			pFirst -> pPrev = NULL;
			pFirst -> pNext = NULL;
			delete pFirst;
			pFirst = NULL;
			pLast = NULL; 	 	
		}	
		else          // More than one node 
		{
		
			pFirst = pFirst -> pNext;
			pLast -> pNext -> pNext = NULL;
			pLast -> pNext -> pPrev = NULL;
			
			delete pLast -> pNext;
			pFirst -> pPrev = pLast;
			pLast -> pNext = pFirst;
		}
		
		return tDelData;
	
	}

	T DeleteLast()
	{
		T iDelData;

		if(NULL == pFirst)
		{
			cout<<"List is Empty";
			return -1;			
		}	

		iDelData = pLast -> tData;
	
		if(pFirst == pLast)  // only One node
		{ 		
			pFirst -> pPrev = NULL;
			pFirst -> pNext = NULL;
			delete pFirst;
			pFirst = NULL;
			pLast = NULL; 	 	
		}	
		else
		{

			pLast = pLast -> pPrev;
		
			pFirst -> pPrev -> pNext = NULL;
		 	pFirst -> pPrev -> pPrev = NULL;
				
			delete pLast -> pNext;
	
			pLast -> pNext = pFirst;	  
			pFirst -> pPrev = pLast;

			Display();
		}

		return iDelData;	
	
		}

	T DeleteAtPosition(int iPos)
	{	

		T iDelData;
		int iCount;	
		Node<T> *pTemp;
	
		if(NULL == pFirst)
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

		pTemp = pFirst;
		iCount = 1;

		while(iCount < iPos)
		{
			iCount++;
			pTemp = pTemp -> pNext;
		}
		iDelData = pTemp -> iData;

		iCount = CountNode();

		if(iPos == iCount)
		pLast = pTemp -> pPrev;
	
		pTemp -> pPrev -> pNext = pTemp -> pNext;
		pTemp -> pNext -> pPrev = pTemp -> pPrev;

		pTemp -> pNext  = NULL;
		pTemp -> pPrev = NULL;
		
		delete pTemp;
		pTemp = NULL;
		return iDelData;	
		
	}

	int SearchFirstOccurance(T tData)
	{
		int iPos = 0;
		Node<T> *pHead = pFirst;
		Node<T> *pTail = pLast;		
	
		if(NULL == pHead)
		{
			cout<<"List is Empty"<<endl;
				return iPos;
		}	
	
		do
		{
			iPos++;
			if(pHead -> tData == tData)
				return iPos;
			
			pHead = pHead -> pNext;
		}while(pHead != pTail-> pNext);	
	
	return 0;	
	}

		int SearchLastOccurance(T iData)
		{
			int iPos = 0;
			int iRemember = 0;	
			Node<T> *pHead = pFirst;
		Node<T> *pTail = pLast;	

		if(NULL == pHead)
		{
			cout<<"List is Empty"<<endl;
			return iPos;
		}
		
		do
		{
			iPos++;		
			if(pHead -> iData == iData)
				iRemember = iPos;
		
			pHead = pHead -> pNext;
		}while(pHead != pTail-> pNext);	
	
		return iRemember;
		}
		int SearchAllOccurance(T tData)
		{
			int iCount = 0;	
			Node<T> *pHead = pFirst;
			Node<T> *pTail = pLast;
	
			if(NULL == pHead)
			{
				cout<<"List is Empty"<<endl;
				return iCount;
			}
	
			do
			{
				if(pHead -> iData == tData)
				iCount++;	
		
				pHead = pHead -> pNext;
			}while(pHead != pTail-> pNext);	
	
			return iCount;
		}

		void Display()
		{	
			Node<T> *pHead = pFirst;
 
			cout<<endl<<endl<<"-----Doubly Circular Linked List-----"<<endl;
			if(NULL == pFirst)
			{
				cout<<"List is Empty";
				return;
			}
				
			do
			{
				cout<<" <- |"<<pHead -> tData<<"| -> ";
				pHead = pHead -> pNext;	
			}while(pHead != (pLast -> pNext));	
		}	

		int CountNode()
		{	
			int iCount = 0;
			Node<T> *pHead = pFirst;
			Node<T> *pTail = pLast;

			if(NULL == pHead)
				return iCount;
	
			do
			{
				iCount++;
				pHead = pHead -> pNext;	
			}while(pHead != (pTail -> pNext));
			return iCount;
		}

	private:
	
void DeleteAllNode()
{
					
	if(NULL == pFirst)
	{
		cout<<endl<<"List is Empty"<<endl;
		return ;
	}
	do
	{				
		pFirst = pFirst -> pNext;
		pLast -> pNext -> pNext = NULL;
		
		if(pFirst == pLast)
		{
			pLast -> pPrev = NULL;
			delete pFirst;
			break;
		} 

		pLast -> pNext -> pPrev = NULL;	
		delete (pLast -> pNext);

		pFirst -> pPrev = pLast;
		pLast -> pNext = pFirst;			
	}while(pFirst != pLast);
	
	pFirst = NULL;
	pLast = NULL;	
	
	cout<<endl<<"Deleted ALL Node Successfully"<<endl;	
}
};

template <typename T>
ostream & operator <<(ostream &out,List<T> &RefObj)
{
	Node<T> *pHead = RefObj.pFirst;
 
	out<<endl<<endl<<"-----Doubly Circular Linked List-----"<<endl;
	if(NULL == RefObj.pFirst)
	{
		out<<"List is Empty";
		return out;
	}
			
	do
	{
		out<<" <- |"<<pHead -> tData<<"| -> ";
		pHead = pHead -> pNext;	
	}while(pHead != ((RefObj.pLast) -> pNext));

	return out;
}

template <typename T>
void MyMain(T)
{
	List<T> obj;
	
	int iPos;
	T tData;
	int iCount;
	int iChoice1;
	int iChoice2;

	do
	{
		cout<<"___________________________________________________________"<<endl;
		cout<<"\t\t\tMain Menu\t\t\t"<<endl;
		cout<<"\t\t1] Insert"<<endl;
		cout<<"\t\t2] Delete"<<endl;
		cout<<"\t\t3] Search"<<endl;
		cout<<"\t\t4] Count"<<endl;
		cout<<"\t\t5] Back"<<endl;

		cout<<endl<<"Enter Your Choice:\t";
		cin>>iChoice1;			

		if(iChoice1 == 2 || iChoice1 == 3)
			if(obj.IsEmpty())
			{
				cout<<"List is Empty"<<endl<<endl;
				continue;
			}
		switch(iChoice1)
		{
			case 1:	cout<<"_____________________________________"<<endl;
					do
					{
						cout<<"1] InsertFirst"<<endl<<"2] InsertLast"<<endl<<"3] InsertAtPosition"<<endl;
						cout<<"4] Back"<<endl;
						cout<<endl<<"Enter the Choice:\t";
						cin>>iChoice2;

						switch(iChoice2)
						{
						case 1: cout<<"_____________________________________"<<endl;
						   	cout<<"Enter the data:\t";
							cin>>tData;
							obj.InsertFirst(tData);
			
								break;

						case 2: cout<<"_____________________________________"<<endl;
					
							cout<<"Enter the data:\t";
							cin>>tData;
							obj.InsertLast(tData);
					
							break;

						case 3: cout<<"_____________________________________"<<endl;
		
								cout<<"Enter the position:\t";
								cin>>iPos;
					
								iCount = obj.CountNode();
								if(iPos <= 0  || iCount + 1 < iPos)
								{
									cout<<"Position is Invaild"<<endl<<endl;
									break;
								}
								cout<<"Enter the data:\t";
								cin>>tData;
					
								obj.InsertAtPosition(iPos,tData);
					
								break;
						case 4: break;
						
						default :cout<<"Choice is Invaild"<<endl<<endl;
								break;
						}
					
					if(iChoice2 > 4)
						continue;					
					
					obj.Display();
					cout<<endl<<"_____________________________________"<<endl;	
					}while(iChoice2 != 4);
					break;

			case 2:	cout<<"_____________________________________"<<endl;	
					do
					{
						cout<<"1] Delete pFirst"<<endl<<"2] Delete pLast"<<endl<<"3] Delete At Position"<<endl;
						cout<<"4] Back"<<endl;
						cout<<endl<<"Enter the Choice:\t";
						cin>>iChoice2;

						switch(iChoice2)
						{

							case 1:cout<<"_____________________________________"<<endl;
					
								//tData = obj.DeleteFirst();
					
								cout<<endl<<"Your deleted Data is:\t"<<tData<<endl;

								
									break;

							case 2: cout<<"_____________________________________"<<endl;
									
									//tData = obj.DeleteLast();
				
									cout<<endl<<"Your deleted Data is:\t"<<tData<<endl;
					
									break;

							case 3: cout<<"_____________________________________"<<endl;
									
									cout<<"Enter the position which to be deleted:\t";
									cin>>iPos;
				
									//iCount = obj.CountNode();
									if(iPos<=0  || iCount < iPos)
									{
										cout<<"Position is Invaild"<<endl<<endl;
										break;
									}
								//	tData = obj.DeleteAtPosition(iPos);
					
									cout<<endl<<"Your deleted Data is:\t"<<tData<<endl;
					
									break;
							case 4:break;
							default:cout<<"Choice is Invaild"<<endl<<endl;
									break;
							}
						if(iChoice2 > 4)
							continue;

					//obj.Display();
						cout<<endl<<"_____________________________________"<<endl;
					}while(iChoice2 != 4);
						break;

			case 3:	cout<<"_____________________________________"<<endl;
					do
					{
						cout<<"1] Serach pFirst occurance"<<endl;
						cout<<"2] search pLast Occarance"<<endl;
						cout<<"3] Search All Occuarance"<<endl;
						cout<<"4] back"<<endl;
						
						cout<<endl<<"Enter the Choice:\t";
						cin>>iChoice2;

						switch(iChoice2)
						{
						case 1:	cout<<"_____________________________________"<<endl;
								
							cout<<"Enter the data which to be search At pFirst Occurance:\t";
							cin>>tData;
					
								//iPos = obj.SearchFirstOccurance(tData);
		
								if(iPos == 0)
									cout<<"Data not found"<<endl;
								else
									cout<<"Data is found at "<<iPos<<" position."<<endl;
						
								break;
	
						case 2:	cout<<"_____________________________________"<<endl;
							
							cout<<"Enter the data which to be search At pLast Occurance:\t";
							cin>>tData;
					
							//iPos = obj.SearchLastOccurance(tData);
					
							if(iPos == 0)
								cout<<"Data not found"<<endl;
							else 
							  cout<<"Data is found at "<<iPos<<" position."<<endl;
					
							break;

						case 3:cout<<"_____________________________________"<<endl;
							
							cout<<"Enter the data which to be search All (count)Occurance:\t";
							cin>>tData;
					
							//iPos = obj.SearchAllOccurance(tData);
						
							cout<<"Total count Is:\t"<<iPos<<endl;
					 
							break;
					case 4:break;
					default:cout<<"Choice is Invaild";
						break;
						}
							
					if(iChoice2 > 4)
						continue;
					//obj.Display();
	
					cout<<endl<<"_____________________________________"<<endl;
					}while(iChoice2 != 4);
						break;

			
			case 4:cout<<"_____________________________________"<<endl;
					//obj.Display();
					
					//cout<<endl<<endl<<"Total count is:\t"<<obj.CountNode()<<endl;
					
					break;

			case 5: cout<<"_____________________________________"<<endl;
							
				break;

			
			default: cout<<"_____________________________________"<<endl<<endl;
					 
				cout<<"Choice is Invalid"<<endl<<endl;
					
					break;
		}
	}while(iChoice1 != 5);
	
}

int main(void)
{
	int iChoice;

	do
	{
		cout<<"Which type of LinkedList You Want to Create :"<<endl;
		cout<<"1 ] int "<<endl<<"2 ] char "<<endl;
		cout<<"3 ] Single precision floating point (float)"<<endl;
		cout<<"4 ] Double precision floation point (double)"<<endl;
		cout<<"5 ] Exit "<<endl;

		cout<<"Enter your choice:\t";
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:MyMain(2);
				break;
			case 2:MyMain('A');
				break;
			case 3:MyMain(88.00f);
				break;
			case 4:MyMain(90.00);
				break;
			case 5:break;

			default : cout<<"Your Choice is Wrong"; 
		}
	}while(iChoice != 5);	

	return 0;
}
