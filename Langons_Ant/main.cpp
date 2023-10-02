#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

const int WIDTH = 50;
const int HEIGHT = 25;

class LangtonAnt {
public:
    LangtonAnt(int x, int y) : x(x), y(y), direction(0) {}

    void move(std::vector<std::vector<int>>& board) {
        
        board[y][x] = (board[y][x] == 0) ? 1 : 0;      // changing cell color 1 / 0

        direction += (board[y][x] == 0) ? -1 : 1;      // changing direction; left -1, right 1

        if (direction < 0) {                           // making sure the direction is between 0-3
            direction = 3;
        }
        else if (direction > 3) {
            direction = 0;
        }


        switch (direction) {
        case 0: y--; break;  // UP
        case 1: x++; break;  // RIGHT
        case 2: y++; break;  // DOWN
        case 3: x--; break;  // LEFT
        }


        if (x < 0) x = WIDTH - 1;
        if (x >= WIDTH) x = 0;
        if (y < 0) y = HEIGHT - 1;
        if (y >= HEIGHT) y = 0;
    }

private:
    int x, y;
    int direction;
};

int main() {
    std::vector<std::vector<int>> board(HEIGHT, std::vector<int>(WIDTH, 0));
    LangtonAnt ant(WIDTH / 2, HEIGHT / 2);

    while (true) {
        system("cls");

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                std::cout << (board[i][j] == 0 ? ' ' : '#');
            }
            std::cout << std::endl;
        }

        ant.move(board);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
