#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Maze
{
public:
    Maze(int row, int column, int curX, int curY, std::vector< std::string > &vec)
        : row_(row), column_(column), currentX_(curX), currentY_(curY), orientation_('N')
    {
        init(vec);
    };

public:
    void init(std::vector< std::string > &vec);
    void direct(char c);
    void forward();
    std::string maze_result();

private:
    char maze_[62][62];
    int row_;
    int column_;
    int currentX_;
    int currentY_;
    int forward_;
    char orientation_;
};

void Maze::init(std::vector< std::string > &vec)
{
    for (int i = 0; i < row_; i++) {
        vec[i].copy(maze_[i], column_, 0);
    }
}

void Maze::direct(char c)
{
    if (orientation_ == 'N') {
        (c == 'R') ? orientation_ = 'E' : orientation_ = 'W';
    } else if (orientation_ == 'S') {
        (c == 'R') ? orientation_ = 'W' : orientation_ = 'E';
    } else if (orientation_ == 'E') {
        (c == 'R') ? orientation_ = 'S' : orientation_ = 'N';
    } else if (orientation_ == 'W') {
        (c == 'R') ? orientation_ = 'N' : orientation_ = 'S';
    }
}
void Maze::forward()
{
    if (orientation_ == 'N') {
        if (maze_[currentX_ - 1][currentY_] != '*')
            --currentX_;
    }
    else if (orientation_ == 'S') {
        if (maze_[currentX_ + 1][currentY_] != '*')
            ++currentX_;
    }
    else if (orientation_ == 'E') {
        if (maze_[currentX_][currentY_ + 1] != '*')
            ++currentY_;
    }
    else if (orientation_ == 'W') {
        if (maze_[currentX_][currentY_ - 1] != '*')
            --currentY_;
    }
}

std::string Maze::maze_result()
{
    std::stringstream ss;
    ss << (currentX_ + 1) << " " << (currentY_ + 1) << " " << orientation_ << "\n";
    return ss.str();
}

void uva10377(std::istream &is, std::ostream &os)
{
    char command;
    std::string line;
    std::getline(is, line);

    int number = atoi(line.c_str());
    if (number <= 0)
        return;

    while (number--) {
        int row, column;
        is >> row;
        is >> column;
        std::getline(is, line);
        std::vector< std::string > vec;

        for (int i = 0; i < row; ++i) {
            std::getline(is, line);
            vec.push_back(line);
        }

        int currentX, currentY;

        is >> currentX;
        is >> currentY;
        currentX--;
        currentY--;
        Maze maze(row, column, currentX, currentY, vec);

        while ((is >> command) && (command != 'Q')) {

            if (command == 'R' || command == 'L') {
                maze.direct(command);
            } else if (command == 'F') {
                maze.forward();
            }
        }

        os << maze.maze_result();
        if (number)
            os << std::endl;
    }
    return;
}

int main(int argc, char **argv)
{
#ifdef GTEST
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    uva10377(std::cin, std::cout);
#endif
    return 0;
}
