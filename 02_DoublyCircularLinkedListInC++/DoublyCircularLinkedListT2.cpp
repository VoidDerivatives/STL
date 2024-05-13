//
// Header Files
//
#include<iostream>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: ostream;
//
// class Node declaration
//
class List; 
class Node
{
	Node *pPrev;
	int iData;
	Node *pNext;

	public : Node();
		 ~Node();

	friend class List;
 	friend ostream & operator <<(ostream &,List &);	
};

//
// class list Declaration  
//
class List
{
	Node *pFirst;
	Node *pLast;
	
	public : List();
		 ~List();
	
	friend ostream & operator <<(ostream &,List &);	
	bool IsEmpty();	

	void InsertFirst(int);
	void InsertLast(int);
	void InsertAtPosition(int,int);

	int DeleteFirst();
	int DeleteLast();
	int DeleteAtPosition(int);
	
	int SearchFirstOccurance(int);
	int SearchLastOccurance(int);
	int SearchAllOccurance(int);
	
	void Display();
	int CountNode();

	private:
	void DeleteAllNode();
};

//
// Constructor to initilize class node
// 
Node :: Node()
{
	pPrev = NULL;
	iData = 0;
	pNext = NULL;
}

//
// Destructor to delete or deintilize class node
//

Node :: ~Node()
{
	iData = 0;
	if(pNext != NULL)
		delete pNext;
		
	pNext = NULL;   
	pPrev = NULL;
}

//
// Constructor in initilize class list 
//

List :: List()
{
	pFirst = NULL;
	pLast = NULL;
}

//
// Destructor to delete or deintilize class node
//

List :: ~List()
{
	if(pFirst != NULL)
		DeleteAllNode();

	pFirst = NULL;
	pLast = NULL;
}

//
// Funtion Definitions
//

bool List :: IsEmpty()
{
	if(pFirst == NULL)
		return 1;
	return 0;
}	

void List :: InsertFirst(int iData)
{
	Node *pNewNode = NULL;

	pNewNode = new Node;	
	if(NULL == pNewNode)
	{
		cout<<"Memory allocation Failed";
		return ;
	}
		
	pNewNode -> iData = iData;	
		
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

void List :: InsertLast(int iData)
{
	Node *pNewNode = NULL;
	
	pNewNode = new Node;
	
	if(NULL == pNewNode)
	{
		cout<<"Memory allocation Failed";
		return ;
	}
		
	pNewNode -> iData = iData;	
		
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
void List :: InsertAtPosition(int iPos,int iData)
{
	Node *pNewNode = NULL;
	Node *pTemp = NULL;
	int iCount ;
	 
	
	iCount = CountNode();
	if(iPos <= 0  || iCount + 1 < iPos)
	{
		cout<<"Position is Invaild"<<endl<<endl;
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(iData);
		return ;
	}

	if(iPos == iCount + 1)
	{
		InsertLast(iData);
		return ;
	}

	pNewNode = new Node;
	if(NULL == pNewNode)
	{
		cout<<"Memory allocation failed"<<endl;
		return ;
	}
	pNewNode -> iData = iData;

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

int List :: DeleteFirst()
{
	int iData;

	if(NULL == pFirst)
	{
		cout<<"List is Empty";
		return -1;			
	}	
	
	iData = pFirst -> iData;

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
	
	return iData;
	
}
int List :: DeleteLast()
{
	int iDelData;

	if(NULL == pFirst)
	{
		cout<<"List is Empty";
		return -1;			
	}	

	iDelData = pLast -> iData;
	
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
int List :: DeleteAtPosition(int iPos)
{

	int iDelData;
	int iCount;	
	Node *pTemp;
	
	if(NULL == pFirst)
	{
		cout<<"List is Empty"<<endl;
		return -1;
	}
	
	iCount = CountNode();
	if(iPos<=0  || iCount < iPos)
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

int List :: SearchFirstOccurance(int iData)
{
	int iPos = 0;
	Node *pHead = pFirst;
	Node *pTail = pLast;		

	if(NULL == pHead)
	{
		cout<<"List is Empty"<<endl;
		return iPos;
	}	
	
	do
	{
		iPos++;
		if(pHead -> iData == iData)
			return iPos;
		
		pHead = pHead -> pNext;
	}while(pHead != pTail-> pNext);	
	
	return 0;	
}
int List :: SearchLastOccurance(int iData)
{
	int iPos = 0;
	int iRemember = 0;	
	Node *pHead = pFirst;
	Node *pTail = pLast;	

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
int List :: SearchAllOccurance(int iData)
{

	int iCount = 0;	
	Node *pHead = pFirst;
	Node *pTail = pLast;
	
	if(NULL == pHead)
	{
		cout<<"List is Empty"<<endl;
		return iCount;
	}
	
	do
	{
		if(pHead -> iData == iData)
			iCount++;	
		
		pHead = pHead -> pNext;
	}while(pHead != pTail-> pNext);	
	
	return iCount;
}

int List :: CountNode()
{	
	int iCount = 0;
	Node *pHead = pFirst;
	Node *pTail = pLast;

	if(NULL == pHead)
		return iCount;
	
	do
	{
		iCount++;
		pHead = pHead -> pNext;	
	}while(pHead != (pTail -> pNext));
	return iCount;
}
void List :: Display()
{	
	Node *pHead = pFirst;
 
	cout<<endl<<endl<<"-----Doubly Circular Linked List-----"<<endl;
	if(NULL == pFirst)
	{
		cout<<"List is Empty";
		return;
	}
			
	do
	{
		cout<<" <- |"<<pHead -> iData<<"| -> ";
		pHead = pHead -> pNext;	
	}while(pHead != (pLast -> pNext));	
}	

void List :: DeleteAllNode()
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
//
// Necked Function
//
ostream & operator <<(ostream &out,List &RefObj)
{
	Node *pHead = RefObj.pFirst;
 
	out<<endl<<endl<<"-----Doubly Circular Linked List-----"<<endl;
	if(NULL == RefObj.pFirst)
	{
		out<<"List is Empty";
		return out;
	}
			
	do
	{
		out<<" <- |"<<pHead -> iData<<"| -> ";
		pHead = pHead -> pNext;	
	}while(pHead != ((RefObj.pLast) -> pNext));

	return out;
}


int main(void)
{
	List obj;
	
	int iPos;
	int iData;
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
		cout<<"\t\t5] Exit"<<endl;

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
							cin>>iData;
							obj.InsertFirst(iData);
			
								break;

						case 2: cout<<"_____________________________________"<<endl;
					
							cout<<"Enter the data:\t";
							cin>>iData;
							obj.InsertLast(iData);
					
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
								cin>>iData;
					
								obj.InsertAtPosition(iPos,iData);
					
								break;
						case 4: break;
						
						default :cout<<"Choice is Invaild"<<endl<<endl;
								break;
						}
					
					if(iChoice2 > 4)
						continue;					
					
					cout<<obj<<endl;
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
					
								iData = obj.DeleteFirst();
					
								cout<<endl<<"Your deleted Data is:\t"<<iData<<endl;

								
									break;

							case 2: cout<<"_____________________________________"<<endl;
									
									iData = obj.DeleteLast();
				
									cout<<endl<<"Your deleted Data is:\t"<<iData<<endl;
					
									break;

							case 3: cout<<"_____________________________________"<<endl;
									
									cout<<"Enter the position which to be deleted:\t";
									cin>>iPos;
				
									iCount = obj.CountNode();
									if(iPos<=0  || iCount < iPos)
									{
										cout<<"Position is Invaild"<<endl<<endl;
										break;
									}
									iData = obj.DeleteAtPosition(iPos);
					
									cout<<endl<<"Your deleted Data is:\t"<<iData<<endl;
					
									break;
							case 4:break;
							default:cout<<"Choice is Invaild"<<endl<<endl;
									break;
							}
						if(iChoice2 > 4)
							continue;

					cout<<obj<<endl;
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
							cin>>iData;
					
								iPos = obj.SearchFirstOccurance(iData);
		
								if(iPos == 0)
									cout<<"Data not found"<<endl;
								else
									cout<<"Data is found at "<<iPos<<" position."<<endl;
						
								break;
	
						case 2:	cout<<"_____________________________________"<<endl;
							
							cout<<"Enter the data which to be search At pLast Occurance:\t";
							cin>>iData;
					
							iPos = obj.SearchLastOccurance(iData);
					
							if(iPos == 0)
								cout<<"Data not found"<<endl;
							else 
							  cout<<"Data is found at "<<iPos<<" position."<<endl;
					
							break;

						case 3:cout<<"_____________________________________"<<endl;
							
							cout<<"Enter the data which to be search All (count)Occurance:\t";
							cin>>iData;
					
							iPos = obj.SearchAllOccurance(iData);
						
							cout<<"Total count Is:\t"<<iPos<<endl;
					 
							break;
					case 4:break;
					default:cout<<"Choice is Invaild";
						break;
						}
							
					if(iChoice2 > 4)
						continue;
					obj.Display();
	
					cout<<endl<<"_____________________________________"<<endl;
					}while(iChoice2 != 4);
						break;

			
			case 4:cout<<"_____________________________________"<<endl;
					cout<<obj<<endl;
					
					cout<<endl<<endl<<"Total count is:\t"<<obj.CountNode()<<endl;
					
					break;

			case 5: cout<<"_____________________________________"<<endl;
							
				break;

			
			default: cout<<"_____________________________________"<<endl<<endl;
					 
				cout<<"Choice is Invalid"<<endl<<endl;
					
					break;
		}
	}while(iChoice1 != 5);
	
	return 0;
}
