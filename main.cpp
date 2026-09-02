#include <iostream>
#include <array>
#include <string>
#include <vector>


/*conway's game of life
Rules:
1. Any live cell with fewer than two live neighbors dies, as by underpoulation. (make function to check adjacent cells)

2. Any live cell with two or three live neighbors lives on to the next generation. 

3. any cell with more than three live neighbours dies, as if by overpopulation

4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproducation.
*/

/*implementation ideas. 

use a array for the rowXcolumns of the 2d grid.

*/

const int ROWS = 20;

const int COLS = 20;

enum cell {
    dead,
    alive,
};

std::vector<std::vector<cell>> v(ROWS, std::vector<cell>(COLS,dead));

//edit board to be able to take input from the user to decide which board is dead or alive
int game_board(){
    
    for (int r = 0; r < v.size(); r++){
        for (int c = 0; c < v[r].size(); c++){

            if(v[r][c] == dead){
                std::cout << ". ";
            }

            else if (v[r][c] == alive){
                std::cout << "* ";
            }
        }
        std::cout << "\n";
    }
}

//checks if cell should be alive or dead in the next generation.
int check_cell(cell cell, int r,int c){
            //if column 0 and 19 than cant check the column to the left and right
            //write basic one for each case than worry about edge case

            //assume each is alive and than go down, if there is less than 3 but more than 2 alive celss than your good, etc. so if each cell has 8 neighbors besides edge case 
            int adj_cell = 0 

            //edge cases: that i can think of currently
            // if the row is 0 than you cant go up
            //if the col is 0 than you cant go left
            // if the row is ROWS-1 than you cant go right
            // if the 


 
//check cells neighbors
int main(){

    //initlize game board
    game_board();
}










