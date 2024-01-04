#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<string>
#include<fstream>
using namespace std;
void create_array_random(int arr[], int size);
void create_array_1(int arr[], int size);
void write_int_file(int arr[], int size, string s);
void write_int_file_1(string s, string s1, string s3);
void print_array(int arr[], int size);
int split(int arr[], int lo, int hi);
void shellSort(int list[], int listLength);
int search_element_linaly(int arr[], int size, int number);
int barrierSearch(int* mas, int size, int value);
int binarySearch(int* mas, int size, int value);
bool search_linely_string(string stroka, string search_word);
int KMP(string text, string pattern);
void badCharHeuristic(string str, int size, int badchar[256]);
int searchBM(string txt, string pat);
int searchRC(string txt, string pat);