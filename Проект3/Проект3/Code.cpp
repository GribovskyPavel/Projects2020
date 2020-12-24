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
	void push_back(double data);         //Вставка элемента в конец списка
	void pop_front();                    //Удаление первого элемента списка
	void clear();                        //Удаление всех элементов списка
	void pop_back();                     //Удаление последнего элемента списка
	void push_front(double data);        //Вставка элемента в начало списка
	void insert(double data,int index);  //Вставка элемента на определенную позицию
	void removeAt(int index);            //Удаление элемента под заданным номером
	void reverseList();                  //Все элементы списка идут в обратном порядке
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
void List::push_back(double data){       //Вставка  элемента в конец списка
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
void List::pop_front(){      //Удаление первого элемента списка
	Node *t=head;
	head=head->next;
	delete t;
	Size--;
};
void List::clear(){       //Удаление всех элементов списка
	while(Size){
		pop_front();	
	}
};
void List::pop_back(){      //Удаление последнего элемента списка
	removeAt(Size-1);
};
void List::push_front(double data){       //Вставка элемента в начало списка
	head=new Node(data,head);
	Size++;
};
void List::insert(double data,int index){       //Вставка элемента на определенную позицию
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
void List::removeAt(int index){       //Удаление элемента под заданным номером
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
void List::reverseList(){        //Все элементы списка идут в обратном порядке
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
	cout<<"Лабораторная работа №3. Вариант 5\nВыберите способ тестирования класса List:\nВвод 1 - с клавиатуры, ввод 0 - из файла.\nВыбрать: "; cin>>mean;
	while(1){
		if(mean==0 || mean==1) break;
		cout<<"Допустимые значения только 0 и 1!\nВвод 1 - с клавиатуры, ввод 0 - из файла.\nВыбрать: ";
		cin>>mean;
	}
	if(mean==1){
		cout<<"Введите количество элементов(тип double) односвязного списка: "; cin>>n;
		for (int i = 0; i < n; i++){
			cout<<"Элемент списка № "<<i<<": ";
			cin>>data;
			K.insert(data,i);
		}
		cout<<"Исходный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<K[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		K.reverseList(); 
		cout<<endl<<"Инвертированный список:"<<endl;
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
		cout<<"Введите количество элементов(тип double) односвязного списка: "; cin>>n;
		for (int i = 0; i < n; i++){
			cout<<"Элемент списка № "<<i<<": ";
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
		cout<<"Исходный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<K[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		K.reverseList(); 
		cout<<endl<<"Инвертированный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<K[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		cout<<endl;
		fin.close();
	}
	system("pause");
}

