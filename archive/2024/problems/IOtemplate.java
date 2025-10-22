import java.util.Scanner;

public class IOtemplate {
    public static void main(String[] args) {
        // create this object to get input from standard in
        // remember to import java.util.Scanner
        Scanner scanner = new Scanner(System.in);

        // use .nextInt() to read a single integer
        int N = scanner.nextInt();
        // use .next() to read a String (assumes input is space-separated)
        String str = scanner.next();

        // prints out N copies of str on a single line
        for (int i = 0; i < N; i++) {
            // you can print to System.out as usual
            System.out.print(str + " ");
        }
        System.out.println();

        // note, the Scanner class doesn't care about newline separators,
        // so for this example program the following inputs would produce the same output.
        // input 1:
        // 5 A
        // input 2:
        // 5
        // A
        // output:
        // A A A A A 
    }
}
