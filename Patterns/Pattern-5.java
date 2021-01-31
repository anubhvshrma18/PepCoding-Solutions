/*
		*	
	*	*	*	
*	*	*	*	*	
	*	*	*	
		*	
*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        int str=1;
        for(int row=1;row<=n;row++){
            int nsp=(n-str)/2;
            for(int i=1;i<=nsp;i++){
                System.out.print("\t");
            }
            for(int j=1;j<=str;j++){
                System.out.print("*\t");
            }
            for(int i=1;i<=nsp;i++){
                System.out.print("\t");
            }
            if(row<((n/2)+1)){
                str=str+2;
            }
            if(row>=((n/2)+1)){
                str=str-2;
            }
            System.out.println();
        }
        // write ur code here

    }
}