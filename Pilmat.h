#include <iostream>

using namespace std;

class Pilmat{

	      //Закрытые переменные класса

		int numer;//Номер
		char *name;//Порода 
		char *type;//Тип
		float vol1;//Обьем
		float cost;//Цена
		float time;//Время
		float vol2;//Обьем
		float vol3;//Обьем

	public://Открытые переменные класса

		Pilmat();//Конструктор
		Pilmat(int a,char *k2, char *k3,float z,float v,float n,float l,float y);//Конструктор с параметрами
		Pilmat(const Pilmat &o);//Конструктор копий
		~Pilmat();//Деструктор 
		void show();//Функция показа
		friend ostream &operator << (ostream &potok,Pilmat ob);//Перегрузка оператора
		friend istream &operator >> (istream &potok,Pilmat &ob);//Перегрузка оператора
		int operator > (Pilmat ob);//Перегрузка оператора
		Pilmat &operator = (Pilmat ob);//Перегрузка оператора
		int terror();//Проверка
		friend int tick(istream &potok,Pilmat &ob);//Функция для open_file()
		int gif_numer();//Функция возвращающая numer
		/*Вспогательные функции для Search()*/
		void help(int x);
		void help1(char *p);
		void help2(char *m);
		void help3(float z);
		void help6(float v);
		void help4(float n);
		void help5(float l);
		void help7(float y);
		int  numerr();
		/*Вспомогательные функции для Editing*/       
		string typee();
		string namee();
		float vol11();
		float vol22();
		float costt();
		float timee();
		float vol33();
};
