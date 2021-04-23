#include <iostream>
#include<cmath>
#include <cstdlib>
#include<ctime>
using namespace std;

const int N = 3;
int grid[N][N];


//This function prints the grid of Tic-Tac-Toe Game as the game progresses
void print_grid() {

    cout << "--";
    for (int i = 0; i < N; cout << "-----", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << "  "<<"|" <<"  ";
        cout << "\n";
        cout << "--";
        for (int i = 0; i < N; cout << "-----", i++);
        cout << "--\n";
}}

bool check_win(){
    int c=0;
    for (int i =0 ; i<N ; i++){
       for (int j =0 ; j<N ; j++){
            c++;
            if (grid[i][j]!=c){return false;}
       }
   }
   return true;
}
//1 2 3
//4 5 6
//7 8
bool check_valid_num(int a) {
     for (int i =0 ; i<N; i++){
            for (int j =0 ; j<N; j++){
                if (grid[i][j]==a){
                        return false;
                }
            }
        }
     return true;
}


//This function generates pac man
int generate_number() {
    srand( (unsigned)time( NULL ) );
    int f=pow(N,2);
    int a = rand() % f ;
    return a;
}

//This function checks if given position is valid or not
bool check_available_move(int i,int a,int b) {
      if (i==4){  if(b+1>N-1){return false;}} //left
 else if (i==2){  if(a-1<0){return false;} }   //down
 else if (i==1){  if(a+1>N-1){return false;}}   // up
 else if (i==3){  if(b-1<0){return false;}}     //right
return true;
 }

//0 2 3
//3 6 6
//8 5 4

//This function checks if given position is valid or not
bool check_valid_direction(int i) {
    if (i==1 || i==2 || i==3 || i==4 ){
        return true;
        }
    else{return false;}
}

//Move with the input direction
void move(int i,int &a,int &b) {
    if (i==3){  grid[a][b]=grid[a][b-1]; grid[a][b-1]=0; b-=1;  } //right

 else if (i==1){ grid[a][b]=grid[a+1][b]; grid[a+1][b]=0;  a+=1;  }   // up

 else if (i==2){ grid[a][b]=grid[a-1][b]; grid[a-1][b]=0; a-=1;}  //down

 else if (i==4){  grid[a][b]=grid[a][b+1]; grid[a][b+1]=0 ;b+=1;}  }   //left

//This function clears the game structures
void grid_clear(int &x ,int &y) {
        cout<<5;
        int a = generate_number();
        for (int i =0 ; i<N; i++){
            for (int j =0 ; j<N; j++){
                while (!check_valid_num(a))
                {
                    a=generate_number();
                }
                if (a==0){
                     x=i; y=j;
                }
                grid[i][j]=a;
            }
        }
}
//This function reads a valid position input
void read_input(int &i ,int a , int b) {
	cout << "Enter the direction: ";
	cin >> i ;
    while (!check_valid_direction(i) || !check_available_move(i,a,b)) {
		cout << "Enter a valid direction: ";
		cin >> i ;
	}
}
//MAIN FUNCTION
void play_game(int &a,int &b) {
    cout << " 8 puzzel Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";

    while (true) {
        //Prints the grid
        print_grid();

        //Read an input position from the player
        int i;
		read_input(i,a,b);
        //Check if the grid has a win state
        move(i,a,b);
        if (check_win()) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Congrats, YOU WON";
            break;
        }

    }
}
int main() {
    while (true) {
        int a,b;
        cout<<1;
    	grid_clear(a,b);
    	cout<<2;
    	play_game(a,b);
    	cout<<3;
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
