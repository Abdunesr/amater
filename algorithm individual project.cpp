
#include <iostream> 
using namespace std;

struct student{
	int id;
	char name[20];
	
	student *nxt;
};

student *head = NULL;

void display();
student * addData();
void insertFirst();
void insertEnd();
void insertAfterId(int id);

int main(){
	int repeat = 0, choise = 0;
	
	while(repeat == 0){
		cout<<"\n enter 0 to exit";
		cout<<"\n enter 1 for displaying";
		cout<<"\n enter 2 to insert data at the begginning of the list";
		cout<<"\n enter 3 to insert data at the end of the list";
		cout<<"\n enter 4 to add by search \n";
		cin>>choise;
		switch(choise){
			case 1: display(); break;
			case 2: insertFirst(); break;
			case 3: insertEnd(); break;
			case 4: 
			 int id;
			 cout<<"\n enter id to be search:";
			 cin>>id;
			 insertAfterId(id);
			 break;
			
			
			case 0: repeat = 1; break;
			default: cout<<"\n unkown input"; break;
		}
	}
}


void display(){
	student *st = head; 
	if(st == NULL)
	 cout<<"No data \n";
  else if(st->nxt == NULL){
  	cout<<"id: "<<st->id<<endl;
  	cout<<"Name: "<<st->name<<endl;
	} else {
		while(st != NULL){
	  	cout<<"id: "<<st->id<<endl;
	  	cout<<"Name: "<<st->name<<endl;
 		 
 		 st = st->nxt;
		}
	}
}

student * addData(){
	student *st = new student;
	cout<<"\n enter ID:";
	cin>>st->id;
	cout<<"\n enter name:";
	cin>>st->name;
	st->nxt = NULL;
	
	return st;
}

void insertFirst(){
	student *st = addData();
	
	if(head == NULL)
	 head = st;
  else {
  	st->nxt = head;
  	head = st;
	}
}

void insertEnd(){
	student *st = addData();
	
	if(head == NULL)
	 head = st;
	 else if(head->nxt == NULL)
	  head->nxt = st;
   else{
   	student *temp = head;
   	while(temp->nxt != NULL)
   	 temp = temp->nxt;
 	  temp->nxt = st;
	 }
}

void insertAfterId(int id){
	if(head == NULL)
	 cout<<"\n NO data in the list";
  else{
  	student *st = head;
  	bool found = false;
  	while(st != NULL){
  		
  		if(id == st->id){
  			student *st2 = st->nxt;
  			student *st3 = addData();
  			st->nxt = st3;
  			st3->nxt = st2;
  			found = true;
  			break;
			}
			st = st->nxt;
		}
		if(found)
		 cout<<"\n successfull";
	  else
		 cout<<"\n not found";
	}
}







