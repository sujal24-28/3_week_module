#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    cout << "Enter Number of response Time: ";
    cin >> N;

    vector<int> responseTimes(N);
    cout << "Enter responseTime: ";
    for (int i = 0; i < N; i++) {
        cin >> responseTimes[i];
    }

    quickSort(responseTimes, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << responseTimes[i] << " ";
    }
    cout << endl;

    return 0;
}
//OUTPUT--

/*
Enter Number of response Time: 6
Enter responseTime: 120 45 78 200 60 95 
45 60 78 95 120 200 
*/
