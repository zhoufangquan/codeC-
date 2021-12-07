#include<iostream>
#include<string>
#include<vector>

using namespace std;

class WordDictionary {  //  ×ÖµäÊ÷Àà
private:
    vector<WordDictionary*> children;
    bool isEnd;

    // WordDictionary* searchPrefix(string prefix) {
    //     WordDictionary* node = this;
    //     for (int i=0;i<prefix.length();i++) {
    //         char ch = prefix[i];
    //         if(ch = '.'){
                
    //         }
    //         else{
    //             ch -= 'a';
    //             if (node->children[ch] == nullptr) {
    //                 return nullptr;
    //             }
    //             node = node->children[ch];
    //         }
    //     }
    //     return node;
    // }

public:
    WordDictionary() : children(26), isEnd(false) {}

    void addWord(string word) {
        WordDictionary* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new WordDictionary();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        WordDictionary* node = this;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(ch == '.'){
                bool match = false;
                for(int j=0;j<26;j++){
                    if(node->children[j] == nullptr) continue;
                    if(node->children[j]->search(word.substr(i+1))){
                        match = true;
                    }
                    if(match) return true;
                }
                return false;
            }
            else{
                ch -= 'a';
                if(node->children[ch] == nullptr) return false;
                node = node->children[ch];
            }
        }
        return node != nullptr && node->isEnd;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


int main(){
    WordDictionary* obj = new WordDictionary();
    obj->addWord("apple");
    cout<<obj->search("apple")<<'\n';
    cout<<obj->search("app")<<'\n';
    obj->addWord("app");    
    cout<<obj->search("app")<<'\n';
    cout<<obj->search(".pp")<<'\n';
    cout<<obj->search(".a.")<<'\n';
    cout<<obj->search(".p.l.")<<'\n';
    return 0;
}