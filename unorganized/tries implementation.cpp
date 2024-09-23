#include <bits/stdc++.h> 
using namespace std;
class Node{
    public:
    int wFreq;
    int pFreq;
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
        for(int i = 0; i<word.length(); i++){
            if(temp->children[word[i]-'a']==NULL){
                temp->children[word[i]-'a'] = new Node();
            }
            temp = temp->children[word[i]-'a'];
            temp->pFreq++;
        }
        temp->wFreq++;
    }
    public:
    int countWordsEqualTo(string &word){
        // Write your code here.
        auto temp = root;
        for(int i = 0; i<word.length(); i++){
            if(temp->children[word[i]-'a']==NULL){
                return 0;
            }
            temp = temp->children[word[i]-'a'];
        }
        return temp->wFreq;
    }
    public:
    int countWordsStartingWith(string &word){
        // Write your code here.
        auto temp = root;
        for(int i = 0; i<word.length(); i++){
            if(temp->children[word[i]-'a']==NULL){
                return 0;
            }
            temp = temp->children[word[i]-'a'];
        }
        return temp->pFreq;
    }
    private:
    void deleteNode(Node* node){
        for(auto &child : node->children){
            if(child!=NULL) deleteNode(child);
            child = NULL;
        }
        delete node;
    }
    public:
    void erase(string &word){
        // Write your code here.
        auto temp = root;
        for(int i = 0; i<word.length(); i++){
            if(temp->children[word[i]-'a']->pFreq==1) {
                deleteNode(temp->children[word[i]-'a']);
                temp->children[word[i]-'a'] = NULL;
                return;
            }
            temp = temp->children[word[i]-'a'];
            temp->pFreq--;
        }
        temp->wFreq--;
    }
};
