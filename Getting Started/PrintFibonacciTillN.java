import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int f1 = 0;
        int f2 = 1;
        System.out.println(f1);
        System.out.println(f2);
        for (int i = 2; i < n; i++) {
            int f3 = f1 + f2;
            System.out.println(f3);
            f1 = f2;
            f2 = f3;

        }
    }
}