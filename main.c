/*
    Подходящие протоколы:
    http, https, ftp
*/

/*
    Необходимые функции:
    - main()        управляющая функция: проверяет текущее состояние и полученный символ -> изменяет состояние, выполняет действия
    - add()         добавить символ в лексему
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
                    add(sym);
                    sym = getc(input);
                    cond = C1;
                }
                else if (sym == 'f')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C6;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            }
            case C1:
                if (sym == 't')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C2;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case C2:
                if (sym == 't')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C3;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case C3:
                if (sym == 'p')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C4;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case C4:
                if (sym == ':')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C8;
                }
                else if (sym == 's')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C7;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case C5:
                if (sym == 't')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C6;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case C6:
                if (sym == 'p')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C7;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case C7:
                if (sym == ':')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C8;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case C8:
                if (sym == '/')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C9;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case C9:
                if (sym == '/')
                {
                    add(sym);
                    sym = getc(input);
                    cond = C10;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case C10:
                if (sym != ' ' && sym != '\n' && sym != '\t')
                {
                    add(sym);
                    sym = getc(input);
                    cond = LEX;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                    cond = ERR;
                }
            case LEX:
                if (sym == ' ' && sym == '\n' && sym == '\t')
                {
                    lex_out();
                    clear();
                    sym = getc(input);
                    cond = C0;
                }
                else
                {
                    add(sym);
                    sym = getc(input);
                }
            case ERR:
                break;
        }
    }

    fclose(input);
    return 0;
}
