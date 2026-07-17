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
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
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
    cout << "Enter Number of Order: ";
    cin >> N;

    vector<int> times(N);
    cout << "Enter Processing times: ";
    for (int i = 0; i < N; i++) {
        cin >> times[i];
    }

    mergeSort(times, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << times[i] << " ";
    }
    cout << endl;

    double median;
    if (N % 2 == 1) {
        median = times[N / 2];
    } else {
        median = (times[N / 2 - 1] + times[N / 2]) / 2.0;
    }
    cout << "Median: " << median << endl;

    int countAbove = 0;
    for (int i = 0; i < N; i++) {
        if (times[i] > median) countAbove++;
    }
    cout << "Orders Above Median: " << countAbove << endl;

    int difference = times[N - 1] - times[0];
    cout << "Difference: " << difference << endl;

    return 0;
}
// OUTPUT--

/*
Enter Number of Order: 7
Enter Processing times: 12 25 18 30 15 22 40
12 15 18 22 25 30 40 
Median: 22
Orders Above Median: 3
Difference: 28
*/