
#include <fstream>
#include <iostream>
#include <random>
using namespace std;

void main(void)

{
	setlocale(LC_ALL, "Russian");
	int m,n,a,b;//m-columns, n-string
	char str;
	cout << "Кол-во строк=";
	cin >> n;
	cout << "Кол-во столбцов=";
	cin >> m;
	cout << "Левый предел=";
	cin >> a;
	cout << "Правый предел=";
	cin >> b;
	cout << "3-х диаг? (y/n)";
	cin >> str;
	//ofstream book_file("matr.txt");
	fstream file;
	file.open("G:\\matr.txt", ios_base::out);
	//file << "Первая строка";
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());  // to seed mersenne twister.
	uniform_real_distribution<> dist(a, b);
	file << n<<endl;
	file << m<<endl;
	if (str=='y')
	{
		file << 0<<" ";
		for (int i = 0; i < 2; ++i)
		file << dist(gen) << " ";
	 file << endl;
		for (int j = 1; j < n-1; j++)
		{
			for (int i = 0; i < 3; ++i)
				file << dist(gen) << " "; // print the raw output of the generator.
			file << endl;
		}

	for (int i = 0; i < 2; ++i)
		file << dist(gen) << " ";
	file << 0<<" ";
	file << endl;
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; ++i)
				file << dist(gen) << " "; // print the raw output of the generator.
			file << endl;
		}
	}
	file.close();
}