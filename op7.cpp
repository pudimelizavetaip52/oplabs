#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


using namespace std;

char s[100];                         // �������� �����
const int n = 20;
typedef char array[n][n];
array arr;                           // ����� ���

int create_words(char[], array);     // ���������� ������� � ������� ���
void long_word(array, int);          // ����� ���������� �����

//==================== ������� �����i� ====================
int main()
{
	int i;                           // ������� ��� � �����
	puts("enter string:");
	gets(s);                         // ������ �����
	i = create_words(s, arr);        // ��������� ������ � ������� ��� � �����
	long_word(arr, i);               // ������ �������� ����� � ���� �������
	system("pause");
}

//============ ���������� ������� � ������� ��� =============
int create_words(char str[], array mas)
{
	int k = 0;                       // ������� ������ � �����
	char *delimiter = "., ";         // �������� �� ������� �������
	char *p;                         // �������� �� ������� �������
	cout << "List of Words:" << endl;
	p = strtok(s, delimiter);        // ��������� ����� �������
	while (p != NULL)                // ���� � ����� � �������
	{
		strcpy(mas[k], p);           // �������� ������� ������� � �����
		puts(p);                     // ������� ������� ������� �� �����
		k++;                         // ������� �� �������� �������
		p = strtok(NULL, delimiter); // ���������� ����� ������
	}
	cout << "number of words=" << k << endl;
	return k;                        // ��������� ������� ���
}

//============== ����� ���������� ����� =============
void long_word(array mas, int k)
{
	int maxlen;                      // ������� �������� �����
	char maxword[20];                // �������� ����� 
	strcpy(maxword, mas[0]);         // �������� ������� �����
	maxlen = strlen(maxword);        // ������� ������� �����
	for (int j = 1; j < k; j++)      // �������� ��� ��� �����
		if (strlen(mas[j]) > maxlen)
		{
			strcpy(maxword, mas[j]);     // ������� �������� �����
			maxlen = strlen(maxword);    // ������� �������� �������
		}
	cout << "masxword=" << maxword << endl;
	cout << "its length=" << maxlen << endl;
}