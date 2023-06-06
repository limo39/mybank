#include <stdio.h>
#include <string.h>
#include <ncurses.h>

// Function to create an account and validate the password
int createAccount(WINDOW *win)
{
    char firstname[50], lastname[50];
    char pass[20], val[20];
    int value;
    int i = 3;

    wprintw(win, "Please create an account\nEnter your first and last names here: ");
    wscanw(win, "%s %s", firstname, lastname);

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
                return 1; // Password validation successful
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
        return 1; // Password validation successful
    }

    return 0; // Password validation failed
}

// Function to handle the main menu options
void handleMenuOption(WINDOW *win, char option)
{
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
            break;

        default:
            wprintw(win, "Invalid option selected\n");
            break;
    }
}

int main()
{
    char option;

    /* Initialize ncurses */
    initscr();
    cbreak
