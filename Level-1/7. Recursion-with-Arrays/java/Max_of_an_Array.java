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
        // int max=Integer.MIN_VALUE;
        System.out.println(maxOfArray(arr,0));
    }

    public static int maxOfArray(int[] arr, int idx) {
        if(idx==arr.length){
            return 0;
        }
        int newmx=maxOfArray(arr,idx+1);
        if(newmx<arr[idx]){
            newmx=arr[idx];
        }
        return newmx;
    }

}