#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#define sizex 40
#define sizey 80

using namespace std;

/* 
 * used to print out the current board
 * 
 * @param a the two-dimensional representation of the board
 **/
void printBoard(int a[][sizey]){
	usleep(100000);
	system("clear");
	for(int i=0; i<sizex; i++){
		for(int j=0; j<sizey; j++){
			if(a[i][j]==1)cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
}

/* 
 * handles over and underflow
 * 
 * @param start the starting position
 * @param offset how far the object will go
 * @return the adjusted coordinate
 * note: only works for incrementing and decrementing in ones
 **/
int wrapperx(int start, int offset){
	if(start+offset < 0)return sizex-1;
	return (start+offset) % sizex;
}


/* 
 * handles over and underflow
 * 
 * @param start the starting position
 * @param offset how far the object will go
 * @return the adjusted coordinate
 * note: only works for incrementing and decrementing in ones
 **/
int wrappery(int start, int offset){
	if(start+offset < 0)return sizey-1;
	return (start+offset)%sizey;
}

/*
 * sanity check for x dimension
 * 
 * @param a number to check
 * @return returns equivalent coordinate
 **/
int checkerx(int a){
	return a%sizex;
}


/*
 * sanity check for x dimension
 * 
 * @param a number to check
 * @return returns equivalent coordinate
 **/
int checkery(int a){
	return a%sizey;
}

int main(){

	int board[sizex][sizey] = {};
	int temp[sizex][sizey] = {};
	int inputx= 0;
	int inputy= 0;
	while(cin){
		cin >> inputx;
		if(inputx ==-1)break;
		cin >> inputy;
		if(inputy ==-1)break;
		if(board[checkerx(inputx)][checkery(inputy)] == 1)board[checkerx(inputx)][checkery(inputy)] = 0;
		else board[checkerx(inputx)][checkery(inputy)] = 1;
	}

	printBoard(board);

	int liveCount = 0;
	while(true){

		for(int i=0; i<sizex; i++){
			for(int j=0; j<sizey; j++){
				temp[i][j] = board[i][j];
			}
		}

		for(int i=0; i<sizex; i++){
			for(int j=0; j<sizey; j++){
				liveCount=0;
				for(int x=-1; x<2; x++){
					for(int y=-1; y<2; y++){
						if(x == 0 && y == 0);
						else if(board[wrapperx(i,x)][wrappery(j,y)] == 1)liveCount+=1;
					}
				}
				if(board[i][j] == 1){
					if(liveCount < 2)temp[i][j] = 0;
					else if(liveCount > 3)temp[i][j] = 0;
				}
				else if(board[i][j] == 0){
					if(liveCount == 3)temp[i][j] = 1;
				}
			}
		}

		for(int i=0; i<sizex; i++){
			for(int j=0; j<sizey; j++){
				board[i][j] = temp[i][j];
			}
		}

		printBoard(board);
	}

}
