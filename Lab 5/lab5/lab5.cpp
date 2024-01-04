#include"Header.h"
int main() {
	setlocale(LC_ALL, "ru");
	int number, number2;
	int key;
	do {
		cout << "Choose:\n1 - Array\n2 - String\n0 - Exit\n>";
		cin >> key;

		switch (key) {
		do {
		case 1:
			system("cls");
			cout << "1 - Linear search" << endl;
			cout << "2 - Search with a barrier" << endl;
			cout << "3 - Binary search" << endl;
			cout << "0 - Exit" << endl << ">";
			cin >> number;
			switch (number) {
			case 1: {
				int n;
				string s;
				cout << "Enter count of elements\n>";
				cin >> n;

				int* array = new int[n];
				create_array_1(array, n);
				print_array(array, n);
				int number1;
				cout << "Search number: ";
				cin >> number1;
				int is = search_element_linaly(array, n, number1);
				if (is > -1) {
					cout << number1 << " in array" << endl;
				}
				else {
					cout << number1 << " not in array" << endl;
				}
				system("pause");
				break;
			
			}
			case 2: {
				int n;
				string s;
				cout << "Enter count of elements\n>";
				cin >> n;
				int* array = new int[n];
				create_array_1(array, n);
				print_array(array, n);
				int number1;
				cout << "Search number: ";
				cin >> number1;
				int is = barrierSearch(array, n, number1);
				if (is > -1) {
					cout << number1 << " in array" << endl;
				}
				else {
					cout << number1 << " not in array" << endl;
				}
				system("pause");
				break;

			}
			case 3: {
				int n;
				string s;
				cout << "Enter count of elements\n>";
				cin >> n;
				int* array = new int[n];
				create_array_1(array, n);
				print_array(array, n);
				int number1;
				cout << "Search number: ";
				cin >> number1;
				int is = binarySearch(array, n, number1);
				if (is > -1) {
					cout << number1 << " in array" << endl;
				}
				else {
					cout << number1 << " not in array" << endl;
				}
				system("pause");
				break;

			}
			case 0:
				break;
			}
			} while (number);
			break;

		case 2:
		do {
			system("cls");
			cout << "1 - Linear string search" << endl;
			cout << "2 - KMP search" << endl;
			cout << "3 - Boyer-Moore search" << endl;
			cout << "4 - Rabin-Karp search" << endl;
			cout << "0 - Exit" << endl << ">";
			cin >> number2;
			
			switch (number2) {
			case 1: {

				int n;
				string s;
				cout << "1 - Enter string\n2 - Create from file\n> ";
				cin >> n;
				if (n == 1) {
					string text;
					cin >> text;
					cout << "String:\n" << text << endl;
					string text1;
					cout << "Search string: ";
					cin >> text1;
					bool is = search_linely_string(text, text1);
					if (is) {
						cout  << text1 << " in string" << endl;
					}
					else {
						cout << text1 << " not in string" << endl;
					}

				}
				else {
					string s;
					ifstream fin;
					fin.open("string.txt");
					string text;
					string s1;
					int count = -1;
					while (!fin.eof()) {
						getline(fin, s1);
						text += s1;

					}
					fin.close();
					cout << "String:\n" << text << endl;
					string text1;
					cout << "Search string: ";
					cin >> text1;
					bool is = search_linely_string(text, text1);
					if (is) {
						cout << text1 << " in string" << endl;
					}
					else {
						cout << text1 << " not in string" << endl;
					}
				}
				system("pause");
				break;
			}
			case 2: {
				int n;
				
				string s;
				cout << "1 - Enter string\n2 - Create from file\n> ";
				cin >> n;
				if (n == 1) {
					string text;
					cin >> text;
					cout << "String:\n" << text << endl;
					string text1;
					cout << "Search string: ";
					cin >> text1;
					int is1 = KMP(text, text1);
					
						//cout << text1 << " in string" << endl;
					
						if (is1 != 1)
							cout << text1 << " not in string" << endl;
					
				}
				else {
					string s;
					ifstream fin;
					fin.open("string.txt");
					string text;
					string s1;
					int count = -1;
					while (!fin.eof()) {
						getline(fin, s1);
						text += s1;

					}
					fin.close();
					cout << "String:\n" << text << endl;
					string text1;
					cout << "Search string: ";
					cin >> text1;
					int is1 = KMP(text, text1);
					/*if (is1 == 1) {
						cout << text1 << " in string" << endl;
					}
					else {
						cout << text1 << " not in string" << endl;
					}*/
					if (is1 == 0)
						cout << text1 << " not in string" << endl;
				}
				system("pause");
				break;
			}
			case 3: {
				int n;
				string s;
				cout << "1 - Enter string\n2 - Create from file\n> ";
				cin >> n;
				if (n == 1) {
					string text;
					cin >> text;
					cout << "String:\n" << text << endl;
					string text1;
					cout << "Search string: ";
					cin >> text1;

					int is = searchBM(text, text1);
					if (is != -1) {
						cout << text1 << " in string" << endl;
					}
					else {
						cout << text1 << " not in string" << endl;
					}
				}
				else {
					string s;
					ifstream fin;
					fin.open("string.txt");
					string text;
					string s1;
					int count = -1;
					while (!fin.eof()) {
						getline(fin, s1);
						text += s1;

					}
					fin.close();
					cout << "String:\n" << text << endl;
					string text1;
					cout << "Search string: ";
					cin >> text1;
					int is = searchBM(text, text1);
					if (is != -1) {
						cout << text1 << " in string" << endl;
					}
					else {
						cout << text1 << " not in string" << endl;
					}
				}
				system("pause");
				break;
			}
			case 4: {
				int n;
				string s;
				cout << "1 - Enter string\n2 - Create from file\n> ";
				cin >> n;
				if (n == 1) {
					string text;
					cin >> text;
					cout << "String:\n" << text << endl;
					string text1;
					cout << "Search string: ";
					cin >> text1;

					int is = searchRC(text, text1);
					if (is != -1) {
						cout << text1 << " in string" << endl;
					}
					else {
						cout << text1 << " not in string" << endl;
					}
				}
				else {
					string s;
					ifstream fin;
					fin.open("string.txt");
					string text;
					string s1;
					int count = -1;
					while (!fin.eof()) {
						getline(fin, s1);
						text += s1;

					}
					fin.close();
					cout << "String:\n" << text << endl;
					string text1;
					cout << "Search string: ";
					cin >> text1;
					int is = searchRC(text, text1);

					if (is != -1) {
						cout << text1 << " in string" << endl;
					}
					else {
						cout << text1 << " not in string" << endl;
					}
				}
				system("pause");
				break;
			}
			case 0:
				break;
			}
			} while (number2);
			break;
	} 
	} while (key);
}
		