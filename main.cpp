#include <ncurses.h> 
int main(int argc, char ** argv){
	initscr(); 
	printw("hello world"); 
	int x,y; 
	x=y=10;
	int c=getch();
	if(c==97){
		mvprintw(y,x,"%d",c);
	}
	if(c==98){
		mvprintw(y,x,"%d",c); 
	}
	if(c==10){
		mvprintw(2,0, "hello world2");
	}
	getch(); 
	endwin();
}
