/*
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to find the number of nodes in the longest path from the root
int maxPathLength(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(maxPathLength(root->left), maxPathLength(root->right));
}

// Function to find the minimum data value in the tree
int findMin(Node* root) {
    if (root == NULL) return -1; // Assuming -1 denotes an empty tree
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to swap left and right pointers at every node
void swapChildren(Node* root) {
    if (root == NULL) return;
    swap(root->left, root->right);
    swapChildren(root->left);
    swapChildren(root->right);
}

// Function to search for a value in the tree
bool search(Node* root, int value) {
    if (root == NULL) return false;
    if (root->data == value) return true;
    if (value < root->data) return search(root->left, value);
    else return search(root->right, value);
}

int main() {
    Node* root = NULL;
    int i;
    int values[] = {50, 30, 70, 20, 40, 60, 80}; // Values to insert into the BST

    // Construct the BST
    for (int i=0;i<sizeof(values);i++) {
        root = insert(root, values[i]);
    }

    // 1. Insert a new node
    root = insert(root, 55);

    // 2. Find number of nodes in the largest path from root
    cout << "Number of nodes in the largest path from root: " << maxPathLength(root) << endl;

    // 3. Minimum data value found in the tree
    cout << "Minimum data value found in the tree: " << findMin(root) << endl;

    // 4. Change a tree so that the roles of the left and right pointers are swapped at every node
    swapChildren(root);

    // 5. Search a value
    int valueToSearch = 60;
    cout << "Value " << valueToSearch << " found in the tree: " << (search(root, valueToSearch) ? "Yes" : "No") << endl;

    return 0;
}*/
#include<iostream>

using namespace std;

struct node{
	int data;
	node*left;
	node*right;
};

node* createNode(int value){
	node* newNode=new node;
	newNode->data=value;
	newNode->left=newNode->right=NULL;
	return newNode;
}

node * insert(node* root,int value){
	if(root==NULL){
		return createNode(value);
	}
	if (value<root->data){
		root->left=insert(root->left,value);
	}
	else if (value>root->data){
		root->right=insert(root->right,value);
	}
	return root;
}

int maxPathLength(node* root){
	if (root==NULL)
		return 0;
	return 1+max(maxPathLength(root->left),maxPathLength(root->right));
}

int findMin(node*root){
	if (root==NULL)
		return -1;
	while(root->left!=NULL){
		root=root->left;
	}
	return root->data;
}

void swapChildren(node*root){
	if (root==NULL)
		return;
	swap(root->left,root->right);
	swapChildren(root->left);
	swapChildren(root->right);
}

bool search(node*root, int value){
	if (root==NULL)
		return false;
	if (root->data==value)
		return true;
	if (value<root->data)
		return search(root->left,value);
	if (value>root->data)
		return search(root->right,value);
}

int main(){
	node* root=NULL;
	int values[10];
	int i,j,n,value;
	cout<<"Enter the number of elements you want to add in the tree: ";
	cin>>n;
	cout<<"Enter the values: "<<endl;
	for (i=0;i<n;i++){
		cin>>values[i];
	}
	//cout<<"THe values to be inserted in the tree are: ";
	//for (i=0;i<n;i++)
	for (i=0;i<sizeof(values);i++){
		root=insert(root,values[i]);
	}
	do{
	int choice;
	cout<<"\nSelect a option below: "<<endl;
	cout<<"\n1.Insert new node"<<endl;
	cout<<"2.Find the number of nodes in the longest path from root"<<endl;
	cout<<"3.Minimum data value found in the tree"<<endl;
	cout<<"4.Swap the left and right branches of the tree"<<endl;
	cout<<"5.Search a value"<<endl;
	cout<<"6.Exit"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"Enter the value you want to insert: ";
			cin>>value;
			insert(root,value);
			cout<<"Value inserted successfully."<<endl;
			break;
			
		case 2:
			cout<<"Number of nodes in the longest path from the root is : "<<maxPathLength(root)<<endl;
			break;
		
		case 3:
			cout<<"The minimum data in the tree is: "<<findMin(root)<<endl;
			break;
		
		case 4:
			swapChildren(root);
			cout<<"The tree has been succesfully swapped.";
			break;
			
		case 5:
			cout<<"Enter the value you want to search: ";
			cin>>value;
			if (search(root,value)==true)
				cout<<"The value is found."<<endl;
			else
				cout<<"The value is not found.";
			break;
		
		case 6:
			exit;
			
		default:
			cout<<"Please enter a valid choice."<<endl;
			exit;
	}
}while(1);
	return 0;
}











































