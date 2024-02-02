#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    //Destructor
     ~Node()
    {
        int value = this->data;

        //memory free;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

    }


};

void insertHead(Node* &head,int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertTail(Node* &tail,int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void inserAnyPos(Node* &head,int pos,int data)
{

    if(pos  == 1)
    {
       insertHead(head,data);
       return ;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;

    }
    //Last e add korle
    if(temp->next == NULL)
    {
        insertTail(head,data);
        return ;
    }

    //chole asci position e node banaw

    Node* majkhane = new Node(data);

    majkhane->next = temp->next;
    temp->next = majkhane;

}

void deleteNode(Node* head,int pos)
{

    if(pos==1)
    {
        //Deleting first Node
        Node* temp = head;
        head= head->next;

        //memory free kortesi
        delete temp;

    }
    else{
            //deleting middle or last node
        Node* temp = head;
        Node* curr;
        int cnt=1;
        while(cnt<=pos)
        {
            if(cnt==pos-1)
            {
                curr = temp->next;
                break;
            }
            temp = temp->next;

            cnt++;
        }

        temp->next = curr->next;
        curr->next = NULL;

        //calling destructor for memory free
        delete curr;
    }
}

void print(Node* &head)
{
    Node* temp =head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* node1 = new Node(10);
cout<<node1->data<<endl;
    Node* head = node1;

   // insertHead(head,15);

    //print(head);

    Node* tail = node1;
    insertTail(tail,20);
    print(head);

    cout<<endl;

   // cout<<"Why"<<endl;

     insertTail(tail,30);
    print(head);
       cout<<endl;
     insertTail(tail,40);
    print(head);

    cout<<endl;

    inserAnyPos(head,3,25);
    print(head);
    cout<<endl;

    deleteNode(head,4);
       print(head);








}
