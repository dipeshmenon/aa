
#include<iostream>
#include<algorithm>

void bucketSort(float arr[], int size) {
    const int bucketSize = 10; // Assuming 10 buckets
    float buckets[bucketSize][size];
    int bucketIndex[bucketSize] = {0};

   
    for (int i = 0; i < size; ++i) {
        int index = arr[i] * bucketSize;
        buckets[index][bucketIndex[index]++] = arr[i];
    }

    // Sort elements within each bucket
    for (int i = 0; i < bucketSize; ++i) {
        std::sort(buckets[i], buckets[i] + bucketIndex[i]);
    }

    // Merge buckets back into the original array
    int k = 0;
    for (int i = 0; i < bucketSize; ++i) {
        for (int j = 0; j < bucketIndex[i]; ++j) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    float arr[n];
    std::cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    bucketSort(arr, n);

    std::cout << "The sorted array is: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
