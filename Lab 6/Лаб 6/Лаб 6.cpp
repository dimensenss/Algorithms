#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#define m 20
#define m1 9
#define m2 11

class HashTable
{
private:
	int mas[m];
	int HashFoo(int key);
public:
	HashTable();
	void Add(int key);
	void Delete(int key);
	int Search(int key);
	void Print();
	void Read_file(string nameFile);
	void Write_file(string nameFile);
	int Empty();
};
HashTable::HashTable()
{
	for (size_t i = 0; i < m; i++)
	{
		mas[i] = 0;
	}
}
int HashTable::Empty()
{
	for (size_t i = 0; i < m; i++)
	{
		if (mas[i] != 0)
		{
			return 1;
		}
	}
	return 0;
}
void HashTable::Add(int key)
{
	mas[HashFoo(key)] = key;
}
int HashTable::HashFoo(int key) {
	double rez = (key * ((sqrt(5) - 1) / 2));
	double fraction, integer;
	fraction = modf(rez, &integer);
	int h = (int)m * fraction;
	return h;
}
void HashTable::Read_file(string name)
{
	ifstream ifst;
	int value;
	ifst.open(name);
	if (!ifst.is_open()) {
		throw exception("Файл не найден");
	}
	while (ifst >> value)
		Add(value);
	ifst.close();
}
void HashTable::Print() {
	for (int i = 0; i < m; i++)
	{
		if (mas[i] != 0)
		{
			cout << i << "  [" << mas[i]<<"]" << endl;
		}
	}
}
void HashTable::Write_file(string name)
{
	ofstream ofst;
	ofst.open(name);
	if (!ofst.is_open()) {
		throw exception("Файл не найден");
	}
	for (int i = 0; i < m; i++)
	{
		if (mas[i] != 0) {
			ofst << i << ": " << mas[i] << endl;
		}
	}
	ofst.close();
}
int HashTable::Search(int key)
{
	if (mas[HashFoo(key)] == 0)
	{
		cout << endl << "Такого элемента в таблице нет" << endl;
		return -1;
	}
	else
	{
		return HashFoo(key);
	}
}
void HashTable::Delete(int key)
{
	if (mas[HashFoo(key)] == 0)
	{
		cout << endl << "Такого элемента в таблице нет" << endl;
	}
	else
	{
		cout << endl << "Элемент таблицы успешно удален" << endl;
		mas[HashFoo(key)] = 0;
	}
}


class HashTableWithChains
{
	class Node
	{
	public:
		int data;
		Node* next;
	};
	Node* node[9];
	int HashFoo(int key);
	Node* Create(int key);

public:
	HashTableWithChains();
	void Add(int key);
	int Delete(int key);
	void Search(int key);
	void Print();
	void Read_file(string name);
	void Write_file(string name);
};
HashTableWithChains::HashTableWithChains()
{
	for (size_t i = 0; i < 9; i++)
	{
		node[i] = nullptr;
	}
}
void HashTableWithChains::Add(int key)
{
	int hash = HashFoo(key);

	if (node[hash] == nullptr)
	{
		node[hash] = Create(key);
	}
	else {
		Node* temp = node[hash];
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = Create(key);
	}
}
int HashTableWithChains::HashFoo(int key)
{
	return key % 9;
}
HashTableWithChains::Node* HashTableWithChains::Create(int key)
{
	Node* temp = new Node;
	temp->data = key;
	temp->next = nullptr;
	return temp;
}
void HashTableWithChains::Print()
{
	Node* current = node[0];

	for (int i = 0; i < 9; i++)
	{
		cout << i << " ";
		while (current != nullptr)
		{
			cout << " - [" << current->data << "] ";
			current = current->next;
		}
		cout << endl;
		if (i == 8) {
			break;
		}
		else {
			current = node[i + 1];
		}
	}
}
void HashTableWithChains::Search(int key)
{
	int hash = HashFoo(key);
	int index = 0;
	Node* temp = node[hash];

	while (temp->data != key)
	{
		index++;
		temp = temp->next;
		if (temp == nullptr) {
			index = -1;
			break;
		}
	}

	if (index == -1)
	{
		cout << endl << "Not find" << endl;
	}
	else {
		cout << hash<< " by index " << index << endl;
	}
}
int HashTableWithChains::Delete(int key)
{
	int hash = HashFoo(key);
	int index = 0;
	Node* temp = node[hash];

	while (temp->data != key)
	{
		index++;
		temp = temp->next;
		if (temp == nullptr)
			return -1;
	}

	if (index == 0)
	{
		temp = node[hash];
		node[hash] = node[hash]->next;
		delete temp;
	}
	else {
		Node* previous = node[hash];
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}
		Node* del_node = previous->next;
		previous->next = del_node->next;
		delete del_node;
	}
	return 1;
}
void HashTableWithChains::Read_file(string name)
{
	ifstream ifst;
	int value;
	ifst.open(name);
	if (!ifst.is_open()) {
		throw exception("Файл не найден");
	}
	while (ifst >> value)
		Add(value);
	ifst.close();
}
void HashTableWithChains::Write_file(string name)
{
	ofstream ofst;
	ofst.open(name);
	if (!ofst.is_open()) {
		throw exception("Файл не найден");
	}
	for (int i = 0; i < 9; i++)
	{
		if (node[i] != nullptr)
		{
			ofst << i << ": " << node[i] << endl;
		}
	}
	ofst.close();
}


class HashTableWithOpenAdressing
{
private:
	class Element
	{
	public:
		int data;
		bool empty;
	};

	Element mas[m2];

	int HashFoo(int key);
	int LinearProb(int key);
	int Quadraticprob(int key);
	int DoubleProb(int key);

public:

	HashTableWithOpenAdressing();
	void Clear();
	int Empty();
	void AddLinear(int key);
	void AddQuadratic(int key);
	void AddDouble(int key);
	void DeleteLinear(int key);
	int SearchLinear(int key);
	void DeleteQuadratic(int key);
	int SearchQuadratic(int key);
	void DeleteDouble(int key);
	int SearchDouble(int key);
	void Print();
	void Read_file_Linear(string name);
	void Read_file_Quadratic(string name);
	void Read_file_Double(string name);
	void Write_file(string name);
};
HashTableWithOpenAdressing::HashTableWithOpenAdressing()
{
	for (size_t i = 0; i < m2; i++)
	{
		mas[i].data = 0;
	}
}
void HashTableWithOpenAdressing::Clear()
{

}
int HashTableWithOpenAdressing::Empty()
{
	return 1;
}
void HashTableWithOpenAdressing::AddLinear(int key)
{
	int poz = LinearProb(key);
	mas[poz].data = key;
	mas[poz].empty = false;
}
void HashTableWithOpenAdressing::AddQuadratic(int key)
{
	int poz = Quadraticprob(key);
	mas[poz].data = key;
	mas[poz].empty = false;
}
void HashTableWithOpenAdressing::AddDouble(int key)
{
	int poz = DoubleProb(key);
	mas[poz].data = key;
	mas[poz].empty = false;
}
void HashTableWithOpenAdressing::DeleteLinear(int key)
{
	int ind = SearchLinear(key);

	if (ind == -1)
	{
		cout << "\nДанного элемента не существует\n";
	}
	else
	{
		cout << "\nЭлемент удален\n";
		mas[ind].data = 0;
		mas[ind].empty = true;
	}
}
int HashTableWithOpenAdressing::SearchLinear(int key)
{
	int hash = HashFoo(key);

	while (mas[hash].empty != true)
	{
		if (mas[hash].data == key)
		{
			return hash;
		}
		hash = (hash + 1) % m2;
	}
	return -1;
}
void HashTableWithOpenAdressing::DeleteQuadratic(int key)
{
	int ind = SearchQuadratic(key);

	if (ind == -1)
	{
		cout << "\nДанного элемента не существует\n";
	}
	else
	{
		cout << "\nЭлемент удален\n";
		mas[ind].data = 0;
		mas[ind].empty = true;
	}
}
int HashTableWithOpenAdressing::SearchQuadratic(int key)
{
	int c1 = 1;
	int c2 = 3;
	int hash = HashFoo(key);
	int h_s = 0;

	while (true)
	{
		for (size_t i = 0; i < m2; i++)
		{
			h_s = (hash + c1 * i + c2 * i * i) % m2;
			if (mas[h_s].data == key)
			{
				return h_s;
			}
		}
		hash++;
	}
	return -1;
}
void HashTableWithOpenAdressing::DeleteDouble(int key)
{
	int ind = SearchDouble(key);

	if (ind == -1)
	{
		cout << "\nДанного элемента не существует\n";
	}
	else
	{
		cout << "\nЭлемент удален\n";
		mas[ind].data = 0;
		mas[ind].empty = true;
	}
}
int HashTableWithOpenAdressing::SearchDouble(int key)
{
	int hash = HashFoo(key);
	int hash2 = 1 + (key % (m2 - 1));
	int kol = 0;

	for (size_t i = 0; i < m2; i++)
	{
		kol = (hash + hash2 * i) % m2;
		if (mas[kol].data == key)
			return kol;
	}
	return -1;
}
void HashTableWithOpenAdressing::Print()
{
	for (int i = 0; i < m2; i++)
	{
		if (mas[i].data != 0)
		{
			cout << i << " " <<"[" << mas[i].data <<"]" << endl;
		}
	}
}
void HashTableWithOpenAdressing::Read_file_Linear(string name)
{
	ifstream ifst;
	int value;
	ifst.open(name);
	if (!ifst.is_open()) {
		throw exception("Файл не найден");
	}
	while (ifst >> value)
		AddLinear(value);
	ifst.close();
}
void HashTableWithOpenAdressing::Read_file_Quadratic(string name)
{
	ifstream ifst;
	int value;
	ifst.open(name);
	if (!ifst.is_open()) {
		throw exception("Файл не найден");
	}
	while (ifst >> value)
		AddQuadratic(value);
	ifst.close();
}
void HashTableWithOpenAdressing::Read_file_Double(string name)
{
	ifstream ifst;
	int value;
	ifst.open(name);
	if (!ifst.is_open()) {
		throw exception("Файл не найден");
	}
	while (ifst >> value)
		AddDouble(value);
	ifst.close();
}
void HashTableWithOpenAdressing::Write_file(string name)
{
	ofstream ofst;
	ofst.open(name);
	if (!ofst.is_open()) {
		throw exception("Файл не найден");
	}
	for (int i = 0; i < m; i++)
	{
		ofstream ofst;
		ofst.open(name);
		if (!ofst.is_open()) {
			throw exception("Файл не найден");
		}
		for (int i = 0; i < 9; i++)
		{
			if (mas[i].data != 0)
			{
				ofst << i << ": " << mas[i].data << endl;
			}
		}
		ofst.close();
	}
	ofst.close();
}

int HashTableWithOpenAdressing::HashFoo(int key)
{
	return key % 11;
}
int HashTableWithOpenAdressing::LinearProb(int key)
{
	int hash = HashFoo(key);
	int i = hash;
	int kol = 0;

	while (kol < m2)
	{
		if (mas[i].empty)
			return i;

		i = (i + 1) % m2;
		kol++;
	}
	return -1;
}
int HashTableWithOpenAdressing::Quadraticprob(int key)
{
	int c1 = 1;
	int c2 = 3;
	int hash = HashFoo(key);
	int h_s = 0;
	bool flag = false;

	while (flag == false)
	{
		for (size_t i = 0; i < m2; i++)
		{
			h_s = (hash + c1 * i + c2 * i * i) % m2;
			if (mas[h_s].empty)
			{
				return h_s;
			}
		}
		hash++;
	}
	return -1;
}
int HashTableWithOpenAdressing::DoubleProb(int key)
{
	int hash = HashFoo(key);
	int hash2 = 1 + (key % (m2 - 1));
	int kol = 0;

	for (size_t i = 0; i < m2; i++)
	{
		kol = (hash + hash2 * i) % m2;
		if (mas[kol].empty)
			return kol;
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choose;
	do {
		system("cls");
		cout << "1 - Hash table\n2 - Chain method\n3 - Open addressing method\n0 - Exit: ";
		cin >> choose;

		if (choose == 1)
		{
			HashTable a;
			int choosing = 0;
			do
			{
				if (a.Empty() == 0)
				{
					cout << "\n";
				}
				else
				{
					cout << endl;
					a.Print();
				}
				cout << endl << endl << endl;
				string name1 = "al6_1.txt";

				int key;
				cout << "1 - Add" << endl;
				cout << "2 - Add from file" << endl;
				//cout << "3 - Добавить в файл" << endl;
				cout << "3 - Search" << endl;
				cout << "4 - Del" << endl;
				cout << "0 - Exit\n";
				cin >> choosing;
				switch (choosing)
				{
				case 1:
					cout << "Enter key: ";
					cin >> key;
					a.Add(key);
					break;
				case 2:
					a.Read_file(name1);
					break;
				/*case 3:
					a.Write_file(name1);
					break;*/
				case 3:
					cout << "Enter key: ";
					cin >> key;
					cout <<"Key " << key<<" in " << a.Search(key);
					cout << endl;

					system("pause");
					break;
				case 4:
					cout << "Enter key: ";
					cin >> key;
					a.Delete(key);
					break;
				case 0:
					break;
				}
				system("cls");
				
			} while (choosing != 0);
		}
		else if (choose == 2)
		{
			int p = 0;
			int choosing =0;
			HashTableWithChains a1;
			do
			{
				if (p == 0)
				{
					cout << "\nEmpty";
				}
				else
				{
					cout << endl;
					a1.Print();
				}
				cout << endl << endl << endl;
				string name2 = "al6_2.txt";
				
				int key;
				cout << "1 - Add" << endl;
				cout << "2 - Add from file" << endl;
				//cout << "3 - Добавить в файл" << endl;
				cout << "3 - Search" << endl;
				cout << "4 - Del" << endl;
				cout << "0 - Exit\n";
				cin >> choosing;
				switch (choosing)
				{
				case 1:
					cout << "Enter key: ";
					cin >> key;
					a1.Add(key);
					p = 1;
					break;
				case 2:
					a1.Read_file(name2);
					p = 1;
					break;
				/*case 3:
					a1.Write_file(name2);
					break;*/
				case 3:
					cout << "Enter key: ";
					cin >> key;
					cout << "Key " << key<<" in "; a1.Search(key);
					cout << endl;

					system("pause");
					break;
				case 4:
					cout << "Enter key: ";
					cin >> key;
					a1.Delete(key);
					break;
				}
				system("cls");
			} while (choosing != 0);
		}
		else if (choose == 3)
		{
			int choosing = 0;
			int choose3;

			HashTableWithOpenAdressing a3;
			string name2 = "al6_3.txt";

			cout << "Choose probing: \n";
			cout << "1 - Linear\n";
			cout << "2 - Square\n";
			cout << "3 - Double\n";
			cout << "0 - Exit\n";
			cin >> choose3;

			system("cls");
			int p = 0;
			if (choose3 == 1)
			{
				do
				{
					if (p == 0)
					{
						cout << "\n";
					}
					else
					{
						cout << endl;
						a3.Print();
					}
					cout << endl << endl << endl;

					int key;
					cout << "1 - Add" << endl;
					cout << "2 - Add from file" << endl;
					//cout << "3 - Добавить в файл" << endl;
					cout << "3 - Search" << endl;
					cout << "4 - Del" << endl;
					cout << "0 - Exit\n";

					cin >> choosing;
					switch (choosing)
					{
					case 1:
						cout << "Enter key: ";
						cin >> key;
						a3.AddLinear(key);
						p = 1;
						break;
					case 2:
						a3.Read_file_Linear(name2);
						p = 1;
						break;
					/*case 3:
						a3.Write_file(name2);
						break;*/
					case 3:
						cout << "Enter key: ";
						cin >> key;
						cout << "Key " << key << " in " << a3.SearchLinear(key) << endl;
						system("pause");
						break;
					case 4:
						cout << "Enter key: ";
						cin >> key;
						a3.DeleteLinear(key);
						break;

					}
					system("cls");
				}while (choosing != 0);
			}
			else if (choose3 == 2)
			{
				HashTableWithOpenAdressing a3;
				string name2 = "al6_3.txt";
				do
				{
					if (p == 0)
					{
						cout << "\n";
					}
					else
					{
						cout << endl;
						a3.Print();
					}
					cout << endl << endl << endl;

					int key;
					cout << "1 - Add" << endl;
					cout << "2 - Add from file" << endl;
					//cout << "3 - Добавить в файл" << endl;
					cout << "3 - Search" << endl;
					cout << "4 - Del" << endl;
					cout << "0 - Exit\n";
					cin >> choosing;
					switch (choosing)
					{
					case 1:
						cout << "Enter key: ";
						cin >> key;
						a3.AddQuadratic(key);
						p = 1;
						break;
					case 2:
						a3.Read_file_Quadratic(name2);
						p = 1;
						break;
					/*case 3:
						a3.Write_file(name2);
						break;*/
					case 3:
						cout << "Enter key: ";
						cin >> key;
						cout << "Key " << key << " in " << a3.SearchQuadratic(key) << endl;
						system("pause");

						break;
					case 4:
						cout << "Enter key: ";
						cin >> key;
						a3.DeleteQuadratic(key);
						break;

					}

					system("cls");
				} while (choosing != 0);
			}
			else if (choose3 == 3)
			{
			HashTableWithOpenAdressing a3;
			string name2 = "al6_3.txt";
				do
				{
					if (p == 0)
					{
						cout << "\n";
					}
					else
					{
						cout << endl;
						a3.Print();
					}
					cout << endl << endl << endl;
					int key;
					cout << "1 - Add" << endl;
					cout << "2 - Add from file" << endl;
					//cout << "3 - Добавить в файл" << endl;
					cout << "3 - Search" << endl;
					cout << "4 - Del" << endl;
					cout << "0 - Exit\n";
					cin >> choosing;
					switch (choosing)
					{
					case 1:
						cout << "Enter key: ";
						cin >> key;
						a3.AddDouble(key);
						p = 1;
						break;
					case 2:
						a3.Read_file_Double(name2);
						p = 1;
						break;
					/*case 3:
						a3.Write_file(name2);
						break;*/
					case 3:
						cout << "Enter key: ";
						cin >> key;
						cout << "Key " << key << " in " << a3.SearchDouble(key) << endl;
						system("pause");
						break;
					case 4:
						cout << "Enter key: ";
						cin >> key;
						a3.DeleteDouble(key);
						break;
					case 0:
						break;
					}
					system("cls");
				} while (choosing != 0);
			}
		}
	} while (choose != 0);
}
