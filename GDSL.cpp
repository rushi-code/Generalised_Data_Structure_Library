
#include<iostream>
using namespace std;


template<class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

template<class T>
struct NodeD  
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

template<class T>
class SinglyLL
{
    public:
        struct NodeS<T> *first;
        int iCount;

        SinglyLL();

        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurence(T);
        int SearchLastOccurence(T);

        T Maximum();
        T Minimum();

        T Summation();
        float Average();

        int Frequency(T);

};

template<class T>
SinglyLL <T>:: SinglyLL()
{
    first = NULL;
    iCount  = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked List are : \n";

    NodeS<T> *temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int SinglyLL <T>:: Count()
{
    return iCount;
}

template<class T>
void SinglyLL <T>:: InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;

        first = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL <T>:: InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template<class T>
void SinglyLL <T>:: InsertAtPos(T no, int iPos)
{
    if((iPos<1) || (iPos> iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount +1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *newn = new NodeS<T>;
        NodeS<T> *temp = first;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyLL <T>:: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else 
    {
        NodeS<T> *temp = first;

        first = first ->next;
        delete temp;
    }
    iCount--;
}

template<class T>
void SinglyLL <T>:: DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else 
    {
        NodeS<T> *temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void SinglyLL <T>:: DeleteAtPos(int iPos)
{
    if((iPos<1) || (iPos> iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {   
        NodeS<T> *temp = first;
        NodeS<T> *tempX = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;

        temp->next = temp->next->next;

        delete tempX;

        iCount--;
    }
}

template<class T>
int SinglyLL <T> :: SearchFirstOccurence(T no)
{
    int iCnt = 0;
    int iIndex = -1;

    NodeS<T> *temp = first;

    for(iCnt = 0; temp != NULL; iCnt++)
    {
        if((temp->data) == no)
        {
            iIndex = iCnt;
            break;
        }
        temp = temp->next;
    }
    if(iIndex == -1)
    {
        std::cout << "No such element is present\n" << std::flush;
    }
    return iIndex;
}

template<class T>
int SinglyLL <T> :: SearchLastOccurence(T no)
{
    int iCnt = 0;
    int iIndex = -1;

    NodeS<T> *temp = first;

    for(iCnt = 0; temp != NULL; iCnt++)
    {
        if((temp->data) == no)
        {
            iIndex = iCnt;
        }
        temp = temp->next;
    }
    if(iIndex == -1)
    {
        std::cout << "No such element is present\n" << std::flush;
    }
    return iIndex;
}

template<class T>
T SinglyLL <T>:: Maximum()
{
    NodeS<T> *temp = first;

    T max = temp->data;

    while(temp != NULL)
    {
        if(temp->data> max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

template<class T>
T SinglyLL <T>:: Minimum()
{
    NodeS<T> *temp = first;

    T min = temp->data;

    while(temp != NULL)
    {
        if(temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

template<class T>
T SinglyLL <T>:: Summation()
{
    NodeS<T> *temp = first;

    T sum = T();

    while(temp != NULL)
    {
        sum = sum + temp->data;
        temp = temp->next;
    }
    return sum;
}

template<class T>
float SinglyLL <T>:: Average()
{
    return static_cast<float>(Summation()) / Count();
}

template<class T>
int SinglyLL <T>:: Frequency(T no)
{
    NodeS<T> *temp = first;
    int iFreq = 0;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iFreq++;
        }
        temp = temp->next;
    }
    return iFreq;
}

template<class T>
class SinglyCL
{
    public:
        struct NodeS<T> *first;
        struct NodeS<T> * last;
        int iCount;

        SinglyCL();

        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurence(T);
        int SearchLastOccurence(T);

        T Maximum();
        T Minimum();

        T Summation();
        float Average();

        int Frequency(T);
};

template<class T>
SinglyCL <T>:: SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount  = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    NodeS<T> *temp = first;

    if(first != NULL && last != NULL)
    {
        cout<<"Elements of Singly Circular Linked List are : \n";
        do
        {
            cout<<"| "<<temp->data<<" | -> ";
            temp = temp->next;
        }while(temp != last->next);

        cout<<"\n";
    }

    else
    {
        cout<<"Linked list is empty\n";
    }
}

template<class T>
int SinglyCL <T>:: Count()
{
    return iCount;
}

template<class T>
void SinglyCL <T>:: InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;

        first = newn;
    }
    last ->next = first;
    iCount++;
}

template<class T>
void SinglyCL <T>:: InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = last->next;
    }
    last ->next = first;
    iCount++;
}

template<class T>
void SinglyCL <T>:: InsertAtPos(T no, int iPos)
{
    if((iPos<1) || (iPos> iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount +1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *newn = new NodeS<T>;
        NodeS<T> *temp = first;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyCL <T>:: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        NodeS<T> *temp = first;

        first = first ->next;
        delete temp;
        last ->next = first;
    }
    
    iCount--;
}

template<class T>
void SinglyCL <T>:: DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        NodeS<T> *temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last ->next = first;
    }

    iCount--;
}

template<class T>
void SinglyCL <T>:: DeleteAtPos(int iPos)
{
    if((iPos<1) || (iPos> iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {   
        NodeS<T> *temp = first;
        NodeS<T> *tempX = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;

        temp->next = temp->next->next;

        delete tempX;

        iCount--;
    }
}

template<class T>
int SinglyCL <T> :: SearchFirstOccurence(T no)
{
    int iCnt = 0;
    int iIndex = -1;

    NodeS<T> *temp = first;

    if(first != NULL && last != NULL)
    {
        do
        {
            if((temp->data) == no)
            {
                iIndex = iCnt;
                break;
            }
            temp = temp->next;
            iCnt++;
        }while(temp != first);
    }
    
    if(iIndex == -1)
    {
        std::cout << "No such element is present\n" << std::flush;
    }
    return iIndex;

}

template<class T>
int SinglyCL <T> :: SearchLastOccurence(T no)
{
    int iCnt = 0;
    int iIndex = -1;

    NodeS<T> *temp = first;

    if(first != NULL && last != NULL)
    {
        do
        {
            if((temp->data) == no)
            {
                iIndex = iCnt;
            }
            temp = temp->next;
            iCnt++;
        }while(temp != first);
    }
    
    if(iIndex == -1)
    {
        std::cout << "No such element is present\n" << std::flush;
    }
    return iIndex;

}

template<class T>
T SinglyCL <T>:: Maximum()
{
    NodeS<T> *temp = first;

    T max = temp->data;

    if(first != NULL && last != NULL)
    {
        do
        {
            if(temp->data > max)
            {
                max = temp->data;
            }
            temp = temp->next;

        }while(temp != first);
    }
    return max;
}

template<class T>
T SinglyCL <T>:: Minimum()
{
    NodeS<T> *temp = first;

    T min = temp->data;

    if(first != NULL && last != NULL)
    {
        do
        {
            if(temp->data < min)
            {
                min = temp->data;
            }
            temp = temp->next;

        }while(temp != first);
    }
    return min;
}

template<class T>
T SinglyCL <T>:: Summation()
{
    NodeS<T> *temp = first;

    T sum = T();

    if(first != NULL && last != NULL)
    {
        do
        {
            sum = sum + temp->data;
            temp = temp->next;

        }while(temp  != first);
    }
    return sum;
}

template<class T>
float SinglyCL <T>:: Average()
{
    return static_cast<float>(Summation()) / Count();
}

template<class T>
int SinglyCL <T>:: Frequency(T no)
{
    NodeS<T> *temp = first;
    int iFreq = 0;


    if(first != NULL &&  last != NULL)
    {
        do
        {
            if(temp->data == no)
            {
                iFreq++;
            }
            temp =temp->next;
        }while( temp != first);
    }
    return iFreq;
        
}

template<class T>
class DoublyLL
{
    public:
        struct NodeD<T> *first;
        int iCount;

        DoublyLL();

        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurence(T);
        int SearchLastOccurence(T);

        T Maximum();
        T Minimum();

        T Summation();
        float Average();

        int Frequency(T);
};

template<class T>
DoublyLL <T>:: DoublyLL()
{
    first = NULL;
    iCount  = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements of Doubly Linear Linked List are : \n";

    NodeD<T> *temp = first;

    cout<<"NULL <=> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLL <T>:: Count()
{
    return iCount;
}

template<class T>
void DoublyLL <T>:: InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;

        first = newn;
    }
    iCount++;
}

template<class T>
void DoublyLL <T>:: InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeD<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
    iCount++;
}

template<class T>
void DoublyLL <T>:: InsertAtPos(T no, int iPos)
{
    if((iPos<1) || (iPos> iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount +1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *newn = new NodeD<T>;
        NodeD<T> *temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template<class T>
void DoublyLL <T>:: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else 
    {
        first = first ->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL <T>:: DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else 
    {
        NodeD<T> *temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL <T>:: DeleteAtPos(int iPos)
{
    if((iPos<1) || (iPos> iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {   
        NodeD<T> *temp = first;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

template<class T>
int DoublyLL <T> :: SearchFirstOccurence(T no)
{
    int iCnt = 0;
    int iIndex = -1;

    NodeD<T> *temp = first;

    for(iCnt = 0; temp != NULL; iCnt++)
    {
        if((temp->data) == no)
        {
            iIndex = iCnt;
            break;
        }
        temp = temp->next;
    }
    if(iIndex == -1)
    {
        std::cout << "No such element is present\n" << std::flush;
    }
    return iIndex;

}

template<class T>
int DoublyLL <T> :: SearchLastOccurence(T no)
{
    int iCnt = 0;
    int iIndex = -1;

    NodeD<T> *temp = first;

    for(iCnt = 0; temp != NULL; iCnt++)
    {
        if((temp->data) == no)
        {
            iIndex = iCnt;
        }
        temp = temp->next;
    }
    if(iIndex == -1)
    {
        std::cout << "No such element is present\n" << std::flush;
    }
    return iIndex;

}

template<class T>
T DoublyLL <T>:: Maximum()
{
    NodeD<T> *temp = first;

    T max = temp->data;

    while(temp != NULL)
    {
        if(temp->data> max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

template<class T>
T DoublyLL <T>:: Minimum()
{
    NodeD<T> *temp = first;

    T min = temp->data;

    while(temp != NULL)
    {
        if(temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

template<class T>
T DoublyLL <T>:: Summation()
{
    NodeD<T> *temp = first;

    T sum = T();

    while(temp != NULL)
    {
        sum = sum + temp->data;
        temp = temp->next;
    }
    return sum;
}

template<class T>
float DoublyLL <T>:: Average()
{
    return static_cast<float>(Summation()) / Count();
}

template<class T>
int DoublyLL <T>:: Frequency(T no)
{
    NodeD<T> *temp = first;
    int iFreq = 0;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iFreq++;
        }
        temp = temp->next;
    }
    return iFreq;
}

template<class T>
class DoublyCL
{
    public:
        struct NodeD<T> *first;
        struct NodeD<T> * last;
        int iCount;

        DoublyCL();

        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurence(T);
        int SearchLastOccurence(T);

        T Maximum();
        T Minimum();

        T Summation();
        float Average();

        int Frequency(T);
};

template<class T>
DoublyCL <T>:: DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount  = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeD<T> *temp = first;

    if(first != NULL && last != NULL)
    {
        cout<<"Elements of Doubly Circular Linked List are : \n";
        cout<<" <=> ";
        do
        {
            cout<<"| "<<temp->data<<" | <=> ";
            temp = temp->next;
        }while(temp != last->next);

        cout<<"\n";
    }

    else
    {
        cout<<"Linked list is empty\n";
    }
}

template<class T>
int DoublyCL <T>:: Count()
{
    return iCount;
}

template<class T>
void DoublyCL <T>:: InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    }
    last ->next = first;
    first->prev = last;
    iCount++;
}

template<class T>
void DoublyCL <T>:: InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;

        last = last->next;

    }
    last ->next = first;
    first->prev = last;

    iCount++;
}

template<class T>
void DoublyCL <T>:: InsertAtPos(T no, int iPos)
{
    if((iPos<1) || (iPos> iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount +1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *newn = new NodeD<T>;
        NodeD<T> *temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template<class T>
void DoublyCL <T>:: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        NodeD<T> *temp = first;

        first = first ->next;
        delete last->next;

        last ->next = first;
        first->prev = last;
    }
    
    iCount--;
}

template<class T>
void DoublyCL <T>:: DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        last = last->prev;
        delete(last->next);

        last ->next = first;
        first->prev = last;
    }

    iCount--;
}

template<class T>
void DoublyCL <T>:: DeleteAtPos(int iPos)
{
    if((iPos<1) || (iPos> iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {   
        NodeD<T> *temp = first;
        NodeD<T> *tempX = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;

        temp->next = temp->next->next;

        delete tempX;

        iCount--;
    }
}

template<class T>
int DoublyCL <T> :: SearchFirstOccurence(T no)
{
    int iCnt = 0;
    int iIndex = -1;

    NodeD<T> *temp = first;

    if(first != NULL && last != NULL)
    {
        do
        {
            if((temp->data) == no)
            {
                iIndex = iCnt;
                break;
            }
            temp = temp->next;
            iCnt++;
        }while(temp != first);
    }
    
    if(iIndex == -1)
    {
        std::cout << "No such element is present\n" << std::flush;
    }
    return iIndex;

}

template<class T>
int DoublyCL <T> :: SearchLastOccurence(T no)
{
    int iCnt = 0;
    int iIndex = -1;

    NodeD<T> *temp = first;

    if(first != NULL && last != NULL)
    {
        do
        {
            if((temp->data) == no)
            {
                iIndex = iCnt;
                break;
            }
            temp = temp->prev;
            iCnt++;
        }while(temp != first);
    }
    
    if(iIndex == -1)
    {
        std::cout << "No such element is present\n" << std::flush;
    }
    return (Count()- iIndex);

}

template<class T>
T DoublyCL <T>:: Maximum()
{
    NodeD<T> *temp = first;

    T max = temp->data;

    if(first != NULL && last != NULL)
    {
        do
        {
            if(temp->data > max)
            {
                max = temp->data;
            }
            temp = temp->next;

        }while(temp != first);
    }
    return max;
}

template<class T>
T DoublyCL <T>:: Minimum()
{
    NodeD<T> *temp = first;

    T min = temp->data;

    if(first != NULL && last != NULL)
    {
        do
        {
            if(temp->data < min)
            {
                min = temp->data;
            }
            temp = temp->next;

        }while(temp != first);
    }
    return min;
}

template<class T>
T DoublyCL <T>:: Summation()
{
    NodeD<T> *temp = first;

    T sum = T();

    if(first != NULL && last != NULL)
    {
        do
        {
            sum = sum + temp->data;
            temp = temp->next;

        }while(temp != first);
    }
    return sum;
}

template<class T>
float DoublyCL <T>:: Average()
{
    return static_cast<float>(Summation()) / Count();
}

template<class T>
int DoublyCL <T> :: Frequency(T no)
{
    NodeD<T> *temp = first;
    int iFreq = 0;

    if((first!= NULL) && (last != NULL))
    {
        do
        {
            if(temp->data == no)
            {
                iFreq++;
            }
            temp = temp->next;
        }while(temp != first);
    }
    return iFreq;
}


template<class T>
class Stack
{
    public:
        NodeS<T> * first = NULL;
        int iCount;

        Stack();
        void Push(T);
        T Pop();
        void Display();
        int Count();
};

template<class T>
Stack<T>:: Stack()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void Stack <T> :: Push(T no)    //InsertLast
{
    NodeS<T> *newn = new NodeS<T>;  

    newn->data = no;
    newn->next = NULL;

    NodeS<T> *temp = first;

    if(first == NULL)
    {
        first = newn;
    }  
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template<class T>
T Stack <T> :: Pop()    //DeleteLast
{
    T value = 0;

    NodeS<T> * temp = first;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
    }
    else if(iCount == 1)
    {
        value = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
    return value;
}

template<class T>
void Stack<T> :: Display()
{
    NodeS<T> *temp = first;
    cout<<"Elements of Stack are : \n";

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
    cout<<"\n";
     
}

template<class T>
int Stack<T> :: Count()
{
    return iCount;
}

template<class T>
class Queue
{
    public:
        NodeS<T> * first = NULL;
        int iCount;

        Queue();
        void Enqueue(T);
        T Dequeue();
        void Display();
        int Count();
};

template<class T>
Queue<T>:: Queue()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void Queue <T> :: Enqueue(T no)    //InsertLast
{
    NodeS<T> *newn = new NodeS<T>;  

    newn->data = no;
    newn->next = NULL;

    NodeS<T> *temp = first;

    if(first == NULL)
    {
        first = newn;
    }  
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template<class T>
T Queue <T> :: Dequeue()    //DeleteFirst
{
    T value = 0;

    NodeS<T> * temp = first;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
    }
    else if(iCount == 1)
    {
        value = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        value = first->data;

        first = first->next;
        delete temp;
    }
    iCount--;
    return value;
}

template<class T>
void Queue<T> :: Display()
{
    NodeS<T> *temp = first;
    cout<<"Elements of Stack are : \n";

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
    cout<<"\n";
     
}

template<class T>
int Queue<T> :: Count()
{
    return iCount;
}

template<class T>
struct NodeT
{
    T data;
    struct NodeT<T>* lchild;
    struct NodeT<T>* rchild;
};

template<class T>
class BinarySearchTree
{
    public:
        NodeT<T> * root;
        NodeT<T> *temp;
        int iCnt;

        BinarySearchTree();
        void Insert(T );
        bool Search(T);
        int Count();
        int CountParentnode(NodeT<T> *);
        int CountLeafnode(NodeT<T> *);
        void InOrder(NodeT<T> *);
        void PreOrder(NodeT<T> *);
        void PostOrder(NodeT<T> *);

};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
    temp = NULL;
    iCnt = 0;
}

template <class T>
void BinarySearchTree<T>:: Insert(T no)
{
    NodeT<T> *temp = root;

    NodeT<T> * newn = new NodeT<T>;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(root == NULL)
    {
        root = newn;
        this->temp = root;
        iCnt++;
    }
    else 
    {
        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate Element : Unable to insert\n";
                delete newn;
                break;
            }
            else if(no> temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    iCnt++;
                    break;
                }
                temp = temp->rchild;
            }

            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    iCnt++;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

template <class T>
bool BinarySearchTree<T>:: Search(T no)
{
    bool bFlag = false;
    NodeT<T> *temp = root;

    if(root == NULL)
    {
        cout<<"Tree is empty\n";
        return bFlag;
    }

    while(temp!= NULL)
    {
        if(no == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }
    }
    return bFlag;
}

template <class T>
int BinarySearchTree<T>:: Count()
{
    return iCnt;
}

template <class T>
int BinarySearchTree<T>:: CountParentnode(NodeT<T> * temp)
{
    static int i = 0;

    if(temp!= NULL)
    {
        if ((temp->lchild != NULL) || (temp->rchild != NULL))
        {
            i++;
        }
        CountParentnode(temp->lchild);
        CountParentnode(temp->rchild);
    
    }
    return i;
}

template <class T>
int BinarySearchTree<T>:: CountLeafnode(NodeT<T> * temp)
{
    static int i = 0;

    if(temp!= NULL)
    {
        if ((temp->lchild == NULL) && (temp->rchild == NULL))
        {
            i++;
        }
        CountLeafnode(temp->lchild);
        CountLeafnode(temp->rchild);
    
    }
    return i;
}

template <class T>
void BinarySearchTree<T>:: InOrder(NodeT<T> * temp)
{
    if(temp!= NULL)
    {
        InOrder(temp->lchild);
        cout<<temp->data<<"\t";
        InOrder(temp->rchild);
    }
}

template <class T>
void BinarySearchTree<T>:: PreOrder(NodeT<T> * temp)
{
    if(temp!= NULL)
    {
        cout<<temp->data<<"\t";
        PreOrder(temp->lchild);
        PreOrder(temp->rchild);
    }
}

template <class T>
void BinarySearchTree<T>:: PostOrder(NodeT<T> * temp)
{
    if(temp!= NULL)
    {

        PreOrder(temp->lchild);
        PreOrder(temp->rchild);
        cout<<temp->data<<"\t";
    }
    
}

int main()
{
    return 0;
}
