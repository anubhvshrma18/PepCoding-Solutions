/*
1												1	
1	2										2	1	
1	2	3								3	2	1	
1	2	3	4						4	3	2	1	
1	2	3	4	5				5	4	3	2	1	
1	2	3	4	5	6		6	5	4	3	2	1	
1	2	3	4	5	6	7	6	5	4	3	2	1
*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        int c=2*n-1;
        for(int r=1;r<=n;r++){
            int str=r;
            int nsp=c-2*str;
            int num=1;
            for(int i=1;i<=str;i++){
                System.out.print(num+"\t");
                num++;
            }
            for(int i=1;i<=nsp;i++){
                System.out.print("\t");
            }
            if(r==n){
                num--;
                str--;
            }
            for(int i=1;i<=str;i++){
                num--;
                System.out.print(num+"\t");
                
            }
            System.out.print("\n");
        }

        // write ur code here

    }
}