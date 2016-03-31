#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


using namespace std;

char s[100];                         // вихідний рядок
const int n = 20;
typedef char array[n][n];
array arr;                           // масив слів

int create_words(char[], array);     // визначення переліку і кількості слів
void long_word(array, int);          // пошук найдовшого слова

//==================== головна функцiя ====================
int main()
{
	int i;                           // кількість слів у рядку
	puts("enter string:");
	gets(s);                         // ввести рядок
	i = create_words(s, arr);        // визначити перелік і кількість слів у рядку
	long_word(arr, i);               // знайти найдовше слово і його довжину
	system("pause");
}

//============ визначення переліку і кількості слів =============
int create_words(char str[], array mas)
{
	int k = 0;                       // кількість лексем у рядку
	char *delimiter = "., ";         // покажчик на розділові символи
	char *p;                         // покажчик на поточну лексему
	cout << "List of Words:" << endl;
	p = strtok(s, delimiter);        // визначити першу лексему
	while (p != NULL)                // поки є рядку є лексеми
	{
		strcpy(mas[k], p);           // копіювати поточну лексему в масив
		puts(p);                     // вивести поточну лексему на екран
		k++;                         // перейти до наступної лексеми
		p = strtok(NULL, delimiter); // продовжити пошук лексем
	}
	cout << "number of words=" << k << endl;
	return k;                        // повернути кількість слів
}

//============== пошук найдовшого слова =============
void long_word(array mas, int k)
{
	int maxlen;                      // довжина шуканого слова
	char maxword[20];                // найдовше слово 
	strcpy(maxword, mas[0]);         // значення першого слова
	maxlen = strlen(maxword);        // довжина першого слова
	for (int j = 1; j < k; j++)      // перегляд усіх слів рядка
		if (strlen(mas[j]) > maxlen)
		{
			strcpy(maxword, mas[j]);     // поточне найдовше слово
			maxlen = strlen(maxword);    // поточна найбільша довжина
		}
	cout << "masxword=" << maxword << endl;
	cout << "its length=" << maxlen << endl;
}