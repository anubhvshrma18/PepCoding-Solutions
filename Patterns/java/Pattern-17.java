/*
		*	
		*	*	
*	*	*	*	*	
		*	*	
		*	
*/
//code
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        int ns1=n/2;
        int ns2=n/2;
        int str=0;
        for(int r=1;r<=n;r++){
            if(r==(n/2)+1){
                ns1=0;
                str=n;
            }
            else{
                ns1=n/2;
                str=n-ns1-ns2;
            }
            for(int i=1;i<=ns1;i++){
                System.out.print("\t");
            }
            for(int i=1;i<=str;i++){
                System.out.print("*\t");
            }
            for(int i=1;i<=ns2;i++){
                System.out.print("\t");
            }
            
            if(r<(n/2)+1){
                ns2--;
            }
            if(r>=(n/2)+1){
                ns2++;
            }
            System.out.print("\n");
        }
        // write ur code here

    }
}