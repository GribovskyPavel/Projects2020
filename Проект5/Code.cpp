#include <iostream>
#include <string>
#include <Windows.h>
#include <Time.h>
using namespace std;

class Learner
{
public:
	virtual void Set()=0;
	virtual string GetName()=0;
	virtual int GetClass()=0;
	virtual void Show()=0;
};

class Pupil: public Learner
{
	string Name;
	int Class;
public:
	Pupil()
	{
		this->Name="";
		this->Class=0;
	}
	Pupil(string Name)
	{
		this->Name=Name;
		this->Class=0;
	}
	Pupil(string Name,int Class)
	{
		this->Name=Name;
		this->Class=Class;
	}
	void Set() override
	{
		cout<<"Введите новое имя объекта класса Pupil: "; cin>>this->Name;
		cout<<"Введите новую группу объекта класса Pupil: "; cin>>this->Class;
		cout<<endl;
	};
	string GetName() override
	{
		return this->Name;	
	};
	int GetClass() override
	{
		return this->Class;
	};
	void Show() override
	{
		cout<<"Имя объекта Pupil: "<<GetName()<<endl;
		cout<<"Номер группы объекта "<<GetName()<<": "<<GetClass()<<endl<<endl;
	};
};

class Student: public Learner
{
	string Name;
	int Group;
public:
	Student()
	{
		this->Name="";
		this->Group=0;
	}
	Student(string Name)
	{
		this->Name=Name;
		this->Group=0;
	}
	Student(string Name,int Group)
	{
		this->Name=Name;
		this->Group=Group;
	}
	void Set() override
	{
		cout<<"Введите новое имя объекта класса Student: ";cin>>this->Name;
		cout<<"Введите новую группу объекта класса Student: "; cin>>this->Group;
		cout<<endl;
	};
	string GetName() override
	{
		return this->Name;
	};
	int GetClass() override
	{
		return this->Group;
	};
	void Show() override
	{
		cout<<"Имя объекта Student: "<<GetName()<<endl;
		cout<<"Номер группы объекта "<<GetName()<<": "<<GetClass()<<endl<<endl;
	};
};


class RealLearner
{
	string Name;
public:
	RealLearner()
	{
		this->Name="";
	}
	RealLearner(string Name)
	{
		this->Name=Name;
	}
	virtual void Set(){
		cout<<"Введите новое имя объекта класса RealLearner: ";cin>>this->Name;
		cout<<endl;
	};
	void SetName(string Name){
		this->Name=Name;
	};
	virtual string GetName(){
		return this->Name;
	};
	virtual void Show(){
	cout<<"Имя объекта RealLearner: "<<GetName()<<endl;
	};
};

class RealPupil: public RealLearner
{
	int Class;
public:
	RealPupil(int Class=0) 
	{
		this->Class= Class;
	}
	RealPupil(string Name,int Class=0) 
	{
		this->Class= Class;
		::RealLearner::SetName(Name);
	}
	void Set() override
	{
		cout<<endl<<"RealPupil"<<endl;
		::RealLearner::Set();
		cout<<"Введите новую группу объекта класса RealPupil: "; cin>>this->Class;
		cout<<endl;
	};
	int GetClass() 
	{
		return this->Class;
	};
	void Show() override
	{
		cout<<endl<<"RealPupil"<<endl;
		::RealLearner::Show();
		cout<<"Номер группы объекта "<<GetName()<<": "<<GetClass()<<endl;
	};
};

class RealStudent: public RealLearner
{
	int Group;
public:
	RealStudent(int Group=0)
	{
		this->Group=Group;
	}
	RealStudent(string Name,int Group=0) 
	{
		this->Group= Group;
		::RealLearner::SetName(Name);
	}
	void Set() override
	{
		cout<<endl<<"RealStudent"<<endl;
		::RealLearner::Set();
		cout<<"Введите новую группу объекта класса RealStudent: "; cin>>this->Group;
		cout<<endl;
	};
	int GetClass()
	{
		return this->Group;
	};
	void Show() override
	{
		cout<<endl<<"RealStudent"<<endl;
		::RealLearner::Show();
		cout<<"Номер группы объекта "<<GetName()<<": "<<GetClass()<<endl;
	};
};


class Stroka
{
	char *str;
protected:
	int len;
public:
	Stroka()
	{
		this->len=0;
		this->str=new char[len+1];
		this->str='\0';
	}
	Stroka(char *Arr)
	{
		this->len=strlen(Arr);
		this->str=new char[len+1];
		for (int i = 0 ; i < len+1 ; i++){
			str[i]=Arr[i];
		}
	}
	Stroka(const Stroka &otherStroka)
	{
		this->len=otherStroka.len;
		this->str=new char[len+1];
		for (int i = 0 ; i < len+1 ; i++){
			str[i]=otherStroka.str[i];
		}
	}
	int GetLen(){
		return this->len;
	};
	void Show(){
		for (int i = 0; i < len ; i++)
			{
				if(str==NULL) break;
				cout<<str[i];
			}
		cout<<endl;
	};
	void Clear(){
		delete[] str;
		this->str='\0';
		this->len=0;
	};
	virtual ~Stroka(){
		delete[] str;
	};
};

class ByteStroka: public Stroka
{
	char *bstr;
public:
	ByteStroka()
	{
		this->len=0;
		this->bstr=new char[len+1];
		this->bstr='\0'; 
	}
	ByteStroka(char *Arr)
	{
		this->len=strlen(Arr);
		this->bstr=new char[len+1];
		for (int i = 0; i < len+1 ; i++)
		{
			bstr[i]=Arr[i];
		}
		for (int i = 0; i < len ; i++)
		{
			if(bstr[i]!='0' && bstr[i]!='1') {
				delete[] bstr;
				this->bstr='\0'; 
				this->len=0; 
				break;
			}
		}
	}
	ByteStroka(const ByteStroka &otherByteStroka)
	{
		this->len=otherByteStroka.len;
		this->bstr=new char[len+1];
		for (int i = 0 ; i < len+1 ; i++){
			bstr[i]=otherByteStroka.bstr[i];
		}
	}

	ByteStroka& operator=(const ByteStroka &b){
		this->len=b.len;
		if(this->bstr!=NULL){
			delete[] this->bstr;
		}
		this->bstr=new char[len+1];
		for (int i = 0 ; i < len+1 ; i++){
			bstr[i]=b.bstr[i];
		}
		return *this;
	}; 
	bool operator==(const ByteStroka &b){
		if(this->len==b.len){
			for (int i = 0; i < len; i++){
				if(this->bstr[i]==b.bstr[i]){
					continue;
				}
				else{
					return false;
				}
			}
			return true;
		}
		else{
			return false;
		}
	};
	ByteStroka operator+(const ByteStroka &b){
		int sum=0,newlen=0;
		char *c;
		for (int i = 0; i < this-> len; i++){
			sum+=((int)this->bstr[i]-48)*pow(2,this->len-1-i);
		}
		for (int i = 0; i < b.len; i++){
			sum+=((int)b.bstr[i]-48)*pow(2,b.len-1-i);
		}
		for (int i = 0;;i++){
			if(sum>=pow(2,i)){
				continue;
			}
			else{
				newlen=i;
				break;
			}
		}
		c=new char[newlen+1];
		for (int i = 0;i < newlen+1; i++){
			if(i==newlen) {c[i]='\0';break;}
			c[newlen-1-i]='0'+sum%2;
			sum/=2;
		}
		ByteStroka newb(c);
		delete[] c;
		return newb;
	};

	int GetBinNum(){
		if(this->bstr!=NULL) return atoi(bstr);
		else return 0;
	};
	int GetNegBinNum(){
		if(this->bstr!=NULL){
		for (int i = 0; i < len; i++){
			if(bstr[i]=='0'){bstr[i]='1';}
			else {bstr[i]='0';}
		}
		for (int i = 0; i < len; i++){
			if(bstr[len-1-i]=='1'){
				bstr[len-1-i]='0';
				continue;
			}
			if(bstr[len-1-i]=='0'){
				bstr[len-1-i]='1'; break;
			}
		}
		return atoi(bstr);
		}
		else return 0;
	};
	~ByteStroka() override
	{
		delete[] bstr;
	};
};

void main(){
	setlocale(LC_CTYPE,"rus");
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Student st1("Николай",5);
	Student st2("Вадим",10);
	Pupil p1("Игнат",1);
	Pupil p2("Алексей",3);

	st1.Show();
	st2.Show();
	p1.Show();
	p2.Show();
	
	RealLearner r("Дмитрий");
	RealStudent rs("Аркадий",12);
	RealPupil rp("Феофан",6);
	r.Show();
	rs.Show();
	rp.Show();

	int n=0,ran=0;
	cout<<endl<<"Введите количество элементов массива объектов класса RealLearner: ";
	cin>>n; cout<<endl;
	RealLearner **A=new RealLearner*[n];
	for (int i = 0; i < n; i++){
		ran=rand()%2;
		if(ran==0) {A[i]=new RealStudent;continue;}
		if(ran==1) {A[i]=new RealPupil;continue;}
	}
	for (int i = 0; i < n; i++){
		A[i]->Set();
	}
	cout<<"Объекты исходного массива, которые принадлежат классу RealStudent:"<<endl;
	for (int i = 0; i < n; i++){
		if(dynamic_cast<RealStudent*>(A[i])){
			A[i]->Show();
		}
	}
	cout<<endl<<"Объекты исходного массива, которые принадлежат классу RealPupil:"<<endl;
	for (int i = 0; i < n; i++){
		if(dynamic_cast<RealPupil*>(A[i])){
			A[i]->Show();
		}
	}
	for (int i = 0; i < n; i++){
		delete A[i];
	}
	delete[] A;

	cout<<endl;
	Stroka s("Проверка");
	s.Show();
	Stroka s1(s);
	s1.Show();

	s1.Clear();
	s1.Show();

	ByteStroka a("1щfyjор");
	ByteStroka b("101100");
	ByteStroka c("1011000010");
	cout<<a.GetBinNum()<<endl;
	cout<<a.GetNegBinNum()<<endl;
	cout<<b.GetBinNum()<<endl;
	cout<<b.GetNegBinNum()<<endl;
	
	b=c;
	cout<<b.GetBinNum()<<endl;

	if(b==c){
		cout<<"Объекты равны"<<endl;
	}
	else cout<<"Объекты не равны"<<endl;
	if(a==c){
		cout<<"Объекты равны"<<endl;
	}
	else cout<<"Объекты не равны"<<endl;

	ByteStroka b1("101011");
	ByteStroka b2("10111");
	ByteStroka bres("");
	bres=b1+b2;
	cout<<bres.GetBinNum()<<endl;

	system("pause");
}