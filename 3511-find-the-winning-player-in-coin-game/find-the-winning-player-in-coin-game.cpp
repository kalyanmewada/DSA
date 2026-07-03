class Solution {
public:
    string winningPlayer(int x, int y) {
        int turn = 0;

        // Continue while the current player can make a move
        while (x >= 1 && y >= 4) {
            x--;        // Use one 75-value coin
            y -= 4;     // Use four 10-value coins
            turn++;     // One successful move completed
        }

        // If the number of moves is even,
        // Alice is the next player and cannot move, so Bob wins.
        if (turn % 2 == 0)
            return "Bob";

        // Otherwise, Bob is the next player and cannot move, so Alice wins.
        return "Alice";
    }
};