/***************************************************************************************
*Project Name : Search algorithms                                                      *
*File Name    : Search alorithms.cpp                                                   *
*Language     : CPP,MSVS ver 2015 and above                                            *
*Programmers : Ратников Роман Олегович, Фицайло Александр Александрович                *
*                                         группа:М3О-210Б-20                           *
*                                                		                               *
*Modified By  :                                                                        *
*Created      : 15/10/2021                                                             *
*Last Revision: 17/10/2021                                                             *
*Comment      :Алгоритмы поиска														   *
***************************************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;


//Прототипы функций


//Линейный поиск

string Better_Linear_Search(int* array,      //Массив
							const int& N,    //Размер массива
							const int& key,  //Ключ
							int& count);     //Количество сравнений
						   

//Быстрый линейный поиск
string Sentinel_Linear_Search(int* array, const int& N, const int& key, int& count);

//Упорядоченный линейный поиск
string Ordered_Linear_Search(int* array, const int& N, const int& key, int& count);

//Бинарный поиск
string Binary_Search(int* array, const int& N, const int& key, int& count);


//Функция печати

void Print_Answer(string (*array[])(int*, const int&, const int&, int&),string* name_f,int* pa[],const int& N, int arr_key[]);

void Print_Time(string(*array[])(int*, const int&, const int&, int&), string* name_f,int* pa[], const int& N, int arr_key[]);

// Этап 1
void Stage1();



//Этап 2
void Stage2();


int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Этап 1 :" << endl;
	Stage1();
	cout << "\nЭтап 2 :" << endl;
	Stage2();
	return 0;
}

// Этап 1
void Stage1()
{
	int key = 100;
    int key2 = 17;
	int nfkey = 101;      //Ненайденный ключ
	int nfkey2 = 30;	  //Ненайденный ключ 2
	int count = 0;
	int N = 30;
	int Array[] = { 33,12, 97, 55, 91, 40, 78, 99, 47, 26, 5, 100,
		62, 13, 5, 42, 15, 42, 26, 28, 2 ,28, 93, 43, 85, 93, 52, 23, 23, 79 };
	int Ordered_Array[] = { 1,2,4,4,5,6,7,8,9,10,10,11,11,12,13,14,15,16,17,18,18,19,20,21,22,23,24,25,26,27,key2*20};

	//Массив указателей на функции
	string(*arr_f[4])(int*, const int&, const int&, int&) = { Better_Linear_Search,
		Sentinel_Linear_Search, Ordered_Linear_Search, Binary_Search };

	//Массив названий функций
	string name_f[]= { "Better_Linear_Search",
		"Sentinel_Linear_Search", "Ordered_Linear_Search","Binary_Search"};


	int* pa[] = { Array, Ordered_Array };



	int arr_key[] = { key,key2,nfkey,nfkey2 };
	
	Print_Answer(arr_f, name_f,pa,N,arr_key);
	
	
	
	
}


//Этап 2
void Stage2()
{
	const int N2 = 500867;
	int* Big_Array= new int[N2];
	int* Ordered_Big_Array = new int[N2+1];
	srand(time(0));

	for (int i = 0;i < N2;++i)
	{
		Big_Array[i] = rand()%N2;
	}
	for (int i = 0;i < N2;++i)
	{
		Ordered_Big_Array[i] = i;
		
	}
	int key_found = 180678;
	int key_found2 = 356356;
	int key_found3 = 498234;
	int big_key_nf = N2 * 2;
	int big_key_nf2 = N2 +3;
	int big_key_nf3 = N2 +600;

	Ordered_Big_Array[N2] = big_key_nf * 2;
	int arr_key_2[] = { key_found,key_found2,key_found3,big_key_nf ,big_key_nf2,big_key_nf3 };
	int* pa[] = { Big_Array,Ordered_Big_Array };
	Big_Array[456567] = key_found;
	Big_Array[200567] = key_found2;
	Big_Array[100349] = key_found3;

	//Массив указателей на функции
	string(*arr_f[4])(int*, const int&, const int&, int&) = { Better_Linear_Search,
		Sentinel_Linear_Search, Ordered_Linear_Search, Binary_Search };

	//Массив названий функций
	string name_f[] = { "Better_Linear_Search",
		"Sentinel_Linear_Search", "Ordered_Linear_Search","Binary_Search" };

	Print_Time(arr_f, name_f, pa, N2, arr_key_2);

	delete[] Big_Array;

}

string Better_Linear_Search(int* array, const int& N, const int& key, int& count)
{
	count = 0;

	for (int i = 0;i < N;++i)
	{
		++count;
		if (array[i] == key)
		{
			++count;
			return to_string(i);
		}
		++count;
	}

	return "NOT_FOUND";
}

string Sentinel_Linear_Search(int* array, const int& N, const int& key, int& count)
{
	count = 0;
	int last = array[N - 1];
	array[N - 1] = key;
	int i = 0;

	while (array[i] != key)
	{
		++count;
		++i;
	}
	++count;
	if (i < N-1)
	{
		++count;
		return to_string(i);
	}
	else
	{
		++count;
		if (last == key)
		{
			++count;
			return to_string(i);
		}
		else
		{
			++count;
			return "NOT_FOUND";
		}
	}
}

string Ordered_Linear_Search(int* array, const int& N, const int& key, int& count)
{
	count = 0;
	int i = 0;
	while (key > array[i])
	{
		++count;
		++i;
	}
	++count;
	if (array[i] == key)
	{
		++count;
		return to_string(i);
	}
	return "NOT_FOUND";
}

string Binary_Search(int* array, const int& N, const int& key, int& count)
{
	count = 0;
	int p = 0;
	int r = N-1;
	int q;
	while (p <= r)
	{
		++count;
		q = (p + r) / 2;
		if (array[q] == key)
		{
			++count;
			return to_string(q);
		}
		++count;
		if (key < array[q])
		{
			++count;
			r = q-1;
		}
		else
		{
			++count;
			p = q + 1;
		}
	}
	++count;
	return "NOT_FOUND";
}

void Print_Answer(string (*array[])(int*, const int&, const int&, int&), string* name_f, int* pa[], const int& N, int arr_key[])

{
	for (int i = 0;i < 4;++i)
	{
		int count=0;
		cout << "\n"<<name_f[i] << endl;
		for (int j = 0;j < 2;++j)
		{
			cout << "\nИндекс ключа "<<arr_key[i / 2+j]<<" : " << array[i](pa[i / 2], N, arr_key[i / 2+j], count) << endl;
			cout << "Количество сравнений : " << count << endl;
		}
	}
}

void Print_Time(string(*array[])(int*, const int&, const int&, int&), string* name_f,int* pa[], const int& N, int arr_key[])
{
	for (int i = 0;i < 4;++i)
	{   
		int sum=0;
		int count = 0;
		cout << "\n" << name_f[i] << endl;

		for (int j = 0;j < 3;++j)
		{
			//Получение времени начала функции

			auto begin = chrono::high_resolution_clock::now();
			cout << "\nИндекс ключа "<<arr_key[j]<<": " << array[i](pa[i / 2], N, arr_key[j], count) << endl;
			//Получение времени окончания функции

			chrono::duration<double> elapsed_ms = chrono::high_resolution_clock::now() - begin;
			cout << "Время поиска : " << elapsed_ms.count()*1000 << "Нс" << endl;
			cout << "Количество сравнений : " << count << endl;
			sum += count;
		}
		cout << "Среднее значение сравнений успешного поиска: " << sum / 3 << endl;
		cout << endl;
		sum = 0;
		for (int j = 3;j < 6;++j)
		{
			auto begin = chrono::high_resolution_clock::now();
			cout << "\nИндекс ключа " << arr_key[j] << ": " << array[i](pa[i / 2], N, arr_key[j], count) << endl;
			chrono::duration<double> elapsed_ms = chrono::high_resolution_clock::now() - begin;
			cout << "Время поиска : " << elapsed_ms.count()*1000 << "  Нс" << endl;
			cout << "Количество сравнений : " << count << endl;
			sum += count;
		}
		cout << "Среднее значение сравнений неуспешного поиска: " << sum / 3 << endl;
	}

}