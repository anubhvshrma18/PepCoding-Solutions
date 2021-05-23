import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        // write your code here.
        int n = scn.nextInt();
        int k = scn.nextInt();
        int count = 0, sum = 0;
        int tem = n;
        while (tem > 0) {
            tem = tem / 10;
            count++;
        }
        // System.out.println(count);
        k = k % count;
        if (k < 0) {
            // k=Math.abs(k)%count;
            k = k + count;
        }
        int temp = k;
        while (k > 0) {
            int rem = n % 10;
            sum = sum * 10 + rem;
            n /= 10;
            k--;
        }
        while (temp > 0) {
            System.out.print(sum % 10);
            sum /= 10;
            temp--;
        }
        System.out.println(n);
    }
}