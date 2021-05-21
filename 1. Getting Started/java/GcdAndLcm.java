import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n1 = scn.nextInt();
        int n2 = scn.nextInt();
        int t1 = n1;
        int t2 = n2;
        while (t1 % t2 != 0) {
            int rem = t1 % t2;
            t1 = t2;
            t2 = rem;

        }
        int gcd = t2;
        int lcm = (n1 * n2) / gcd;
        System.out.println(gcd + "\n" + lcm);
    }
}