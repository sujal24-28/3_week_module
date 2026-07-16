#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}


void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    cout << "Enter Number of Students: ";
    cin >> N;

    vector<int> packages(N);
    cout << "Enter Package values (multiplied by 100): ";
    for (int i = 0; i < N; i++) {
        cin >> packages[i];
    }

    mergeSort(packages, 0, N - 1);

  
    for (int i = 0; i < N; i++) {
        cout << packages[i] << " ";
    }
    cout << endl;

    return 0;
}
// OUTPUT--

/*
Enter Number of Students: 6
Enter Package values (multiplied by 100): 450 1200 800 650 300 1500 
300 450 650 800 1200 1500 
*/