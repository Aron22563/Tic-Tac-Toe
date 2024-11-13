#include <ncurses.h> 
int main(int argc, char ** argv){
	initscr(); 
	//printw("Press ENTER, ARROW_UP, ARROW_DOWN, ARROW_RIGHT, ARROW_LEFT");
	int c='a';
	while(c!='q'){
		c=getch();
	switch(c){
		case 'w': printw("Forward");
			  break;
		case 's': printw("Backward");
			  break;  
		case 'd': printw("Right");
			  break; 
		case 'a': printw("Left");
			  break;
		case 'q': endwin();
			  break;
	default: 
		printw("no matching key found!");
		break;
	}
	}
	endwin();
}
