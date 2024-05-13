#include<iostream>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: ostream;
#include "server.h"

void DisplayIterator(List &);
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
					
					cout<<obj<<endl;  // opeartor overloading
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

				
					DisplayIterator(obj);	 // DisplayIterator
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
					obj.Display();  // Display function
	
					cout<<endl<<"_____________________________________"<<endl;
					}while(iChoice2 != 4);
						break;

			
			case 4:cout<<"_____________________________________"<<endl;
			DisplayIterator(obj);
					
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

void DisplayIterator(List &list)
{
	cout<<"\n Iterator display start ;Linked List is :"<<endl;
	
	if(list.IsEmpty())
	{
		cout<<"List is Empty"<<endl<<endl;
		return ;
	}
	for(List :: iterator iter = list.Begin();iter != list.End();++iter)
		cout<<" <-|"<<*iter<<"|-> ";

	cout<<endl;		
	
}
