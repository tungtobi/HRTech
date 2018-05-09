#include <iostream>
#include <vector>
using namespace std;

const int n = 5;
const int maze[n][n] =
{
    1, 1, 1, 1, 1,
    1, 0, 1, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1
};

int getMinValue(vector<int> steps);
int moveStep(int dir, int x, int y, int step);

int main()
{
    cout << moveStep(0, 1, n - 2, 1);
    return 0;
}

int getMinValue(vector<int> steps)
{
    int min = steps[0];
    for (int i : steps)
    {
        if (i < min)
        {
            min = i;
        }
    }
    return min;
}

int moveStep(int dir, int x, int y, int step)
{
    if (x == 3 && y == 1)
    {
        return 1;
    }
    else
    {
        vector<int> steps;
        if (x < n - 1 && dir != 180)
        {
            if (maze[y][x + 1] == 0)
            steps.push_back(moveStep(0, x + 1, y, step));
        }
        else if (x > 0 && dir != 0)
        {
            if (maze[y][x - 1] == 0)
            steps.push_back(moveStep(180, x - 1, y, step));
        }
        if (y > 0 && dir != 270)
        {
            if (maze[y - 1][x] == 0)
           {
               cout << "fhg";

               steps.push_back(moveStep(90, x, y - 1, step));

           }
        }
        else if (y < n - 1 && dir != 90)
        {
            if (maze[y + 1][x] == 0)
            steps.push_back(moveStep(270, x, y + 1, step));
        }

        return step + getMinValue(steps);
    }
}
