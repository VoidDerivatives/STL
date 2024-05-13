#include "server.h"

int main(void)
{
	// an int vector of 10 elements
	vector intV(10);

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
	
	for(vector :: iterator iter = intV.begin() ; iter != intV.end() ; ++iter)
		cout<<*iter<<' ';

	cout<<endl<<endl;

	vector newV(20);  // all elements are 0
	
	cout<<"newV = ";
	for(size_t i = 0 ;i < newV.Size() ; ++i)
		cout<<newV[i]<<' ';

	// swapping two vectors

	newV.swap(intV);
	
	cout<<"\nnew after swapping = ";
	for(size_t i = 0 ;i < newV.Size() ; ++i)	
		cout<<newV[i]<<' ';
 
	cout<<"\nintV after swapping = ";
	for(size_t i = 0 ;i < intV.Size() ; ++i)	
		cout<<intV[i]<<' ';  // old contents of newV

	cout<<"\n\nintV =";
	cout<<intV;
	cout<<"\nnewV =";
	cout<<newV;

	cout<<endl;


 	return 0;	
}
