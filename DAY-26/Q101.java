import java.util.Random;
import java.util.Scanner;

public class Q101 {
    public static void main(String[] args) {
        // Create instances for user input and random number generation
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        
        // Define boundaries and generate the secret number (1 to 100)
        int min = 1;
        int max = 100;
        int secretNumber = random.nextInt(max - min + 1) + min;
        
        int attempts = 0;
        int guess = 0;
        boolean hasGuessedCorrectly = false;
        
        System.out.println("Welcome to the Number Guessing Game!");
        System.out.println("I have chosen a secret number between " + min + " and " + max + ".");
        System.out.println("Try to guess it!");

        // Game loop continues until the user guesses correctly
        while (!hasGuessedCorrectly) {
            System.out.print("\nEnter your guess: ");
            
            // Validate input to ensure it is an integer
            if (scanner.hasNextInt()) {
                guess = scanner.nextInt();
                attempts++;
                
                // Check the player's guess against the secret number
                if (guess < min || guess > max) {
                    System.out.println("Please guess a number within the range (" + min + " to " + max + ").");
                } else if (guess < secretNumber) {
                    System.out.println("Too low! Try a higher number.");
                } else if (guess > secretNumber) {
                    System.out.println("Too high! Try a lower number.");
                } else {
                    hasGuessedCorrectly = true;
                    System.out.println("\nCongratulations! You've guessed the correct number.");
                    System.out.println("It took you " + attempts + " attempts.");
                }
            } else {
                System.out.println("Invalid input! Please enter a valid integer.");
                scanner.next(); // Clear the invalid input from scanner buffer
            }
        }
        
        // Close the scanner resource
        scanner.close();
    }
}