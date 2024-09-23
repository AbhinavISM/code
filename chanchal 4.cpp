#include <bits/stdc++.h> 
using namespace std;
#define ll long long
class Node{
    public:
    ll wFreq;
    ll pFreq;
    vector<Node*> children;
    Node(){
        wFreq = 0;
        pFreq = 0;
        children = vector<Node*>(26, NULL);
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        // Write your code here.
        root = new Node();
    }
    public:
    void insert(string &word){
        // Write your code here.
        auto temp = root;
        for(ll i = 0; i<word.length(); i++){
            if(temp->children[word[i]-'a']==NULL){
                temp->children[word[i]-'a'] = new Node();
            }
            temp = temp->children[word[i]-'a'];
            temp->pFreq++;
        }
        temp->wFreq++;
    }
    public:
    ll countPrefix(string &word){
        // Write your code here.
        auto temp = root;
        for(ll i = 0; i<word.length(); i++){
            if(temp->children[word[i]-'a']==NULL){
                return 0;
            }
            temp = temp->children[word[i]-'a'];
        }
        return temp->pFreq;
    }
};
bool cmp(string & w1, string & w2){
    return w1.size()>w2.size();
}
long long solution(vector<string> words){
    sort(words.begin(), words.end(), cmp);
	Trie t;
	ll ans = 0;
	for(string word : words) {
        reverse(word.begin(), word.end());
        ans += t.countPrefix(word);
		t.insert(word);
	}
	return ans;
}
int main(){
	// vector<string> words = {"back", "backdoor", "gammon", "backgammon", "comeback", "come", "door"};
    vector<string> words = {"cba", "a", "a", "b", "ba", "ca"};
    cout<<solution(words);
}