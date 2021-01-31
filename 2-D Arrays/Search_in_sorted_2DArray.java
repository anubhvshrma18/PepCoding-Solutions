import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int mat[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = scn.nextInt();
            }
        }
        int elm = scn.nextInt();
        searchsorted(mat, elm);

    }
    public static void searchsorted(int mat[][], int elm) {
        int nr = mat.length;
        int nc = nr;
        int i = 0, j = nc - 1;
        while (true) {
            int ref = mat[i][j];
            if (elm == ref) {
                System.out.println(i + "\n" + j);
                break;
            } else if (elm > ref) {
                i++;
            } else if (elm < ref) {
                j--;
            }


            if (i >= nr || j < 0) {
                System.out.println("Not Found");
                break;
            }

        }
        return;
    }

}