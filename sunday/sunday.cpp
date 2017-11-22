#include <iostream>

#define MAX 100

int getLen(char* str) {
    register int counter = 0;
    while (str[counter++]);
    return counter - 1;
}

int sunday(char* s, char* t) {
    int tLen = getLen(t);
    int sLen = getLen(s);

    int next[26];

    for (register int i = 0; i < 26; i++) next[i] = 1;

    for (register int i = 0; i < tLen; i++) next[t[i] - 'a'] = tLen - i;

    int counter = 0;
    register int ptr = 0;
    for (register int i = 0; i <= sLen - tLen; ) {
      if (s[i + ptr] == t[ptr]) {
          ptr++;
          if (ptr == tLen) {
              counter++;
              ptr = 0;
              i += tLen;
          }
      } else {
          i += next[s[i + tLen] - 'a'];
          ptr = 0;
      }
    }
    return counter;
}

int main() {
    char s[MAX], t[MAX];

    std::cin >> s >> t;

    std::cout << sunday(s, t) << std::endl;

    return 0;
}
