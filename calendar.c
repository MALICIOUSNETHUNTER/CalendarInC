#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h> // Added for exit()


int getKey();
void display(int, int, int, int[]);
void calendar(int, int);

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Setcolor(int Forgc)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int wColor;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) | (Forgc & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char *week[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main()
{
    int nmonth, nyear, ch;
enteryear:
    while (1)
    {
        printf("enter year and month (month): ");
        scanf("%d%d", &nyear, &nmonth);
        if (nyear < 1945)
        {
            printf("\n\t Please Enter year above 1945\n");
            continue;
        }
        else
        {
            calendar(nyear, nmonth);
        }
        while (1)
        {
            gotoxy(20, 20);
            printf("(*) Use LEFT, RIGHT, UP and DOWN arrow.");
            gotoxy(20, 22);
            printf("(*) Use F to go to specific year and month.");
            gotoxy(20, 24);
            printf("(*) Press ESC to Exit.");
            ch = getKey();
            switch (ch)
            {
            case 80: // Down arrow: next month
                if (nmonth == 12)
                {
                    nmonth = 1;
                    nyear++;
                }
                else
                {
                    nmonth++;
                }
                calendar(nyear, nmonth);
                break;
            case 72: // Up arrow: previous month
                if (nmonth == 1)
                {
                    nyear--;
                    nmonth = 12;
                }
                else
                {
                    nmonth--;
                }
                calendar(nyear, nmonth);
                break;
            case 77: // Right arrow: next year (assuming standard arrow key codes)
                nyear++;
                calendar(nyear, nmonth);
                break;
            case 75: // Left arrow: previous year
                if (nyear == 1945)
                {
                    gotoxy(15, 2);
                    printf("Year below 1945 is not available");
                }
                else
                {
                    nyear--;
                    calendar(nyear, nmonth);
                }
                break;
            case 27: // ESC
                system("cls");
                gotoxy(50, 14);
                printf("exiting program\n\n\n\n\n");
                exit(0);
            case 70: // F (assuming uppercase F, but getKey returns lowercase? Wait, getch() returns ASCII, F is 70)
                system("cls");
                goto enteryear;

            case 102: // F (assuming lowercase f, but getKey returns Uppercase? Wait, getch() returns ASCII, f is 102)
                system("cls");
                goto enteryear;
            }
        }
        break;
    }
    getch();
    return 0;
}

// displaying the calendar
void display(int nyear, int nmonth, int tdays, int days[])
{
    int i, j, pos;
    Setcolor(12);
    gotoxy(56, 6);
    printf("%s %d", month[nmonth - 1], nyear);

    // Print week headers
    int xpos[] = {31, 42, 51, 61, 71, 81, 91};
    for (i = 0; i < 7; i++)
    {
        if (i == 6)
            Setcolor(9);
        else
            Setcolor(10);
        gotoxy(xpos[i], 8);
        printf("%s", week[i]);
    }

    // Print days
    j = 10;
    pos = xpos[tdays];
    for (i = 0; i < days[nmonth - 1]; i++)
    {
        gotoxy(pos, j);
        printf("%d", i + 1);
        pos += 10;
        if (pos > 91)
        {
            pos = 31;
            j++;
        }
    }

    // Draw the border
    Setcolor(5);
    for (i = 22; i < 102; i++) // Horizontal lines
    {
        gotoxy(i, 4);
        printf("%c", 196);
        gotoxy(i, 17);
        printf("%c", 196);
    }
    // Corners
    gotoxy(21, 4);
    printf("%c", 218);
    gotoxy(102, 4);
    printf("%c", 191);
    gotoxy(21, 17);
    printf("%c", 192);
    gotoxy(102, 17);
    printf("%c", 217);
    // Vertical lines
    for (i = 5; i < 17; i++)
    {
        gotoxy(21, i);
        printf("%c", 179);
        gotoxy(102, i);
        printf("%c", 179);
    }
    Setcolor(11);
    gotoxy(24, 11);
    printf("%c", 174);
    gotoxy(98, 11);
    printf("%c", 175);
}

//============= ARROW KEY ===============
int getKey()
{
    int ch = getch();
    if (ch == 0 || ch == 224)
    {
        ch = getch();
    }
    return ch;
}

//============= Calculating function of the calendar========
void calendar(int nyear, int nmonth)
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tdays = 0, k, myear;
    system("cls");
    myear = nyear - 1;
    if (myear >= 1945)
    {
        for (k = 1945; k <= myear; k++)
        {
            if ((k % 4 == 0 && k % 100 != 0) || (k % 400 == 0))
            {
                tdays += 366;
            }
            else
            {
                tdays += 365;
            }
        }
        if ((nyear % 4 == 0 && nyear % 100 != 0) || (nyear % 400 == 0))
        {
            days[1] = 29;
        }
        for (k = 0; k < nmonth - 1; k++)
        {
            tdays += days[k];
        }
        tdays = tdays % 7;
        display(nyear, nmonth, tdays, days);
    }
}
