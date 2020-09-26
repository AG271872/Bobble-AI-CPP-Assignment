#include <bits/stdc++.h>
using namespace std;

vector<struct trie *> v;
int x=0;
struct trie{
    char data;
    struct trie *child[26];
    struct trie *parent;
    bool isend;
    int val;


    trie(struct trie *par,char ch){
      memset(child,0,sizeof(child));
      parent =par;
      isend=false;
      data=ch;
      val=0;
    }
};

struct trie *root=NULL;

void insert(string str,int key){

    struct trie *cur=root;
    int ind;
    for(char ch : str){
        if(ch >=65 && ch<=90)
          ind=ch-'A';

        else
          ind=ch-'a';
        if(cur->child[ind]==NULL)
            cur->child[ind] = new trie(cur,ch);
        cur=cur->child[ind];
    }
    cur->val=key;
    cur->isend=true;
    v.push_back(cur);
    ++x;
}

void readFile(string fname) {
   //string fname="EnglishDictionary.csv";
    ifstream fr(fname);
    string word;
    string freq;
    if(!fr.is_open())
        cout<<"file not open";
    while(fr.good()){
    getline(fr,word,',');
    getline(fr,freq,'\n');
    insert(word,stoi(freq));
   }
   fr.close();
}

string  backtrack(struct trie *cur){

     string word;

     while(cur!=NULL){
         word+=cur->data;
         cur=cur->parent;
     }
     cout<<endl;
     reverse(word.begin(),word.end());
    return word;
 }

void display(int ind){

 string s;
 int x=1;
 auto i=v.begin();
        for( i;i!=v.end();i++)
        {
            if(x==ind)
                break;
            x++;
        }
        cout<<"word ="<< backtrack(*i)<<endl;

}
int main(){


    root = new trie(NULL,'\0');
    readFile("EnglishDictionary.csv");

    int n;
    cin>>n;
    while(n--){
        int ind;
        cin>>ind;
        display(ind);
    }


}
