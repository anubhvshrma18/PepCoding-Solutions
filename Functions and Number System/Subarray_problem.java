import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scn.nextInt();
        }
        subarray(arr);
    }
    public static void subarray(int arr[]) {
        int str = 0;
        while (str < arr.length) {
            int end = str;
            while (end < arr.length) {
                for (int i = str; i <= end; i++) {
                    System.out.print(arr[i] + "\t");
                }
                System.out.println();
                end++;
            }
            // System.out.println();
            str++;
        }
    }
}