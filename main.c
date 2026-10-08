/*
    Подходящие протоколы:
    http, https, ftp
*/

/*
    Необходимые функции:
    - main()        управляющая функция: проверяет текущее состояние и полученный символ -> изменяет состояние, выполняет действия
    - add()         добавить символ в лексему
    - get_char()    сдвинуть указатель на следующий символ
    - lex_out()     вывести полученную лексему
    - clear()       очистить стек символов
*/

#include <stdio.h>
#include <stdlib.h>

enum condition
{
    C0,
    C1,
    C2,
    C3,
    C4,
    C5,
    C6,
    C7,
    C8,
    C9,
    C10,
    C11,
    C12,
    LEX,
    ERR
} cond = C0;

struct stack
{
    char sym;
    struct stack * prev;
} buffer;

void add(char sym)
{
    struct stack new;
    new.sym = sym;
    new.prev = &buffer;
    buffer = new;
    return;
}

void clear()
{
    struct stack new = {'\0', NULL};
    buffer = new;
    return;
}

void lex_out()
{
    for(; buffer.prev != NULL; buffer = *buffer.prev)
    {
        printf('%c', buffer.sym);
    }
}

int main()
{
    FILE * input = fopen("input.txt", "r");

    for (char sym = getc(input); sym != EOF; sym = getc(input))
    {
        switch(cond)
        {
            case C0:
            {

                if (sym == 'h')
                {

                }
                else if (sym == 'f')
                {

                }
                else
                {
                    
                }
            }
            case C1:
                break;
            case C2:
                break;
            case C3:
                break;
            case C4:
                break;
            case C5:
                break;
            case C6:
                break;
            case C7:
                break;
            case C8:
                break;
            case C9:
                break;
            case C10:
                break;
            case C11:
                break;
            case C12:
                break;
            case LEX:
                break;
            case ERR:
                break;
        }
    }

    fclose(input);
    return 0;
}
