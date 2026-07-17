#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


int partition(vector<long long>& arr, int low, int high) {
    long long pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<long long>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    cin >> N;
    vector<long long> trades(N);

    for (int i = 0; i < N; i++) {
        cin >> trades[i];
    }

    quickSort(trades, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << trades[i] << " ";
    }
    cout << endl;

    cout << "Top 5: ";
    for (int i = 0; i < 5; i++) {
        cout << trades[i] << " ";
    }
    cout << endl;

    long long sumTop5 = 0;
    for (int i = 0; i < 5; i++) {
        sumTop5 += trades[i];
    }
    double avgTop5 = (double)sumTop5 / 5.0;
    cout << "Average of Top 5: " << fixed << setprecision(0) << avgTop5 << endl;

    long long sumAll = 0;
    for (int i = 0; i < N; i++) {
        sumAll += trades[i];
    }
    double overallAvg = (double)sumAll / N;

    int countAboveAvg = 0;
    for (int i = 0; i < N; i++) {
        if (trades[i] > overallAvg) {
            countAboveAvg++;
        }
    }
    cout << "Values Above Overall Average: " << countAboveAvg << endl;

    return 0;
}
// OUTPUT--

/*
8 
500 1200 700 2000 900 1500 3000 2500 
3000 2500 2000 1500 1200 900 700 500 
Top 5: 3000 2500 2000 1500 1200 
Average of Top 5: 2040
Values Above Overall Average: 3
*/