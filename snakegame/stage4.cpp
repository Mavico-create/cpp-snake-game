#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <conio.h> //Windows specific for keyboard input

const int WIDTH = 20;
const int HEIGHT = 10;

struct Point { int x, y;};
bool operator==(const Point& a, const Point& b) {return a.x == b.x && a.y == b.y; }

void clearScreen() { system("cls"); }

void drawBoard(const std::vector<std::vector<char>>& board){
    for (int y =0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) std::cout << board[y][x];
        std::cout << '\n';
    }
}

bool hitsSelf(const std::vector<Point>& snake, const Point& p){
    for (const auto& s : snake){
        if (s == p) return true;
    }

    return false;
}

int main() {
    srand((unsigned)time(nullptr)); //Seed random number generator

    std::vector<Point> snake = {{10,5}, {9,5}, {8,5}};
    Point dir = {1, 0};
    Point food = {15, 5};

    bool alive = true;
    int score = 0;

    while (alive){
        //--- Input ---
        if (_kbhit()) {
            char c = _getch();
            //Prevents 180-degreee turns 
            if ((c=='w' || c=='W') && dir.y != 1) dir = {0, -1};
            else if ((c=='s' || c == 'S') && dir.y !=-1) dir= {0, 1};
            else if ((c=='a'|| c=='A') && dir.x != 1) dir= {-1, 0};
            else if ((c=='d'|| c=='D') && dir.x !=-1) dir= {1, 0};
            else if (c =='q'|| c=='Q') break; //Quit
        }

        //Move and Collision
        Point newHead = { snake[0].x + dir.x, snake[0].y + dir.y };

        //checks walls
        if (newHead.x <= 0 || newHead.x >= WIDTH-1 || newHead.y <= 0 || newHead.y >= HEIGHT-1){
            alive = false;
            break;
        }

        //Checks tail

        if(hitsSelf(snake, newHead)){
            alive =false;
            break;
        }

        bool ateFood = (newHead == food);

        //Moves the snake
        snake.insert(snake.begin(), newHead);
        if (!ateFood){
            snake.pop_back();
        } else {
            score++;
            //Spans new food
            do{
                food = {1 + rand()%(WIDTH-2), 1 + rand()%(HEIGHT-2)};
            } while(hitsSelf (snake, food));
        }

        //Render
        std::vector<std::vector<char>> board(HEIGHT, std::vector<char>(WIDTH, '.'));
        for (int y=0; y<HEIGHT; ++y) { board[y][0]= '#'; board[y][WIDTH-1]='#'; }
        for (int x=0; x<WIDTH; ++x) { board[0][x]='#'; board[HEIGHT-1][x]='#'; }

        board[food.y][food.x] = '*';
        for (size_t i = 0; i<snake.size(); ++i){
            board[snake[i].y][snake[i].x] = (i==0) ? 'O' : 'o';
        }

        clearScreen();
        drawBoard(board);
        std::cout << "Score: "<< score << "| WASD to move, Q to quit\n ";

        //To pause
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    clearScreen(); 
    std::cout << "=========================\n";
    std::cout << "   GAME OVER! \n";
    std::cout << "   Final Score: " << score << "\n";
    std::cout << "=========================\n";
    return 0;
}