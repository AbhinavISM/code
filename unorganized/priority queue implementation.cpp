#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> pq;
    public:
    PriorityQueue() {
    }

    void insert(int element) {
        pq.push_back(element);
        int childIdx = pq.size()-1;
        while(childIdx>0){
            int parIdx = (childIdx-1)/2;
            if(pq[parIdx]<pq[childIdx]) swap(pq[parIdx], pq[childIdx]);
            else break;
            childIdx = parIdx;
        }
        // Implement the insert() function here
    }

    int getMax() {
        if(pq.size()==0) return INT_MIN;
        return pq[0];
        // Implement the getMax() function here
    }

    int removeMax() {
        if(pq.size()==0) return INT_MIN;
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int parIdx = 0;
        while(parIdx<pq.size()){
            int leftChild = parIdx*2+1;
            int rightChild = parIdx*2+2;
            int maxIdx = parIdx;

            if(leftChild<pq.size()&&pq[leftChild]>pq[maxIdx]){
                maxIdx = leftChild;
            }
            if(rightChild<pq.size()&&pq[rightChild]>pq[maxIdx]){
                maxIdx = rightChild;
            }
            if(maxIdx==parIdx) break;
            swap(pq[parIdx], pq[maxIdx]);
            parIdx = maxIdx;
        }
        return  ans;
        // Implement the removeMax() function here
    }

    int getSize() { 
        return pq.size();
        // Implement the getSize() function here
    }

    bool isEmpty() {
        return pq.size()==0;
        // Implement the isEmpty() function here
    }
};