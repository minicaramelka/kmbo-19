#include "llist.h"

using namespace std;

LList::LList(){
        head = NULL;
}

LList::LList(const LList& copyLList) { 
	this->head = nullptr; 
	Node* currentNode = copyLList.head; 
	while(currentNode) { 
		this->push_back(currentNode->data); 
		currentNode = currentNode->next; 
	} 
}


LList::~LList(){
	while (head) {
		pop_front();
	}
}

int LList::operator[](size_t idx) const{
	Node* bufNode = head;
	for (int i = 0; i < idx; ++i){
    	bufNode = bufNode->next;
	}
	return bufNode->data;
}

int& LList::operator[](size_t idx){
	Node* bufNode = head;
	for (int i = 0; i < idx; ++i){
		bufNode = bufNode->next;
	}
	return bufNode->data;
}

void LList::push_back(int val){
        Node *nd = new Node;
        nd->data = val;
        nd->next = NULL;
        if(head == NULL){
            head = nd;
	}
        else{
            Node *current = head;
            while(current->next != NULL){
                current = current->next;
	    }
            current->next = nd;
        }
}

void LList::push_front(int val){
    Node *nd = new Node;
    if(head){
    	Node *tmp = head;
        head = nd;
        nd->next = tmp;
        nd->data = val;
    }
    else{
	head = nd;
        nd->next = NULL;
        nd->data = val;
        }
    }

void LList::pop_back(){
    if(head){
        Node *tmp = head;
        Node *nd = head;
        while(tmp->next!=NULL){
       		nd = tmp;
		tmp = tmp->next;

        }
        nd->next = NULL;
        delete tmp;
    }
}

void LList::pop_front(){
    if(head){
        Node *tmp = head;
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
    else
        cout << "The list is empty!" << endl;
}

size_t LList::size() const{
    int counter=0;
    Node *nd = head;
    while(nd){
        nd = nd->next;
    	counter++;
    }
	return counter;
}

void LList::erase_at(size_t idx){
	if(head){
    	    if(idx!=0){
            	int counter = 0;
            	Node *tmp = head;
            	while(counter<=idx){
                    tmp = tmp->next;
                    counter++;
            	}
            	counter=0;
            	Node *nd = head;
            	while(counter<idx-1){
                    nd = nd->next;
                    counter++;
            	}
            	nd->next = tmp;
            }
	    else{
                Node *tmp = head;
                tmp = tmp->next;
                delete head;
                head = tmp;
            }
        }
        else{
    	cout<<"The list is empty!" << endl;
        }
}

void LList::insert_at(size_t idx, int val){
	Node *tmp = head;
	int k = 0;
	while(tmp){
    	    tmp = tmp->next;
            k++;
        }
    	if(idx==0){
    	    Node *nd = new Node;
            if(head){
        	Node *current = head;
                head = nd;
                nd->next = current;
                nd->data = val;
            }
            else{
        	head = nd;
        	nd->next = NULL;
        	nd->data = val;
            }
    	}
        if(idx==k){
    	    Node *nd = new Node;
            nd->data = val;
            nd->next = NULL;
            if(head == NULL){
        	head = nd;
	    }
            else{
        	Node *current = head;
                while(current->next != NULL){
            	    current = current->next;
		}
                current->next = nd;
            }

        }
	if(idx!=0 && idx!=k){
           Node *nd = head;
           int counter = 0;
           while(counter < idx-1){
	       nd=nd->next;
	       counter++;
           }
           Node *current = head;
           counter = 0;
           while(counter < idx){
	       current=current->next;	
	       counter++;
           }
           Node *a = new Node;
           nd->next = a;
           a->next = current;
           a->data = val;
        }
}

void LList::reverse(){
        Node *tmp = head;
        Node *next = NULL;
        Node *last = NULL;
        while(tmp){
            next = tmp->next;
            tmp->next = last;
            last = tmp;
            tmp = next;
        }
        head = last;
} 
