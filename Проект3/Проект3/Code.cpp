#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class List{
	struct Node{
		double data;
		Node *next;
		Node(double data=double(),Node *next=NULL){
		this->data=data;
		this->next=next;
		};
    };
	int Size;
	Node *head;
public:
	List();
	~List();
	void push_back(double data);         //������� �������� � ����� ������
	void pop_front();                    //�������� ������� �������� ������
	void clear();                        //�������� ���� ��������� ������
	void pop_back();                     //�������� ���������� �������� ������
	void push_front(double data);        //������� �������� � ������ ������
	void insert(double data,int index);  //������� �������� �� ������������ �������
	void removeAt(int index);            //�������� �������� ��� �������� �������
	void reverseList();                  //��� �������� ������ ���� � �������� �������
	int GetSize(){ return Size;};
	double& operator [](const int index);
};

List::List(){
	Size=0;
	head=NULL;
};
List::~List(){
	clear();
};
double& List::operator[](const int index){
	int size=0;
	Node* cur=this->head;
	while(cur!=NULL){
		if (size==index){
			return cur->data;
		}
		cur=cur->next;
		size++;
	}
};
void List::push_back(double data){       //�������  �������� � ����� ������
	if(head==NULL){
		head =new Node(data);
	}
	else{
		Node* cur=this->head;
		while(cur->next!=NULL){
			cur=cur->next;
		}
		cur->next=new Node(data);
	}
	Size++;
};
void List::pop_front(){      //�������� ������� �������� ������
	Node *t=head;
	head=head->next;
	delete t;
	Size--;
};
void List::clear(){       //�������� ���� ��������� ������
	while(Size){
		pop_front();	
	}
};
void List::pop_back(){      //�������� ���������� �������� ������
	removeAt(Size-1);
};
void List::push_front(double data){       //������� �������� � ������ ������
	head=new Node(data,head);
	Size++;
};
void List::insert(double data,int index){       //������� �������� �� ������������ �������
	if (index==0){
		push_front(data);
	}
	else{
		Node* prev=this->head;
		for (int i = 0; i < index-1; i++){
			prev=prev->next;
		}
		Node* newNode=new Node (data,prev->next);
		prev->next=newNode;
		Size++;
	}
};
void List::removeAt(int index){       //�������� �������� ��� �������� �������
	if (index==0){
		pop_front();
	}
	else
	{
		Node* prev=this->head;
		for (int i = 0; i < index-1; i++){
			prev=prev->next;
	    }
	    Node *Del=prev->next;
	    prev->next=Del->next;
	    delete Del;
	    Size--;
	}
};
void List::reverseList(){        //��� �������� ������ ���� � �������� �������
	if(Size>1){
		Node *prev=NULL,*cur,*next;
		cur=head;
		while(cur){
			next=cur->next;
			cur->next=prev;
			prev=cur;
			cur=next;
		}
		head=prev;
	}
};
void main(){
	setlocale(LC_CTYPE,"rus");
	List K;
	int n=0; 
	double data=0;
	int mean;
	cout<<"������������ ������ �3. ������� 5\n�������� ������ ������������ ������ List:\n���� 1 - � ����������, ���� 0 - �� �����.\n�������: "; cin>>mean;
	while(1){
		if(mean==0 || mean==1) break;
		cout<<"���������� �������� ������ 0 � 1!\n���� 1 - � ����������, ���� 0 - �� �����.\n�������: ";
		cin>>mean;
	}
	if(mean==1){
		cout<<"������� ���������� ���������(��� double) ������������ ������: "; cin>>n;
		for (int i = 0; i < n; i++){
			cout<<"������� ������ � "<<i<<": ";
			cin>>data;
			K.insert(data,i);
		}
		cout<<"�������� ������:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<K[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		K.reverseList(); 
		cout<<endl<<"��������������� ������:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<K[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		cout<<endl;
	}
	if(mean==0){
		fstream fout;
		string name="Data.txt";
		fout.open(name, fstream::in | fstream::out);
		if(!fout.is_open()) cout<<"ERROR"<<endl;
		cout<<"������� ���������� ���������(��� double) ������������ ������: "; cin>>n;
		for (int i = 0; i < n; i++){
			cout<<"������� ������ � "<<i<<": ";
			cin>>data;
			fout<<data<<"\n";
		}
		fout.close();

		fstream fin;
		char c;
		string str;
		fin.open(name, fstream::in | fstream::out);
		if(!fin.is_open()) cout<<"ERROR"<<endl;
		for (int i = 0; i < n; i++){
			str="";
			getline(fin,str);
			K.insert(stod(str),i);
		}
		cout<<"�������� ������:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<K[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		K.reverseList(); 
		cout<<endl<<"��������������� ������:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<K[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		cout<<endl;
		fin.close();
	}
	system("pause");
}

