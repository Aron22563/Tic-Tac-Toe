#include <ncurses.h>
bool valid_coordinates(WINDOW* win, int step_x, int step_y, int player_x, int player_y);

int main() {
  initscr();
  cbreak();
  noecho();
  int c=0;
  int rows, cols;
  getmaxyx(stdscr, rows, cols);
  mvprintw(rows - 1, 0, "Press 'q' to exit... ");
int win_height=30; 
  int win_width=30; 
  int start_y= (rows-win_height)/2; 
  int start_x= (cols- win_width)/2; 
  WINDOW* win = newwin(win_height, win_width, start_y, start_x);
  refresh();
  keypad(win, TRUE);
  box(win, 0, 0);
  wmove(win, 10,1); 
  whline(win,ACS_HLINE, win_width-2);
  wmove(win,20,1);
  whline(win,ACS_HLINE, win_width-2);
  wmove(win,1,10);
  wvline(win,ACS_VLINE, win_height-2);
  wmove(win,1,20);
  wvline(win,ACS_VLINE, win_height-2);
  int player_x=15;
  int player_y=15; 
  wmove(win, player_x, player_y);
  while (c != 'q') {
    c = wgetch(win); 
    switch (c) {
      case KEY_DOWN:
        if(!valid_coordinates(win, 0, 10, player_x, player_y)){
            mvprintw(rows -2, 0, "Not a valid move!");
        }else{
        player_y=player_y+10;
        wmove(win, player_y, player_x);
        }
        break;
      case KEY_UP:
        if(!valid_coordinates(win, 0, -10, player_x, player_y)){
            mvprintw(rows -2, 0, "Not a valid move!");
        }else{
        player_y=player_y-10;
        wmove(win, player_y, player_x); 
        }
        break;
      case KEY_RIGHT:
        if(!valid_coordinates(win, 10, 0, player_x, player_y)){
            mvprintw(rows -2, 0, "Not a valid move!");
        }else{
        player_x=player_x+10;
        wmove(win, player_y, player_x); 
        }
        break;
      case KEY_LEFT:
        if(!valid_coordinates(win, -10, 0, player_x, player_y)){
            mvprintw(rows -2, 0, "Not a valid move!");
        }else{
        player_x=player_x-10;
        wmove(win, player_y, player_x); 
        }
        break;
      case 'q':
        break;
      default:
        mvprintw(rows - 2, 0, "No matching key found!");
        break;
    }
    refresh();     
    wrefresh(win); 
  }

  endwin();
  return 0;
}
bool valid_coordinates(WINDOW* win, int step_x, int step_y, int player_x, int player_y) {
    int rows, cols; 
    getmaxyx(win, rows, cols);

    int new_x = player_x + step_x;
    int new_y = player_y + step_y;

    return (new_x >= 0 && new_x < cols) && (new_y >= 0 && new_y < rows);
}

