#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* lchild;
	int data;
	Node* rchild;
	Node(int val){
		lchild=NULL;
		data=val;
		rchild=NULL;
	}
};
class BST{
	Node* root;
	public:
		BST(){
			root=NULL;
		}
		Node* getroot(){
			return root;
		}
		void insert(int);
		void remove(int);
		void preorder(Node*);
		void inorder(Node*);
		void postorder(Node*);
};
void BST::insert(int val){
	Node* curr=new Node(val);
	if(root==NULL){
		root=curr;
		return;
	}
	Node* temp=root,*parent;
	while(temp!=NULL){
		parent=temp;
		if(temp->data>val){
			temp=temp->lchild;
		}
		else if(temp->data<val){
			temp=temp->rchild;
		}
		else{
			cout<<"Equal data is present in the tree "<<endl;
			return;
		}
	}
	if(parent->data>val){
		parent->lchild=curr;
	}
	else{
		parent->rchild=curr;
	}
}

void BST::inorder(Node* r){
	if(r==NULL){
		return ;
	}
	inorder(r->lchild);
	cout<<r->data<<" ";
	inorder(r->rchild);
}
void BST::remove(int  val){
    if(root==NULL){
        cout<<"No element"<<endl;
        return;
    }
    Node* x=root;
	Node* parent=NULL;
    while(x!=NULL && x->data!=val){
        parent=x;
        if(x->data>val){
            x=x->lchild;
        }
        else if(x->data<val){
            x=x->rchild;
        }
    }
    if(x==NULL){
        cout<<"No data found to delete"<<endl;
        return;
    }
    if(x->rchild==NULL || x->lchild==NULL){
        Node* temp;
        if(x->lchild==NULL) temp = x->rchild;
        else temp= x->lchild;
        if(parent==NULL){  //Only root is present
            delete(root);
            root=temp;
            return;
        }
        if(parent->data<val){
            parent->rchild=temp;
        }
        else 
            parent->lchild=temp;
    delete(x);
    return;
    }
    
    //Both children are present
    
    Node* succ=x->rchild;
    Node* psucc=NULL;
    while(succ->lchild!=NULL){
        psucc=succ;
        succ=succ->lchild;
    }
    x->data=succ->data;
    if(psucc==NULL) x->rchild=succ->rchild;
    else 
        psucc->lchild=succ->rchild;
    delete(succ);
    
}

void BST::preorder(Node* r){
	if(r==NULL){
		return ;
	}
	cout<<r->data<<" ";
	preorder(r->lchild);
	preorder(r->rchild);
}

void BST::postorder(Node* r){
	if(r==NULL){
		return ;
	}
	postorder(r->lchild);
	postorder(r->rchild);
	cout<<r->data<<" ";
}

int main(){
	int n;
	BST t;
	do{
		cout<<"1->insert , 2-> remove , 3-> preorder , 4->inorder , 5->postorder , 6->exit "<<endl;
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the value to insert = ";
				int val;
				cin>>val;
				t.insert(val);
				cout<<endl;
				break;
			case 2:
				cout<<"Enter the value to remove = ";
				cin>>val;
				t.remove(val);
				cout<<endl;
				break;
			case 3:
				t.preorder(t.getroot());
				cout<<endl;
				break;
			case 4:
				t.inorder(t.getroot());
				cout<<endl;
				break;
			case 5:
				t.postorder(t.getroot());
				cout<<endl;
				break;
			case 6:
				exit(0);
		}
	}while(1);
	return 0;
}




