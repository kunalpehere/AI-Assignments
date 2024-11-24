/*BFS & DFS
#include<stdio.h>
#include<stdlib.h>

#define MAX_VALUE 100

struct Graph{
    int no_Vertex;
    int m[MAX_VALUE][MAX_VALUE];
};

struct Graph* createGraph(int n){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->no_Vertex = n;
    graph->m[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph->m[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    graph->m[src][dest] = 1;
}

void bfs(struct Graph* graph, int src){
    int n = graph->no_Vertex;

    int* queue = (int*)malloc(sizeof(int)*100);
    int front = 0,rare = 0;

    int visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    queue[rare++] = src;
    visited[src] = 1;

    while(front<rare){
        int curr = queue[front++];
        printf("%d",curr);
        for(int i=0;i<n;i++){
            if(graph->m[curr][i] == 1 && visited[i] == 0){
                queue[rare++] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(struct Graph* graph, int src){
    int n = graph->no_Vertex;

    int* stack = (int*)malloc(sizeof(int)*100);
    int top = -1;

    int visited[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }

    stack[++top] = src;
    visited[src] = 1;

    while(top!=-1){
        int curr = stack[top--];
        printf("%d",curr);
        for(int i=0;i<n;i++){
            if(graph->m[curr][i] == 1 && visited[i] == 0){
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

int main(){

    int n;
    int edge;
    int ele;
    int src;

    printf("\nEnter Size : ");
    scanf("%d",&n);
    struct Graph* graph = createGraph(n);

    printf("\nEnter edges :\n");

    for(int i=0;i<n;i++){
        printf("\nEnter no. of edges for vertex %d : ",i);
        scanf("%d",&edge);
        printf("\nEnter vertex connected : ");
        for(int j=0;j<edge;j++){
            scanf("%d",&ele);
            addEdge(graph,i,ele);
        }
    }

    printf("\nEnter Source vertex : ");
    scanf("%d",&src);
    printf("\nBFS : ");
    bfs(graph,src);
    printf("\nDFS : ");
    dfs(graph,src);

    return 0;
}
*/

/*Tic_Tac_Toe_Ai
#include <stdio.h>
#include <limits.h>
#define PLAYER 'X'
#define AI 'O'
#define SIZE 3
char board[SIZE][SIZE];
// Function Prototypes
void initializeBoard();
void printBoard();
int isMovesLeft();
int checkWin();
int minimax(int depth, int isMax);
int bestMove();
void makeMove(int row, int col, char player);
int main()
{
    int row, col;
    initializeBoard();

    while (1)
    {
        printBoard();

        // Player's move
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '_')
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        makeMove(row - 1, col - 1, PLAYER);

        if (checkWin() == 10)
        {
            printBoard();
            printf("You win!\n");
            break;
        }

        if (!isMovesLeft())
        {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        // AI's move
        int aiMove = bestMove();
        makeMove(aiMove / SIZE, aiMove % SIZE, AI);

        if (checkWin() == -10)
        {
            printBoard();
            printf("AI wins!\n");
            break;
        }

        if (!isMovesLeft())
        {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }
    return 0;
}
// Initialize the Tic-Tac-Toe board
void initializeBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '_';
        }
    }
}
void printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
int isMovesLeft()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '_')
            {
                return 1;
            }
        }
    }
    return 0;
}
int checkWin()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_')
        {
            return (board[i][0] == PLAYER) ? 10 : -10;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_')
        {
            return (board[0][i] == PLAYER) ? 10 : -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_')
    {
        return (board[0][0] == PLAYER) ? 10 : -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_')
    {
        return (board[0][2] == PLAYER) ? 10 : -10;
    }

    return 0;
}
int minimax(int depth, int isMax)
{
    int score = checkWin();

    if (score == 10)
        return score - depth;

    if (score == -10)
        return score + depth;

    if (!isMovesLeft())
        return 0;

    if (isMax)
    {
        int best = INT_MIN;

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = PLAYER;
                    best = (best > minimax(depth + 1, 0)) ? best : minimax(depth + 1, 0);
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
    else
    {
        int best = INT_MAX;

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = AI;
                    best = (best < minimax(depth + 1, 1)) ? best : minimax(depth + 1, 1);
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}
int bestMove()
{
    int bestVal = INT_MAX;
    int move = -1;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '_')
            {
                board[i][j] = AI;
                int moveVal = minimax(0, 1);
                board[i][j] = '_';

                if (moveVal < bestVal)
                {
                    bestVal = moveVal;
                    move = i * SIZE + j;
                }
            }
        }
    }
    return move;
}
void makeMove(int row, int col, char player)
{
    board[row][col] = player;
}

































*/

/*Tic_Tac_Toe
#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];
char currentPlayer;

// Function prototypes
void initializeBoard();
void printBoard();
int makeMove(int row, int col);
int checkWin();
int isMovesLeft();

// Initialize the Tic-Tac-Toe board with empty spaces
void initializeBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '_';
        }
    }
}

// Print the Tic-Tac-Toe board
void printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Make a move on the board
int makeMove(int row, int col)
{
    // Check if the move is within the bounds of the board and the cell is empty
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '_')
    {
        board[row][col] = currentPlayer;
        return 1;
    }
    return 0;
}

// Check if there is a winner
int checkWin()
{
    // Check rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
        {
            return 1;
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    {
        return 1;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    {
        return 1;
    }

    return 0;
}

// Check if there are moves left on the board
int isMovesLeft()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '_')
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int row, col;
    int gameOver = 0;

    initializeBoard();
    currentPlayer = 'X';

    while (!gameOver)
    {
        printBoard();
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (makeMove(row - 1, col - 1))
        {
            // Check if the current player has won
            if (checkWin())
            {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                gameOver = 1;
            }
            else if (!isMovesLeft())
            {
                printBoard();
                printf("It's a draw!\n");
                gameOver = 1;
            }
            else
            {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else
        {
            printf("Invalid move! Please try again.\n");
        }
    }

    return 0;
}
*/

/*CSP Greedy
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 4 // Example graph with 4 vertices

void greedyColoring(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int result[numVertices];
    result[0] = 0; // Assign the first color to the first vertex

    // Initialize remaining vertices as uncolored
    for (int i = 1; i < numVertices; i++) {
        result[i] = -1;
    }

    // Boolean array to keep track of available colors
    bool availableColors[MAX_VERTICES] = {false};

    // Assign colors to remaining vertices
    for (int u = 1; u < numVertices; u++) {
        // Mark colors used by adjacent vertices as unavailable
        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && result[v] != -1) {
                availableColors[result[v]] = true;
            }
        }

        // Find the first available color
        int color;
        for (color = 0; color < numVertices; color++) {
            if (!availableColors[color]) {
                break;
            }
        }

        result[u] = color; // Assign the found color to the current vertex

        // Reset the values back to false for the next iteration
        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && result[v] != -1) {
                availableColors[result[v]] = false;
            }
        }
    }

    // Print the result
    printf("Vertex Coloring Result:\n");
    for (int u = 0; u < numVertices; u++) {
        printf("Vertex %d ---> Color %d\n", u, result[u]);
    }
}
int main() {
    // Example adjacency matrix for a simple graph with 4 vertices
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    int numVertices = MAX_VERTICES;
    printf("Using the following adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }    
    greedyColoring(graph, numVertices);
    return 0;
}
*/

/*CSP BFS
#include<stdio.h>
#include<stdlib.h>
#define MAX_VAL 100

struct Graph{
    int n;
    int m[MAX_VAL][MAX_VAL];
};

struct Graph* createGraph(int n){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->n = n;
    graph->m[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph->m[i][j] = -1;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph,int src,int dest){
    graph->m[src][dest] = 1;
}

void graphColoring(struct Graph* graph,int m){

    int n = graph->n;
    int* queue = (int*)malloc(sizeof(int)*100);
    int front=0,rare=0;

    int colored[n];
    for(int i=0;i<n;i++){
        colored[i] = -1;
    }

    int visited[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }

    int ncolor = m+1;
    int color[ncolor];
    for(int i=0;i<ncolor;i++){
        color[i] = 0;
    }

    queue[rare++] = 0;
    visited[0] = 1;
   
    while(front<rare){
        int curr = queue[front++];

        int flag = -1;
        // checking neighbours color
        for(int i=0;i<n;i++){
            if(graph->m[curr][i] == 1 && colored[i] != -1){
                color[colored[i]] = 1;
            }
        }
    
        // identify ideal color
        for(int i=1;i<ncolor;i++){
            if(color[i] == 0){
                flag = i;
                break;
            }
        }
        // if any color is ideal then assign to curr element otherwise no solution.
        if(flag != -1){
            colored[curr] = flag;
        }else{
            printf("\nSolution not exist!!!!");
            return;
        }
        
        // insert all neighbours
        for(int i=0;i<n;i++){
            if(graph->m[curr][i] == 1 && visited[i] == 0){
                queue[rare++] = i;
                visited[i] = 1;
            }
        }

        // free all color 
        for(int i=1;i<ncolor;i++){
            color[i] = 0;
        }
    }

    // print solution
    printf("\nSolution Exist : ");
    for(int i=0;i<n;i++){
        printf("%d ",colored[i]);
    }
}

int main(){

    int n=6;
    struct Graph* graph = createGraph(n);
    int hvalue[] = {5,3,2,4,6,0};

    addEdge(graph,0,1);
    addEdge(graph,0,5);

    addEdge(graph,1,0);
    addEdge(graph,1,2);
    addEdge(graph,1,3);

    addEdge(graph,2,1);
    addEdge(graph,2,4);
    addEdge(graph,2,5);

    addEdge(graph,3,1);
    addEdge(graph,3,4);

    addEdge(graph,4,2);
    addEdge(graph,4,3);
    addEdge(graph,4,5);

    addEdge(graph,5,0);
    addEdge(graph,5,2);
    addEdge(graph,5,4);

    graphColoring(graph,3);
}
*/

/*A-Star
#include<stdio.h>
#include<stdlib.h>

#define MAX_Val 100

struct Graph{
    int n;
    int m[MAX_Val][MAX_Val];
    int fvalue[MAX_Val];
};

struct Graph* createGraph(int n){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->n = n;
    graph->m[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph->m[i][j] = -1;
        }
    }
    graph->fvalue[n];
    for(int i=0;i<n;i++){
        graph->fvalue[i] = -1;
    }
    return graph;
}

void addEdge(struct Graph* graph,int src,int dest,int cost){
    graph->m[src][dest] = cost;
}

void sort_queue(int* queue,int front,int rare,int fvalue[]){
    int min = fvalue[queue[front]];
    int index = front;

    for(int i=front;i<rare;i++){
        if(fvalue[queue[i]] != -1 && min > fvalue[queue[i]]){
            min = fvalue[queue[i]];
            index = i;
        }
    }
    int temp = queue[index];
    queue[index] = queue[front];
    queue[front] = temp;
}

void print(int* queue,int front,int rare){
    for(int i=front;i<rare;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void astar(struct Graph* graph,int src,int dest,int hvalue[]){

    int n = graph->n;
    int* queue = (int*)malloc(sizeof(int)*100);
    int front = 0,rare=0;

    int visited[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }

    int parent[n];
    for(int i=0;i<n;i++){
        parent[i] = -1;
    }

    int dist[n];
    for(int i=0;i<n;i++){
        dist[i] = 999;
    }

    queue[rare++] = src;
    visited[src] = 1;
    parent[src] = -1;
    dist[src] = 0;

    while(front<rare){
        int curr = queue[front++];
        printf("%d ",curr);
        visited[curr] = 1;
     
        for(int i=0;i<n;i++){
            if(graph->m[curr][i] != -1 && visited[i] == 0){
                int dist_value = dist[curr] + graph->m[curr][i];
                if(dist[i] >= dist_value){
                    dist[i] = dist_value;
                    parent[i] = curr;
                }
                queue[rare++] = i;
                visited[i] = 1;
                graph->fvalue[i] = hvalue[i] + dist[i];
            }
        }

        for(int i=0;i<n;i++){
            if(i!=curr){
                visited[i] =0;
            }
        }
    
        if(curr == dest) break;
        sort_queue(queue,front,rare,graph->fvalue);
    }
    printf("\nDist : ");
    for(int i=0;i<n;i++){
        printf("%d ",dist[i]);
    }
    printf("\nParent : ");
    for(int i=0;i<n;i++){
        printf("%d ",parent[i]);
    }
}       

int main(){
    
    int n,ele,edge,cost,src,dest;

    n=6;
    struct Graph* graph = createGraph(n);
    int hvalue[] = {5,3,2,4,6,0};

    addEdge(graph,0,1,1);
    addEdge(graph,0,5,10);

    addEdge(graph,1,0,1);
    addEdge(graph,1,2,1);
    addEdge(graph,1,3,2);

    addEdge(graph,2,1,1);
    addEdge(graph,2,4,3);
    addEdge(graph,2,5,4);

    addEdge(graph,3,1,2);
    addEdge(graph,3,4,5);

    addEdge(graph,4,2,3);
    addEdge(graph,4,3,5);
    addEdge(graph,4,5,2);

    addEdge(graph,5,0,10);
    addEdge(graph,5,2,4);
    addEdge(graph,5,4,2);

    src = 0;dest = 5;

    // printf("\nEnter size : ");
    // scanf("%d",&n);

    // struct Graph* graph = createGraph(n);
    // int hvalue[n];
    // printf("\nBuild Graph\n");
    // for(int i=0;i<n;i++){
    //     printf("\nEnter total Edges for vertex %d : ",i);
    //     scanf("%d",&edge);
    //     printf("\nEnter connected vertex and cost\n");
    //     for(int j=0;j<edge;j++){
    //         printf("\nvertex : ");
    //         scanf("%d",&ele);
    //         printf("\ncost : ");
    //         scanf("%d",&cost);
    //         addEdge(graph,i,ele,cost);
    //     }
    //     printf("\n");
    // }
    
    // printf("\nEnter hvalues : ");
    // for(int i=0;i<n;i++){
    //     scanf("%d",&ele);
    //     hvalue[i] = ele;
    // }

    // printf("\nPath : ");
    astar(graph,src,dest,hvalue);
}
*/

/*AO-Star
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 20  // Maximum number of nodes in the graph

// Structure to represent a node in the graph
struct Node {
    int id;
    int cost;  // Heuristic cost
    bool isAndNode;  // True if AND node, False if OR node
    int children[2];  // Stores the children nodes (for AND-OR structure)
    int numChildren;  // Number of children (can be 1 or 2 for this example)
};

// Function to find the minimum cost path from the given node in the AND-OR graph
int AOStar(int node, struct Node graph[], int n, int solution[]) {
    // If the node is a leaf node, return its cost
    if (graph[node].numChildren == 0) {
        solution[node] = node;  // Add to solution
        return graph[node].cost;
    }

    int minCost = INT_MAX;  // Initialize minimum cost to infinity

    if (graph[node].isAndNode) {
        // AND node: Both children need to be solved, so sum their costs
        int cost1 = AOStar(graph[node].children[0], graph, n, solution);
        int cost2 = AOStar(graph[node].children[1], graph, n, solution);
        minCost = cost1 + cost2 + graph[node].cost;
        solution[node] = node;  // Mark current node as part of the solution
    } else {
        // OR node: Solve the child with the minimum cost
        for (int i = 0; i < graph[node].numChildren; i++) {
            int cost = AOStar(graph[node].children[i], graph, n, solution);
            if (cost < minCost) {
                minCost = cost;
                solution[node] = node;  // Update solution path
            }
        }
    }

    return minCost;
}

int main() {
    // Define an example AND-OR graph
    // Graph has 7 nodes where:
    // Nodes 0, 3, 4 are OR nodes; Nodes 1, 2, 5, 6 are AND nodes
    struct Node graph[MAX] = {
        {0, 0, false, {1, 2}, 2},  // Root node (OR node)
        {1, 1, true, {3, 4}, 2},   // AND node with 2 children (3 and 4)
        {2, 2, true, {5, 6}, 2},   // AND node with 2 children (5 and 6)
        {3, 3, false, {}, 0},      // Leaf node (OR node)
        {4, 4, false, {}, 0},      // Leaf node (OR node)
        {5, 5, false, {}, 0},      // Leaf node (OR node)
        {6, 6, false, {}, 0}       // Leaf node (OR node)
    };

    int solution[MAX] = {0};  // To store the solution path
    int startNode = 0;  // Start from the root node

    // Find the minimum cost solution from the start node
    int result = AOStar(startNode, graph, MAX, solution);

    // Print the solution path
    printf("Optimal Solution Path: \n");
    for (int i = 0; i < MAX; i++) {
        if (solution[i] != 0) {
            printf("Node %d -> ", solution[i]);
        }
    }
    printf("\nTotal Cost: %d\n", result);

    return 0;
}
*/

/*Prolog.pl
food(apple).
food(vegetables).
eats(anil, peanuts).
alive(anil).
food(Y) :- eats(X, Y), \+killed(X).
alive(X) :- \+killed(X).
killed(X) :- \+alive(X).
likes(john, X) :- food(X).
eats(harry, X) :- eats(anil, X).
*/

/*Expert_System
% Define diseases based on symptoms
disease(malaria) :- symptom(fever), symptom(headache), symptom(nausea).
disease(covid) :- symptom(fever), symptom(cough), symptom(fatigue).

% Predicate to ask yes/no questions about symptoms
ask_symptom(Symptom) :-
    format('Do you have ~w? (yes/no) ', [Symptom]),
    read(Response),
    (Response == yes -> assert(symptom(Symptom));
    Response == no -> true;
    write('Please answer yes or no.'), nl, ask_symptom(Symptom)).

% Collect symptoms based on user responses
get_symptoms :-
    ask_symptom(fever),
    ask_symptom(cough),
    ask_symptom(headache),
    ask_symptom(nausea),
    ask_symptom(fatigue).

% Predicate to predict disease based on symptoms
predict_disease :-
    findall(Disease, disease(Disease), Diseases),
    (member(malaria, Diseases) -> write('Possible disease: Malaria'), nl
    ; member(covid, Diseases) -> write('Possible disease: COVID-19'), nl
    ; write('No matching disease found for the provided symptoms.'), nl).

% To start the prediction
start :-
    get_symptoms,
    predict_disease.
*/

/*C-Prolog and Expert System
% Facts
human(john).
human(mary).
human(alice).

% Rule: All humans are mortal
mortal(X) :- human(X).

% Query to check if John is mortal
is_mortal :- mortal(john), write('John is mortal.'), nl.

"how to run predicat logic
?- [predicate_logic].
?- [predicate_logic].
?- [predicate_logic]."
-----------------------------------------------------------
% Facts
battery(fine).
battery(dead).
headlights(down).
headlights(dim).
fuel_gauge(low).

% Rules
problem(starter) :- \+ battery(dead), \+ battery(fine).
problem(lack_of_fuel) :- fuel_gauge(low).
problem(alternator) :- battery(dead), headlights(dim).

% Query to check car problem
diagnose :- 
    problem(X),
    write('Possible problem: '), write(X), nl.

"How to run Expert System
?- [expertsys].
?- diagnose.
Possible problem: lack_of_fuel.
"
*/











