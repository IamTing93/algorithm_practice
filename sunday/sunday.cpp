#include <iostream>

#define MAX 100

int getLen(char* str) {
	register int counter = 0;
	while (str[counter++]);
	return counter - 1;
}

int sunday(char* s, int sLen, char* t, int tLen) {

	int next[26];

	for (register int i = 0; i < 26; i++) next[i] = tLen + 1;

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
		} else if (i + tLen < sLen) {
			i += next[s[i + tLen] - 'a'];
			ptr = 0;
		} else {
			break;
		}
	}
	return counter;
}

int main() {
	char s[MAX], t[MAX];

	std::cin >> s >> t;

	std::cout << sunday(s, getLen(s), t, getLen(t)) << std::endl;

	return 0;
}

