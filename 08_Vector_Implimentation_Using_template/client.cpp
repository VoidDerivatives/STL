#include "server.h"
using std :: cin;
template<typename T>
void MyMain(T);

int main(void)
{
	int iChoice;

	do
	{
		cout<<endl<<"Which type of Arrya You Want to Create :"<<endl;
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

template <typename T>
void MyMain(T)
{
	// an int vector of 10 elements
	vector<T> intV(10);

	for(size_t i = 0 ;i < intV.Size() ; ++i)
		intV[i] = i;   // Fill vector ,random access

	// vector increase demand
	intV.insert(intV.end(),100);
	// append the number 100
	// use as array

	for(size_t i = 0 ; i < intV.Size() ; ++i)
		cout<<intV[i]<<' ';
	
	cout<<endl<<endl;
	
	// use with an iteraor
	
	for(typename vector<T> :: iterator iter = intV.begin() ; iter != intV.end() ; ++iter)
		cout<<*iter<<' ';

	cout<<endl<<endl;

	vector<T> newV(20);  // all elements are 0
	
	cout<<"newV = ";
	for(size_t i = 0 ;i < newV.Size() ; ++i)
		cout<<newV[i]<<' ';

	// swapping two vectors

	newV.swap(intV);
	
	cout<<"\nnewV after swapping = ";
	//for(size_t i = 0 ;i < newV.Size() ; ++i)	
	//	cout<<newV[i]<<' ';
	for(typename vector<T> :: iterator iter = newV.begin() ; iter != newV.end() ; ++iter)
		cout<<*iter<<' '; 


	cout<<"\nintV after swapping = ";
	//for(size_t i = 0 ;i < intV.Size() ; ++i)	
	//	cout<<intV[i]<<' ';  // old contents of newV
	for(typename vector<T> :: iterator iter = intV.begin() ; iter != intV.end() ; ++iter)
		cout<<*iter<<' ';

	cout<<"\n\nintV =";
	cout<<intV;
	cout<<"\nnewV =";
	cout<<newV;

	cout<<endl;
	
}
