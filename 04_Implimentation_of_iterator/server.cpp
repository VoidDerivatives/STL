#include<iostream>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: ostream;

#include "server.h"
 
// class Node
Node :: Node()
{
	pPrev = NULL;
	iData = 0;
	pNext = NULL;
}

Node :: ~Node()
{
	iData = 0;
	if(pNext != NULL)
		delete pNext;
		
	pNext = NULL;   
	pPrev = NULL;
}

// class list
List :: List()
{
	pFirst = NULL;
	pLast = NULL;
}

List :: ~List()
{
	if(pFirst != NULL)
		DeleteAllNode();

	pFirst = NULL;
	pLast = NULL;
}

// class iterator

List :: iterator :: iterator()
{
	pCurrentNode = NULL; 
}

List :: iterator :: ~iterator()
{
	pCurrentNode = NULL; 
}

//
// Funtion Definitions of list
//

List :: iterator & List :: Begin()
{
	startiter.SetPCurrent(pFirst);
	
	return startiter;
} 

List :: iterator & List :: End()
{
	enditer.SetPCurrent(pLast);

	return enditer;
}

// Function definitions of iterator

void List :: iterator :: SetPCurrent(Node* node)
{
	pCurrentNode = node;
}

Node * List :: iterator :: GetPCurrent()
{
	return pCurrentNode;
}

//
// operator overloading of iterator class
//

bool List :: iterator :: operator !=(iterator &Second)
{
	if(pCurrentNode != Second.pCurrentNode)	
		return true;
	
	return false;		
}

bool List :: iterator :: operator ==(iterator &Second)
{
	return (pCurrentNode == Second.pCurrentNode);			
}

int List :: iterator :: operator *()
{
	return pCurrentNode -> iData;	
}

List :: iterator & List :: iterator :: operator ++()
{
	pCurrentNode = pCurrentNode -> pNext;

	return *this;
}

List :: iterator List :: iterator :: operator ++(int)
{
	iterator temp = *this;
	pCurrentNode = pCurrentNode -> pNext;
	return temp;
}

List :: iterator & List :: iterator :: operator --()
{
	pCurrentNode = pCurrentNode -> pPrev;

	return *this;
}

List :: iterator List :: iterator :: operator --(int)
{
	iterator temp = *this;
	pCurrentNode = pCurrentNode -> pPrev;

	return temp;
}

//
// Function definitions of list class
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
