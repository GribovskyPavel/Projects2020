#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <Windows.h>
using namespace std;

template <typename T> class List{
	struct Node{
		T data;
		Node *next;
		Node(T data=T(),Node *next=NULL){
		this->data=data;
		this->next=next;
		};
    };
	int Size;
	Node *head;
public:
	List();
	~List();
	void push_back(T data);         //Вставка элемента в конец списка
	void pop_front();                    //Удаление первого элемента списка
	void clear();                        //Удаление всех элементов списка
	void pop_back();                     //Удаление последнего элемента списка
	void push_front(T data);        //Вставка элемента в начало списка
	void insert(T data,int index);  //Вставка элемента на определенную позицию
	void removeAt(int index);            //Удаление элемента под заданным номером
	void reverseList();                  //Все элементы списка идут в обратном порядке
	int GetSize(){ return Size;};
	T& operator [](const int index);
};

template <typename T> List<T>::List(){
	Size=0;
	head=NULL;
};
template <typename T> List<T>::~List(){
	clear();
};
template <typename T> T& List<T>::operator[](const int index){
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
template <typename T> void List<T>::push_back(T data){       //Вставка  элемента в конец списка
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
template <typename T> void List<T>::pop_front(){      //Удаление первого элемента списка
	Node *t=head;
	head=head->next;
	delete t;
	Size--;
};
template <typename T> void List<T>::clear(){       //Удаление всех элементов списка
	while(Size){
		pop_front();	
	}
};
template <typename T> void List<T>::pop_back(){      //Удаление последнего элемента списка
	removeAt(Size-1);
};
template <typename T> void List<T>::push_front(T data){       //Вставка элемента в начало списка
	head=new Node(data,head);
	Size++;
};
template <typename T> void List<T>::insert(T data,int index){       //Вставка элемента на определенную позицию
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
template <typename T> void List<T>::removeAt(int index){       //Удаление элемента под заданным номером
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
template <typename T> void List<T>::reverseList(){        //Все элементы списка идут в обратном порядке
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
void ListInt(int mean);
void ListDouble(int mean);
void ListChar(int mean);
void main(){
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE,"rus");
	int mean,type,br=0;
	cout<<"Лабораторная работа №4. Вариант 5\nВыберите способ тестирования класса List:\nВвод 1 - с клавиатуры, ввод 0 - из файла.\nВыбрать: "; cin>>mean;
	while(true){
		if(mean==0 || mean==1) break;
		cout<<"Допустимые значения только 0 и 1!\nВвод 1 - с клавиатуры, ввод 0 - из файла.\nВыбрать: ";
		cin>>mean;
	}
	cout<<"Выберите тип данных для шаблонного класса List:\nВвод 0 - тип int, ввод 1 - тип double, ввод 2 - тип char.\nВыбрать: "; cin>>type;
	while(true){
		if(type==0 || type==1 || type==2) break;
		cout<<"Допустимые значения только 0, 1, 2!\nВвод 0 - тип int, ввод 1 - тип double, ввод 2 - тип char.\nВыбрать: ";
		cin>>type;
	}
	while(true){
		switch(type){
			case 0: {ListInt(mean);break;}
			case 1: {ListDouble(mean);break;}
			case 2: {ListChar(mean);break;}
			default: {break;}
		}
		cout<<endl<<"Если нужно выйти из цикла введите - 1\nПродолжаем? Ввод:  ";
		cin>>br;
		if(br==1) break;
		cout<<"Выберите тип данных для шаблонного класса List:\nВвод 0 - тип int, ввод 1 - тип double, ввод 2 - тип char.\nВыбрать: "; cin>>type;
		while(true){
			if(type==0 || type==1 || type==2) break;
			cout<<"Допустимые значения только 0, 1, 2!\nВвод 0 - тип int, ввод 1 - тип double, ввод 2 - тип char.\nВыбрать: ";
			cin>>type;
		}
	}
	system("pause");
}
void ListInt(int mean){
	List<int> I;
	int n=0; 
	int data=0;
	if(mean==1){
		cout<<"Введите количество элементов(тип int) односвязного списка: "; cin>>n;
		for (int i = 0; i < n; i++){
			cout<<"Элемент списка № "<<i<<": ";
			cin>>data;
			I.insert(data,i);
		}
		cout<<"Исходный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<I[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		I.reverseList(); 
		cout<<endl<<"Инвертированный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<I[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		cout<<endl;
	}
	if(mean==0){
		fstream fout;
		string name="Data.txt";
		fout.open(name, fstream::in | fstream::out);
		if(!fout.is_open()) cout<<"ERROR"<<endl;
		cout<<"Введите количество элементов(тип int) односвязного списка: "; cin>>n;
		for (int i = 0; i < n; i++){
			cout<<"Элемент списка № "<<i<<": ";
			cin>>data;
			fout<<data<<"\n";
		}
		fout.close();

		fstream fin;
		string str;
		fin.open(name, fstream::in | fstream::out);
		if(!fin.is_open()) cout<<"ERROR"<<endl;
		for (int i = 0; i < n; i++){
			str="";
			getline(fin,str);
			I.insert(stod(str),i);
		}
		cout<<"Исходный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<I[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		I.reverseList(); 
		cout<<endl<<"Инвертированный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<I[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		cout<<endl;
		fin.close();
	}
};
void ListDouble(int mean){
	List<double> D;
	int n=0; 
	double data=0;
	if(mean==1){
		cout<<"Введите количество элементов(тип double) односвязного списка: "; cin>>n;
		for (int i = 0; i < n; i++){
			cout<<"Элемент списка № "<<i<<": ";
			cin>>data;
			D.insert(data,i);
		}
		cout<<"Исходный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<D[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		D.reverseList(); 
		cout<<endl<<"Инвертированный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<D[i]<<" ";
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
		string str;
		fin.open(name, fstream::in | fstream::out);
		if(!fin.is_open()) cout<<"ERROR"<<endl;
		for (int i = 0; i < n; i++){
			str="";
			getline(fin,str);
			D.insert(stod(str),i);
		}
		cout<<"Исходный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<D[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		D.reverseList(); 
		cout<<endl<<"Инвертированный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<D[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		cout<<endl;
		fin.close();
	}
};
void ListChar(int mean){
	List<char> C;
	int n=0; 
	char data='0';
	if(mean==1){
		cout<<"Введите количество элементов(тип char) односвязного списка: "; cin>>n;
		for (int i = 0; i < n; i++){
			cout<<"Элемент списка № "<<i<<": ";
			cin>>data;
			C.insert(data,i);
		}
		cout<<"Исходный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<C[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		C.reverseList(); 
		cout<<endl<<"Инвертированный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<C[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		cout<<endl;
	}
	if(mean==0){
		fstream fout;
		string name="Data.txt";
		fout.open(name, fstream::in | fstream::out);
		if(!fout.is_open()) cout<<"ERROR"<<endl;
		cout<<"Введите количество элементов(тип char) односвязного списка: "; cin>>n;
		for (int i = 0; i < n; i++){
			cout<<"Элемент списка № "<<i<<": ";
			cin>>data;
			fout<<data<<"\n";
		}
		fout.close();

		fstream fin;
		string str;
		fin.open(name, fstream::in | fstream::out);
		if(!fin.is_open()) cout<<"ERROR"<<endl;
		for (int i = 0; i < n; i++){
			str="";
			getline(fin,str);
			C.insert(*str.c_str(),i);
		}
		cout<<"Исходный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<C[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		C.reverseList(); 
		cout<<endl<<"Инвертированный список:"<<endl;
		for (int i = 0; i < n; i++){
			cout<<C[i]<<" ";
			if(i==n-1) cout<<endl;
		}
		cout<<endl;
		fin.close();
	}
};

