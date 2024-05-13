#include<iostream>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: ostream;
#include "server.h"

template <typename T>
void DisplayIterator(List<T> &);

template <typename T>
int MyMain(T)
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
					
								tData = obj.DeleteFirst();
								
								cout<<endl<<"Your deleted Data is:\t"<<tData<<endl;

								
									break;

							case 2: cout<<"_____________________________________"<<endl;
									
									tData = obj.DeleteLast();
				
									cout<<endl<<"Your deleted Data is:\t"<<tData<<endl;
					
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
									tData = obj.DeleteAtPosition(iPos);
					
									cout<<endl<<"Your deleted Data is:\t"<<tData<<endl;
					
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
							cin>>tData;
					
								iPos = obj.SearchFirstOccurance(tData);
		
								if(iPos == 0)
									cout<<"Data not found"<<endl;
								else
									cout<<"Data is found at "<<iPos<<" position."<<endl;
						
								break;
	
						case 2:	cout<<"_____________________________________"<<endl;
							
							cout<<"Enter the data which to be search At pLast Occurance:\t";
							cin>>tData;
					
							iPos = obj.SearchLastOccurance(tData);
					
							if(iPos == 0)
								cout<<"Data not found"<<endl;
							else 
							  cout<<"Data is found at "<<iPos<<" position."<<endl;
					
							break;

						case 3:cout<<"_____________________________________"<<endl;
							
							cout<<"Enter the data which to be search All (count)Occurance:\t";
							cin>>tData;
					
							iPos = obj.SearchAllOccurance(tData);
						
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

template <typename T>
void DisplayIterator(List<T> &list)
{
	cout<<"\n Iterator display start ;Linked List is :"<<endl;
	
	if(list.IsEmpty())
	{
		cout<<"List is Empty"<<endl<<endl;
		return ;
	}
	for(typename List<T> :: iterator iter = list.Begin();iter != list.End();++iter)
		cout<<" <-|"<<*iter<<"|-> ";

	cout<<endl;		
	
}

int main(void)
{
	int iChoice;

	do
	{
		cout<<endl<<"Which type of LinkedList You Want to Create :"<<endl;
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

