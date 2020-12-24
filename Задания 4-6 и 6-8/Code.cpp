#include <iostream>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <string>
#define twefo 24
#define sixty 60
using namespace std;
void FormatOut(int hour,int min,int sec);

class Vector{
	int n;
	int* N;
public:
	void Set_n(int othern){n=othern;}
	int Get_n(){return n;}
	int GetNElem(int i){return N[i];}
	void ShowVec(int i){
		if(i==0) cout<<"( ";
		cout<<N[i]<<" ";
		if(i==n-1) cout<<")"<<endl;
	};
	void ShowVecAll(int n){
		for(int i=0;i<n;i++){
		if(i==0) cout<<"( ";
		cout<<N[i]<<" ";
		if(i==n-1) cout<<")"<<endl;
		}
	};
	double LenghtVec(){
	int len=0;
	for(int i=0;i<n;i++){
		len+=N[i]*N[i];
	}
	return len;
};
	Vector (const Vector &other){
	this->n=other.n;
	this->N=new int[n];
	for (int i = 0; i < n; i++){
		this->N[i]=other.N[i];
		}
	};
	Vector& operator =(const Vector &other){
		this->n=other.n;
		delete[] this->N;
		this->N=new int[n];
	for (int i = 0; i < n; i++){
		this->N[i]=other.N[i];
	}
	return *this;
	};
	Vector(int othern=3){
		Set_n(othern);
		N=new int[n];
		cout<<"Введите координаты вектора: "<<endl;
		for(int i=0;i<n;i++){
			cout<<"Элемент вектора ["<<i<<"]: ";
			cin>>N[i];
		}
		ShowVecAll(n);
	}
	Vector(int othern,int reg){
		Set_n(othern);
		N=new int[n];
		cout<<endl;
		for(int i=0;i<n;i++){
			N[i]=rand()%reg;
			ShowVec(i);
		}
	}
	~Vector(){
	 delete []N;
	};
	friend ostream& operator<<(ostream& os,const Vector &v){
		for(int i=0;i<v.n;i++){
		if(i==0) os<<"( ";
		os<<v.N[i]<<" ";
		if(i==(v.n-1)) os<<")";
		}
		return os;
	};
	friend istream& operator>>(istream& is,Vector &v){
		cout<<"Введите координаты вектора: "<<endl;
		for(int i=0;i<v.n;i++){
			cout<<"Элемент вектора ["<<i<<"]: ";
			is>>v.N[i];
		}
		return is;
	};
};

class Time{
	string S;
	int sec;
	int min;
	int hour;
public:
	Time() {
		this->hour = 0;
		this->min = 0;
		this->sec = 0;
	};
	Time(int hour1,int min1, int sec1){
	this->hour=hour1;
	this->min=min1;
	this->sec=sec1;
	if(sec>sixty-1){
			while(1){
				if(sec<sixty) break;
				this->sec=sec-sixty; this->min++;
			}
	};
	if(min>sixty-1){
			while(1){
				if(min<sixty) break;
				this->min=min-sixty; this->hour++;
			}
	};
	if(hour> twefo-1){
			while(1){
				if(hour< twefo) break;
				this->hour=hour- twefo;
			}
	};
	FormatOut(hour,min,sec);
	};
	Time(int sec1){
		this->hour=0;
	    this->min=0;
		if(twefo * sixty * sixty<=sec1) {
			while(1){
				if (sec1<twefo * sixty * sixty) break;
				sec1 = sec1 - twefo * sixty * sixty;
			}
		}; 
		if(sixty * sixty<=sec1 && sec1<twefo * sixty * sixty) {
			int s=sec1;
			while(1){
				if (s - sixty * sixty >= 0) { s = s - sixty * sixty; this->hour++; }
				else {
					if (s == 0) break;
						while(1){
						if (s == 0) break;
						if (s - sixty >= 0) { s = s - sixty; this->min++; }
						else { this->sec = s; break;}
					}
					this->sec = s;
					if(s<sixty) break;
				}
			}
			FormatOut(hour,min,sec);
		}
		if(sixty<=sec1 && sec1<sixty * sixty){
			int s=sec1;
			while(1){
				if(s<sixty) break;
				if(s-sixty>=0){s=s-sixty; this->min++;}
				else{ this->sec=s; break; }
			}
			this->sec=s;

			if (min>=10 && sec>=10) cout << "00:" << min << ":" << sec << endl;
			if (sec<10 && min >= 10) cout << "00:" << min << ":0" << sec << endl;
			if (min<10 && sec >= 10) cout << "00:0" << min << ":" << sec << endl;
			if (min<10 && sec<10) cout << "00:0" << min << ":0" << sec<<endl;
		}
		if (0 <= sec1 && sec1 < sixty) {
			int s=sec1;
			this->sec = s;
			if (s>9) {
				cout << "00:00:" << sec << endl;
		    }
			else {
				cout << "00:00:0" << sec << endl;
			}
		};
	};
	Time(string S) {
		if(S.length()!=8) cout << "Строка должна иметь длину 8 символов!" << endl;
		string S_H = S.substr(0,2);
		string S_M = S.substr(3,2);
		string S_S = S.substr(6,2);
		this->hour=stoi(S_H);
		this->min=stoi(S_M);
		this->sec=stoi(S_S);
		if(sec>sixty-1){
			while(1){
				if(sec<sixty) break;
				this->sec=this->sec-sixty; this->min++;
			}
		};
		if(min>sixty-1){
			while(1){
				if(min<sixty) break;
				this->min=this->min-sixty; this->hour++;
			}
		};
		if(hour>twefo-1){
			while(1){
				if(hour<twefo) break;
				this->hour=this->hour-twefo;
			}
		};
		FormatOut(hour,min,sec);
	};
	Time(const Time &other) {
		this->hour = other.hour;
		this->min = other.min;
		this->sec = other.sec;
		this->S = other.S;
	};
	Time& operator = (const Time &other) {
		this->hour = other.hour;
		this->min = other.min;
		this->sec = other.sec;
		this->S = other.S;
		return *this;
	};
	friend Time operator -(const Time t1, const Time t2);
	friend Time operator +(const Time t1, const Time t2);
	friend Time operator -(const Time t1, int t2);
	friend Time operator +(const Time t1, int t2);
	bool operator ==(const  Time& t2){
		return this->sec ==t2.sec && this->min ==t2.min && this->hour ==t2.hour;
	};
	bool operator !=(const  Time& t2){
		return !(this->sec ==t2.sec && this->min ==t2.min && this->hour ==t2.hour);
	};
	bool operator <(const  Time& t2){
		int time1 = sixty * sixty * this->hour + sixty * this->min + this->sec;
		int time2 = sixty * sixty * t2.hour + sixty * t2.min + t2.sec;
		return time1<time2;
	};
	bool operator >(const  Time& t2){
		int time1 = sixty * sixty * this->hour + sixty * this->min + this->sec;
		int time2 = sixty * sixty * t2.hour + sixty * t2.min + t2.sec;
		return time1>time2;
	};
	int Time2Sec(){
		return this->hour*sixty*sixty+this->min*sixty+this->sec;
	};
	int Time2MinFix(){
		int tmin = this->hour*sixty+this->min;
		if(this->sec>30){
			tmin++;
		}
		return tmin;
	};
};

Time operator -(const Time t1, const Time t2) {
	int sec1 = sixty * sixty * t1.hour + sixty * t1.min + t1.sec;
	int sec2 = sixty * sixty * t2.hour + sixty * t2.min + t2.sec;
	cout <<"Разница между двумя моментами времени в секундах: "<< abs(sec1-sec2) << endl;
	return Time(abs(sec1-sec2));
};
Time operator +(const Time t1, const Time t2){
	int time1 = sixty * sixty * t1.hour + sixty * t1.min + t1.sec;
	int time2 = sixty * sixty * t2.hour + sixty * t2.min + t2.sec;
	cout <<"Сложение времени и заданного количества секунд: "<< time1+time2 << endl;
	return Time(time1+time2);
};
Time operator -(const Time t1, int t2){
	int sec1 = sixty * sixty * t1.hour + sixty * t1.min + t1.sec;
	int sec2 =t2;
	cout <<"Разница между двумя моментами времени в секундах: "<< abs(sec1-sec2) << endl;
	return Time(abs(sec1-sec2));
};
Time operator +(const Time t1, int t2){
	int time1 = sixty * sixty * t1.hour + sixty * t1.min + t1.sec;
	int time2 = t2;
	cout <<"Сложение времени и заданного количества секунд: "<< time1+time2 << endl;
	return Time(time1+time2);
};

void CollOrOrt(Vector v1,Vector v2, bool bl);
double DistTwoP(double x1,double y1, double x2, double y2);
bool Is_It_Triangle(double *X,double *Y);

class Matrix{
	int n;
	int **N;
public:
	Matrix(int n, int range=10){
		this->n=n;
		N=new int*[n];
		for (int i = 0; i < n; i++){
			N[i]=new int[n];
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				N[i][j]=rand()%range;
			}
		}
	}
	int GetN(){
	return this->n;
	};
	int FirstNorm(){
		int max=0;
		int* I=new int[n]; 
		for (int i = 0; i < n; i++){
			I[i]=0;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				I[i]+=N[i][j];
			}
		}
		for (int i = 0; i < n; i++){
			if(I[i]>max){max=I[i];}
		}
		delete[] I;
		return max;
	};
	int SecondNorm(){
		int max=0;
		int* I=new int[n]; 
		for (int i = 0; i < n; i++){
			I[i]=0;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				I[i]+=N[j][i];
			}
		}
		for (int i = 0; i < n; i++){
			if(I[i]>max){max=I[i];}
		}
		delete[] I;
		return max;
	};
	void Show(){
		cout<<endl;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cout<<N[i][j]<<"  ";
			}
			cout<<endl;
		}
	};
	~Matrix(){
		for (int i = 0; i < n; i++){
			delete[] N[i];
		}
		delete[] N;
	};
};

class Triangle{
	double X[3];
	double Y[3];
public:
	Triangle(int r=10){
		for (int i = 0; i < 3; i++){
			X[i]=rand()%r;
			Y[i]=rand()%r;
		}
		for (int i = 0;; i++){
			if(Is_It_Triangle(X,Y)){
				break;
			}
			else{
				X[i]=rand()%r;
				Y[i]=rand()%r;
			}
		}
	}
	Triangle(bool b,int r=10){
		if(b==true){
			for (int i = 0; i < 3; i++){
				X[i]=rand()%r;
				Y[i]=rand()%r;
			}
			for (int i = 0;; i++){
				if(Is_It_Triangle(X,Y)){
					break;
				}
				else{
					X[i]=rand()%r;
					Y[i]=rand()%r;
				}
			}
		}
		else{
			cout<<endl<<"Инициализация вершин "<<3<<"-угольника"<<endl; 
			for (int i = 0; i < 3; i++){
				cout<<"Координата х"<<i+1<<": "; cin>>X[i];
				cout<<"Координата y"<<i+1<<": "; cin>>Y[i]; cout<<endl;
			}
			for (int i = 0;; i++){
				if(Is_It_Triangle(X,Y)){
					break;
				}
				else{
					cout<<"Введенный треугольник вырожденный!"<<endl<<"Введите новые координаты:"<<endl;
					for (int i = 0; i < 3; i++){
						cout<<"Координата х"<<i+1<<": "; cin>>X[i];
						cout<<"Координата y"<<i+1<<": "; cin>>Y[i]; cout<<endl;
					}
				}
			}
		}
	}

	void Set(double *X,double *Y,int n){
		this->X[0]=X[0];
		this->X[1]=X[1+n];
		this->X[2]=X[2+n];
		this->Y[0]=Y[0];
		this->Y[1]=Y[1+n];
		this->Y[2]=Y[2+n];
	};
	void Show(){
		cout<<endl<<"Координаты вершин по оси х исходного многоугольника: ";
		for (int i = 0; i < 3; i++){
			cout<<X[i]<<"  ";
		}
			cout<<endl<<"Координаты вершин по оси y исходного многоугольника: ";
		for (int i = 0; i < 3; i++){
			cout<<Y[i]<<"  ";
		}
		cout<<endl;
	};
	double Square(){
		double term1=0,term2=0;
		double res=0;
		for (int i = 0; i < 3; i++){
			if(i==2){
				term1+=X[i]*Y[0];
				term2+=X[0]*Y[i];
			}
			else{
				term1+=X[i]*Y[i+1];
				term2+=Y[i]*X[i+1];
			}
		}
		res=abs(term1-term2)/2.;
		return res;
	};
	virtual ~Triangle(){}
};

class N_angle: public Triangle
{
	int n;
	double *X;
	double *Y;
public:
	N_angle(int n,int r=10)
	{
		this->n=n;
		X=new double[n];
		Y=new double[n];
		for (int i = 0; i < n; i++){
			X[i]=rand()%r;
			Y[i]=rand()%r;
		}
	}
	N_angle(int n, bool b,int r=10){
		this->n=n;
		X=new double[n];
		Y=new double[n];
		if(b==true){
			for (int i = 0; i < n; i++){
				X[i]=rand()%r;
				Y[i]=rand()%r;
			}
		}
		else{
			cout<<endl<<"Инициализация вершин "<<n<<"-угольника"<<endl; 
			for (int i = 0; i < n; i++){
				cout<<"Координата х"<<i+1<<": "; cin>>X[i];
				cout<<"Координата y"<<i+1<<": "; cin>>Y[i]; cout<<endl;
			}
		}
	}
	int GetN(){
		return this->n;
	};
	void Show(){
		cout<<endl<<"Координаты вершин по оси х исходного "<<n<<"-угольника: ";
		for (int i = 0; i < n; i++){
			cout<<X[i]<<"  ";
		}
			cout<<endl<<"Координаты вершин по оси y исходного "<<n<<"-угольника: ";
		for (int i = 0; i < n; i++){
			cout<<Y[i]<<"  ";
		}
		cout<<endl;
	};
	double HardSquare(){
		double sum=0;
		Triangle* T=new Triangle[n-2];
		for (int i = 0; i < n-2; i++){
			T[i].Set(X,Y,i);
		}
		for (int i = 0; i < n-2; i++){
			sum+=T[i].Square();
		}
		delete[] T;
		return sum;
	};

	~N_angle() override
	{
		delete[] X;
		delete[] Y;
	}
};

class Pair{
	int a;
	int b;
public:
	Pair()
	{
		this->a=0;
		this->b=0;
	}
	Pair(int a, int b)
	{
		this->a=a;
		this->b=b;
	}

	Pair operator+(const Pair& p){
		Pair P;
		P.a=this->a+p.a;
		P.b=this->b+p.b;
		return P;
	};
	Pair operator*(int p){
		Pair A;
		A.a=this->a*p;
		A.b=this->b*p;
		return A;
	};
	
	int GetA(){
		return this->a;
	};
	int GetB(){
		return this->b;
	};
	void Set(int a, int b){
		this->a=a;
		this->b=b;
	};
	void virtual Show(){
		cout<<endl<<"Первое число объекта: "<<a<<endl<<"Bторое число объекта: "<<b<<endl;
	};
};

class Money: public Pair
{
	int rub;
	int kop;
public:
	Money()
	{
		this->rub=0;
		this->kop=0;
	}
	Money(int sum){
		this->rub=0;
		this->kop=0;
		if(sum>=100){
			while (true){
				if(sum>=100){
					sum=sum-100;
					this->rub++;
				}
				else{
				this->kop=sum;
					break;
				}
			}
		}
		else{
			this->rub=0;
			this->kop=sum;
		}
	}
	Money(int rub, int kop)
	{
		this->rub=abs(rub);
		if(abs(kop)>=100){
			int buf1=abs(kop);
			for (int i = 0;; i++){
				if(buf1>=100){
					buf1=buf1-100;
					this->rub++;
				}
				else{
					this->kop=buf1;
					break;
				}
			}
		}
		else{
			this->kop=abs(kop);
		}
	}
	int GetRub(){
		return this->rub;
	};
	int GetKop(){
		return this->kop;
	};
	void Show() override
	{
		cout<<endl<<"Рубли объекта: "<<rub<<endl<<"Копейки объекта: "<<kop<<endl;
	};

	Money operator+(const Money& m){
		Money M;
		M.rub=this->rub+m.rub;
		M.kop=this->kop+m.kop;
		if(M.kop>=100){
			int buf=M.kop;
			for (int i = 0 ;; i++){
				if(buf>=100){
					buf=buf-100;
					M.rub++;
				}
				else{
					M.kop=buf;
					break;
				}
			}
		}
		return M;
	}
	Money operator-(const Money& m){
		Money M;
		int kop1=100*this->rub+this->kop,kop2=100*m.rub+m.kop;
		int diff=kop1-kop2;
		if(diff>0){
			if(diff>=100){
				for (int i = 0 ;; i++){
					if(diff>=100){
						diff=diff-100;
						M.rub++;
					}
					else{
						M.kop=diff;
						break;
					}
				}
			}
			else{
				M.kop=diff;
				M.rub=0;
			}
		}
		if(diff<0){
			if(diff<=-100){
				for (int i = 0 ;; i++){
					if(diff<=-100){
						diff=diff+100;
						M.rub--;
					}
					else{
						M.kop=diff;
						break;
					}
				}
			}
			else{
				M.kop=diff;
				M.rub=0;
			}
		}
		return M;
	}
	Money operator/(int div){
		int sum=abs(100*this->rub+this->kop);
		if(sum%div==0){
			sum=sum/div;
			Money n(sum);
			return n;
		}
		else{
			cout<<"Исходная сумма не делится нацело на "<<div<<"!"<<endl;
			return *this;
		}
	};
};

class Array{
protected:
	char *C;
	int n;
public:
	Array(){
		this->n=0;
		this->C=new char[n+1];
		this->C='\0';
	}
	Array(char *Arr)
	{
		this->n=strlen(Arr);
		this->C=new char[n+1];
		for (int i = 0 ; i < n+1 ; i++){
			C[i]=Arr[i];
		}
	}
	Array(int n){
		this->n=n;
		this->C=new char[n+1];
	}
	Array(const Array & other){
		this->n=other.n;
		this->C=new char[n+1];
		for (int i = 0 ; i < n+1 ; i++){
			C[i]=other.C[i];
	    }
	}

	char operator [](int i){
		if(i>=0 && i<=n){
			return this->C[i];
		}
		else{
			cout<<"\nОтсутствует объект с заданным индексом "<<i<<"!\n";
			return '\0';
		}
	};
	Array & operator =(const Array& other){
		this->n=other.n;
		if(C!=NULL){
			delete[] C;
		}
		this->C=new char[n+1];
		for (int i = 0 ; i < n+1 ; i++){
			C[i]=other.C[i];
	    }
		return *this;
	};
	virtual Array operator+(Array& other){
		int max=0,min=0;
		if(this->GetN()>=other.n){
			max=this->GetN();
			min=other.n;
			Array a(max);
			for (int i = 0; i < min; i++){
				a.Init((char)(other.C[i]+this->C[i]),i);
				if(other.C[i]+this->C[i]<32){
					a.Init(' ',i);
				}
			}
			for (int i = min; i < max+1; i++){
				a.Init(this->C[i],i);
			}
			return a;
		}
		else{
			max=other.n;
			min=this->GetN();
			Array b(max);
			for (int i = 0; i < min; i++){
				b.Init((char)(other.C[i]+this->C[i]),i);
				if(other.C[i]+this->C[i]<32){
					b.Init(' ',i);
				}
			}
			for (int i = min; i < max+1; i++){
				b.Init(other.C[i],i);
			}
			return b;
		}
	};

	void Init(char c,int i){
		this->C[i]=c;
	};
	void Set(char *Arr){
		delete[] C;
		this->n=strlen(Arr);
		this->C=new char[n+1];
		for (int i = 0 ; i < n+1 ; i++){
			C[i]=Arr[i];
		}
	};
	int GetN(){
		return this->n;
	};
	char GetElem(int i){
		return this->C[i];
	};
	void Show(){
		for (int i = 0; i < n ; i++)
				{
					if(C==NULL) break;
					cout<<C[i];
				}
			cout<<endl;
	};

	void Clear(){
		delete[] C;
		this->C='\0';
		this->n=0;
	};
	virtual ~Array()
	{
		delete[] C;
	}
};

class Octal: public Array
{
public:
	Octal(){
		this->n=0;
		if(this->C!=NULL){
			delete[] C;
		}
		this->C=new char[n+1];
		this->C='\0';
	}
	Octal(char *Arr)
	{
		this->n=strlen(Arr);
		if(this->C!=NULL){
			delete[] C;
		}
		this->C=new char[n+1];
		for (int i = 0; i < n+1 ; i++)
		{
			C[i]=Arr[i];
		}
		for (int i = 0; i < n ; i++)
		{
			if(C[i]!='0' && C[i]!='1' && C[i]!='2' && C[i]!='3' && C[i]!='4' && C[i]!='5'&& C[i]!='6' && C[i]!='7') {
				delete[] C;
				this->C='\0'; 
				this->n=0; 
				break;
			}
		}
	}

	Array operator+(Array &b) override
	{
		int sum=0,newlen=0;
		char *c;
		for (int i = 0; i < this-> n; i++){
			sum+=((int)this->C[i]-48)*pow(8,this->n-1-i);
		}
		for (int i = 0; i < b.GetN(); i++){
			sum+=((int)b.GetElem(i)-48)*pow(8,b.GetN()-1-i);
		}
		for (int i = 0;;i++){
			if(sum>=pow(8,i)){
				continue;
			}
			else{
				newlen=i;
				break;
			}
		}
		c=new char[newlen+1];
		for (int i = 0;i < newlen+1; i++){
			if(i==newlen) {
				c[i]='\0';
				break;
			}
			c[newlen-1-i]='0'+sum%8;
			sum/=8;
		}
		Array newb(c);
		delete[] c;
		return newb;
	};
	Octal& operator=(Array& ar){
		this->n=ar.GetN();
		if(this->C!=NULL){
			delete[] C;
		}
		this->C=new char[n+1];
		for (int i = 0 ; i < n+1 ; i++){
			C[i]=ar.GetElem(i);
	    }
		return *this;
	};
};

class MString: public Array
{
public:
	MString(){
	this->n=0;
		if(this->C!=NULL){
			delete[] C;
		}
		this->C=new char[n+1];
		this->C='\0';
	}
	MString(char *Arr){
		this->n=strlen(Arr);
		if(this->C!=NULL){
			delete[] C;
		}
		this->C=new char[n+1];
		for (int i = 0; i < n+1 ; i++)
		{
			C[i]=Arr[i];
		}
	}

	MString& operator=(Array& ar){
		this->n=ar.GetN();
		if(this->C!=NULL){
			delete[] C;
		}
		this->C=new char[n+1];
		for (int i = 0 ; i < n+1 ; i++){
			C[i]=ar.GetElem(i);
	    }
		return *this;
	};
	Array operator+(Array &b) override
	{
		int newlen=this->GetN()+b.GetN();
		char* S=new char[newlen+1];
		for (int i = 0; i < this->GetN(); i++){
			S[i]=this->GetElem(i);
		}
		for (int i =  this->GetN(); i < newlen+1; i++){
			if(i==newlen){
				S[i]='\0';
				break;
			}
			S[i]=b.GetElem(i-this->GetN());
		}
		Array Ar(S);
		delete[] S;
		return Ar;
	}
};

void main()
{
	srand(time(0));
	setlocale(LC_CTYPE,"rus");
	cout<<"Вариант 5"<<endl;
	cout<<"Чтобы выполнить первое задание введите - 1";
	if(_getch()=='1')
	{
		int dim=0,m=0;
		bool bl=0;
		cout<<endl<<"Введите размерность вектора: ";
		cin>>dim;
		Vector v11(dim);
		Vector v22(dim,10);

		cout<<"Введите количество векторов: ";
		cin>>m;
		Vector* VV = new Vector[m];
		cout<<endl<<"Какие векторы нужно вывести?"<<endl<<"( 1-вывод коллинеарных векторов, 0-вывод ортогональных векторов): ";
		cin>>bl;
		for (int i = 0; i < m; i++){
			for (int j = i+1 ; j < m; j++){
				CollOrOrt(VV[i],VV[j],bl);
			}
		}
		delete []VV;
    }
	cout<<endl<<"Чтобы выполнить второе задание введите - 2";
	if(_getch()=='2')
	{
		cout<<endl;
		Time a2("23:09:08");
		Time a3("67:78:98");
		cout<<endl;
		Time b1(13,56,34);
		Time b2(1453);
		Time b3 = b1 - b2;
		Time b4 = b1 + b2;
		Time b5 = b1 - 1234;
		Time b6 = b1 + 987;
		cout<<endl;
		if(b3==b4){
			cout<<"Объекты класса Time равны"<<endl;
		}
		if(b3!=b4){
			cout<<"Объекты класса Time не равны"<<endl;
		}
		if(b3>b4){
			cout<<"Первый объект класса Time больше второго"<<endl;
		}
		if(b3<b4){
			cout<<"Первый объект класса Time меньше второго"<<endl;
		}
		cout<<b2.Time2Sec()<<endl;
		cout<<b2.Time2MinFix()<<endl;
	}
	cout<<endl<<"Чтобы выполнить третье задание введите - 3";
	if(_getch()=='3')
	{
		Matrix M(3);
		M.Show();
		cout<<M.FirstNorm()<<endl;
		cout<<M.SecondNorm()<<endl;
		int m=0;
		cout<<"Введите количество объектов класса Matrix: ";cin>>m;cout<<endl;
		Matrix **B=new Matrix*[m];
		int indmin1=0,indmin2=0;
		for (int i = 0; i < m ; i++){
			B[i]=new Matrix(4);
		}
		int min1=B[0]->FirstNorm(),min2=B[0]->SecondNorm();
		for (int i = 0; i < m ; i++){
			B[i]->Show();
		}
		for (int i = 0; i < m; i++){
			if(min1>B[i]->FirstNorm()){indmin1=i;}
			if(min2>B[i]->SecondNorm()){indmin2=i;}
		}
		cout<<"Матрица с минимальной первой нормой:"<<endl;
		B[indmin1]->Show();
		cout<<"Матрица с минимальной второй нормой:"<<endl;
		B[indmin2]->Show();
		for (int i = 0; i < m ; i++){
			delete B[i];
		}
		delete[] B;
	}
	cout<<endl<<"Чтобы выполнить четвертое задание введите - 4";
	if(_getch()=='4')
	{
		cout<<endl;
		/*Triangle t(20);
		t.Show();
		cout<<"Площадь объекта t: "<<t.Square()<<endl;
		N_angle s(3,0);
		s.Show();
		cout<<"Площадь объекта s: "<<s.Square()<<endl;
		int m=0,index=0;
		double max=0;
		cout<<endl<<"Введите количество многоугольников: "; cin>>m;
		N_angle **N=new N_angle*[m];
		for (int i = 0; i < m; i++){
			N[i]=new N_angle(i+3,0);
		}
		for (int i = 0; i < m; i++){
			if(max<N[i]->Square()){
				max=N[i]->Square();
				index=i;
			}
		}
		cout<<endl<<"Многоугольник с наибольшей площадью:"<<endl;
		N[index]->Show();
		cout<<"Площадь объекта N[i]: "<<N[index]->Square()<<endl;
		for (int i = 0; i < m; i++){
			delete N[i];
		}
		delete[] N;*/
		
		Triangle s;
		s.Show();
		cout<<"Площадь объекта s: "<<s.Square()<<endl;
		Triangle t(0,20);
		t.Show();
		cout<<"Площадь объекта s: "<<t.Square()<<endl;
		N_angle poly(4,false);
		cout<<poly.HardSquare()<<endl;

		int m=0,index=0;
		double max=0;
		cout<<endl<<"Введите количество многоугольников: "; cin>>m;
		N_angle **N=new N_angle*[m];
		for (int i = 0; i < m; i++){
			N[i]=new N_angle(i+3,false);
		}
		for (int i = 0; i < m; i++){
			if(max<N[i]->HardSquare()){
				max=N[i]->HardSquare();
				index=i;
			}
		}
		cout<<endl<<"Многоугольник с наибольшей площадью:"<<endl;
		N[index]->Show();
		cout<<"Площадь объекта N[i]: "<<N[index]->HardSquare()<<endl;
		for (int i = 0; i < m; i++){
			delete N[i];
		}
		delete[] N;
	}
	cout<<endl<<"Чтобы выполнить пятое задание введите - 5";
	if(_getch()=='5')
	{
		Pair s(2,3);
		Pair k(9,5);
		Pair res=s+k;
		res.Show();
		res=k*4;
		res.Show();

		Money m1(12,189),m2(45,97),res2;
		res2=m1+m2;
		res2.Show();
		res2=m1-m2;
		res2.Show();
		res2=m2-m1;
		res2.Show();

		res2=m1/3;
		res2.Show();
		res2=m1/2;
		res2.Show();
	}
	cout<<endl<<"Чтобы выполнить шестое задание введите - 6";
	if(_getch()=='6')
	{
		cout<<endl<<endl;
		char p='l';
		Array b("Hello");
		for (double i = 0; i < b.GetN();i=i+1.5){
			cout<<b[i]<<" ";
		}
		cout<<endl;
		for (double i = 0; i < b.GetN();i=i-1.5){
			cout<<b[i]<<" ";
			if(b[i]=='\0') break;
		}
		cout<<endl;
		for (double i = 0; i < b.GetN();i=i-1.5){
			cout<<b[p]<<" ";
			if(b[p]=='\0') break;
		}
		cout<<endl;

		Array A1("Hello");
		A1.Show();
		Array A2("Good Bye");
		A2.Show();
		Array ARes;
		ARes=A1+A2;
		ARes.Show();

		Octal o1("276"); //190
		Octal o2("62");  //50
		Octal ores;
		ores=o1+o2;  //240
		ores.Show();

		MString ms1("Hello");
		ms1.Show();
		MString ms2(", guys!");
		ms2.Show();
		MString msres;
		msres=ms1+ms2;
		msres.Show();
	}
	cout<<endl;
	system("pause");
}
void CollOrOrt(Vector v1,Vector v2,bool bl){
	if(v1.Get_n()==v2.Get_n())
	{
		int a=0;
		for(int i=0;i<v1.Get_n();i++){
			a+=v1.GetNElem(i)*v2.GetNElem(i);
		}
		if(a==0 && bl==0){
			cout<<"Вектор "<<v1<<" ортогонален вектору "<<v2<<endl;
		}
		if(v1.LenghtVec()*v2.LenghtVec()==a*a && bl==1){
			cout<<"Вектор "<<v1<<" коллинеарен вектору "<<v2<<endl;
		}
	}
	else{
		cout<<"Исходные векторы разных размерностей!"<<endl;
	}
};
void FormatOut(int hour,int min,int sec){
	if (min >= 10 && sec >= 10 && hour>=10) cout <<hour<< ":" << min << ":" << sec << endl;
	if (sec<10 && hour >= 10 && min >= 10) cout << hour << ":" << min << ":0" << sec << endl;
	if (min<10 && hour >= 10 && sec>=10) cout <<hour<< ":0" << min << ":" << sec << endl;
	if (min<10 && sec<10 && hour >= 10) cout << hour << ":0" << min << ":0" << sec << endl;
	if (min >= 10 && sec >= 10 && hour < 10) cout <<"0"<< hour << ":" << min << ":" << sec << endl;
	if (sec<10 && hour < 10 && min>=10) cout << "0" << hour << ":" << min << ":0" << sec << endl;
	if (min<10 && hour < 10 && sec>=10) cout << "0" << hour << ":0" << min << ":" << sec << endl;
	if (min<10 && sec<10 && hour < 10) cout << "0" << hour << ":0" << min << ":0" << sec << endl;
};
double DistTwoP(double x1,double y1, double x2, double y2){
	return pow(x2-x1,2)+pow(y2-y1,2);
};
bool Is_It_Triangle(double *X,double *Y){
	if(abs(pow(((X[2]-X[0])*(X[1]-X[0])+(Y[2]-Y[0])*(Y[1]-Y[0])),2)/(DistTwoP(X[0],Y[0],X[2],Y[2])*DistTwoP(X[0],Y[0],X[1],Y[1])))!=1){
		return true;
	}
	else{
		return false;
	}
};