#include"Header.h"
void create_array_1(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

}
void create_array_random(int arr[], int size) {
    srand(time(NULL));
    int MAX = 100;
    int MIN = 0;
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (MAX - MIN) + MIN;
    }
}

void write_int_file(int arr[], int size, string s) {
    ofstream fout;
    fout.open("array.txt");
    fout.close();
    fout.open("array.txt");
    for (int i = 0; i < size; i++) {
        fout << arr[i] << " ";
    }
    fout << endl << s;
    cout << endl;
    fout.close();
}
void write_int_file_1(string s, string s1, string s3)
{
    ofstream fout;
    fout.open("array.txt");
    fout.close();
    fout.open("array.txt");
    fout << " В " << s << " найти : " << s1 << endl << "Ответ: " << s3;
    fout.close();
}
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int search_element_linaly(int arr[], int size, int number) {
    int is = -1;
    arr[size] = number;
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            is = i;
            break;
        }
    }
    return is;
}
int barrierSearch(int* mas, int size, int value) {

    int index = 0;
    if (mas[size - 1] != value) {

        mas[size - 1] = value;
        for (; mas[index] != value; index++);
    }
    else
        return (size - 1);

    return index < size - 1 ? index : -1;
}


int split(int arr[], int lo, int hi)
{
    int i = lo - 1;
    // select last element as pivot
    int pivot = hi;
    // All elements less than arr[pivot] are brought to left side
    // This splits array into two parts
    // array -> [left subarr] [pivot] [right subarr]
    for (int j = lo; j < pivot; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Bring pivot element to it's correct postion in sorted array
    // by swapping smallest element of right subarray with pivot
    swap(arr[i + 1], arr[pivot]);
    return i + 1;
}
void shellSort(int list[], int listLength)
{
    for (int step = listLength / 2; step > 0; step /= 2)
    {
        for (int i = step; i < listLength; i += 1)
        {
            int j = i;
            while (j >= step && list[j - step] > list[i])
            {
                swap(list[j], list[j - step]);
                j -= step;
            }
        }
    }
}

int binarySearch(int* mas, int size, int value) {

    shellSort(mas, size);
    int indexLeft = 0;
    int indexRight = size - 1;
    int index = 0;

    while (indexLeft <= indexRight)
    {
        index = (indexRight + indexLeft) / 2;
        if (mas[index] == value) {
            return index;
        }
        if (mas[index] > value) {
            indexRight = index - 1;
        }
        else {
            indexLeft = index + 1;
        }
    }

    return -1;
}


bool search_linely_string(string stroka, string search_word) {
    bool is = false;
    for (int i = 0; i < stroka.length();) {
        for (int j = 0, l = i; j < search_word.length(); j++, l++) {
            if (stroka[l] == search_word[j]) {
                is = true;
            }
            else {
                is = false;
                break;
            }
        }
        if (is) {
            is = true;
            break;
        }
        else {
            i++;
        }
    }
    return is;
}

int KMP(string text, string pattern)
{
    int m = text.length();
    int n = pattern.length();

    // если шаблон это пустая строка
    if (n == 0)
    {
        cout << "string = 0";
        return 0;
    }
    int size = n + 1;
    int* next = new int[size];
    // если длина текста меньше длины шаблона
    if (m < n)
    {
        cout << pattern<<" not in string\n";
        return 0;
    }

    // next[i] сохраняет индекс следующего лучшего частичного совпадения


    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];

        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j];
        }

        if (j > 0 || pattern[j] == pattern[i]) {
            next[i + 1] = j + 1;
        }
    }

    for (int i = 0, j = 0; i < m; i++)
    {
        if (text[i] == pattern[j])
        {
            if (++j == n) {
                cout << pattern<<" in string" << endl;
                //return 1;
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    // так как `i` будет увеличен на следующей итерации
        }
    }
}

void badCharHeuristic(string str, int size,
    int badchar[256])
{
    int i;

    for (i = 0; i < 256; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}


int searchBM(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[256];

    badCharHeuristic(pat, m, badchar);

    int s = 0;

    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {

            return s;

            // s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }
    return -1;
}
int searchRC(string txt, string pat)
{
    int q = 31;
    int d = 52;
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {

        if (p == t) {

            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            if (j == M)
                return i;
            // cout << "Pattern found at index " << i
            //<< endl;
        }

        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;


            if (t < 0)
                t = (t + q);
        }
    }
    return -1;
}


