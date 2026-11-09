#include <iostream>
#include <vector>

const int WIDTH = 20;
const int HEIGHT = 10;

void drawBoard(const std::vector<std::vector<char>>& board){
    for (int y = 0; y < HEIGHT; ++y){
        for (int x = 0; x < WIDTH; ++x){
            std::cout << board[y][x];
        }
        std::cout << '\n';
    }
}

int main() {
    //The 2D grid, initialised with '.'
    std::vector < std::vector<char>> board(HEIGHT, std::vector<char>(WIDTH, '.'));

    //Walls
    for (int x = 0; x < WIDTH; ++x) { board[0][x] = '#'; board[HEIGHT-1][x] = '#'; }
    for (int y = 0; y < HEIGHT; ++y) { board[0][y] = '#'; board[y][WIDTH-1] = '#'; }

    //Snake 
    board[5][10] = 'O'; //This will be the head
    board[5][9] = 'o';
    board[5][8] = 'o';

    //Food
    board[3][15] = '*';

    drawBoard(board);
    return 0;
}