// Biểu diễn đồ thị bằng ma trận lân cận và danh sách lân cận
#include <iostream>
#define MAX 100

using namespace std;

// Ma trận lân cận
int adjMatrix[MAX][MAX];
// Danh sách lân cận
int adjList[MAX][MAX]; // Mỗi hàng là danh sách lân cận của một đỉnh
int listSize[MAX];    // Kích thước danh sách mỗi hàng

// Tạo ma trận lân cận
void createAdjacencyMatrix(int numVertices, int edges[][2], int numEdges) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjMatrix[u][v] = 1;
    }
}

// Tạo danh sách lân cận
void createAdjacencyList(int numVertices, int edges[][2], int numEdges) {
    for (int i = 0; i < numVertices; i++) {
        listSize[i] = 0;
    }
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u][listSize[u]] = v;
        listSize[u]++;
    }
}

// Duyệt BFS
void bfs(int startVertex, int numVertices, char vertices[]) {
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = startVertex;
    visited[startVertex] = true;

    cout << "Thứ tự duyệt BFS: ";

    while (front < rear) {
        int current = queue[front++];
        cout << vertices[current] << " ";

        for (int i = 0; i < listSize[current]; i++) {
            int neighbor = adjList[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
        }
    }
    cout << endl;
}

// Duyệt DFS (sử dụng stack)
void dfs(int startVertex, int numVertices, char vertices[]) {
    bool visited[MAX] = {false};
    int stack[MAX];
    int top = -1;

    stack[++top] = startVertex;

    cout << "Thứ tự duyệt DFS: ";

    while (top >= 0) {
        int current = stack[top--];

        if (!visited[current]) {
            visited[current] = true;
            cout << vertices[current] << " ";

            for (int i = listSize[current] - 1; i >= 0; i--) {
                int neighbor = adjList[current][i];
                if (!visited[neighbor]) {
                    stack[++top] = neighbor;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int numVertices = 7;
    int edges[][2] = {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}, {3, 4}, {3, 5}, {4, 2}, {4, 5}, {4, 6}, {6, 1}
    };
    int numEdges = 10;
    char vertices[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

    // Tạo ma trận lân cận
    createAdjacencyMatrix(numVertices, edges, numEdges);
    cout << "Ma trận lân cận:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Tạo danh sách lân cận
    createAdjacencyList(numVertices, edges, numEdges);
    cout << "\nDanh sách lân cận:" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << vertices[i] << ": ";
        for (int j = 0; j < listSize[i]; j++) {
            cout << vertices[adjList[i][j]] << " ";
        }
        cout << endl;
    }

    // Duyệt BFS
    bfs(0, numVertices, vertices);

    // Duyệt DFS
    dfs(0, numVertices, vertices);

    return 0;
}
