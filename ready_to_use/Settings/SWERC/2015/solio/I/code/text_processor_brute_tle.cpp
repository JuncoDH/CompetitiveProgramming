// SWERC 2015 - Text Processor
// Approach: Brute Force. Insert substrings in the query interval in a Trie. O(Q * W^2) 
// Author: Miguel Oliveira
#include <cstdio>
#include <cstring>
const int MAX = 100010;

int w;
long long ans_window[MAX];
char text[MAX];

struct Trie {
  Trie* next[26];
  Trie() {
    memset(next, 0, sizeof next);
  }
};

int TrieInsert(Trie* node, int pos, int am) {
  int num_distinct = 0;
  for (int i = 0; i < am; ++i, ++pos) {
    int c = text[pos]-'a';
    if (!node->next[c]) {
      ++num_distinct;
      node->next[c] = new Trie();
    }
    node = node->next[c];
  }
  return num_distinct;
}

long long Query(int start) {
  Trie root;
  long long answer = 0;
  for (int i = 0; i < w; ++i) 
    answer += TrieInsert(&root, start+i, w-i);
  return answer;
}

int main(){
  int n, xx;
  scanf("%s %d %d\n", text, &n, &w); // n is the number of queries
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &xx);
    printf("%lld\n", Query(xx-1));
  }
  return 0;
}

