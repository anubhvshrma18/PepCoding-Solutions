import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int x = scn.nextInt();
        int ans = power(x, n);
        System.out.println(ans);
    }

    public static int power(int x, int n) {
        if (x == 0) {
            return 1;
        }
        int xM1power = power(x - 1, n);
        int npower = n * xM1power;
        return npower;
    }

}