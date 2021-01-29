import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here 
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        for (int fact = 1; fact * fact <= n; fact++) {
            System.out.println(fact * fact);
        }
    }
}