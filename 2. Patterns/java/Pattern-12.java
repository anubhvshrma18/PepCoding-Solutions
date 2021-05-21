/*
0	
1	1	
2	3	5	
8	13	21	34	
55	89	144	233	377	
*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        int fi=0,fy=1;
        for(int r=1;r<=n;r++){
            for(int c=1;c<=r;c++){
                System.out.print(fi+"\t");
                int x=fi+fy;
                fi=fy;
                fy=x;
            }
            System.out.print("\n");
        }
        // write ur code here

    }
}