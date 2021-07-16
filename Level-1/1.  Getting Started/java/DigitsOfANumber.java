import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here 
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int y = n;
        int sum = 1, count = 0;
        while (n > 0) {
            n = n / 10;
            count++;
        }
        for (int i = 1; i < count; i++) {
            sum = sum * 10;
        }
        while (count > 0) {
            System.out.println(y / sum);
            y = y % sum;
            sum = sum / 10;
            count--;
        }


    }
}