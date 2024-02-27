#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>   
#include <vector>     
#include <cstring>

using namespace std;

struct subject{
	string idSubject, name;
	string STCLT, STCTH;
};

struct nodeSubject{ // cau truc cay nhi phan can bang 
	subject data;
	int height;
	nodeSubject *left, *right;
};

void init(nodeSubject *&root){
	root = NULL;
}

nodeSubject* createNodeSubject(subject data){ // tao mot node voi voi gia tri da cho
	nodeSubject *newNode = new nodeSubject;
	newNode->data = data;
	newNode->height = 1;
	newNode->left = newNode->right = NULL;
	return newNode;
}

int getHeight(nodeSubject *root){
	if(root == NULL) return 0; // truong hop danh sach rong
	return root->height;
}

int getBalance(nodeSubject *root){
	if(root == NULL) return 0; // truong hop danh sach rong
	return getHeight(root->left) - getHeight(root->right);
}

nodeSubject* rightRotate(nodeSubject *y){
	nodeSubject *x = y->left;
	nodeSubject *T2 = x->right;
	x->right = y;
	y->left = T2;
	
	y->height = 1 + max(getHeight(y->left), getHeight(y->right));
	x->height = 1 + max(getHeight(x->left), getHeight(x->right));
	
	return x;
}


void addNode(nodeSubject *&root, subject s){
	if(root == NULL){ // truong hop danh sach rong
		root = createNodeSubject(s);
		return;
	}
	addNode(root->left, s);
	
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	int balance = getBalance(root);
	
	if(balance > 1){ // cay khong can bang luon trong truong hop left left
		root = rightRotate(root);
	}
}

void readSubjectList(nodeSubject *&root, string nameFileSubjectList){ // xu ly doc file
	fstream f;
	f.open(nameFileSubjectList, ios::in);
	if(!f.is_open()){
		cout << "Failed Open!" << endl;
		return;
	}
	cout << "Completed Open!" << endl;
	
	subject s;
	while(!f.eof()){
		string line;
		getline(f, line);
		
		stringstream ss(line);
		getline(ss, s.idSubject, '#');
		getline(ss, s.name, '#');
		getline(ss, s.STCLT, '#');
		getline(ss, s.STCTH, '#');
		
		addNode(root, s);
	}
}

void display(nodeSubject *root){
	if(root == NULL) return;
	cout << root->data.idSubject << " " << root->data.name << " " << root->data.STCLT << " " << root->data.STCTH << endl;
	display(root->left);
	display(root->right);
}

int main(){
	nodeSubject *root;
	init(root);
	string nameFileSubjectList = "subjectlist.txt";
	readSubjectList(root, nameFileSubjectList);
	
	display(root);
}
