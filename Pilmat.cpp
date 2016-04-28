#include "Pilmat.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;//Пространство имён

Pilmat::Pilmat()//Конструктор
{
	numer=0;//Номер 
        name = new char[100];//Породы
        type = new char[30];//Тип
        vol1=0;//Обьём
        cost=0;//Обьём
        time=0;//Время
        vol2=0;//Обьём
        vol3=0;//Обьём
};

Pilmat::Pilmat(int a,char *k2, char *k3,float z,float v,float n,float l,float y)//Конструктор с параметрами 
{
	numer=a;//Номер в списке 
        name = new char[100];//Породы
	strcpy(name,k2);
        type = new char[30];//Тип
	strcpy(type,k3);
        vol1 = z;//Обьём
	vol2 = v;//Обьём
        cost = n;//Обьём
        time = l;//Время
        vol3 = y;//Обьём
};

Pilmat::~Pilmat()//Деструктор
{
	delete [] name;
	delete [] type;
}

Pilmat::Pilmat(const Pilmat &o)//Конструктор копий
{
	numer=o.numer;
	name=new char[100];
	strcpy(name,o.name);
	type=new char[100];
	strcpy(type,o.type);
	vol1=o.vol1;
	vol2=o.vol2;
	cost=o.cost;
	time=o.time;
	vol3=o.vol3;
}

int tick(istream &potok,Pilmat &ob)//Функция для open_file()
{
	char *buf;
	buf=new char[15];
	potok.getline(buf,15);
	ob.numer=atoi(buf);
	
	potok.getline(ob.name,100);
	potok.getline(ob.type,100);

	potok.getline(buf,15);
	ob.vol1=atoi(buf);
	
	potok.getline(buf,15);
	ob.vol2=atoi(buf);
	
	potok.getline(buf,15);
	ob.cost=atoi(buf);
	
	potok.getline(buf,15);
	ob.time=atoi(buf);

	potok.getline(buf,15);
	ob.vol3=atoi(buf);

}

/*Вспомогательные функции для Search()*/

int Pilmat::numerr()
{
        return numer;
}

string Pilmat::namee()
{
	return name;
}

string Pilmat::typee()
{
	return type;
}

float Pilmat::vol11()
{
	return vol1;
}

float Pilmat::vol22()
{
	return vol2;
}

float Pilmat::costt()
{
	return cost;
}

float Pilmat::timee()
{
	return time;
}

float Pilmat::vol33()
{
	return vol3;
}

/*Вспомогательные функции для Editing()*/

void Pilmat::help(int x)
{	
	numer=x;
}

void Pilmat::help1(char* p)
{
	name = new char[sizeof(p)];
        strcpy(name,p);
}

void Pilmat::help2(char *m)
{
	type = new char[sizeof(m)];
	strcpy(type,m);
}

void Pilmat::help3(float z)
{	
	vol1=z;
}

void Pilmat::help6(float v)
{	
	vol2=v;
}
void Pilmat::help4(float n)
{	
	cost=n;
}

void Pilmat::help5(float l)
{	
	time=l;
}

void Pilmat::help7(float y)
{	
	vol3=y;
}

/*Вспомогательная функция*/

int Pilmat::gif_numer()
{
	return numer;
}

void Pilmat::show()//Функция показа
{
	cout<< "1.Номер в списке >>" <<numer<<"\n";
	cout<< "2.Порода древесины >>" << name <<"\n";
	cout<< "3.Тип древесины >>" <<type<<"\n";
	cout<< "4.Обьём древесины, имеющийся на складе(м^3) >>" <<vol1<<"\n";
	cout<< "5.Обьём древесины, который неоходимо обработать(м^3) >>" <<vol2<<"\n";
	cout<< "6.Производственные затраты на обработку 1 м^3 древесины(руб) >>" <<cost<<"\n";
	cout<< "7.Время, которе необходимо для производства 1 м^3 древесины(час) >>" <<time<<"\n";
	cout<< "8.Обьём древесины, полученный в результате обработки(м^3) >>" <<vol3<<"\n";
	cout<< "\n";
}

int Pilmat::operator > (Pilmat ob)//Перегрузка оператора
{
	return (numer>ob.numer);
}

Pilmat &Pilmat::operator = (Pilmat ob)//Перегрузка оператора присваивания 
{
	numer=ob.numer;
	strcpy(name,ob.name);
	strcpy(type,ob.type);
	vol1=ob.vol1;
	vol2=ob.vol2;
	cost=ob.cost;
	time=ob.time;
	vol3=ob.vol3;
	return *this;	
}

istream &operator >>(istream & potok, Pilmat &ob)//Перегрузка оператор 
{
	potok>>ob.numer;
	potok>>ob.name;
	potok>>ob.type;
	potok>>ob.vol1;
	potok>>ob.vol2;
	potok>>ob.cost;
	potok>>ob.time;
	potok>>ob.vol3;
	return potok;
};

ostream &operator <<(ostream & potok, Pilmat ob)//Перегрузка оператор
{
	potok<<ob.numer<<"\n";
	potok<<ob.name<<"\n";
	potok<<ob.type<<"\n";
	potok<<ob.vol1<<"\n";
	potok<<ob.vol2<<"\n";
	potok<<ob.cost<<"\n";
	potok<<ob.time<<"\n";
	potok<<ob.vol3;
	return potok;
};

int Pilmat::terror()//Функция проверки
{
	if ((numer>0)&&(strlen(name)>2)&&(strlen(type)>2)&&(vol1>1)&&(vol2>1)&&(cost>1)&&(time>1)&&(vol3>1))
	return 1;
	else
		return 0;
};