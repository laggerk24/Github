#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int num){
      this->data = num;
      this->next = NULL;
    }    
};

void print(Node* &head){
  Node *temp = head;
  if(temp == NULL){
    cout<<"No data in the head";
    cout<<endl;
  }
  if(temp->next == NULL){
    cout<<temp->data<<" ";
  }
  else{
    while(temp->next != NULL){     //to check how babbar has implemented the print method
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<temp->data;
    cout<<endl;
  }
}

void insertIntoHead(Node* &head,Node* &tail,int num){

  Node *nodeToInsert = new Node(num);
  if(head == NULL){
    head = nodeToInsert;
    tail = nodeToInsert;
  }
  else{
    nodeToInsert->next = head;
    head = nodeToInsert;
  }
}

void insertIntoTail(Node* &head,Node* &tail, int num){
  Node *nodeToInsert = new Node(num);
  if(head ==NULL){
    head = nodeToInsert;
    tail = nodeToInsert;
  }
  else{
    tail->next = nodeToInsert;
    tail = nodeToInsert;
  }
}

void insertIntoLL(Node* &head, Node* &tail, int position, int num){
  Node *temp = head;
  if(position == 1){
    insertIntoHead(head,tail,num);
    return;
  }
  else{
    int cnt = 1;
    while(cnt<(position-1)){
      temp = temp->next;
      cnt++;
    }
    if(temp->next == NULL){
      insertIntoTail(head,tail,num);
      return;
    }
    Node *nodeToInsert = new Node(num);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
  }
}

void DeleteNode(Node* &head,Node* &tail,int position){
  Node *prev = NULL;
  Node *curr = head;
  int cnt = 1;
  while(cnt<position){
    prev = curr;
    curr = curr->next;
    cnt++;
  }
  if(prev == NULL){
    if(curr->next == NULL){
      delete head;
      head = NULL;
    }
    else{
      head = head->next;
      curr->next = NULL;
      delete curr;
    } 
  }
  else{
    if(curr->next == NULL){
      tail = prev;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}

int main(){
  Node *node1 = new Node(5);
  Node *head = node1;
  Node *tail = node1;

  // Node *head = NULL;
  // Node *tail = NULL;

  insertIntoHead(head,tail,10);
  insertIntoHead(head,tail,2);
  // cout<<head->data<<endl;
  insertIntoTail(head,tail,15);
  insertIntoLL(head,tail,5,24);
  print(head);
  cout<<"Head-"<<head->data<<" Tail-"<<tail->data<<endl;
  DeleteNode(head,tail,5);
  print(head);
  cout<<"Head-"<<head->data<<" Tail-"<<tail->data<<endl;

}
