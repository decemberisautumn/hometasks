#include <iostream>
#include <cstring>

void toggleCase(char str[]) {
	for(; *str; ++str) {
		if(*str >= 'A' && *str <= 'Z')
			*str = *str + ('a' - 'A');
		else if(*str >= 'a' && *str <= 'z')
			*str = *str - ('a' - 'A');
	}
}

void reverse(char str[], int len) {
		for(int i = 0; i < len / 2; ++i) {
				int tmp = str[i];
				str[i] = str[len - i - 1];
				str[len - i - 1] = tmp;
		}
}

void reverseLetters(char str[]) {
		while(*str) {
				int word_end = 0;
				while(*str == ' ')
						++str;
				while(str[word_end] && str[word_end] != ' ')
						++word_end;

				reverse(str, word_end);

				str += word_end + 1;
		}
}

void reverseWords(char str[]) {
		reverse(str, strlen(str));
		reverseLetters(str);
}

int main() {
		char input1[] = "AbX 1D2 !a";
		toggleCase(input1);
		std::cout << input1 << '\n';

		char input2[] = "hello bye";
		reverseLetters(input2);
		std::cout << input2 << '\n';

		char input3[] = "hello bye";
		reverseWords(input3);
		std::cout << input3 << '\n';

		return 0;
}

