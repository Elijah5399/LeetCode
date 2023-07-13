class Solution {
    char[][] bcopy;
    int[][] dirs = new int[][]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    public char[][] updateBoard(char[][] board, int[] click) {
        char[][] bcopy = new char[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                bcopy[i][j] = board[i][j];
            }
        }
        this.bcopy = bcopy;
        dfs(click);
        return this.bcopy;
    }
    private void dfs(int[] click) {
        int y = click[0], x = click[1];
        if (bcopy[y][x] == 'M') {
            //unrevealed mine
            bcopy[y][x] = 'X';
        } else if (bcopy[y][x] == 'B' || 
        (Integer.valueOf(bcopy[y][x]) >= 1 && Integer.valueOf(bcopy[y][x]) <= 8)
        || bcopy[y][x] == 'X') {
            //do nothing, already revealed
        } else if (bcopy[y][x] == 'E') {
            int surrMines = 0;
            for (int[] dir : dirs) {
                int new_y = dir[0] + y, new_x = dir[1] + x;
                if (new_y >= 0 && new_x >= 0 && new_y < bcopy.length && new_x < bcopy[0].length) {
                    if (bcopy[new_y][new_x] == 'M' || bcopy[new_y][new_x] == 'X') {
                        surrMines++;
                    }
                }
            }
            if (surrMines > 0) {
                bcopy[y][x] = Integer.toString(surrMines).charAt(0);
            } else {
                //no surrounding mines; dfs adjacent
                bcopy[y][x] = 'B';
                for (int[] dir : dirs) {
                int new_y = dir[0] + y, new_x = dir[1] + x;
                if (new_y >= 0 && new_x >= 0 && new_y < bcopy.length && new_x < bcopy[0].length) {
                    dfs(new int[]{new_y, new_x});
                }
            }
            }
        }
    }
}