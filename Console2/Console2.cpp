#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;
class Polynom {
    int n;
    double* koef;
public:
    Polynom();
    Polynom(int k);
    Polynom(int k, double* mas);
    Polynom(const Polynom& ob);
    ~Polynom() { delete[]koef; }

    void GiveMemory(int k);
    void SetPolynom(int k, double* mas);
    void SetDegree(int k) { n = k; };
    void CalculateValue(double x);
    int GetDegree() { return n; };
    double GetOneCoefficient(int i) { return(koef[i]); };
    void SumShow(Polynom a, Polynom b) {
        Polynom s;
        s = a + b;
        cout << " f(x)+g(x) = "; cout << s;
    };
    void AntiSumShow(Polynom a, Polynom b) {
        Polynom s;
        s = a - b;
        cout << " f(x)-g(x) = "; cout << s;
    };
    void MultShow(Polynom a, Polynom b) {
        Polynom s;
        s = a * b;
        cout << " f(x)*g(x) = "; cout << s;
    };
    void Show() {
        char c = ' ';
        for (int i = this->n;i >= 0;i--) {
            double ai = this->koef[i];
            if (ai == 0) continue;
            else { if (ai > 0) cout << c; cout << ai; }
            if (i == 0) continue; else cout << "x";
            if (i == 1) continue; else cout << "^" << i;
            if (ai != 0)c = '+';
        }
        cout << "\n";
    }

    Polynom operator+(Polynom ob);
    Polynom operator-(Polynom ob);
    Polynom operator*(Polynom ob);

    double& operator++(int i) {
        double rez = koef[i] + 1;
        return(rez);
    };
    double& operator--(int i) {
        double rez = koef[i] - 1;
        return(rez);
    };
    double& operator[](int i) { return(koef[i]); }

    Polynom& operator = (const Polynom p) {
        if (&p == this) return *this;
        if (koef) delete[] koef;
        n = p.n;
        koef = new double[p.n + 1];
        for (int i = 0;i <= p.n;i++)
            koef[i] = p.koef[i];
        return *this;
    }

    friend ostream& operator <<(ostream& mystream, Polynom& ob);
    friend istream& operator >>(istream& mystream, Polynom& ob);
    int min(int n, int m)
    {
        return (n < m) ? n : m;
    }
    int max(int n, int m)
    {
        return (n > m) ? n : m;
    }
};
Polynom::Polynom()
{
    n = rand() % 5;
    koef = new double[n + 1];
    if (!koef) { cout << "Error";return; }
    for (int i = n;i >= 0;i--)
        koef[i] = rand() % 10 - 5;
}
Polynom::Polynom(int k)
{
    n = k;
    koef = new double[n + 1];
    if (!koef) { cout << "Error";return; }
    for (int i = n;i >= 0;i--)
        koef[i] = rand() % 10 - 5;
}
Polynom::Polynom(int k, double* mas)
{
    n = k;
    koef = new double[n + 1];
    if (!koef) { cout << "Error";return; }
    for (int i = n;i >= 0;i--)
        koef[i] = mas[i];
}
Polynom::Polynom(const Polynom& other)
{
    n = other.n;
    koef = new double[n + 1];
    if (!koef) { cout << "Error";return; }
    for (int i = 0;i <= n;i++)
        koef[i] = other.koef[i];
}
void Polynom::GiveMemory(int k)
{
    if (koef) delete[] koef;
    koef = new double[k + 1];
    if (!koef) { cout << "Error";return; }
}
void Polynom::SetPolynom(int k, double* mas)
{
    n = k;
    if (koef) delete[] koef;
    koef = new double[n + 1];
    for (int i = n;i >= 0;i--)
        koef[i] = mas[i];
}
void Polynom::CalculateValue(double x = 1.0)
{
    double s;
    int i;
    for (s = koef[0], i = 1;i <= n;i++)
        s = s + koef[i] * pow(x, i);
    cout << "f(" << x << ")="; cout << s << endl;
}
Polynom Polynom::operator+(Polynom ob)
{
    int i;
    Polynom rab;
    rab.GiveMemory(max(n, ob.GetDegree()));
    for (i = 0;i <= min(n, ob.GetDegree());i++)
        rab.koef[i] = koef[i] + ob.GetOneCoefficient(i);
    if (n < ob.GetDegree())
    {
        for (i = min(n, ob.GetDegree()) + 1;i <= ob.GetDegree();i++)
            rab.koef[i] = ob.GetOneCoefficient(i);
        rab.n = ob.GetDegree();
    }
    else
    {
        for (i = min(n, ob.GetDegree()) + 1;i <= n;i++) rab.koef[i] = koef[i];
        rab.n = n;
    }
    return rab;
}
Polynom Polynom::operator-(Polynom ob)
{
    int i;
    Polynom a;
    a.GiveMemory(max(n, ob.GetDegree()));
    for (i = 0;i <= min(n, ob.GetDegree());i++)
        a.koef[i] = koef[i] - ob.GetOneCoefficient(i);
    if (n < ob.GetDegree())
    {
        for (i = min(n, ob.GetDegree()) + 1;i <= ob.GetDegree();i++)
            a.koef[i] = ob.GetOneCoefficient(i);
        a.n = ob.GetDegree();
    }
    else
    {
        for (i = min(n, ob.GetDegree()) + 1;i <= n;i++) a.koef[i] = koef[i];
        a.n = n;
    }
    return a;
}
Polynom Polynom::operator*(Polynom ob)
{
    int i, j, k;
    double s;
    Polynom rab;
    rab.GiveMemory(n + ob.GetDegree());
    for (i = 0;i <= n + ob.GetDegree();i++)
    {
        s = 0;
        for (j = 0;j <= n;j++)
            for (k = 0;k <= ob.GetDegree();k++)
                if (j + k == i)s = s + koef[j] * ob.GetOneCoefficient(k);
        rab.koef[i] = s;
    }
    rab.n = n + ob.GetDegree();
    return rab;
}
ostream& operator<<(ostream& mystream, Polynom& ob)
{
    char c = ' ';
    for (int i = ob.n;i >= 0;i--) {
        double ai = ob.koef[i];
        if (ai == 0) continue;
        else { if (ai > 0) mystream << c; mystream << ai; }
        if (i == 0) continue; else mystream << "x";
        if (i == 1) continue; else mystream << "^" << i;
        if (ai != 0)c = '+';
    }
    //if(c==' ')mystream<<0;
    mystream << "\n";
    return mystream;
}
istream& operator>>(istream& mystream, Polynom& ob)
{
    int i;
    cout << "Введите степень многочлена: ";
    mystream >> ob.n;
    cout << endl;
    if (ob.koef != NULL) {
        delete[] ob.koef;
    }
    ob.koef = new double[ob.n + 1];
    for (i = ob.n;i >= 0;i--)
    {
        cout << "Введите коэффициенты многочлена при степени " << i << ": ";
        mystream >> ob.koef[i];
    }
    return mystream;
}
Polynom SumOfElem(Polynom* Arr, int number);
Polynom SumOfElemInit(Polynom* Arr, int number);
int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    const int m = 3;  int n = 5, i, number;

    Polynom f, g, s;
    Polynom* p1, A[m];
    double B[6] = { 1.0,3.2,0.0,4.1,0.0,1.1 };
    p1 = new Polynom(n, B);
    cout << *p1;
    p1->CalculateValue(2.0);

    s = A[0]; cout << A[0];
    for (i = 1;i < m;i++)
    {
        s = s + A[i]; cout << A[i];
    }
    cout << "Summa: ";  cout << s;
    delete p1;

    cout << "Выполнить первую часть?( 1-да );" << endl;
    if (_getch() == '1') {
        cin >> f;
        cout << " f(x) = ";  cout << f;
        cin >> g;
        cout << " g(x) = "; cout << g;
        s.SumShow(f, g);
        s.AntiSumShow(f, g);
        s.MultShow(f, g);
    }

    cout << "Введите количество полинoмов: ";
    cin >> number;
    Polynom* Poly = new Polynom[number];
    cout << endl << "Выберите способ задания полиномов ( 1-ввод самостоятельный , 2- автоматичeская инициализация );";
    if (_getch() == '1') {
        cout << endl << "Сумма полиномов: ";
        SumOfElem(Poly, number).Show();
        cout << endl;
    }
    if (_getch() == '2') {
        cout << endl << "Сумма полиномов: ";
        SumOfElemInit(Poly, number).Show();
        cout << endl;
    }
    delete[] Poly;
    system("pause");
    return 0;
}
Polynom SumOfElemInit(Polynom* Arr, int number) {
    Polynom Sum;
    for (int i = 0;i < number;i++) {
        Sum = Sum + Arr[i];
    }
    return Sum;
};
Polynom SumOfElem(Polynom* Arr, int number) {
    Polynom Sum;
    for (int i = 0; i < number; i++) {
        cin >> Arr[i];
        if (i == 0) Sum = Arr[0];
        cout << Arr[i];
        if (i != 0) Sum = Sum + Arr[i];
    }
    return Sum;
};


