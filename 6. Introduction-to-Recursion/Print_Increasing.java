import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        printIncreasing(n);
    }

    public static void printIncreasing(int n) {
        if (n < 1) {
            return;
        }
        printIncreasing(n - 1);
        System.out.println(n);
        
    }

}