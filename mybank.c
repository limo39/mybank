#include <stdio.h>
#include <string.h>
#include <ncurses.h>

int main()
{
    char option;
    double balance = 50000.00;

    /* Initialize ncurses */
    initscr();
    cbreak();
    noecho();

    /* Create a new window */
    WINDOW *win = newwin(10, 30, 5, 5);
    refresh();

    /* Greeting message */
    wprintw(win, "Hello, Welcome to Mybank.\nWith us, Banking has been made easy.\n\n");
    wrefresh(win);

    /* Create an account - Implementing registration */
    char firstname[50], lastname[50];

    wprintw(win, "Please create an account\nEnter your first and last names here: ");
    wscanw(win, "%s %s", firstname, lastname);

    char pass[20];
    char val[20];
    int value;
    int i = 3;
    int passwordCorrect = 0; // Flag var to track correct password validation.

    wprintw(win, "Create a password: ");
    wscanw(win, "%s", pass);

    wprintw(win, "Confirm password: ");
    wscanw(win, "%s", val);

    value = strcmp(pass, val);

    if (value != 0)
    {
        while (i >= 0)
        {
            wprintw(win, "\nYour passwords don't match\n");
            wprintw(win, "Try again, Re-enter password: ");
            wscanw(win, "%s", val);

            value = strcmp(pass, val);

            if (value == 0)
            {
                passwordCorrect = 1;
                break;
            }

            if (i > 0)
                wprintw(win, "Passwords don't match. You have %d more attempts\n", i);
            else
                wprintw(win, "Sorry. You can't create an account");
            i--;
        }
    }
    else
    {
        passwordCorrect = 1;
    }

    if (passwordCorrect)
    {
        wprintw(win, "Welcome to instant banking with My Bank.\nYou have a fixed amount of 50,000\n\n");
        wrefresh(win);

        while (1)
        {
            wprintw(win, "Menu:\n");
            wprintw(win, "a) Transfer funds\n");
            wprintw(win, "b) Deposit funds\n");
            wprintw(win, "c) Check balance\n");
            wprintw(win, "d) Quit the program\n");

            wprintw(win, "Select an option: ");
            wscanw(win, " %c", &option);

            switch (option)
            {
                case 'a':
                    wprintw(win, "Option a: Transfer Money\n");
                    /* Add code to transfer money */
                    break;

                case 'b':
                    wprintw(win, "Option b: Deposit Money\n");
                    /* Add code to deposit money */
                    break;

                case 'c':
                    wprintw(win, "Option c: Check balance\n");
                    /* Add code to check balance */
                    break;

                case 'd':
                    wprintw(win, "Option d: Quit the program\n");
                    endwin();
                    return 0;
            }

            wrefresh(win);
        }
    }

    endwin();
    return 0;
}
