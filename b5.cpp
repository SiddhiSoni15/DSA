#include <iostream>
#include <string.h>
using namespace std;

struct node{
	string label;
	int ch_count;
	struct node *child[10];
}*root;

class Tree{
	public:
		void createtree();
		void display (node *n);
		Tree(){
			root=NULL;
		}
};

void Tree::createtree(){
	int tbooks,tchapters,i,j,k;
	root = new node;
	cout<<"enter name of book:";
	cin.ignore();
	getline(cin,root->label);
	
	
	cout<<"enter number of chapters in book:";
	cin>>tchapters;
	root->ch_count=tchapters;
	for(i=0;i<tchapters;i++){
		root->child[i]=new node;
		cout<<"enter name of chapter "<<i+1<<":";
		cin.ignore();
		getline(cin,root->child[i]->label);
		
		
		cout<<"Enter number of sections in chapter "<<root->child[i]->label<<":";
		cin>>root->child[i]->ch_count;
		for (j=0;j<root->child[i]->ch_count;j++){
			root->child[i]->child[j]=new node;
			cout<<"enter name of section "<<j+1<<":";
			cin.ignore();
			getline(cin,root->child[i]->child[j]->label);
			
			cout<<"Enter number of sub sections in section "<<root->child[i]->child[j]->label<<":";
			cin>>root->child[i]->child[j]->ch_count;
			for (k=0;k<root->child[i]->child[j]->ch_count;k++){
			root->child[i]->child[j]->child[k]=new node;
			cout<<"enter name of sub section "<<k+1<<":";
			cin.ignore();
			getline(cin,root->child[i]->child[j]->child[k]->label);	
			}	
		}
	}
}

void Tree::display(node *n){
	int i,j,k,tchapters;
	if(n!=NULL){
		cout<<"\n BOOK HIERARCHY";
		cout<<"\n Book title:"<<n->label;
		tchapters=n->ch_count;
		for(i=0;i<tchapters;i++){
			cout<<"\nChapter "<<i+1<<":";
			cout<<n->child[i]->label;
			cout<<"\nSections:";
			for(j=0;j<n->child[i]->ch_count;j++){
				cout<<"\n"<<n->child[i]->child[j]->label;
				cout<<"\nSubsections:";
				for(k=0;k<n->child[i]->child[j]->ch_count;k++){
				cout<<"\n"<<n->child[i]->child[j]->child[k]->label;
				}
			}
		}
	} 
	cout<<endl;
}

int main(){
	int ch;
	Tree tree;
	while(1){
		cout<<"1.Create"<<endl;
		cout<<"2.Display"<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch){
			case 1:
				tree.createtree();
				break;
			case 2:
				tree.display(root);
				break;
			case 3:
				cout<<"thank you";
				exit(1);
		}
	}
	return 0;
}
