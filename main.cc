#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#define size 30

using namespace std;

void printBoard(int a[][size]){
	string garbage = "";
	//cin >> garbage;
	usleep(100000);
	system("clear");
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(a[i][j]==1)cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
}

int wrapper(int a, int b){
	if(a+b < 0)return size-1;
	return (a+b)%size;
}

int main(){

	int board[size][size] = {};
	int temp[size][size] = {};
	int inputx= 0;
	int inputy= 0;
	while(cin){
		cin >> inputx;
		if(inputx ==-1)break;
		cin >> inputy;
		if(board[inputx][inputy] == 1)board[inputx][inputy] = 0;
		else board[inputx][inputy] = 1;
	}

	string garbo = "";
	printBoard(board);
	cin >> garbo;

	int liveCount = 0;
	while(true){
		
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				temp[i][j] = board[i][j];
			}
		}

		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				liveCount=0;
				for(int x=-1; x<2; x++){
					for(int y=-1; y<2; y++){
						if(x == 0 && y == 0);
						else if(board[wrapper(i,x)][wrapper(j,y)] == 1)liveCount+=1;
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

		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				board[i][j] = temp[i][j];
			}
		}

		printBoard(board);
	}


}
