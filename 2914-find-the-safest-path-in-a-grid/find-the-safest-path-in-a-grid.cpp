class Solution {
public:

    // Directions: Down, Up, Right, Left
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    // ------------------------------------------------------------
    // This function checks whether we can reach the destination
    // while only stepping on cells whose safeness >= limit.
    // ------------------------------------------------------------
    bool canReach(vector<vector<int>>& dist, int limit)
    {
        int n = dist.size();

        // If the starting cell itself is unsafe, no path is possible.
        if(dist[0][0] < limit)
            return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            // Destination reached.
            if(x == n-1 && y == n-1)
                return true;

            for(auto [dx, dy] : dir)
            {
                int nx = x + dx;
                int ny = y + dy;

                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if(vis[nx][ny])
                    continue;

                // Only move to cells whose safeness
                // is at least 'limit'.
                if(dist[nx][ny] >= limit)
                {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        int n = grid.size();

        // ------------------------------------------------------------
        // STEP 1: Multi-source BFS
        // dist[i][j] = Distance from nearest thief.
        // ------------------------------------------------------------
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Push all thieves into the queue.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto [dx, dy] : dir)
            {
                int nx = x + dx;
                int ny = y + dy;

                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if(dist[nx][ny] != -1)
                    continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        // ------------------------------------------------------------
        // STEP 2: Binary Search on the answer.
        // ------------------------------------------------------------

        int low = 0;

        // The maximum possible safeness cannot exceed
        // the distance at the starting cell.
        int high = dist[0][0];

        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(canReach(dist, mid))
            {
                ans = mid;          // mid is possible
                low = mid + 1;      // Try for a larger safeness
            }
            else
            {
                high = mid - 1;     // Need a smaller safeness
            }
        }

        return ans;
    }
};