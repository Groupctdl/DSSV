#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>   
#include <vector>     
#include <cstring>
using namespace std;

struct student{    
    string id;
    string firstName;
    string lastName, gender, phone, idClass, year;
};

struct nodeStudent{
    student value;
    nodeStudent *next;
};

void init(nodeStudent *&head){
    head=NULL;
}

nodeStudent* createNodeStudent(student x){
    nodeStudent *p=new nodeStudent;
    p->value=x;
    p->next=NULL;
    return p;
}

void addFirst(nodeStudent *&head,student x){
    nodeStudent *p=createNodeStudent(x);
    p->next=head;
    head=p;
}

void addLast(nodeStudent *&head,student x){
    nodeStudent *p=createNodeStudent(x);
   
    if(head==NULL){
        head=p;
    }
    else{
        nodeStudent *last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=p;
    }
}

// doc file 
void readStudentList(nodeStudent *&head, string nameFileStudentList){
    ifstream f;
    f.open(nameFileStudentList, ios::in);
    if(!f.is_open()){
        cout << "fail open!" << endl;
        return;
    }
    cout << "complete open!" << endl; // doc file
    
    student e;
    while(!f.eof()){
        
        string line;
        getline(f, line); 
        stringstream ss(line);
        
        getline(ss, e.id, '#');
        getline(ss, e.firstName, '#');
        getline(ss, e.lastName, '#');
        getline(ss, e.gender, '#');
        getline(ss, e.phone, '#');
        getline(ss, e.idClass, '#');
        getline(ss, e.year, '#');
        
        addLast(head,e);
    }
    
    f.close();
}

void printfStudent(student stu){
    cout << stu.id << " " << stu.firstName << " " << stu.lastName << " " << stu.gender << " " << stu.phone << " " << stu.idClass << " " << stu.year << endl;
    
}
void displayStudentList(nodeStudent *head){
    nodeStudent *p=head;
    while(p!=NULL){
        printfStudent(p->value);
        p=p->next;
    }
}

int main()
{
	
    nodeStudent *head;
    init(head);
    
    string nameFileStudentList = "studentlist.txt";
    readStudentList(head, nameFileStudentList);

    displayStudentList(head);

    return 0;
}
