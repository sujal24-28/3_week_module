#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }
    heapSort(scores, N);
    for (int i = 0; i < N; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    return 0;
}
// OUTPUT--

/*
6
850 1200 950 600 1500 1000 
600 850 950 1000 1200 1500 
*/