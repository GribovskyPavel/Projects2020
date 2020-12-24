#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;

void Task11();
void Task12();
void Task13();
void Task21();
void Task31();
//Лабораторная работа №1
class Worker{
	char* fio;
	char* dol;
	int year;
	double wage;
public:
	Worker(){
		this->fio=new char[1];
		this->dol=new char[1];
		this->year=0;
		this->wage=0;
	}

	void set(){
		if(this->fio!=NULL){
			delete[] fio;
			string s;
			cout << "Введите ФИО работника: "; cin>>s;
			this->fio=new char[s.length()+1];
			for (int i = 0; i < s.length()+1; i++){
				fio[i]=s[i];
			}
		}
		if(this->dol!=NULL){
			delete[] dol;
			string p;
			cout << "Введите должность работника: "; cin>>p;
			this->dol=new char[p.length()+1];
			for (int i = 0; i < p.length()+1; i++){
				dol[i]=p[i];
			}
		}
		cout << "Введите заработную плату работника: "; cin>>wage; 
		cout << "Введите год поступления на работу: "; cin>>year; cout<<endl;
	};
	void get(){
		cout << "ФИО работника: "<<fio<<endl;
		cout << "Должность работника: "<<dol<<endl;
		cout << "Заработная плата работника: "<<wage<<endl;
		cout << "Год поступления на работу: "<<year<<endl; 
	};
	void getfio(){
		cout << "ФИО работника: "<<fio<<endl;
	};

	void FSetYear(int year){ this->year=year;};
	void FSetWage(double wage){ this->wage=wage;};
	void FSetDol(char *Dol,int n){
		if(dol!=NULL){delete[] dol;}
		this->dol=new char[n+1];
		for (int i = 0; i < n+1; i++){
			dol[i]=Dol[i];
		}
	};
	void FSetFio(char *Fio,int n){ 
		if(fio!=NULL){delete[] fio;}
		this->fio=new char[n+1];
		for (int i = 0; i < n+1; i++){
			fio[i]=Fio[i];
		}
	};

	int GetYear(){ return year;};
	double GetWage(){ return wage;};
	char* GetDol(){ return dol;};
	char* GetFio(){ return fio;};
	friend ostream& operator<<(ostream& os,const Worker& w){
		os<<w.fio<<" "<<w.dol<<" "<<w.wage<<" "<<w.year<<"\n";
		return os;
	};
	friend istream& operator>>(istream& is, Worker& w){
		is>>w.fio>>w.dol>>w.wage>>w.year;
		return is;
	};
	~Worker(){
		delete[] fio;
		delete[] dol;
	}
};
//Лабораторная работа №2
class Polynom {
	int n;
	double *koef;
public: 
	 Polynom(); 
	 Polynom(int k);
	 Polynom(int k,double *mas);
	 Polynom(const Polynom& ob); 
	 ~Polynom(){delete[] koef;}

	 void GiveMemory(int k);
	 void SetPolynom(int k,double *mas);
	 void SetDegree(int k){n=k;}; 
	 void CalculateValue(double x); 
	 void SetPolyCoef(double value,int index){
		koef[index]=value;
	 };
	 int GetDegree(){return n;};   
	 double GetOneCoefficient(int i){return(koef[i]);};
	 void SumShow(Polynom a, Polynom b){
		Polynom s;
		s=a+b;
		cout<<" f(x)+g(x) = "; cout<<s;
	 };
	 void AntiSumShow(Polynom a, Polynom b){
		Polynom s;
		s=a-b;
		cout<<" f(x)-g(x) = "; cout<<s;
	 };
	 void MultShow(Polynom a, Polynom b){
		Polynom s;
		s=a*b;
		cout<<" f(x)*g(x) = "; cout<<s;
	 };

	 Polynom operator+(Polynom ob); 
	 Polynom operator-(Polynom ob); 
	 Polynom operator*(Polynom ob);
	 double& operator++(int i){
		 double rez=koef[i]+1;
		 return(rez);};
	 double& operator--(int i){
		 double rez=koef[i]-1;
		 return(rez);};
	 double& operator[](int i){return(koef[i]);}
	 Polynom& operator = (const Polynom p) {
		if(&p==this) return *this;
		if(koef!=NULL) delete[] koef;
		n=p.n;
		koef=new double [p.n+1];
		for(int i=0;i<=p.n;i++)
			koef[i]=p.koef[i];
		return *this;
	}

	 friend ostream& operator<<(ostream& mystream,Polynom &ob);
	 friend istream& operator>>(istream& mystream,Polynom &ob);
};

Polynom::Polynom()
{  
	 n=rand()%5;
	 koef=new double[n+1];
	 if(!koef){cout<<"Error";getch();return;}
	 for(int i=n;i>=0;i--)
		 koef[i]=rand()%10-5;
}
Polynom::Polynom(int k)
{   n=k;
	koef=new double[n+1];
	if(!koef){cout<<"Error";getch();return;}
	for(int i=n;i>=0;i--)
		koef[i]=0;
}
Polynom::Polynom(int k,double mas[])
{
	 n=k;
	 koef=new double[n+1];
	 if(!koef){cout<<"Error";getch();return;}
	 for(int i=n;i>=0;i--)
		 koef[i]=mas[i];
}
Polynom::Polynom(const Polynom&ob)
{
	 n=ob.n;
	 koef=new double[n+1];
	 if(!koef){cout<<"Error";getch();return;}
	 for(int i=0;i<=n;i++)
		koef[i]=ob.koef[i];
}

void Polynom::GiveMemory(int k)
{
	 if(koef!=NULL) delete [] koef;
	 koef=new double[k+1];
	 if(!koef){cout<<"Error";getch();return;}
}
void Polynom::SetPolynom(int k,double *mas)
{
	 n=k;
	 if(koef) delete [] koef;
	 koef = new double [n+1];
	 for(int i=n;i>=0;i--)
		 koef[i]=mas[i];
}
void Polynom::CalculateValue(double x=1.0)
{ 
	double s;
	int i;
	for(s=koef[0],i=1;i<=n;i++)
		s=s+koef[i]*pow(x,i);
	cout<<"f("<<x<<")="; cout<<s<<endl;
}

Polynom Polynom::operator+(Polynom ob)
{ 
	 int i;
	 Polynom rab;
	 rab.GiveMemory(max(n,ob.GetDegree()));
	 for(i=0;i<=min(n,ob.GetDegree());i++)
		rab.koef[i]=koef[i]+ob.GetOneCoefficient(i);
	 if(n<ob.GetDegree())
	   {
		for(i=min(n,ob.GetDegree())+1;i<=ob.GetDegree();i++)
		   rab.koef[i]=ob.GetOneCoefficient(i);
		rab.n=ob.GetDegree();
	   }
	 else
	   {
		for(i=min(n,ob.GetDegree())+1;i<=n;i++) rab.koef[i]=koef[i];
	  rab.n=n;
	   }
	 return rab;
}
Polynom Polynom::operator-(Polynom ob)
{ int i;
 Polynom a;
 a.GiveMemory(max(n,ob.GetDegree()));
 for(i=0;i<=min(n,ob.GetDegree());i++)
    a.koef[i]=koef[i]-ob.GetOneCoefficient(i);
 if(n<ob.GetDegree())
   {
    for(i=min(n,ob.GetDegree())+1;i<=ob.GetDegree();i++)
       a.koef[i]=ob.GetOneCoefficient(i);
    a.n=ob.GetDegree();
   }
 else
   {
    for(i=min(n,ob.GetDegree())+1;i<=n;i++) a.koef[i]=koef[i];
  a.n=n;
   }
 return a;
}
Polynom Polynom::operator*(Polynom ob)
{
 int i,j,k;
 double s;
 Polynom rab;
 rab.GiveMemory(n+ob.GetDegree());
 for(i=0;i<=n+ob.GetDegree();i++)
    { s=0;
     for(j=0;j<=n;j++)
        for(k=0;k<=ob.GetDegree();k++)
           if(j+k==i)s=s+koef[j]*ob.GetOneCoefficient(k);
     rab.koef[i]=s;
    }
 rab.n=n+ob.GetDegree();
 return rab;
}

ostream& operator<<(ostream& mystream,Polynom &ob)
{ char c=' '; 
   for(int i=ob.n;i>=0;i--){
	      double ai=ob.koef[i];
          if(ai==0) continue;
			else {if(ai>0) mystream<<c; mystream<<ai;}
          if(i==0) continue; else mystream<<"x";
          if(i==1) continue; else mystream<<"^"<<i;
          if(ai!=0)c='+';
    }
 //if(c==' ')mystream<<0;
 mystream<<"\n";
 return mystream;
}
istream& operator>>(istream& mystream,Polynom &ob)
{
	 int i;
	 cout<<"Введите степень многочлена: ";
	 mystream>>ob.n; 
	 cout<<endl;
	 if(ob.koef!=NULL){
		delete[] ob.koef;
	 }
	 ob.koef=new double[ob.n+1];
	 for(i=ob.n;i>=0;i--)
		{
		 cout<<"Введите коэффициенты многочлена при степени "<<i<<": "; 
		 mystream>>ob.koef[i];
		}

	 return mystream;
}

Polynom SumOfElem(Polynom** Arr, int number);
//Лабораторная работа №3
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
	srand(time(0));
	setlocale(LC_ALL,"rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*ifstream fin;
	const char fname[] = "Data.txt";
	const int maxlen = 128;
	int n=30;
	cout << "Открытие файла " << fname<<endl;
	fin.open(fname); if (!fin.is_open())
	cout << "Ошибка открытия файла "<<fname<<endl;
	char* s = new char[maxlen];
	Worker* worker = new Worker[n];
	while (!fin.eof()) {
		fin.getline(s,maxlen);
		cout << s << endl;
	}
	fin.close(); 
	delete[] s;
	delete[] worker;*/
	/*fstream fout;
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
		fin.close();*/
	cout<<"Лабораторная работа №6"<<endl;
	cout<<"Измененная лабораторная работа №1"<<endl;
	cout<<"Выполнить задание №1? (Если да, то введите - 1)"<<endl;
	if(_getch()=='1')
	{
		/*Worker a;
		cout<<a;
		Worker b;
		cin>>b;*/
		Task11();
	}
	cout<<"Выполнить задание №2? (Если да, то введите - 2)"<<endl;
	if(_getch()=='2')
	{
		Task12();
	}
	cout<<"Выполнить задание №3? (Если да, то введите - 3)"<<endl;
	if(_getch()=='3')
	{
		Task13();
	}
	cout<<"Измененная лабораторная работа №2"<<endl;
	cout<<"Выполнить задание №4? (Если да, то введите - 4)"<<endl;
	if(_getch()=='4')
	{
		Task21();
	}
	cout<<"Измененная лабораторная работа №3"<<endl;
	cout<<"Выполнить задание №5? (Если да, то введите - 5)"<<endl;
	if(_getch()=='5')
	{
		Task31();
	}
	system("pause");
};
void Task11(){
	try
		{
			fstream fout;
			string name="Data.txt";
			fout.open(name,fstream::out | fstream::trunc);
			if(!fout.is_open()) {
				fout.close();
				throw 1;
			}
			Worker *List,*NList;
			int n,k,a=0;
			cout<<"Введите количество работников: "; cin>>n;
			cout<<"Введите заданное число лет: "; cin>>k;
			List=new Worker[n];
			NList=new Worker[n];
			for(int i=0;i<n;i++){
				cout<<"Данные о работнике № "<<i+1<<endl;
				List[i].set();
				fout<<List[i].GetFio()<<endl<<List[i].GetDol()<<endl<<List[i].GetWage()<<endl<<List[i].GetYear()<<endl<<endl;
			}
			fstream fin;
			string s;
			char *copys;
			int count=0;
			fin.open(name, fstream::in);
			if(!fin.is_open()) {
				delete[] List;
				delete[] NList;
				fout.close();
				fin.close();
				throw 1.0;
			}
			for (int i = 1, j = 0; i < 5*n+1 ; i++){
				s="";
				getline(fin,s);
				if(i%5!=0){
					if(count==0){
						copys=new char[s.length()+1];
						strcpy(copys,s.c_str());
						NList[j].FSetFio(copys,s.length());
						delete[] copys;
						count++;
						continue;
					}
					if(count==1){
						copys=new char[s.length()+1];
						strcpy(copys,s.c_str());
						NList[j].FSetDol(copys,s.length());
						delete[] copys;
						count++;
						continue;
					}
					if(count==2){
						NList[j].FSetWage(stod(s));
						count++;
						continue;
					}
					if(count==3){
						NList[j].FSetYear(stoi(s));
						j++; count=0;
						continue;
					}
				}
			}
			fstream fout2;
			string name2="Result.txt";
			fout2.open(name2,fstream::out | fstream::trunc);
			if(!fout2.is_open()) {
				delete[] List;
				delete[] NList;
				fout.close();
				fin.close();
				fout2.close();
				throw 1;
			}
			cout<<"Список работников, стаж работы которых на данном предприятии превышает заданное число лет: "<<endl;
			for(int i=0;i<n;i++){
				if(2020-NList[i].GetYear()>k){
					string S=NList[i].GetFio();
					cout<<S<<"\n";
					fout2<<S<<"\n";
				}
			}
			delete[] List;
			delete[] NList;
			fout2.close();
			fout.close();
			fin.close();
		}
		catch(int){
			cerr<<"Файла с таким именем не существует( процесс записи в файл)!"<<endl;
			return;
		}
		catch(double){
			cerr<<"Файла с таким именем не существует( процесс чтения из файла)!"<<endl;
			return;
		}
		catch(...){
			cerr<<"Неизвестная ошибка!"<<endl;
			return;
		}
};
void Task12(){
	try
		{
			fstream fout;
			string name="Data2.txt";
			fout.open(name,fstream::out | fstream::trunc);
			if(!fout.is_open()) {
				fout.close();
				throw 1;
			}
			Worker *List,*NList;
			int n,k,a=0;
			cout<<"Введите количество работников: "; cin>>n;
			cout<<"Введите зарплату: "; cin>>k;
			List=new Worker[n];
			NList=new Worker[n];
			for(int i=0;i<n;i++){
				cout<<"Данные о работнике № "<<i+1<<endl;
				List[i].set();
				fout<<List[i].GetFio()<<endl<<List[i].GetDol()<<endl<<List[i].GetWage()<<endl<<List[i].GetYear()<<endl<<endl;
			}
			fstream fin;
			string s;
			char *copys;
			int count=0;
			fin.open(name, fstream::in);
			if(!fin.is_open()) {
				delete[] List;
				delete[] NList;
				fout.close();
				fin.close();
				throw 1.0;
			}
			for (int i = 1, j = 0; i < 5*n+1 ; i++){
				s="";
				getline(fin,s);
				if(i%5!=0){
					if(count==0){
						copys=new char[s.length()+1];
						strcpy(copys,s.c_str());
						NList[j].FSetFio(copys,s.length());
						delete[] copys;
						count++;
						continue;
					}
					if(count==1){
						copys=new char[s.length()+1];
						strcpy(copys,s.c_str());
						NList[j].FSetDol(copys,s.length());
						delete[] copys;
						count++;
						continue;
					}
					if(count==2){
						NList[j].FSetWage(stod(s));
						count++;
						continue;
					}
					if(count==3){
						NList[j].FSetYear(stoi(s));
						j++; count=0;
						continue;
					}
				}
			}
			fstream fout2;
			string name2="Result2.txt";
			fout2.open(name2,fstream::out | fstream::trunc);
			if(!fout2.is_open()) {
				delete[] List;
				delete[] NList;
				fout.close();
				fin.close();
				fout2.close();
				throw 1;
			}
			cout<<"Список работников, зарплата которых больше заданной: "<<endl;
			for(int i=0;i<n;i++){
				if(NList[i].GetWage()>k){
					string S=NList[i].GetFio();
					cout<<S<<"\n";
					fout2<<S<<"\n";
				}
			}
			delete[] List;
			delete[] NList;
			fout2.close();
			fout.close();
			fin.close();
		}
		catch(int){
			cerr<<"Файла с таким именем не существует( процесс записи в файл)!"<<endl;
			return;
		}
		catch(double){
			cerr<<"Файла с таким именем не существует( процесс чтения из файла)!"<<endl;
			return;
		}
		catch(...){
			cerr<<"Неизвестная ошибка!"<<endl;
			return;
		}
};
void Task13(){
	try
		{
			fstream fout;
			string name="Data3.txt",A;
			fout.open(name,fstream::out | fstream::trunc);
			if(!fout.is_open()) {
				fout.close();
				throw 1;
			}
			Worker *List,*NList;
			int n,a=0;
			cout<<"Введите количество работников: "; cin>>n;
			cout<<"Введите заданную должность: "; cin>>A;
			List=new Worker[n];
			NList=new Worker[n];
			for(int i=0;i<n;i++){
				cout<<"Данные о работнике № "<<i+1<<endl;
				List[i].set();
				fout<<List[i].GetFio()<<endl<<List[i].GetDol()<<endl<<List[i].GetWage()<<endl<<List[i].GetYear()<<endl<<endl;
			}
			fstream fin;
			string s;
			char *copys;
			int count=0;
			fin.open(name, fstream::in);
			if(!fin.is_open()) {
				delete[] List;
				delete[] NList;
				fout.close();
				fin.close();
				throw 1.0;
			}
			for (int i = 1, j = 0; i < 5*n+1 ; i++){
				s="";
				getline(fin,s);
				if(i%5!=0){
					if(count==0){
						copys=new char[s.length()+1];
						strcpy(copys,s.c_str());
						NList[j].FSetFio(copys,s.length());
						delete[] copys;
						count++;
						continue;
					}
					if(count==1){
						copys=new char[s.length()+1];
						strcpy(copys,s.c_str());
						NList[j].FSetDol(copys,s.length());
						delete[] copys;
						count++;
						continue;
					}
					if(count==2){
						NList[j].FSetWage(stod(s));
						count++;
						continue;
					}
					if(count==3){
						NList[j].FSetYear(stoi(s));
						j++; count=0;
						continue;
					}
				}
			}
			fstream fout2;
			string name2="Result3.txt";
			fout2.open(name2,fstream::out | fstream::trunc);
			if(!fout2.is_open()) {
				delete[] List;
				delete[] NList;
				fout.close();
				fin.close();
				fout2.close();
				throw 1;
			}
			cout<<"Список работников, занимающих заданную должность: "<<endl;
			for(int i=0;i<n;i++){
				if(strcmp(NList[i].GetDol(),A.c_str())==0){
					string S=NList[i].GetFio();
					cout<<S<<"\n";
					fout2<<S<<"\n";
				}
			}
			delete[] List;
			delete[] NList;
			fout2.close();
			fout.close();
			fin.close();
		}
		catch(int){
			cerr<<"Файла с таким именем не существует( процесс записи в файл)!"<<endl;
			return;
		}
		catch(double){
			cerr<<"Файла с таким именем не существует( процесс чтения из файла)!"<<endl;
			return;
		}
		catch(...){
			cerr<<"Неизвестная ошибка!"<<endl;
			return;
		}
};
void Task21(){
	try{
		/*Polynom p1,p2,p3;
			cout << "Выполнить первую часть?( 1-да );"<<endl;
			if (_getch() == '1') {
				cin >> p1;
				cout << " f(x) = ";  cout << p1;
				cin >> p2;
				cout << " g(x) = "; cout << p2;
				p3.SumShow(p1, p2);
				p3.AntiSumShow(p1, p2);
				p3.MultShow(p1, p2);
			}*/
		fstream fin;
		string name="Data4.txt";
		string s;
		fin.open(name, fstream::in);
		if(!fin.is_open()) {
			fin.close();
			throw 1.0;
		}
		int number=0,countElem=0,i=0,_count=0;
		while (!fin.eof()){
			s="";
			getline(fin,s);
			if(s==""){
				_count++;
			}
		}
		fin.close();
		fstream fin2;
		fin2.open(name, fstream::in);
		if(!fin2.is_open()) {
			fin2.close();
			throw 1.0;
		}
		Polynom **Poly=new Polynom*[_count];
		while (!fin2.eof()){
			s="";
			getline(fin2,s);
			if(s!=""){
				countElem++;
			}
			else{
				Poly[i]=new Polynom(countElem-1);
				countElem=0; i++;
			}
		}
		i=0;
		fin2.close();
		int j=0;
		fstream fin3;
		fin3.open(name, fstream::in);
		if(!fin3.is_open()) {
			for (int i = 0; i < _count; i++){
				delete Poly[i];
			}
			delete[] Poly;
			fin3.close();
			throw 1.0;
		}
		while (!fin3.eof()){
			s="";
			getline(fin3,s);
			if(s!=""){
				Poly[i]->SetPolyCoef(stod(s),j);
				j++;
			}
			if(s==""){
				i++;
				j=0;
			}
		}
		fin3.close();
		for (int i = 0; i < _count; i++){
			cout<<*(Poly[i])<<endl;
		}
		fstream fout;
		string name2="Result4.txt";
		fout.open(name2,fstream::out | fstream::trunc);
		if(!fout.is_open()) {
			for (int i = 0; i < _count; i++){
				delete Poly[i];
			}
			delete[] Poly;
			fout.close();
			throw 1;
		}
		fout<<SumOfElem(Poly,_count)<<endl;
		cout<<"Сумма полиномов:\n"<<SumOfElem(Poly,_count)<<endl;
		fout.close();
		for (int i = 0; i < _count; i++){
			delete Poly[i];
		}
		delete[] Poly;
	}
	catch(int){
		cout<<"Ошибка открытия файла при записи в файл!"<<endl;
		return;
	}
	catch(double){
		cout<<"Ошибка открытия файла при чтении из файла!"<<endl;
		return;
	}
	catch(...){
		cout<<"Неизвестная ошибка!"<<endl;
		return;
	}
};
void Task31(){
	try{
		List K;
		int n=0; 
		double data=0;
		fstream fout;
		string name="Data5.txt";
		fout.open(name, fstream::trunc | fstream::out);
		if(!fout.is_open()) {
			cout<<"ERROR"<<endl;
			fout.close();
			throw 1;
		}
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
		fin.open(name, fstream::in);
		if(!fin.is_open()) {
			cout<<"ERROR"<<endl;
			fin.close();
			throw 1.0;
		}
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
		fstream fout2;
		string name2="Result5.txt";
		fout2.open(name2, fstream::trunc | fstream::out);
		if(!fout2.is_open()) {
			cout<<"ERROR"<<endl;
			fout2.close();
			fin.close();
			throw 1;
		}
		for (int i = 0; i < n; i++){
			fout2<<K[i]<<" ";
			if(i==n-1) cout<<"\n";
		}
		cout<<endl;
		fout2.close();
		fin.close();
	}
	catch(int){
		cout<<"Ошибка открытия файла при записи в файл!"<<endl;
		return;
	}
	catch(double){
		cout<<"Ошибка открытия файла при чтении из файла!"<<endl;
		return;
	}
	catch(...){
		cout<<"Неизвестная ошибка!"<<endl;
		return;
	}
};

Polynom SumOfElem(Polynom **Arr, int number) {
	int maxlen=0;
	for (int i = 0; i<number; i++) {
		if(maxlen<Arr[i]->GetDegree()){
			maxlen=Arr[i]->GetDegree();
		}
	}
	Polynom Sum(maxlen);
	for (int i = 0; i<number; i++) {
		/*Sum.SetPolyCoef(*/
		Sum=Sum+*(Arr[i]);
	}
	return Sum;
};
