#include<iostream>
using namespace std;


template<class T>

struct node
{
    T data;
    struct node *next;

};

template<class T>
class SinglyLL
{
    public :
        struct node<T> *Head;
        int Count;

        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void Display();
        int CountNode();

        
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
       

};


template<class T>
SinglyLL<T>:: SinglyLL()
{

    Head = NULL;
    Count = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)   
{
    struct node<T> *newn = NULL;    
    newn = new node<T>;         
    
    newn-> data = no;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T> *temp = Head;

    if (Head != NULL)   
    {
       Head = Head-> next;
       delete temp;
    }
    Count--;

}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn-> data = no;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;

    }
    else
    {
        struct node<T> *temp = Head;
        while (temp-> next != NULL)
        {
            temp = temp -> next;
        }
        temp-> next = newn;

    }
    Count++;
    
}


template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T>* temp = Head;

    if(Head== NULL)
    {
        return;
    }
    else if (Head -> next == NULL)
    {
        delete Head;
        Head = NULL;
        Count--;
    }
    else
    {
        while(temp -> next ->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp-> next = NULL;
        Count--;
    }
}

template<class T>
void SinglyLL<T> :: InsertAtPos(T no, int ipos)
{
    if((ipos<1)||(ipos > Count+1))
    {
        cout<<"Invalid Position.. !"<<endl;
        return;
    }


    if(ipos == 1)   //Insert at First
    {
        InsertFirst(ipos);
    }
    else if (ipos == Count+1)   // Insert at Last
    {
        InsertLast(ipos);
    }
    else            // Insert at Position
    {
        struct node <T>* newn = new node<T>;
        node<T>*temp = Head;

        newn ->data = no;
        newn->next = NULL;

        for(int i=1; i < (ipos-1); i++)
        {
            temp = temp -> next;
        }
        newn->next= temp->next;
        temp->next = newn;
    }
    Count++;
}


template<class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
	if((ipos < 1) || (ipos > Count))  //Filter
	{
		cout<<"Invalid Position";
		return;
	}
		
	if(ipos == 1)    // Delete at First
	{
		DeleteFirst();
	}
	else if(ipos == Count)  // Delete at Last
	{
		DeleteLast();
	}
	else               //Delete at Position
	{ 
		node<T>* temp = Head;
		
		for(int i=1; i < ipos-1; i++)
		{
			temp = temp->next;
		}
		
        node<T>* tempdelete = temp->next;
		
		temp->next = tempdelete->next;
		delete tempdelete;

		Count--;
	}
}

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Element from Linked list are :"<< endl;
    struct node<T> *temp = Head;
    while(temp!= NULL)
    {
        cout<<temp-> data<<"   ";
        temp = temp -> next;
    }
    cout<<endl;
}

template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

int main()
{
    
    SinglyLL <int> obj1;
    SinglyLL <float> obj2;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(51);  
    obj1.InsertLast(101);

    obj1.Display();
    cout<<"Number of Nodes are: "<<obj1.CountNode()<<endl;

    obj2.InsertFirst(21.10);
    obj2.InsertFirst(11.09);
    obj2.InsertLast(51.88);  
    obj2.InsertLast(101.81);

    obj2.Display();
    cout<<"Number of Nodes are: "<<obj2.CountNode()<<endl;

    obj2.DeleteFirst();
    obj2.Display();
    cout<<"Number of Nodes after Delete at First are: "<<obj2.CountNode()<<endl;

    obj1.DeleteLast();
    obj1.Display();
    cout<<"Number of Nodes after Delete at Last are: "<<obj1.CountNode()<<endl;

    obj1.InsertAtPos(75,3);
    obj1.Display();
    cout<<"Number of Nodes after Insert at position : "<<obj1.CountNode()<<endl;


    obj2.InsertAtPos(25.9,3);
    obj2.Display();
    cout<<"Number of Nodes after Insert at position : "<<obj2.CountNode()<<endl;


    obj1.DeleteAtPos(3);
    obj1.Display();
    cout<<"Number of Nodes after Delete at position : "<<obj1.CountNode()<<endl;

    obj2.DeleteAtPos(3);
    obj2.Display();
    cout<<"Number of Nodes after Delete at position : "<<obj2.CountNode()<<endl;



    return 0 ;
}
