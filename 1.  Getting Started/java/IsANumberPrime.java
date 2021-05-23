import java.util.*;

public class IsANumberPrime {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();

        // write ur code here
        for (int j = 0; j < t; j++) {
            int n = scn.nextInt();
            int flag = 0;
            if (n == 2) {
                System.out.println("prime");
            } else {
                for (int i = 2; i * i <= n; i++) {
                    if (n % i == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1) {
                    System.out.println("not prime");
                } else {
                    System.out.println("prime");
                }
            }
        }


    }
}