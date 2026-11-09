#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

void printPoint(const Point& p){
    std::cout << "(" << p.x << "," << p.y << ")\n";

}

int main() {
    std::vector<Point> snake;
    snake.push_back({5, 5}); //head
    snake.push_back({4, 5}); //body
    snake.push_back({3, 5}); //tail

        for (const Point& p : snake){
            printPoint(p);
        }

        return 0;
}