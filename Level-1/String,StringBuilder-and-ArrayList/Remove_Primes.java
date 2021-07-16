import java.io.*;
import java.util.*;

public class Main {
    public static boolean isPrime(int n) {
        int flag=0;
        if (n == 2) {
            return true;
        }
        else {
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                return false;
            } else {
                return true;
            }
        }
    }

    public static void solution(ArrayList < Integer > al) {
        // write your code here
        int idx = 0;
        while (idx < al.size()) {
            if (isPrime(al.get(idx))) {
                al.remove(idx);
            } else {
                idx++;
            }
        }

    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        ArrayList < Integer > al = new ArrayList < > ();
        for (int i = 0; i < n; i++) {
            al.add(scn.nextInt());
        }
        solution(al);
        System.out.println(al);
    }

}