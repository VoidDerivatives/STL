#include"server.h"
template<typename T>
void MyMain(T);

template <typename T>
void PrintLists(List<T> &l1,List<T> &l2)
{
	cout<<"List1 :";
	
	for(typename List<T> :: iterator iter = l1.Begin();iter != l1.End();++iter)
		cout<<*iter<<" ";
		
	cout<<endl<<"List2 :";
	
	for(typename List<T> :: iterator iter = l2.Begin();iter != l2.End();++iter)
		cout<<*iter<<" ";

	cout<<endl<<endl;
}
int main()
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
			case 1:MyMain(69);
				break;
			case 2:MyMain('E');
				break;
			case 3:MyMain(69.00f);
				break;
			case 4:MyMain(69.00);
				break;
			case 5:break;

			default : cout<<"Your Choice is Wrong"; 
		}
	}while(iChoice != 5);	

	return 0;
}

template<typename T>
void MyMain(T tNo)
{
	List<T> list1,list2;
	
	for(int i = 0 ; i < 6 ; i++)
	{
		list1.push_back(i+65);
		list2.push_front(i+65);
	}

	PrintLists(list1,list2);

	//insert a;; element pf list1 before the first element with value E of list2
	// find() - returns as iterator to the first element with value E

	list2.splice( find(list2.Begin() , list2.End() ,tNo) ,list1);

	PrintLists(list1,list2);

	//move first element of list2 to the end

	list2.splice(list2.End(),list2,list2.Begin());

	PrintLists(list1,list2);

	// sort second list , assgin to list1 and remove duplicates 
	list2.Sort(); 
	PrintLists(list1,list2);
	list1 = list2;
	PrintLists(list1,list2);
	list2.unique();

	PrintLists(list1,list2);

	// merge both sorted lists into the first list

	list1.merge(list2);

	PrintLists(list1,list2);	
}
