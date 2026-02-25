#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int input(int *a, int n);
void swap(int *x, int *y);
void sorting(int *a, int n);
void output(int *a, int n);

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n <= NMAX && n > 0) {
        int *arr = calloc(n, sizeof(int));
        if (arr != NULL) {
            if (input(arr, n)) {
                sorting(arr, n);
                output(arr, n);
            } else {
                printf("n/a");
            }
            free(arr);
        } else {
            printf("n/a");
        }
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int n) {
    int flag = 1;
    for (int *p = a; p - a < n; p++) {
        if (scanf("%d", p) != 1) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void sorting(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) swap(a + j, a + j + 1);
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}
