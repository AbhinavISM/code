#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> queue;
    for (int i = 0; i < n; i++) {
    	int t;
    	cin>>t;
    	queue.push(t);
    }

    int cur_winner = queue.front();
    queue.pop();
    int win_count = 0;

    while (true) {
        int second_player = queue.front();
        queue.pop();

        if (cur_winner > second_player) {
            queue.push(second_player);
            win_count++;
        } else {
            queue.push(cur_winner);
            cur_winner = second_player;
            win_count = 1;
        }

        if (win_count == k || win_count == n - 1) {
            cout << cur_winner << endl;
            break;
        }
    }

    return 0;
}
