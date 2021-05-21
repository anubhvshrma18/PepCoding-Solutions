/*--
*	*	*		*	
    	*		*	
*	*	*	*	*	
*		*			
*		*	*	*	

--*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        for(int r=1;r<=n;r++){
            for(int j=1;j<=n;j++){
                if(r==1 && (j==n || j<=(n/2)+1)){
                    System.out.print("*\t");
                }
                else if(r<=(n/2) && (j==n || j==(n/2)+1)){
                    System.out.print("*\t");
                }
                else if(r==(n/2)+1){
                    System.out.print("*\t");
                }
                else if(r>(n/2)+1 && (j==1 || j==(n/2)+1)){
                    System.out.print("*\t");
                }
                else if(r==n && (j==1 || j>=(n/2)+1)){
                    System.out.print("*\t");
                }
                else{
                    System.out.print("\t");
                }
            }
            System.out.print("\n");
        }
        // write ur code here

    }
}