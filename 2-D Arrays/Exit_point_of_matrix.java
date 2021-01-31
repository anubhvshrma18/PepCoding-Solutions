import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int nr = scn.nextInt();
        int nc = scn.nextInt();
        int mat[][] = new int[nr][nc];
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                mat[i][j] = scn.nextInt();
            }
        }
        exitpoint(mat);

    }
    public static void exitpoint(int mat[][]) {
        int nr = mat.length;
        int nc = mat[0].length;
        int i = 0, j = 0, dir = 0;
        while ((i >= 0 && i < nr) && (j >= 0 && j < nc)) {
            dir = (dir + mat[i][j]) % 4;
            if (dir == 0) {
                j++;
            } else if (dir == 1) {
                i++;
            } else if (dir == 2) {
                j--;
            } else {
                i--;
            }
        }
        if (dir == 0) {
            j--;
            System.out.println(i + "\n" + j);
        }
        if (dir == 1) {
            i--;
            System.out.println(i + "\n" + j);
        }
        if (dir == 2) {
            j++;
            System.out.println(i + "\n" + j);
        }
        if (dir == 3) {
            i++;
            System.out.println(i + "\n" + j);
        }
    }

}