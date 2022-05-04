#include <iostream>

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

void InsertAtTail(Node* &tail,Node* curr){

    tail->next=curr;
//    tail=tail->next;
    tail=curr;
}
Node* sortList(Node *head){
// 	Dummy pointers for  to escape from if-Conditions
    Node* zeroHead=new Node(-1);
	Node* zeroTail=zeroHead;
    Node* oneHead =new Node(-1);
	Node* oneTail=oneHead;
	Node* twoHead =new Node(-1);
	Node* twoTail=twoHead;
// 	created Seprated lists for 0s,1s,2s
	Node* curr=head;
	while(curr!=NULL){
		int value=curr->data;
		if(value==0){
			InsertAtTail(zeroTail,curr);
		}else if(value==1){
			InsertAtTail(oneTail,curr);
		}else if(value==2){
			InsertAtTail(twoTail,curr);
		}
		curr=curr->next;
	}
// 	merge all 3 linked lists
	if(oneHead->next!=NULL){//1's list non empty
		zeroTail->next=oneHead->next;
	}else{// 1's list is empty
		zeroTail->next=twoHead->next;
	}
	oneTail->next=twoHead->next;
	twoTail->next=NULL;
// 	placing head at riht place
	 head=zeroHead->next;
	return head;
// 	deleting all dummy head nodes
	delete zeroHead;
	delete oneHead;
	delete twoHead;
	return head;
}


int main() {

    return 0;
}
