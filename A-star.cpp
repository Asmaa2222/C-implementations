#include <bits/stdc++.h>
using namespace std;
 pair<int, int> p ;

typedef pair<int, int> Pair;
typedef pair<int, pair<int, int>> pPair;

#define ROW 18
#define COL 36

 int row=6;
    int column=9;
    int data[13][26]; // to store the data of the table// To determine in which room the enemy will be created
    int x,y;
    int ra=rand()%4;// to move in a random direction
    int last_move=3;
struct cell
{ // 0<=i<r && 0<=j <Col

    int parent_i, parent_j;
    float f, g, h; // f=g+h
};
Pair bossPosition;
bool isValid(int r, int col) // in the range of the grid
{            
    cout<<"V";                  // to check the cell is valid or not
    return ((r < ROW) && (col < COL));
}

bool isBlock(int ar[][COL], int r, int col)
{ 
    // if the cell is block +we might use it depends on the enemy lma netfeq
    return (ar[r][col] == -1);
}

bool isDestination(int r, int col, Pair dest)
{                                                     // to check whether enemy reached (its destination) the player or not
    return (r == dest.first && col == dest.second); // collision
}

int H_Calculation(int r, int col, Pair dest)
{
    // return the estimation distance using the rule of difference between two points
    return (sqrt((r - dest.first) * (r - dest.first) + (col - dest.second) * (col - dest.second)));
}

// will be changed and make the boss move according to the sequence of steps
void tracePath(cell cellDetails[][COL], Pair dest)
{
    int r = dest.first;
    int col = dest.second;

    stack<Pair> bossPath;

    while (!(cellDetails[r][col].parent_i == r && cellDetails[r][col].parent_j == col))
    {
        cout<<"HIIIIIIIIIIIIIIIII"<<endl;
        bossPath.push(make_pair(r, col));
        // the following parents of the pair pushed after the cells
        int temp_r = cellDetails[r][col].parent_i;
        int temp_col = cellDetails[r][col].parent_j;
        r = temp_r;
        col = temp_col;
    }
    bossPath.push(make_pair(r, col));
     bossPath.pop();
    while (!bossPath.empty())
    {
        pair<int, int> p = bossPath.top();
bossPosition.first=bossPath.top().first;
cout<<bossPosition.first<<"  "<<bossPosition.second<<endl;
         bossPosition.second=bossPath.top().second;
        bossPath.pop();
        cout<< "<"<<p.first<<" "<<p.second<<">"<<endl;
        if(p.first+1==row)
        {
        column++; 
        cout<<"("<<row<<" "<<column<<")"<<endl; 
        }

       // set position of boss
        //  tracePath(cell cellDetails[][COL], Pair dest) //recursion with the new position ???
    }

    return;
}

void aStarSearch(int grid[][COL], Pair src, Pair dest)
{
    bool closedList[ROW][COL] = {false}; // initialize closed list (2D array)

    // Declare a 2D array of structure to hold the details
    cell cellDetails[ROW][COL];
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0;
    cellDetails[i][j].g = 0;
    cellDetails[i][j].h = 0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    //  This open list is implemented as a set of pair of pair
    set<pPair> openList;

    // Put the starting cell on the open list and set its'f' as 0
    openList.insert(make_pair(0, make_pair(i, j)));
    bool foundDest = false; // the destination is not reached.
    while (!openList.empty())
    {
        pPair p = *openList.begin(); // Remove this vertex from the open list
        openList.erase(openList.begin());
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true; // Add this vertex to the closed list

        // Cell-->Popped Cell (i, j)
        //(4 directions ) N -->  North (i-1, j) S -->  South (i+1, j) E -->  East (i, j+1) W -->  West (i, j-1)
        int gNew, hNew, fNew; // To store the 'g', 'h' and 'f' of the 4 successors

        if (isValid(i - 1, j) == true) // north
        {
            if (isDestination(i - 1, j, dest) == true)
            {
                cellDetails[i - 1][j].parent_i = i; // Set the Parent of the destination cell
                cellDetails[i - 1][j].parent_j = j;
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (!(closedList[i - 1][j]) && !(isBlock(grid, i - 1, j)))
            {
                gNew = cellDetails[i][j].g + 1;
                hNew = H_Calculation(i - 1, j, dest);
                fNew = gNew + hNew;

                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i - 1][j].f == FLT_MAX || cellDetails[i - 1][j].f > fNew)
                {
                    openList.insert(make_pair(fNew, make_pair(i - 1, j)));

                    // Update the details of this cell
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                }
            }
        }
        if (isValid(i + 1, j) == true) //(South)
        {
            // If the destination cell is the same as the  current successor
            if (isDestination(i + 1, j, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }

            else if (!closedList[i + 1][j] && !isBlock(grid, i + 1, j))
            {
                gNew = cellDetails[i][j].g + 1;
                hNew = H_Calculation(i + 1, j, dest);
                fNew = gNew + hNew;

                if (cellDetails[i + 1][j].f == FLT_MAX || cellDetails[i + 1][j].f > fNew)
                {
                    openList.insert(make_pair(
                        fNew, make_pair(i + 1, j)));
                    // Update the details of this cell
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                }
            }
        }

        if (isValid(i, j + 1) == true) // east
        {
            if (isDestination(i, j + 1, dest) == true) // Set the Parent of the destination cell

            {
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }

            else if (!closedList[i][j + 1] && !isBlock(grid, i, j + 1))
            {
                gNew = cellDetails[i][j].g + 1;
                hNew = H_Calculation(i, j + 1, dest);
                fNew = gNew + hNew;
                if (cellDetails[i][j + 1].f == FLT_MAX || cellDetails[i][j + 1].f > fNew)
                {
                    openList.insert(make_pair(
                        fNew, make_pair(i, j + 1)));
                    // Update the details of this cell
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                }
            }
        }

        if (isValid(i, j - 1) == true) // west
        {
            if (isDestination(i, j - 1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            else if (!closedList[i][j - 1] && !isBlock(grid, i, j - 1) == true)
            {
                gNew = cellDetails[i][j].g + 1;
                hNew = H_Calculation(i, j - 1, dest);
                fNew = gNew + hNew;
                if (cellDetails[i][j - 1].f == FLT_MAX || cellDetails[i][j - 1].f > fNew)
                {
                    openList.insert(make_pair(
                        fNew, make_pair(i, j - 1)));

                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                }
            }
        }
    }
    return;
}

void move()
{

}
int main()
{
        int grid[ROW][COL]
        = { { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
            { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
            { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } };
 
    // Source is the left-most bottom-most corner

Pair player; player.first=8; player.second=0;
Pair enemy; enemy.first=0; enemy.second=0;

    aStarSearch(grid, enemy, player);
    cout<<"The second one is\n";

    Pair src = make_pair(8, 0);
 
    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 0);
 
    aStarSearch(grid, src, dest);


    return 0;
}