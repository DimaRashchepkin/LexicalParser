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
    struct stack * next;
} *first = NULL, *last = NULL;

void add(char sym)
{
    struct stack *new = malloc(sizeof(struct stack));
    new->sym = sym;
    new->next = NULL;
    if (first == NULL)
    {
        first = new;
        last = new;
    }
    else
    {
        last->next = new;
        last = new;
    }
    return;
}

void clear()
{
    struct stack *p = first;
    while (p != NULL)
    {
        struct stack *next = p->next;
        free(p);
        p = next;
    }
    first = NULL;
    last = NULL;
}

void lex_out()
{
    for (struct stack *p = first; p != NULL; p = p->next)
    {
        printf("%c", p->sym);
    }
    printf("\n");
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
                    cond = C1;
                }
                else if (sym == 'f')
                {
                    add(sym);
                    cond = C5;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            }
            case C1:
                if (sym == 't')
                {
                    add(sym);
                    cond = C2;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case C2:
                if (sym == 't')
                {
                    add(sym);
                    cond = C3;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case C3:
                if (sym == 'p')
                {
                    add(sym);
                    cond = C4;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case C4:
                if (sym == ':')
                {
                    add(sym);
                    cond = C8;
                }
                else if (sym == 's')
                {
                    add(sym);
                    cond = C7;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case C5:
                if (sym == 't')
                {
                    add(sym);
                    cond = C6;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case C6:
                if (sym == 'p')
                {
                    add(sym);
                    cond = C7;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case C7:
                if (sym == ':')
                {
                    add(sym);
                    cond = C8;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case C8:
                if (sym == '/')
                {
                    add(sym);
                    cond = C9;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case C9:
                if (sym == '/')
                {
                    add(sym);
                    cond = C10;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case C10:
                if (sym != ' ' && sym != '\n' && sym != '\t')
                {
                    add(sym);
                    cond = LEX;
                }
                else
                {
                    add(sym);
                    cond = ERR;
                }
                break;
            case LEX:
                if (sym == ' ' || sym == '\n' || sym == '\t')
                {
                    lex_out();
                    clear();
                    cond = C0;
                }
                else
                {
                    add(sym);
                }
                break;
            case ERR:
                if (sym == ' ' || sym == '\n' || sym == '\t')
                {
                    clear();
                    cond = C0;
                }
                else
                {
                    add(sym);
                }
                break;
        }
    }
    if (cond == LEX)
    {
        lex_out();
        clear();
    }

    fclose(input);
    return 0;
}
