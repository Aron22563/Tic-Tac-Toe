#include <ncurses.h>
#include <vector>
bool valid_coordinates(WINDOW *win, int step_x, int step_y, int player_x,
                       int player_y);

int main() {

  //NCURSES INIT
  initscr();
  cbreak();
  noecho();

  // GENERAL SCREEN
  int rows, cols;
  getmaxyx(stdscr, rows, cols);

  // BOTTOM MENU
  int bottom_menu_height=5; 
  int bottom_menu_width=cols;
  WINDOW *bottom_menu= newwin(bottom_menu_height, bottom_menu_width, rows-bottom_menu_height,0);
  box(bottom_menu, 0,0);
  mvwprintw(bottom_menu, 1, 1, "Press 'q' to exit... ");

  // GRID
  int grid_height = 30;
  int grid_width = 30;
  int grid_y = (rows - grid_height) / 2;
  int grid_x = (cols - grid_width) / 2;
  WINDOW *grid= newwin(grid_height, grid_width, grid_y, grid_x);
  keypad(grid, TRUE);
  box(grid, 0, 0);
  wmove(grid, 10, 1);
  whline(grid, ACS_HLINE, grid_width - 2);
  wmove(grid, 20, 1);
  whline(grid, ACS_HLINE, grid_width - 2);
  wmove(grid, 1, 10);
  wvline(grid, ACS_VLINE, grid_height - 2);
  wmove(grid, 1, 20);
  wvline(grid, ACS_VLINE, grid_height - 2);
  refresh();

  // PLAYER INIT
  int player_start_y=15; 
  int player_start_x=15; 
  int player_y = player_start_y;
  int player_x = player_start_x;
  wmove(grid, player_y, player_x);

  // INPUT PARSE
  int c = 0;
  while (c != 'q') {
    c = wgetch(grid);

    mvwprintw(grid, player_y, player_x, " ");

    switch (c) {
    case KEY_DOWN:
      if (valid_coordinates(grid, 1, 0, player_y, player_x)) player_y += 10;
      else mvwprintw(bottom_menu, 3, 1, "Not a valid move!");
      break;
    case KEY_UP:
      if (valid_coordinates(grid, -10, 0, player_y, player_x)) player_y -= 10;
      else mvwprintw(bottom_menu, 3, 1, "Not a valid move!");
      break;
    case KEY_RIGHT:
      if (valid_coordinates(grid, 0, 10, player_y, player_x)) player_x += 10;
      else mvwprintw(bottom_menu, 3, 1, "Not a valid move!");
      break;
    case KEY_LEFT:
      if (valid_coordinates(grid, 0, -10, player_y, player_x)) player_x -= 10;
      else mvwprintw(bottom_menu, 3, 1, "Not a valid move!");
      break;
    default:
      mvwprintw(bottom_menu, 3, 1, "No matching key found! ");
      break;
    }

    mvwprintw(grid, player_y, player_x, "X");

    // REFRESH
    refresh();
    wrefresh(grid);
    wrefresh(bottom_menu);
  }

  endwin();
  return 0;
}

// Check if step into direction step_y, step_x are within grid bounds of grid for player_y, player_x
bool valid_coordinates(WINDOW *grid, int step_y, int step_x, int player_y,
                       int player_x) {
  int rows, cols;
  getmaxyx(grid, rows, cols);

  int new_y = player_y + step_y;
  int new_x = player_x + step_x;

  return (new_y >= 0 && new_y < rows) && (new_x >= 0 && new_x < cols);
}
