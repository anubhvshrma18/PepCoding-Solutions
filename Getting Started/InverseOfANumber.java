import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here 
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int x = 0, count = 0;
        int temp = n;
        while (n > 0) {
            n = n / 10;
            count++;
        }
        for (int i = 1; i <= count; i++) {
            x = x + (int)(i * (Math.pow(10, (temp % 10) - 1)));
            temp = temp / 10;
        }
        System.out.println(x);
    }
}