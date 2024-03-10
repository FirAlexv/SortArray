#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void BubbleSort (int* array, int size);
void QuickSortRecursive (int* mas, int size);

void CoutArray (int* array, int size);
int* CreateFillArray (int size);
bool CheckSize (int size);

unsigned int Stopwatch (unsigned int start_time, unsigned int end_time);

int main ()
{
    //Размер массива и диапазон значений генерации случайныйх чисел
    const int size = 1000000;

    unsigned int start_time = 0;
    unsigned int end_time = 0;

    int* myArray = CreateFillArray (size);

    //Тестовый вывод
    /*cout << "Fill array:\n";
    CoutArray (myArray, size);*/

    //Пузырек
    /*start_time = clock ();
    BubbleSort (myArray, size);
    end_time = clock ();
    cout << "BubbleSort array: " << Stopwatch (start_time, end_time) << " ms" << endl;*/

    //Блок быстрой сортировки
    start_time = clock ();
    QuickSortRecursive (myArray, size);
    end_time = clock ();
    cout << "QuickSortRecursive array working time: " << Stopwatch (start_time, end_time) << " ms" << endl;

    //Тестовый вывод
    /*cout << "Sorted array:\n";
    CoutArray (myArray, size);*/

    return 0;
}

/// <summary>
/// Вывод массива
/// </summary>
/// <param name="array">Указатель на массив</param>
/// <param name="size">Размер массива</param>
void CoutArray (int* array, int size)
{
    if (CheckSize (size))
    {
        for (int i = 0; i < size; i++)
            cout << "element[" << i << "]:" << array[i] << '\n';
        cout << endl;
    }
}

/// <summary>
/// Заполнение массива
/// </summary>
/// <param name="array">Массив</param>
/// <param name="size">Размер массива</param>
int* CreateFillArray (int size)
{
    srand (time (0));
    int* array;

    if (CheckSize (size))
    {
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = 1 + rand () % size;
        }
        return array;
    }
}

/// <summary>
/// Проверка размера
/// </summary>
/// <param name="size">Размер</param>
/// <returns>true - размер положительный, false - в противном случае</returns>
bool CheckSize (int size)
{
    if (size <= 0)
    {
        cout << "Invalid size" << endl;
        return false;
        exit (0);
    }
}

/// <summary>
/// Секундомер для отчета времени
/// </summary>
/// <param name="start_time">Время начала замера</param>
/// <param name="end_time">Времея конца замера</param>
/// <returns></returns>
unsigned int Stopwatch (unsigned int start_time, unsigned int end_time)
{
    return end_time - start_time;
}

/// <summary>
/// Сортировка пузырьком
/// </summary>
/// <param name="array">Указатель на массив</param>
/// <param name="size">Размер массива</param>
void BubbleSort (int* array, int size)
{
    int buf;
    if (CheckSize (size))
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    // меняем элементы местами
                    buf = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = buf;
                }
            }
        }
    }
}

/// <summary>
/// Быстрая сортировка
/// </summary>
/// <param name="array">Указатель на массив</param>
/// <param name="size">Размер массива</param>
void QuickSortRecursive (int* array, int size)
{
    if (CheckSize (size))
    {
        int i = 0;
        int j = size - 1;

        int mid = array[size / 2];

        do
        {
            while (array[i] < mid)
            {
                i++;
            }

            while (array[j] > mid)
            {
                j--;
            }

            if (i <= j)
            {
                int buf = array[i];
                array[i] = array[j];
                array[j] = buf;

                i++;
                j--;
            }
        } while (i <= j);

        if (j > 0)
        {
            //Left
            QuickSortRecursive (array, j + 1);
        }
        if (i < size)
        {
            //Right
            QuickSortRecursive (&array[i], size - i);
        }
    }
}