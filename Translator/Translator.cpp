#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_WORD 18
#define WORD_SIZE 10
#define STR_SIZE 127

char Dic[MAX_WORD][2][50] = { { "i", "나는" },
{ "you", "너는" },
{ "we", "우리는" },
{ "they", "그들은" },
{ "he", "그는" },
{ "she", "그녀는" },
{ "my", "나의" },
{ "me", "나를" },
{ "your", "너의" },
{ "his", "그의" },
{ "him", "그를" },
{ "her", "그녀의" },
{ "boy", "소년" },
{ "girl", "소녀" },
{ "a", "하나의" },
{ "an", "하나의" },
{ "teacher", "선생님" },
{ "student", "학생" }
};

void Translate(char[]);

void main()
{
	char cInputWord[STR_SIZE];

	while (1){
		printf("문장을 입력하세요(127자): ");
		gets(cInputWord);

		Translate(cInputWord);
	}
}

//문자열에 공백이나 \0이 있으면
//공백, \0 전까지 문자열을 복사
// 복사된 문자열을 Dic에서 찾아서
//있으면 바꿔주고 없으면 그대로 삽입
void Translate(char input[])
{
	char cWord[WORD_SIZE];
	char cOutput[STR_SIZE] = "\0";
	int start = 0, end;
	int i, j, k;

	for (i = 0; i <= strlen(input); i++){
		if ((input[i] == ' ') || (input[i] == '\0')){
			end = i - 1;
			for (j = start, k = 0; j <= end; j++, k++){
				cWord[k] = input[j];
			}
			cWord[k] = '\0';
			start = i + 1;

			for (j = 0; j < MAX_WORD; j++){
				if (strcmp(cWord, Dic[j][0]) == 0){
					strcat(cOutput, Dic[j][1]);
					break;
				}
			}
			if (j == MAX_WORD)	strcat(cOutput, cWord);
			strcat(cOutput, " ");
		}
	}
	printf("\n#%s\n\n", cOutput);
}