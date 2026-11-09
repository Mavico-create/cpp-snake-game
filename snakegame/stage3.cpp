#include <iostream>
#include <vector>
#include <thread> //for pausing
#include <chrono> //for milliseconds

const int HEIGHT = 10;
const int WIDTH = 20;

struct Point { int x, y; };

// This will clear the screen commands works in Windows PowerShell!
void clearScreen () {
    system("cls"); 
}

void drawBoard(const std::vector<std::vector<char>>& board){
    for (int y = 0; y < HEIGHT; ++y){
        for (int x = 0; x < WIDTH; ++x) std::cout << board[y][x];
        std::cout << '\n';
    }
}

int main() {
    //Setting up the snake and direction 
    std::vector<Point> snake ={{10,5}, {9,5}, {8,5}}; //The head is [0]
    Point dir = {1, 0}; //Moves right (x goes +1, y stays 0)


    //The Game Loop
    for (int tick = 0; tick < 30; ++tick){


        //--- Move logic ---
        //Finds where the new head will be 
        Point newHead = { snake[0].x + dir.x, snake[0].y + dir.y };

        //This will add it to the front of the vector
        snake.insert(snake.begin(), newHead);

        //This will remove the last element (aka the tail) so that the snae=ke can stay the same length
        snake.pop_back();


        //--- Draw logic ---
        // Creates a empty board
        std::vector<std::vector<char>> board(HEIGHT, std::vector<char>(WIDTH, '.'));

        //Draws the walls 
        for(int y = 0; y < HEIGHT; ++y) {board[y][0] = '#'; board[y][WIDTH-1] = '#'; } 
        for(int x = 0; x < WIDTH; ++x) {board[0][x] = '#'; board[HEIGHT-1][x] ='#'; }

        //Draws the snake
        for (size_t i = 0; i < snake.size(); ++i){
            board[snake [i].y][snake[i].x] = (i == 0) ? 'O' : 'o';
        }

        clearScreen();
        drawBoard(board);

        //Pauses for 200 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return 0;
}