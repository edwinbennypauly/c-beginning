#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main()
{
    int h, m, s;
    int d = 1000; // delay of 1000 milliseconds, will be used in sleep function

    printf("Set time: \n");
    scanf("%d%d%d", &h, &m, &s);

    if (h > 12 || m > 60 || s > 60)
    {
        printf("Invalid time or format (hour, minute, seconds)\n");
        exit(0);
    }

    while (1)
    {
        if (_kbhit())  // Check if a key has been pressed
        {
            char ch = _getch();  // Get the pressed key
            if (ch == 'p' || ch == 'P')
            {
                printf("\nPaused. Press any key to resume...");
                _getch(); // Wait for any key to be pressed
                printf("\nResuming...");
            }
            else if (ch == 'q' || ch == 'Q')
            {
                printf("\nExiting program...");
                exit(0);
            }
        }

        s++;
        if (s > 59)
        {
            m++;
            s = 0;
        }
        if (m > 59)
        {
            h++;
            m = 0;
        }
        if (h > 12)
        {
            h = 1;
        }

        printf("\nClock");
        printf("\n%02d:%02d:%02d", h, m, s);

        Sleep(d);

        system("cls");
    }

    return 0;
}
