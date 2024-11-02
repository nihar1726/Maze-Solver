#include <iostream>

using namespace std;

// Define the dimensions of the maze
const int N = 5; // Number of rows
const int M = 5; // Number of columns

// Directions for moving in the maze (right, down, left, up)
const int directions[4][2] = {
    {0, 1},  // right
    {1, 0},  // down
    {0, -1}, // left
    {-1, 0}  // up
};

// Function to check if a cell is valid (inside the maze and not a wall)
bool isValid(int x, int y, int maze[N][M], bool visited[N][M])
{
    return (x >= 0 && x < N && y >= 0 && y < M &&
            maze[x][y] == 0 && !visited[x][y]);
}

// Recursive function to solve the maze
bool solveMaze(int x, int y, int maze[N][M], bool visited[N][M])
{
    // Base case: if we have reached the destination
    if (x == N - 1 && y == M - 1)
    {
        return true; // Path found
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Explore all possible directions
    for (int i = 0; i < 4; i++)
    {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (isValid(newX, newY, maze, visited))
        {
            if (solveMaze(newX, newY, maze, visited))
            {
                return true; // Path found
            }
        }
    }

    // Backtrack: unmark the current cell
    visited[x][y] = false;
    return false; // No path found
}

int main()
{
    // Define the maze (0 = path, 1 = wall)
    int maze[N][M] = {
        {0, 0, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    // Create a visited array
    bool visited[N][M] = {false};

    // Start solving the maze from the top-left corner
    if (solveMaze(0, 0, maze, visited))
    {
        cout << "Path to the destination found!" << endl;
    }
    else
    {
        cout << "No path to the destination exists." << endl;
    }

    return 0;
}