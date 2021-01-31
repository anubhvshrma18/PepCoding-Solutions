/*
		1	
	2	3	2	
3	4	5	4	3	
	2	3	2	
		1	

*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        int str=1;
    
        for(int row=1;row<=n;row++){
            int num=row;
            if(row>(n/2)+1){
                num=n-row+1;
            }
            int nsp=(n-str)/2;
            for(int i=1;i<=nsp;i++){
                System.out.print("\t");
            }
            for(int j=1;j<=str;j++){
                if(j>(str/2)+1){
                    num--;
                }
                System.out.print(num+"\t");
                if(j<(str/2)+1){
                    num++;
                }
                
            }
            for(int i=1;i<=nsp;i++){
                System.out.print("\t");
            }
            if(row<((n/2)+1)){
                str=str+2;
            }
            if(row>=((n/2)+1)){
                str=str-2;
                num--;
            }
            System.out.print("\n");
        }
        // write ur code here

    }
}