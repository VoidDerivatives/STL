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
	pDummyNode = new Node;
	
	if(pDummyNode == NULL)
	{
		cout<<"Memory Allocation Failed"<<endl;
		return;	
	}	
	
	pDummyNode -> iData = 0;
	pDummyNode -> pNext = pDummyNode;
	pDummyNode -> pPrev = pDummyNode;

}

List :: ~List()
{
	if(pDummyNode != pDummyNode -> pNext)
		DeleteAllNode();
	
	pDummyNode -> pPrev = NULL;
	pDummyNode -> pNext = NULL;

	delete pDummyNode;

	pDummyNode = NULL;
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
	startiter.SetPCurrent(pDummyNode -> pNext);
	
	return startiter;
} 

List :: iterator & List :: End()
{
	enditer.SetPCurrent(pDummyNode);

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
	if(pDummyNode == pDummyNode -> pNext)
		return true;
	return false;
}	

void List :: InsertFirst(int iNo)
{
	Node *pNewNode = NULL;
	
	pNewNode = new Node;

	if(pNewNode == NULL)
	{	
		cout<<"Memory Allocation Failed "<<endl;
		return ;
	}
	
	pNewNode -> iData = iNo;

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

void List :: InsertLast(int iNo)
{
	Node *pNewNode = NULL;
	
	pNewNode = new Node;

	if(pNewNode == NULL)
	{	
		cout<<"Memory Allocation Failed "<<endl;
		return ;
	}
	
	pNewNode -> iData = iNo;

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
void List :: InsertAtPosition(int iPos,int iNo)
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
		InsertFirst(iNo);
		return ;
	}

	//if(iPos == iCount + 1)
	//{
	//	InsertLast(iNo);
	//	return ;
	//}

	pNewNode = new Node;
	if(NULL == pNewNode)
	{
		cout<<"Memory allocation failed"<<endl;
		return ;
	}
	pNewNode -> iData = iNo;

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

int List :: DeleteFirst()
{
	int iDelData;

	if(pDummyNode -> pNext == pDummyNode)
	{
		cout<<"List is Empty";
		return -1;			
	}	

	iDelData = pDummyNode -> pNext -> iData;

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
	
	return iDelData;	
}
int List :: DeleteLast()
{
	int iDelData;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty";
		return -1;			
	}	

	iDelData = pDummyNode -> pPrev -> iData;
	
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

	return iDelData;
}
int List :: DeleteAtPosition(int iPos)
{
	int iDelData;
	int iCount;	
	Node *pTemp = NULL;
	
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
	iDelData = pTemp -> iData;
	
	pTemp -> pPrev -> pNext = pTemp -> pNext;
	pTemp -> pNext -> pPrev = pTemp -> pPrev;

	pTemp -> pPrev = NULL;	
	pTemp -> pNext = NULL;

	delete pTemp;
	
	pTemp = NULL;
	return iDelData;	
			
}

int List :: SearchFirstOccurance(int iNo)
{
	int iPos = 0;
	Node *pTemp = pDummyNode -> pNext;		

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty"<<endl;
		return iPos;
	}	
	
	do
	{
		iPos++;
		if(pTemp -> iData == iNo)
			return iPos;
		
		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);	
	
	return 0;	
}
int List :: SearchLastOccurance(int iNo)
{
	int iPos = 0;
	int iRemember = 0;	
	Node *pTemp = pDummyNode -> pNext;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty"<<endl;
		return iPos;
	}
	
	do
	{
		iPos++;		
		if(pTemp -> iData == iNo)
			iRemember = iPos;

		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);	
	
	return iRemember;
}
int List :: SearchAllOccurance(int iNo)
{
	int iCount = 0;	
	Node *pTemp = pDummyNode -> pNext;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty"<<endl;
		return iCount;
	}
	
	do
	{
		if(pTemp -> iData == iNo)
			iCount++;
	
		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);	
	
	return iCount;
}
int List :: CountNode()
{
	int iCount = 0;
	Node *pTemp = pDummyNode -> pNext;

	if(pDummyNode -> pNext == pDummyNode)
		return iCount;
	do
	{
		iCount++;
		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);
	
	return iCount;
} 

void List :: Display()
{
	Node *pTemp = pDummyNode -> pNext;

	cout<<endl<<endl<<"-----Doubly Circular Linked List-----"<<endl<<endl;

	if(pDummyNode == pDummyNode -> pNext)
	{
		cout<<"List is Empty "<<endl;
		return;		
	}

	do
	{
		cout<<" <-|"<< pTemp -> iData <<"|-> ";
		pTemp = pTemp -> pNext;
	}while(pDummyNode != pTemp);
}

void List :: DeleteAllNode()
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
	
	cout<<endl<<"Deleted ALL Node Successfully"<<endl;	
}
ostream & operator <<(ostream &out,List &RefObj)
{
	Node *pTemp = RefObj.pDummyNode->pNext;
 
	out<<endl<<endl<<"-----Doubly Circular Linked List-----"<<endl;
	
	if(RefObj.pDummyNode == RefObj.pDummyNode -> pNext)
	{
		out<<"List is Empty";
		return out;
	}
			
	do
	{
		out<<" <- |"<<pTemp -> iData<<"| -> ";
		pTemp = pTemp -> pNext;	
	}while(pTemp != RefObj.pDummyNode);

	return out;
}
