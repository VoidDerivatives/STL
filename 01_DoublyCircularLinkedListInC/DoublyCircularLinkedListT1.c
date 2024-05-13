#include<stdio.h>
#include<malloc.h>
//
// Structure Declaration
//
struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

//
// Function Declaration
//
void InsertFirst(struct node **,struct node **,int);
void InsertLast(struct node **,struct node **,int);
void InsertAtPosition(struct node **,struct node **,int,int);

int DeleteFirst(struct node **,struct node **);
int DeleteLast(struct node **,struct node **);
int DeleteAtPosition(struct node **,struct node **,int);

int SearchFirstOccurance(struct node *,struct node *,int);
int SearchLastOccurance(struct node *,struct node *,int);
int SearchAllOccurance(struct node *,struct node *,int);

void Display(struct node *,struct node *);
void DeleteAllNode(struct node **,struct node **);
int CountNode(struct node *,struct node *);

//
//  Function Definition
//

int main(void)
{
	struct node *pFirst = NULL;
	struct node *pLast = NULL;
	int iPos;
	int iData;
	int iCount;
	int iChoice1;
	int iChoice2;

	do
	{
		printf("___________________________________________________________\n");
		printf("\t\t\tMain Menu\t\t\t\n");
		printf("\t\t1] Insert\n");
		printf("\t\t2] Delete\n");
		printf("\t\t3] Search\n");
		printf("\t\t4] Count\n");
		printf("\t\t5] Exit\n");

		printf("\nEnter Your Choice:\t");
		scanf("%d",&iChoice1);			

		if(iChoice1 == 2 || iChoice1 == 3)
			if(pFirst == NULL)
			{
				printf("List is Empty\n\n");
				continue;
			}
		switch(iChoice1)
		{
			case 1:	printf("_____________________________________\n");
					do
					{
						printf("1] InsertFirst \n2] InsertLast\n3] InsertAtPosition\n");
						printf("4] Back\n");
						printf("\nEnter the Choice:\t");
						scanf("%d",&iChoice2);

						switch(iChoice2)
						{
						case 1: printf("_____________________________________\n");
						   	printf("Enter the data:\t");
							scanf("%d",&iData);
							InsertFirst(&pFirst,&pLast,iData);
			
								break;

						case 2: printf("_____________________________________\n");
					
							printf("Enter the data:\t");
							scanf("%d",&iData);
							InsertLast(&pFirst,&pLast,iData);
					
							break;

						case 3: printf("_____________________________________\n");
		
								printf("Enter the position:\t");
								scanf("%d",&iPos);
					
								iCount = CountNode(pFirst,pLast);
								if(iPos <= 0  || iCount + 1 < iPos)
								{
									printf("Position is Invaild\n\n");
									break;
								}
								printf("Enter the data:\t");
								scanf("%d",&iData);
					
								InsertAtPosition(&pFirst,&pLast,iPos,iData);
					
								break;
						case 4: break;
						
						default :printf("Choice is Invaild\n\n");
								break;
						}
					
					if(iChoice2 > 4)
						continue;					
					
					Display(pFirst,pLast);
					printf("\n_____________________________________\n");	
					}while(iChoice2 != 4);
					break;

			case 2:	printf("_____________________________________\n");	
					do
					{
						printf("1] Delete pFirst\n2] Delete pLast\n3] Delete At Position\n");
						printf("4] Back\n");
						printf("\nEnter the iChoice1:\t");
						scanf("%d",&iChoice2);

						switch(iChoice2)
						{

							case 1:printf("_____________________________________\n");
					
									iData = DeleteFirst(&pFirst,&pLast);
					
									printf("Your deleted Data is:\t%d\n",iData);

								
									break;

							case 2: printf("_____________________________________\n");
									
									iData = DeleteLast(&pFirst,&pLast);
				
									printf("Your deleted Data is:\t%d\n",iData);
					
									break;

							case 3: printf("_____________________________________\n");
									
									printf("Enter the position which to be deleted:\t");
									scanf("%d",&iPos);
				
									iCount = CountNode(pFirst,pLast);
									if(iPos<=0  || iCount < iPos)
									{
										printf("Position is Invaild\n\n");
										break;
									}
									iData = DeleteAtPosition(&pFirst,&pLast,iPos);
					
									printf("Your deleted Data is:\t%d\n",iData);
					
									break;
							case 4:break;
							default:printf("Choice is Invaild\n\n");
									break;
							}
						if(iChoice2 > 4)
							continue;

						Display(pFirst,pLast);
						printf("\n_____________________________________\n");
					}while(iChoice2 != 4);
						break;

			case 3:	printf("_____________________________________\n");
					do
					{
						printf("1] Serach pFirst occurance\n");
						printf("2] search pLast Occarance\n");
						printf("3] Search All Occuarance\n");
						printf("4] back\n");
						
						printf("\nEnter the iChoice1:\t");
						scanf("%d",&iChoice2);

						switch(iChoice2)
						{
						case 1:	printf("_____________________________________\n");
								
							printf("Enter the data which to be search At pFirst Occurance:\t");
							scanf("%d",&iData);
					
								iPos = SearchFirstOccurance(pFirst,pLast,iData);
		
								if(iPos == 0)
									printf("Data not found\n");
								else
									printf("Data is found at \"%d\" position.\n",iPos);
						
								break;
	
						case 2:	printf("_____________________________________\n");
							
							printf("Enter the data which to be search At pLast Occurance:\t");
							scanf("%d",&iData);
					
							iPos = SearchLastOccurance(pFirst,pLast,iData);
					
							if(iPos == 0)
								printf("Data not found\n");
							else 
							  printf("Data is found at \"%d\" position.\n",iPos);
					
							break;

						case 3:printf("_____________________________________\n");
							
							printf("Enter the data which to be search All (count)Occurance:\t");
							scanf("%d",&iData);
					
							iPos = SearchAllOccurance(pFirst,pLast,iData);
						
							printf("Total count Is:\t%d\n",iPos);
					 
							break;
					case 4:break;
					default:printf("Choice is Invaild");
						break;
						}
							
					if(iChoice2 > 4)
						continue;
					Display(pFirst,pLast);
	
						printf("\n_____________________________________\n");
					}while(iChoice2 != 4);
						break;

			
			case 4:printf("_____________________________________\n");
					Display(pFirst,pLast);
					
					printf("\n\nTotal count is:\t%d\n",CountNode(pFirst,pLast));
					
					break;

			case 5: printf("_____________________________________\n");
							
				if(pFirst == NULL)
					printf("List is Empty");
				else
					 DeleteAllNode(&pFirst,&pLast);

				 printf("\n_____________________________________\n");
					 break;

			
			default: printf("\n_____________________________________\n\n"); 
					 
					printf("Choice is Invalid\n\n");
					
					break;
		}
	}while(iChoice1 != 5);

	return 0;
}
void InsertFirst(struct node **ppHead,struct node **ppTail,int iData)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *)malloc(sizeof(struct node));	
	if(pNewNode == NULL)
	{
		printf("Memory allocation Failed");
		return ;
	}
		
	pNewNode -> iData = iData;	
		
	if(*ppHead == NULL)  // pFirst Node
	{
		*ppHead = pNewNode;
		*ppTail = pNewNode;
				
	}	
	else       // More than One Node	
	{
		pNewNode -> pNext = *ppHead;  // pFirst node address
		pNewNode -> pPrev = *ppTail;  // pLast node cha address	
		*ppHead = pNewNode;
	}	
	
	(*ppTail) -> pNext = *ppHead;
	(*ppHead) -> pPrev = *ppTail;


	pNewNode = NULL ; // sanskar  				
}
void InsertLast(struct node **ppHead,struct node **ppTail,int iData)
{
	struct node *pNewNode = NULL;
	
	pNewNode = (struct node *)malloc(sizeof(struct node));	
	if(pNewNode == NULL)
	{
		printf("Memory allocation Failed");
		return ;
	}
		
	pNewNode -> iData = iData;	
		
	if(*ppHead == NULL)  // pFirst Node
	{
		*ppHead = pNewNode;
		*ppTail = pNewNode;			
	}	
	else
	{
		pNewNode -> pPrev = *ppTail;
		(*ppTail) -> pNext = pNewNode;
		*ppTail = pNewNode;
	}
	
	(*ppTail) -> pNext = *ppHead;
	(*ppHead) -> pPrev = *ppTail;

	pNewNode = NULL;
 	
}
void InsertAtPosition(struct node **ppHead,struct node **ppTail,int iPos,int iData)
{
	struct node *pNewNode = NULL;
	struct node *pTemp = NULL;
	int iCount ;
	 
	pNewNode = (struct node *)malloc(sizeof(struct node));
	if(pNewNode == NULL)
	{
		printf("Memory allocation failed");
		return ;
	}
	pNewNode -> iData = iData;

	if(iPos == 1)
	{
		InsertFirst(ppHead,ppTail,iData);
		return ;
	}
	
	iCount = CountNode(*ppHead,*ppTail);
	if(iPos == iCount + 1)
	{
		InsertLast(ppHead,ppTail,iData);
		return ;
	}

	pTemp = *ppHead;
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
int DeleteFirst(struct node **ppHead,struct node **ppTail)
{
	int iData;

	if(*ppHead == NULL)
	{
		printf("List is Empty");
		return -1;			
	}	
	
	iData = (*ppHead) -> iData;

	if(*ppHead == *ppTail)  // only One node
	{
		(*ppHead) -> pPrev = NULL;
		(*ppHead) -> pNext = NULL;
		free(*ppHead);
		*ppHead = NULL;
		*ppTail = NULL; 	 	
	}	
	else          // More than one node 
	{
	
		*ppHead = (*ppHead) -> pNext;
		(*ppTail) -> pNext -> pNext = NULL;
		(*ppTail) -> pNext -> pPrev = NULL;
		
		free((*ppTail) -> pNext);
		(*ppHead) -> pPrev = *ppTail;
		(*ppTail) -> pNext = *ppHead;
	}
	
	return iData;
	
}
int DeleteLast(struct node **ppHead,struct node **ppTail)
{
	int iData;

	if(*ppHead == NULL)
	{
		printf("List is Empty");
		return -1;			
	}	

	if(*ppHead == *ppTail)  // only One node
	{
		iData = (*ppHead) -> iData;	
		(*ppHead) -> pPrev = NULL;
		(*ppHead) -> pNext = NULL;
		free(*ppHead);
		*ppHead = NULL;
		*ppTail = NULL; 	 	
	}	
	else
	{
		*ppTail = (*ppTail) -> pPrev;
		
		iData = (*ppHead) -> pPrev -> iData;
		(*ppHead) -> pPrev -> pNext = NULL;
	 	(*ppHead) -> pPrev -> pPrev = NULL;
		
		free((*ppHead) -> pPrev);
		
		(*ppTail) -> pNext = *ppHead;	  
		(*ppHead) -> pPrev = *ppTail;
	}

	return iData;	
	
}
int DeleteAtPosition(struct node **ppHead,struct node **ppTail,int iPos)
{
	int iDelData;
	int iCount;	
	struct node *pTemp;
	
	if(*ppHead == NULL)
	{
		printf("List is Empty\n");
		return -1;
	}
	
	if(iPos == 1)  // One node
	{
		return(DeleteFirst(ppHead,ppTail));
	}

	pTemp = *ppHead;
	iCount = 1;

	while(iCount < iPos)
	{
		iCount++;
		pTemp = pTemp -> pNext;
	}
	iDelData = pTemp -> iData;

	iCount = CountNode(*ppHead,*ppTail);

	if(iPos == iCount)
		*ppTail = pTemp -> pPrev;
	
	pTemp -> pPrev -> pNext = pTemp -> pNext;
	pTemp -> pNext -> pPrev = pTemp -> pPrev;

	pTemp -> pNext  = NULL;
	pTemp -> pPrev = NULL;
	
	free(pTemp);
	pTemp = NULL;
	return iDelData;	
		
}
int SearchFirstOccurance(struct node *pHead,struct node *pTail,int iData)
{
	int iPos = 0;
		
	if(pHead == NULL)
	{
		printf("List is Empty\n");
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
int SearchLastOccurance(struct node *pHead,struct node *pTail,int iData)
{
	int iPos = 0;
	int iRemember = 0;	
	
	if(pHead == NULL)
	{
		printf("List is Empty\n");
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
int SearchAllOccurance(struct node *pHead,struct node *pTail,int iData)
{

	int iCount = 0;	
	
	if(pHead == NULL)
	{
		printf("List is Empty\n");
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
void Display(struct node *pHead,struct node *pTail)
{	
	
	printf("\n\n-----Doubly Circular Linked List-----\n\n");
	if(pHead == NULL)
	{
		printf("List is Empty");
		return;
	}		
	do
	{
		printf(" <- |%d| -> ",pHead -> iData);
		pHead = pHead -> pNext;	
	}while(pHead != (pTail -> pNext));	
}
int CountNode(struct node *pHead,struct node *pTail)
{	
	int iCount = 0;

	if(pHead == NULL)
		return iCount;
	
	do
	{
		iCount++;
		pHead = pHead -> pNext;	
	}while(pHead != (pTail -> pNext));
	return iCount;
}
void DeleteAllNode(struct node **ppHead,struct node **ppTail)
{
					
	if(*ppHead == NULL)
	{
		printf("\nList is Empty\n");
		return ;
	}
	do
	{				
		*ppHead = (*ppHead) -> pNext;
		(*ppTail) -> pNext -> pNext = NULL;
		
		if(*ppHead == *ppTail)
		{
			(*ppTail) -> pPrev = NULL;
			free(*ppHead);
			break;
		} 

		(*ppTail) -> pNext -> pPrev = NULL;	
		free((*ppTail)  -> pNext);

		(*ppHead) -> pPrev = *ppTail;
		(*ppTail) -> pNext = *ppHead;			
	}while(*ppHead != *ppTail);
	
	*ppHead = NULL;
	*ppTail = NULL;	
	
	printf("\nDeleted ALL Node Successfully\n");	
}
