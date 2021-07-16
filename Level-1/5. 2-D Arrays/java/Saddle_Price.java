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
        int ans = saddlepoint(mat);
        if (ans == Integer.MAX_VALUE) {
            System.out.println("Invalid input");
        } else {
            System.out.println(ans);
        }

    }
    public static int saddlepoint(int mat[][]) {
        int n = mat.length;
        for (int i = 0; i < n; i++) {
            int rowMin = Integer.MAX_VALUE;
            int minCol = -1;
            boolean flag = true;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] < rowMin) {
                    rowMin = mat[i][j];
                    minCol = j;
                }
            }
            for (int r = 0; r < n; r++) {
                if (rowMin < mat[r][minCol]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                return rowMin;
            }
        }
        return Integer.MAX_VALUE;
    }

}