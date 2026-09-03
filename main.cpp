#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

/*conway's game of life
Rules:
1. Any live cell with fewer than two live neighbors dies, as by underpoulation. (make function to check adjacent cells)

2. Any live cell with two or three live neighbors lives on to the next generation. 

3. any cell with more than three live neighbours dies, as if by overpopulation

4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproducation.
*/

//TODO: be able to decide what cells start alive or dead


const int ROWS = 20;

const int COLS = 20;

enum cell {
    dead,
    alive,
};

std::vector<std::vector<cell>> v(ROWS, std::vector<cell>(COLS,dead));


void game_board(){
    
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
cell check_cell(int r,int c){
            //if column 0 and 19 than cant check the column to the left and right
            //write basic one for each case than worry about edge case

            //assume each is alive and than go down, if there is less than 3 but more than 2 alive celss than your good, etc. so if each cell has 8 neighbors besides edge case 
            
            //edge cases: that i can think of currently
            // if the row is 0 than you cant go up
            //if the col is 0 than you cant go left
            // if the row is ROWS-1 than you cant go down
            // if the col os COLS-1 than you cant go up

            cell curr_cell = v[r][c];
            int adj_cell = 0; 

            //loop through the adjacent cells, 
            for (int r_offset = r-1; r_offset <= r + 1; r_offset++){

                for(int c_offset = c-1; c_offset <= c + 1; c_offset++){
                    
                    if(r_offset == r && c_offset == c){
                        continue;
                    }

                    // dont access bad memory
                    if(r_offset < 0 || r_offset >= ROWS || c_offset < 0 || c_offset >= COLS){
                        continue;
                    }


                    cell cell = v[r_offset][c_offset];

                    if (cell == alive){
                        adj_cell++;
  
                    }    
                }
            }
                    //if cell is alive
                if (curr_cell == alive){
                    if(adj_cell == 2 || adj_cell == 3){
                        return alive;
                    }
                    return dead;
                }

                //dead
                else{

                    if(adj_cell == 3){
                        return alive;
                    }
                    return dead;
                }
}


void cls(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "\x18[2J";
}
 
//check cells neighbors
int main(){

    //teseting manuualy for now
    v[2][3] = alive;
    v[3][4] = alive;
    v[4][4] = alive;
    v[4][3] = alive;
    v[4][2] = alive;

    //use check_cell to check if that cell should be alive or dead. than go to next generation
    for(;;){

        vector<vector<cell>> v_next = v; 

        game_board();

        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
               //check if the cell should be alive or dead in the next gen
                cell cell_status = check_cell(r, c);

                //set cell to alive or dead depending on the rules
                v_next[r][c] = cell_status;

                //clear screen/ print 100 new lines (idk why theres no method to this nativley in c++ lil silly)
            }
        }
        cls();

        v = v_next;
        
    }
}



