#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Function to swap elements (used in sorting)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort (for simplicity)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function for Binary Search
int binarySearch(int arr[], int n, int key, int *comparisons) {
    int left = 0, right = n - 1;
    *comparisons = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        (*comparisons)++;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n, key;

    printf("Enter number of products: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter product IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter product ID to search: ");
    scanf("%d", &key);

    int comparisons;

    // -------- Linear Search --------
    int index1 = linearSearch(arr, n, key, &comparisons);
    printf("\n--- Linear Search ---\n");
    if (index1 != -1)
        printf("Product found at index %d\n", index1);
    else
        printf("Product not found\n");
    printf("Comparisons: %d\n", comparisons);

    // -------- Sorting --------
    bubbleSort(arr, n);

    printf("\nSorted Product IDs:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // -------- Binary Search --------
    int index2 = binarySearch(arr, n, key, &comparisons);
    printf("\n\n--- Binary Search ---\n");
    if (index2 != -1)
        printf("Product found at index %d (in sorted array)\n", index2);
    else
        printf("Product not found\n");
    printf("Comparisons: %d\n", comparisons);

    return 0;
}