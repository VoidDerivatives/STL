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
	
	void DeleteAllNode();
	
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

	// class iterator declration
	class iterator
	{
		Node *pCurrentNode;

		public :
		iterator();
		~iterator();

		void SetPCurrent(Node *);
		Node* GetPCurrent();


		// opeartor overload

		bool operator !=(iterator &);

		bool operator ==(iterator &);
	
		int operator *();

		iterator & operator ++();	 
	
		iterator operator ++(int);

		iterator & operator --();

		iterator operator --(int);

	};
	
	iterator startiter;  // object
	iterator enditer;    //objet

	iterator & Begin();
	iterator & End();
	
};
