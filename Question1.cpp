#include <iostream>
#include <stack>
#include <utility>//pair

using namespace std;

// Standard partition function (Lomuto scheme).
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Iterative quicksort using a stack 
void quicksort_iterative(int arr[], int n) {
    // empty stack to hold (start, end) of subarrays
    stack<pair<int,int>> st;

    // Push the entire array as our range
    st.push({0, n - 1});

    while (!st.empty()) {
        // Pop top of stack:
        auto [low, high] = st.top();
        st.pop();

        // Only sort if there are at least 2 elements
        if (low < high) {
            // Partition the subarray around a pivot
            int p = partition(arr, low, high);

            // Push left subarray boundaries if it has more than one element
            if (p - 1 > low) {
                st.push({low, p - 1});
            }
            // Push right subarray boundaries if it has more than one element
            if (p + 1 < high) {
                st.push({p + 1, high});
            }
        }
    }
}

int main() {
    int arr[] = { 10, 7, 5, 19, 11, 5, 1, 1, 2, 4, 67, 1092, };
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort_iterative(arr, n);

    cout << "Sorted array is in session:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}