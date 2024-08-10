class Solution {
public:
    vector<int> parent; // Parents array for Union-Find
    int regionsCount;   // Counter for the number of regions found

    // Function to calculate the number of regions separated by slashes in the grid
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        regionsCount = n * n * 4;
        parent.resize(regionsCount);
        for (int i = 0; i < regionsCount; ++i) parent[i] = i;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int rootIndex = i * n + j;
                if (i < n - 1) {
                    merge(rootIndex * 4 + 2, (rootIndex + n) * 4);
                }
                if (j < n - 1) {
                    merge(rootIndex * 4 + 1, (rootIndex + 1) * 4 + 3);
                }
                char value = grid[i][j];
                if (value == '/') {
                    merge(rootIndex * 4, rootIndex * 4 + 3);
                    merge(rootIndex * 4 + 1, rootIndex * 4 + 2);
                } else if (value == '\\') {
                    merge(rootIndex * 4, rootIndex * 4 + 1);
                    merge(rootIndex * 4 + 2, rootIndex * 4 + 3);
                } else {
                    merge(rootIndex * 4, rootIndex * 4 + 1);
                    merge(rootIndex * 4 + 1, rootIndex * 4 + 2);
                    merge(rootIndex * 4 + 2, rootIndex * 4 + 3);
                }
            }
        }

        return regionsCount;
    }

    // Function to merge two nodes in the Union-Find structure
    void merge(int nodeA, int nodeB) {
        int parentA = find(nodeA);
        int parentB = find(nodeB);
        if (parentA != parentB) {
            parent[parentA] = parentB;
            --regionsCount; // Decrement the regions count only if a merge occurred
        }
    }

    // Recursive function to find the root parent of a node in Union-Find
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
};
