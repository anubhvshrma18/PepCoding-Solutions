/*
1	
2	3	
4	5	6	
7	8	9	10	
11	12	13	14	15
*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        int num=1;
        for(int r=1;r<=n;r++){
            for(int c=1;c<=r;c++){
                System.out.print(num+"\t");
                num++;
            }
            System.out.print("\n");
        }
        // write ur code here

    }
}