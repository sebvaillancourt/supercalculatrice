#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char input[101];
char input2[5]= {'e','x','i','t','\0'};
char charOperator[101];
char charOperand[101];
double operands[100];
int tokenNumber;
double tokens[100];
int result;
int open;

int main()
{
    int j = 0;
    char str[100] = "";
    input[0] = '\0';
    while(open==0)
    {
        cprintf("Supercalculatrice verion 0.1.1\necrit par Sebastien Vaillancourt\n\n", "GRAY");
        open=1;
    }
    cprintf("operation>", "BLUE");
    gets(input);
    result = checker(input, input2);
    if(result == 1)
    {
        exit(0);
    }
    else
    {

        for(int i = 0; input[i] != '\0'; ++i) //make sure we haven't reached the end of the string
        {
            if((input[i] >= '0'&& input[i]<='9') || input[i]=='/' || input[i]=='*' || input[i]=='-' || input[i]=='+' || input[i]==' ')
            {
                if(input[i]!=' ') //get rid of the spaces
                {
                    str[j]=input[i];
                    j++;
                }
                else
                {
                    str[j]=input[i];
                }
            }
            else //if none-recognized characters
            {
                cprintf("Invalid operation!\n", "RED");
                main();
            }
        }

        cprintf(str, "GREEN");
        cprintf("\n", "GREEN");
        main();
    }
}


int checker(char input[],char check[])
{
    int i,result=1;
    for(i=0; input[i]!='\0' || check[i]!='\0'; i++)
    {
        if(input[i] != check[i])
        {
            result=0;
            break;
        }
    }
    return result;
}
void cprintf(char text[1000], char color[11])
{
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    //First save the current color information
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    //Set the new color information
    if(color=="BLACK")
    {
        SetConsoleTextAttribute ( h, 0 );
    }
    else if(color=="DARKBLUE")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_BLUE );
    }
    else if(color=="DARKGREEN")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_GREEN );
    }
    else if(color=="DARKCYAN")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_BLUE );
    }
    else if(color=="DARKRED")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_RED );
    }
    else if(color=="DARKMAGENTA")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE );
    }
    else if(color=="DARKYELLOW")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_GREEN );
    }
    else if(color=="DARKGRAY")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
    }
    else if(color=="GRAY")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY );
    }
    else if(color=="BLUE")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_BLUE );
    }
    else if(color=="GREEN")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_GREEN );
    }
    else if(color=="CYAN")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE );
    }
    else if(color=="RED")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_RED );
    }
    else if(color=="MAGENTA")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE );
    }
    else if(color=="YELLOW")
    {
        SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN );
    }
    else
    {
        SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
    }

    printf ("%s", text);
    SetConsoleTextAttribute ( h, wOldColorAttrs);
}
