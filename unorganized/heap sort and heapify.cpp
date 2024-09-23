#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left <= n-1 && arr[largest] < arr[left]) {
        largest = left;
    }
            
    if(right <= n-1 && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int size) {
    while(size > 0) {
        swap(arr[0], arr[size-1]);

        size--;
        
        heapify(arr, size, 0);
    }
}

int32_t main() {
    vector<int> arr;
    int size = arr.size();
    
    // Heap creation (prerequisite for heap sort)
    for(int i = size/2-1; i>=0; i--) {
        heapify(arr, size, i);
    }

    // Calling heap sort
    heapSort(arr, size);

    return 0;
}