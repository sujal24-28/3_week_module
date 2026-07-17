#include <iostream>
#include <vector>
#include <iomanip>
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
    vector<int> times(N);
    for (int i = 0; i < N; i++) {
        cin >> times[i];
    }

    heapSort(times, N);

    for (int i = 0; i < N; i++) {
        cout << times[i] << " ";
    }
    cout << endl;

    int fastest = times[0];
    int slowest = times[N - 1];

    long long sum = 0;
    for (int t : times) sum += t;
    double avg = (double)sum / N;

    int countFaster = 0;
    for (int t : times) {
        if (t < avg) countFaster++;
    }
    double percentage = (double)countFaster * 100.0 / N;

    cout << "Fastest: " << fastest << endl;
    cout << "Slowest: " << slowest << endl;
    cout << "Average: " << fixed << setprecision(2) << avg << endl;
    cout << "Cases Faster Than Average: " << countFaster << endl;
    cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;

    return 0;
}
// OUTPUT--

/*
8
12 7 15 9 20 5 10 8 
5 7 8 9 10 12 15 20 
Fastest: 5
Slowest: 20
Average: 10.75
Cases Faster Than Average: 5
Percentage: 62.50%
*/