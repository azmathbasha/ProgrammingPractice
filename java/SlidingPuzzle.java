/**
 * A 3x3 sliding puzzle (also known as the 8-puzzle) is a game where you have an empty space that you can use to slide adjacent tiles. 
 * The goal is to arrange the tiles in order from 1 to 8, leaving the bottom-right corner as the empty space.

 * Here's a basic implementation of the 3x3 sliding puzzle 
 */
import java.util.*;

public class SlidingPuzzle {
    private static final int SIZE = 3;
    private static int[][] puzzle = new int[SIZE][SIZE];
    private static int emptyRow = SIZE - 1;
    private static int emptyCol = SIZE - 1;

    public static void main(String[] args) {
        initializePuzzle();
        shufflePuzzle();
        playGame();
    }

    // Initialize the puzzle in order (1 to 8) with the last spot empty
    private static void initializePuzzle() {
        int number = 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i == SIZE - 1 && j == SIZE - 1) {
                    puzzle[i][j] = 0; // Empty space
                } else {
                    puzzle[i][j] = number++;
                }
            }
        }
    }

    // Shuffle the puzzle randomly
    private static void shufflePuzzle() {
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            int direction = random.nextInt(4);
            moveTile(direction);
        }
    }

    // Move the tile based on the direction (0 = UP, 1 = DOWN, 2 = LEFT, 3 = RIGHT)
    private static void moveTile(int direction) {
        int newRow = emptyRow;
        int newCol = emptyCol;

        switch (direction) {
            case 0: newRow = emptyRow - 1; break; // UP
            case 1: newRow = emptyRow + 1; break; // DOWN
            case 2: newCol = emptyCol - 1; break; // LEFT
            case 3: newCol = emptyCol + 1; break; // RIGHT
        }

        if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE) {
            puzzle[emptyRow][emptyCol] = puzzle[newRow][newCol];
            puzzle[newRow][newCol] = 0;
            emptyRow = newRow;
            emptyCol = newCol;
        }
    }

    // Play the game
    private static void playGame() {
        Scanner scanner = new Scanner(System.in);

        while (!isSolved()) {
            printPuzzle();
            System.out.println("Enter move (w: UP, s: DOWN, a: LEFT, d: RIGHT): ");
            String move = scanner.nextLine();

            switch (move) {
                case "w": moveTile(0); break; // UP
                case "s": moveTile(1); break; // DOWN
                case "a": moveTile(2); break; // LEFT
                case "d": moveTile(3); break; // RIGHT
                default: System.out.println("Invalid move! Try again.");
            }
        }

        printPuzzle();
        System.out.println("Congratulations! You solved the puzzle.");
    }

    // Check if the puzzle is solved
    private static boolean isSolved() {
        int number = 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i == SIZE - 1 && j == SIZE - 1) {
                    return puzzle[i][j] == 0;
                }
                if (puzzle[i][j] != number++) {
                    return false;
                }
            }
        }
        return true;
    }

    // Print the current state of the puzzle
    private static void printPuzzle() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (puzzle[i][j] == 0) {
                    System.out.print("  "); // Empty space
                } else {
                    System.out.print(puzzle[i][j] + " ");
                }
            }
            System.out.println();
        }
    }
}
