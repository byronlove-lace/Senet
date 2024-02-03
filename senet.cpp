#include <iostream>
#include <array>
#include <ncurses.h>
#include "ncurses_tools.h"

using std::cout;
using std::endl;
using std::array;

constexpr int SQ_HEIGHT = 5;
constexpr int SQ_WIDTH = 8;

array <WINDOW *, 30> board;

int terminal_check();
void draw_title();
void draw_square(int sq);
void draw_board();
void highlight_square(int square);
void erase_board();

int main(int argc, char *argv[])
{
        int key;
        int square = 0;

        initscr();
        noecho();
        cbreak();

        clear();
        if (terminal_check() == 1)
                return 1;

        draw_title();
        getch();
        clear();

        draw_board();
        highlight_square(square);

        do
        {
                key = getch();

                switch(key)
                {
                        case '+':
                        case '=':
                                if (square < 29)
                                {
                                        draw_square(square);
                                        highlight_square(++square); // ***why ++***
                                }
                                break;

                        case '-':
                        case '_':
                                if (square > 0)
                                {
                                        draw_square(square);
                                        highlight_square(--square); // ***why ++***
                                }
                                break; // **not in OG code**
                }
        } while ((key != 'q') && (key != 'Q'));

        erase_board();
        endwin();
}

int terminal_check()
{
        if ((LINES < 24) || (COLS < 80)) 
        {
                endwin();
                cout << "Your terminal needs to be at least 80x24" << endl;
                return 1;
        }

        return 0;
}

void draw_title()
{
        int titleX, titleY;

        titleY = percentile_to_position(LINES, 50.00);
        titleX = percentile_to_position(COLS - 5, 50.00); // letters in senet

        attron(A_BOLD);
        mvprintw(titleY, titleX, "Senet"); 
        attroff(A_BOLD);
        refresh(); // not necessary as mvpritw calls refresh anyway
}

void draw_board()
{

        int i;
        int startY, startX;

        startY = 0;
        for (i = 0; i < 10; ++i)
        {
                startX = i * SQ_WIDTH;
                board[i] = newwin(SQ_HEIGHT, SQ_WIDTH, startY, startX);
        }

        startY = SQ_HEIGHT;
        for (i = 10; i < 20; ++i)
        {
                startX = (19 - i) * SQ_WIDTH;
                board[i] = newwin(SQ_HEIGHT, SQ_WIDTH, startY, startX);
        }

        startY = 2 * SQ_HEIGHT;
        for (i = 20; i < 30; ++i)
        {
                startX = (i - 20) * SQ_WIDTH;
                board[i] = newwin(SQ_HEIGHT, SQ_WIDTH, startY, startX);
        }

        // put border on each window and refresh

        refresh();

        for (i = 0; i < 30; ++i)
        {
                draw_square(i);
        }
}

void highlight_square(int sq)
{
        wattron(board[sq], A_REVERSE);
        draw_square(sq);
        wattroff(board[sq], A_REVERSE);
}

void draw_square(int sq)
{
        /*
         *  second row is numbered backwards 
         *  windows follow this pattern
         *  so index 14 (15 in base 1) 
         *  is counted from the right
         */

        switch(sq)
        {
                // return square(15)
                case 14: 
                        wborder(board[sq], '#', '#', '#', '#', '#', '#', '#', '#');
                        break;
                case 25: 
                        wborder(board[sq], '$', '$', '$', '$', '#', '#', '#', '#');
                        break;
                case 26: 
                        wborder(board[sq], '>', '<', 'v', '^', '#', '#', '#', '#');
                        break;
                case 27: 
                        wborder(board[sq], '$', '$', '$', '$', '#', '#', '#', '#');
                        break;
                case 28: 
                        wborder(board[sq], '$', '$', '$', '$', '#', '#', '#', '#');
                        break;

                default:
                       box(board[sq], 0, 0); 
        }

        wrefresh(board[sq]);
}

void erase_board()
{
        int i;

        for (i = 0; i < 30; ++i)
        {
                wborder(board[i], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
                wrefresh(board[i]);
                delwin(board[i]);
        }
}
