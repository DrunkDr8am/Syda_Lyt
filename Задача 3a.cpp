#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void form2(char* in, char* Nepovt);
void form1(char* in, char* Povtor);
char* skip(char* str);
char* copyPovtor(char** from, char* to);
char* copyNepovt(char** from, char* to);
int check(char* s);
int getStr(char** s);

int main() {
    char* Povtor, * Nepovt;
    char* s = NULL; //строка источник
    char** p = &Nepovt; //строка приёмник
    int flag;

    //пока не ввели конец файла работает цикл
    while (1)
    {
        puts("vveditr stroky sostoyashyy is bykv or CTRL+Z to exit");
        flag = getStr(&s); //flag -  код ошибки
        if (flag == -1) //если он равен -1 - то ввели конец файла
        {
            puts("see you!");
            return 0;
        }
        if (flag == -2) //если равен -2 - нехватка памяти
        {
            puts("NYJNO BOL`SHE PAMYATI");
            return 0;
        }
        if (!check(s))
        {
            puts("err input! only words");
            free(s);
        }
        else
        {
            printf("\nvvedennaya stroka: \"%s\"\n", s);

            Nepovt = (char*)calloc((strlen(s) + 2), sizeof(char));
            Povtor = (char*)calloc((strlen(s) + 3), sizeof(char));

            form2(s, Nepovt);
            printf("\nstroka bez povtoryayshihsya bukv: \"%s\" \n", Nepovt);

            form1(s, Povtor);
            printf("\nstroka is povtoryayshihsya bykv: \"%s\" \n", Povtor);



            free(Povtor);
            free(Nepovt);
            free(s);
        }
    }
    return 0;
}
void form2(char* in, char* Nepovt) {
    int i;
    while (*(in = skip(in)))
    {
        Nepovt = copyNepovt(&in, Nepovt);
    }
}
void form1(char* in, char* Povtor) {
    while (*(in = skip(in)))
    {
        Povtor = copyPovtor(&in, Povtor);
    }
}
char* copyPovtor(char** from, char* to) //повторяющиеся буквы
{
    int i, k, a, b, n, l;
    n = 0;
    l = 1;
    k = strspn(*from, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM\t");
    for (i = 0; i < k; ++i)
    {
        a = **from;
        *(*from)--;
        b = **from;
        *(*from)++;
        if ((a == b) || (a == b + 32) || (a == b - 32))
        {
            strncat_s(to, 2 + strlen(to), *from, 1);
            n++;
        }
        *(*from)++;
    }
    if (n > 0)
    {
        strncat_s(to, 2 + strlen(to), " ", 1);
    }

    return to;
}
char* copyNepovt(char** from, char* to) {
    int i, k, a, b, n;
    n = 0;
    k = strspn(*from, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM\t");
    for (i = 0; i < k; ++i)
    {
        a = **from;
        *(*from)--;
        b = **from;
        *(*from)++;
        if ((a != b) && (a != b + 32) && (a != b - 32))
        {
            strncat_s(to, 2 + strlen(to), *from, 1);
        }
        *(*from)++;
    }
    strncat_s(to, 2 + strlen(to), " ", 1);
    return to;
}
//Пропуск пробелов
char* skip(char* str)
{
    while (*str && (*str < 'a' || *str>'z') && (*str < 'A' || *str>'Z'))
        str++;
    return str;
}
//Проверка, что строка состоит из букв
int check(char* s)
{
    int k;
    char c;
    k = strspn(s, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM \t"); //подсчитали сколько символов в ходит в перечисленные
    if (k == 0) {
        return 0;
    }
    c = *(s + k); //получили символ после них, если это нуль-байт, то строка ок, иначе - нет
    return c == '\0';
}
//Ввод
int getStr(char** s) //получаем строку из входного потока
{
    char buf[81];
    int n;           //сюда будет записываться результат scanf
    int len = 0;     //сюда длина результирующей строки
    *s = (char*)malloc(1);//указатель на результирующую сткроу
    **s = '\0';//ноль байт, пока строка имеет только конец строки

    do {
        n = scanf_s("%80[^\n]", buf, 81);//считываем буфер

        if (n < 0)
        {                      //если ввели конец файла (ctrl+Z), то будет -1
            free(*s);          //очищаем память, возвращаем пустой указатель
            return -1;
        }

        if (n > 0) {           //если буфер не пустой
            len += strlen(buf);//увеличиваем результирующую длину
            *s = (char*)realloc(*s, len + 1);//добавляем память
            if (*s)            //если память выделилась
                strcat_s(*s, len + 1, buf);//копируем строку из буфера в конец нашей строки
            else
            {            //если память не выделилась
                free(*s);//очищаем память
                return -2;
            }
        }
        else
            scanf_s("%*c");//если перенос строки, то очищаем входной поток
    } while (n > 0);       //пока во входном потоке есть хоть один символ
    return 0;
}