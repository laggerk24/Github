#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node *prev;
  Node(int num){
    this->data = num;
    this->next = NULL;
    this->prev = NULL;
  }
};
 
void print(Node* &head){
  Node *temp = head;
  if(temp==NULL){
    cout<<"No value in Linked List"<<endl;
  }
  else if(temp->next == NULL){
    cout<<temp->data<<" ";
  }
  else{
    while(temp->next != NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<temp->data<<" ";
  }
  cout<<endl;
}

void insertIntoHead(Node* &head,Node* &tail ,int num){
  Node *nodeToInsert = new Node(num);
  if(head==NULL && tail==NULL){
    head = nodeToInsert;
    tail = nodeToInsert;
  }
  else{
    nodeToInsert->next = head;
    head->prev = nodeToInsert;
    head = nodeToInsert;
  }
}

void insertIntoTail(Node* &head, Node* &tail, int num){
  Node *nodeToInsert = new Node(num);
  if(head==NULL && tail==NULL){
    head = nodeToInsert;
    tail = nodeToInsert;
  }
  else{
    nodeToInsert->prev = tail;
    tail->next = nodeToInsert;
    tail = nodeToInsert;
  }
}

void insertIntoPosition(Node* &head, Node* &tail, int num, int position){
  Node *nodeToInsert = new Node(num);
  if(position == 1)
    insertIntoHead(head,tail,num);
  else{
    int cnt = 1;
    Node* temp = head;
    while(cnt < position-1){
      temp = temp->next;
      cnt++;
    }
    if(temp->next == NULL)
    {
      insertIntoTail(head,tail,num);
      return;
    }
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next = nodeToInsert; 
  }
}

void deleteFromPosition(Node* &head,Node* &tail, int position){
  Node *current = head;
  Node *previous = NULL;
  if(current == NULL){
    cout<<"No Node to delete"<<endl;
    return;
  }

  int cnt = 1;
  while(cnt<position){
    previous = current;
    current = current->next;
    cnt++;
  }
  if(previous == NULL && current->next == NULL){
    delete current;
    head = NULL;
    tail = NULL;
  }
  else if(previous == NULL){
    head = current->next;
    current->next = NULL;
    delete current;
  }
  else if(current->next == NULL){
    previous->next = NULL;
    current->prev = NULL;
    tail = previous;
    delete current;
  }
  else{
    previous->next = current->next;
    current->next->prev = previous;
    current->next = NULL;
    current->prev = NULL;
    delete current;
  }
}
 
int main(){
  Node *node1 = new Node(5);
  // Node *node1 = NULL;
  Node *head = node1;
  Node *tail = node1;
  insertIntoHead(head,tail,4);
  insertIntoTail(head,tail,6);
  insertIntoPosition(head,tail,7,3);
  insertIntoPosition(head,tail,10,2);
  print(head);
  cout<<"head-"<<head->data<<" "<<"tail-"<<tail->data<<endl;
  deleteFromPosition(head,tail,5);
  // cout<<endl;
  print(head);
  cout<<"head-"<<head->data<<" "<<"tail-"<<tail->data<<endl;
}
 