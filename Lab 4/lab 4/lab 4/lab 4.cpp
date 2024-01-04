#include <iomanip>
#include <iostream>
#include <windows.h>
#include <chrono>
using namespace std;

void Counting_Sort(int n, int mas[]);
void Shell_Sort(int n, int mas[]);
void Heap_Sort(int* mas, int n);

void a(int array[], int n);//упорядоченный массив
void b(int array[], int n);//упорядоченный в обратном порядке
void c(int array[], int n);//неупорядоченный массив

void dur_(double duration[], int n, double aver_dur);//сортировка и расчёт среднего значения

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 10000;//количество элементов в массиве
    const int M = 500;//количество циклов
    cout << "N = " << N << endl;

    int Array[N], Array2[N], Array3[N];
    double dur_arr[M];//массив, заполненный временем
    int i;

    //УПОРЯДОЧЕННЫЙ МАССИВ  //УПОРЯДОЧЕННЫЙ МАССИВ  //УПОРЯДОЧЕННЫЙ МАССИВ  //УПОРЯДОЧЕННЫЙ МАССИВ
    a(Array, N);
    cout << "Начальный массив (упорядоченный):" << endl;
    for (i = 0; i < N; i++)
        cout << Array[i] << setw(4);
    cout << endl;

    //начало сортировки подсчётом

    double aver_dur = 0;

    for (int i = 0; i < M; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        Counting_Sort(N, Array);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        dur_arr[i] = duration.count();//заполнение массива значениями времени

    }

    cout << "Сортировка подсчётом:" << endl;
    for (i = 0; i < N; i++)
        cout << Array[i] << setw(4);
    cout << endl;

    dur_(dur_arr, M, aver_dur);//сортировка массива со значениями времени и расчёт среднего значения
    cout << endl;

    //начало сортировки Шелла
    a(Array2, N);
    /*cout << "Начальный массив (упорядоченный):" << endl;
    for (i = 0; i < N; i++)
      cout << Array2[i] << setw(4);
    cout << endl;*/

    aver_dur = 0;
    for (int i = 0; i < M; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        Shell_Sort(N, Array2);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        dur_arr[i] = duration.count();//заполнение массива значениями времени
    }

    cout << "Сортировка Шелла:" << endl;
    for (i = 0; i < N; i++)
        cout << Array2[i] << setw(4);
    cout << endl;

    dur_(dur_arr, M, aver_dur);//сортировка массива со значениями времени и расчёт среднего значения
    cout << endl;

    //начало сортировки кучей
    a(Array3, N);
    /*cout << "Начальный массив (упорядоченный):" << endl;
    for (i = 0; i < N; i++)
      cout << Array3[i] << setw(4);
    cout << endl;*/

    aver_dur = 0;
    for (int i = 0; i < M; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        Heap_Sort(Array3, N);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        dur_arr[i] = duration.count();//заполнение массива значениями времени
    }

    cout << "Сортировка кучей:" << endl;
    for (i = 0; i < N; i++)
        cout << Array3[i] << setw(4);
    cout << endl;

    dur_(dur_arr, M, aver_dur);//сортировка массива со значениями времени и расчёт среднего значения
    cout << endl;

    //УПОРЯДОЧЕННЫЙ В ОБРАТНОМ ПОРЯДКЕ МАССИВ  //УПОРЯДОЧЕННЫЙ В ОБРАТНОМ ПОРЯДКЕ МАССИВ

    //начало сортировки подсчётом
    b(Array, N);
    cout << "Начальный массив (упорядоченный в обратном порядке):" << endl;
    for (i = 0; i < N; i++)
        cout << Array[i] << setw(4);
    cout << endl;

    aver_dur = 0;
    for (int i = 0; i < M; i++)
    {
        b(Array, N);

        auto start = std::chrono::high_resolution_clock::now();
        Counting_Sort(N, Array);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        dur_arr[i] = duration.count();//заполнение массива значениями времени
    }

    cout << "Сортировка подсчётом:" << endl;
    for (i = 0; i < N; i++)
        cout << Array[i] << setw(4);
    cout << endl;

    dur_(dur_arr, M, aver_dur);//сортировка массива со значениями времени и расчёт среднего значения
    cout << endl;

    //начало сортировки Шелла
    b(Array2, N);
    /*cout << "Начальный массив (упорядоченный в обратном порядке):" << endl;
    for (i = 0; i < N; i++)
      cout << Array2[i] << setw(4);
    cout << endl;*/

    aver_dur = 0;
    for (int i = 0; i < M; i++)
    {
        b(Array2, N);

        auto start = std::chrono::high_resolution_clock::now();

        Shell_Sort(N, Array2);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        dur_arr[i] = duration.count();//заполнение массива значениями времени

    }

    cout << "Сортировка Шелла:" << endl;
    for (i = 0; i < N; i++)
        cout << Array2[i] << setw(4);
    cout << endl;

    dur_(dur_arr, M, aver_dur);//сортировка массива со значениями времени и расчёт среднего значения
    cout << endl;

    //начало сортировки кучей

    b(Array3, N);
    /*cout << "Начальный массив (упорядоченный в обратном порядке):" << endl;
    for (i = 0; i < N; i++)
      cout << Array3[i] << setw(4);
    cout << endl;*/

    aver_dur = 0;
    for (int i = 0; i < M; i++)
    {
        b(Array3, N);

        auto start = std::chrono::high_resolution_clock::now();
        Heap_Sort(Array3, N);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        dur_arr[i] = duration.count();//заполнение массива значениями времени
    }

    cout << "Сортировка кучей:" << endl;
    for (i = 0; i < N; i++)
        cout << Array3[i] << setw(4);
    cout << endl;

    dur_(dur_arr, M, aver_dur);//сортировка массива со значениями времени и расчёт среднего значения
    cout << endl;

    //НЕУПОРЯДОЧЕННЫЙ МАССИВ  //НЕУПОРЯДОЧЕННЫЙ МАССИВ  //НЕУПОРЯДОЧЕННЫЙ МАССИВ  //НЕУПОРЯДОЧЕННЫЙ МАССИВ
    //начало сортировки вставками 
    c(Array, N);
    for (i = 0; i < N; i++)//копия рандомного массива
    {
        Array2[i] = Array[i];
        Array3[i] = Array[i];
    }

    cout << "Начальный массив (неупорядоченный):" << endl;
    for (i = 0; i < N; i++)
        cout << Array[i] << setw(4);
    cout << endl;

    aver_dur = 0;
    for (int i = 0; i < M; i++)
    {

        c(Array, N);

        auto start = std::chrono::high_resolution_clock::now();
        Counting_Sort(N, Array);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        dur_arr[i] = duration.count();//заполнение массива значениями времени
    }

    cout << "Сортировка подсчётом:" << endl;
    for (i = 0; i < N; i++)
        cout << Array[i] << setw(4);
    cout << endl;

    dur_(dur_arr, M, aver_dur);//сортировка массива со значениями времени и расчёт среднего значения
    cout << endl;

    //начало сортировки Шелла

    /*cout << "Начальный массив (неупорядоченный):" << endl;
    for (i = 0; i < N; i++)
      cout << Array2[i] << setw(4);
    cout << endl;*/

    aver_dur = 0;
    for (int i = 0; i < M; i++)
    {
        c(Array2, N);

        auto start = std::chrono::high_resolution_clock::now();
        Shell_Sort(N, Array2);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        dur_arr[i] = duration.count();//заполнение массива значениями времени
    }

    cout << "Сортировка Шелла:" << endl;
    for (i = 0; i < N; i++)
        cout << Array2[i] << setw(4);
    cout << endl << endl;

    dur_(dur_arr, M, aver_dur);//сортировка массива со значениями времени и расчёт среднего значения
    cout << endl;

    //начало сортировки кучей

    //cout << "Начальный массив (неупорядоченный):" << endl;
    //for (i = 0; i < N; i++)
    //  cout << Array3[i] << setw(4);
    //cout << endl;

    aver_dur = 0;
    for (int i = 0; i < M; i++)
    {
        c(Array3, N);

        auto start = std::chrono::high_resolution_clock::now();
        Heap_Sort(Array3, N);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        dur_arr[i] = duration.count();//заполнение массива значениями времени
    }

    cout << "Сортировка кучей:" << endl;
    for (i = 0; i < N; i++)
        cout << Array3[i] << setw(4);
    cout << endl << endl;
    dur_(dur_arr, M, aver_dur);//сортировка массива со значениями времени и расчёт среднего значения
    cout << endl;
}
void a(int array[], int n)//упорядоченный массив
{
    int i;
    for (i = 0; i < n; i++)
        array[i] = i + 1;
}
void b(int array[], int n)//упорядоченный в обратном порядке
{
    int i;
    int k = n;
    for (i = 0; i < n; i++, k--)
    {
        array[i] = k;
    }
}
void c(int array[], int n)//неупорядоченный массив
{
    int i;
    for (i = 0; i < n; i++)
        array[i] = i + 1;
    for (int i = 0; i < n; ++i)
        swap(array[i], array[rand() % n]);
}
void dur_(double duration[], int n, double aver_dur)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (duration[i] < duration[j])
                swap(duration[i], duration[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        //cout << "Duration " << i << " = " << duration[i] << "s\n";
        if (i <= 350 & i >= 150)
            aver_dur += duration[i];
    }
    printf("Среднее значение времени : = %.8lf\n", aver_dur / 200);
}
void Counting_Sort(int n, int mas[])
{
    int* new_mas;
    new_mas = (int*)malloc(n * sizeof(int));
    int k;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
        {
            if (mas[i] > mas[j])
                k++;
        }
        new_mas[k] = mas[i];
    }
    for (int i = 0; i < n; i++)
    {
        mas[i] = new_mas[i];
    }
}
void Shell_Sort(int n, int mas[])
{
    int i, j, step;
    int temp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            temp = mas[i];
            for (j = i; j >= step; j -= step)
            {
                if (temp < mas[j - step])
                    mas[j] = mas[j - step];
                else
                    break;
            }
            mas[j] = temp;
        }
}
void siftDown(int* mas, int root, int bottom)
{
    int maxChild;
    int done = 0;

    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;

        else if (mas[root * 2] > mas[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (mas[root] < mas[maxChild])
        {
            int temp = mas[root];
            mas[root] = mas[maxChild];
            mas[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}
void Heap_Sort(int* mas, int n)
{
    for (int i = (n / 2); i >= 0; i--)
        siftDown(mas, i, n - 1);
    for (int i = n - 1; i >= 1; i--)
    {
        int temp = mas[0];
        mas[0] = mas[i];
        mas[i] = temp;
        siftDown(mas, 0, i - 1);
    }
}