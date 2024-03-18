#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* lchild;
    int data;
    Node* rchild;
    Node(int val){
        data=val;
        lchild=NULL;
        rchild=NULL;
    }
};

class Tree{
    Node * root;
    public:
        Tree(){
            root=NULL;
        }
        Node* getroot(){
            return root;
        }
        void insert(int);
        void remove(int);
        int height(Node*);
        void preorder(Node*);
        void postorder(Node*);
        void inorder(Node*);
        int external(Node*);
        int internal(Node*);
        int total(Node*);
        bool search(Node*,int);
        
};
void Tree::insert(int val){
    Node* curr=new Node(val);
    if(root==NULL){
        root=curr;
        return;
    }
    Node* temp=root,* parent;
    while(temp!=NULL){
        parent=temp;
        if(temp->data>val){
            temp=temp->lchild;
        }
        else if(temp->data<val){
            temp=temp->rchild;
        }
        else{
            cout<<"Same data is already presemnt in the tree"<<endl;
            return;
        }
	}
	if(parent->data>val) 
		parent->lchild=curr;
	else 
		parent->rchild=curr;
}
void Tree::remove(int  val){
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
void Tree::inorder(Node* r){
     if(r==NULL) return ;
     inorder(r->lchild);
     cout<<r->data<<" ";
     inorder(r->rchild); 
}
void Tree::preorder(Node* r){
     if(r==NULL) return ;
     cout<<r->data<<" ";
     preorder(r->lchild);
     preorder(r->rchild);
   
} 
void Tree::postorder(Node* r){
     if(r==NULL) return ;
    postorder(r->lchild);
    postorder(r->rchild);
     cout<<r->data<<" ";
}
int Tree::height(Node* r){
	if(r==NULL) return 0;
	int lh=height(r->lchild);
	int rh=height(r->rchild);
	return max(lh,rh)+1;
}
int Tree::total(Node * r){
	if(r==NULL) return 0;
	return total(r->lchild)+total(r->rchild)+1;
}
int Tree::external(Node * r){
	if(r==NULL) return 0;
	if(r->lchild==NULL && r->lchild==NULL) return 1;
	return external(r->rchild)+external(r->lchild);
}
int Tree::internal(Node* r){
	if(r==NULL || (r->lchild==NULL && r->lchild==NULL)) return 0;
	return internal(r->lchild)+internal(r->rchild)+1;
}
bool Tree::search(Node* r,int key){
	if(r==NULL) return false;
	Node* temp=root;
	while(temp!=NULL){
		if(temp->data>key) temp=temp->lchild;
		else if(temp->data<key) temp=temp->rchild;
		else return true;
		
	}
	return false;
}
int main(){
    cout<<"Readhe krishna "<<endl;
    Tree b;
    int n,val;
    do{
        cout<<endl<<"1->insert,2->preorder,3->inorder,4->postorder,5->delete ,6->height,7->total node ,8->internal,9->search ,10->external,10->>exit"<<endl;
        cin>>n;
        switch(n){
            case 1:
                    cout<<"enter a value to inser"<<endl;
                    cin>>val;
                    b.insert(val);
                    break;
            case 2:
                    b.preorder(b.getroot());
                    break;
            case 3:
                b.inorder(b.getroot());
                break;
            case 4:
                    b.postorder(b.getroot());
                    break;

            case 5: 
           		 cout<<"Enter value to delete"<<endl;
           		 cin>>val;
                 b.remove(val);
                 break;
            case 6:
            	cout<<"Height is "<<b.height(b.getroot())<<endl;
            	break;
            case 7:
            	cout<<"Total node is "<<b.total(b.getroot())<<endl;
            	break;
            case 8:
            	cout<<"mid node "<<b.internal(b.getroot())<<endl;
            	break;
            case 9:
            	cout<<"Leave node "<<b.external(b.getroot())<<endl;
            	break;
            case 10:
				cout<<"Enlemet to search ";
				cin>>val;
				cout<<b.search(b.getroot(),val);
				break; 
			case 11:
			   	exit(0);
			default:
				cout<<"Wrong Choise "<<endl;
         }
     }while(1);
      
     return 0;
}