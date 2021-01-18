#include <stdio.h>
#include <malloc.h>
#include <random>
#include <time.h>
#include <ctime>
#include <locale.h>

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int main() {
    setlocale(LC_ALL, "Rus");
    clock_t time1, time2;
    int n;
    printf("Случайная последовательность\n ");
    printf("Введите количество элементов массива: ");
    scanf_s("%d", &n);
    int* arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = ((rand() % 2001) - 1000);
    }
    printf("\n");
    time1 = clock();
    qs(arr, 0, n - 1);
    time2 = clock();

    double seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Время сортировкой быстрой: %f\n", seconds);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = ((rand() % 2001) - 1000);
    }

    time1 = clock();
    shell(arr, n);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Время сортировки Шелла: %f\n", seconds);


    printf("\nВозрастающая последовательность\n ");

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    time1 = clock();
    qs(arr, 0, n - 1);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Время сортировкой быстрой: %f\n", seconds);

    time1 = clock();
    shell(arr, n);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Время сортировки Шелла: %f\n", seconds);

    printf("\nУбывающая последовательность\n ");


    int count = n;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = count;
        count--;
    }

    time1 = clock();
    qs(arr, 0, n - 1);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Время сортировкой быстрой: %f", seconds);

    count = n;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = count;
        count--;
    }

    time1 = clock();
    shell(arr, n);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Время сортировки Шелла: %f\n", seconds);

    printf("Возрастающая и убывающая\n");

    count = n;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            arr[i] = i;
        }
        else {
            arr[i] = count;
            count--;
        }
    }

    time1 = clock();
    qs(arr, 0, n - 1);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Время сортировкой быстрой: %f\n", seconds);

    count = n;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            arr[i] = i;
        }
        else {
            arr[i] = count;
            count--;
        }
    }

    time1 = clock();
    shell(arr, n);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Время сортировки Шелла: %f\n", seconds);

    printf("\nСтандартная qsort\n");

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = ((rand() % 2001) - 1000);
    }

    time1 = clock();
    qsort(arr, n, sizeof(int), compare);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Случайная последовательность: %f\n", seconds);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    time1 = clock();
    qsort(arr, n, sizeof(int), compare);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Возрастающая: %f\n", seconds);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = count;
        count--;
    }

    time1 = clock();
    qsort(arr, n, sizeof(int), compare);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Убывающая: %f\n", seconds);

    count = n;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            arr[i] = i;
        }
        else {
            arr[i] = count;
            count--;
        }
    }

    time1 = clock();
    qsort(arr, n, sizeof(int), compare);
    time2 = clock();

    seconds = (double)(time2 - time1) / CLOCKS_PER_SEC;
    printf("\n Наполовину: %f\n", seconds);

    return (0);


}
