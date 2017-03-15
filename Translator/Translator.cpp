#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_WORD 18
#define WORD_SIZE 10
#define STR_SIZE 127

char Dic[MAX_WORD][2][50] = { { "i", "����" },
{ "you", "�ʴ�" },
{ "we", "�츮��" },
{ "they", "�׵���" },
{ "he", "�״�" },
{ "she", "�׳��" },
{ "my", "����" },
{ "me", "����" },
{ "your", "����" },
{ "his", "����" },
{ "him", "�׸�" },
{ "her", "�׳���" },
{ "boy", "�ҳ�" },
{ "girl", "�ҳ�" },
{ "a", "�ϳ���" },
{ "an", "�ϳ���" },
{ "teacher", "������" },
{ "student", "�л�" }
};

void Translate(char[]);

void main()
{
	char cInputWord[STR_SIZE];

	while (1){
		printf("������ �Է��ϼ���(127��): ");
		gets(cInputWord);

		Translate(cInputWord);
	}
}

//���ڿ��� �����̳� \0�� ������
//����, \0 ������ ���ڿ��� ����
// ����� ���ڿ��� Dic���� ã�Ƽ�
//������ �ٲ��ְ� ������ �״�� ����
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