#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRIGHT_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRIGHT_TO_FILE
	cout << "Hello Files" << endl;

	std::ofstream fout;				//1)создаем поток
	fout.open("File.txt", std::ios_base::app);			//2)открываем поток. при открытие потока указываем в какой файл буднм писать
	fout << "Hello Files" << endl;  //3)пишем в  поток
	fout << "привет" << endl;
	fout.close();					//4)закрываем поток.

	system("notepad File.txt");

#endif // WRIGHT_TO_FILE

	std::ifstream fin("File.txt");	//1)создание открытие потока можно совместить
	if (fin.is_open())				//2 при чтении проверять открылся ли поток 
	{
		while (!fin.eof())			//3)TODO : read from file
		{
			const int SIZE = 1024000;
			char buffer[SIZE]{};
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout <<buffer<< endl;
		}
		fin.close();				//4) поток есть смысл закрывать только если он был открыт
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
}