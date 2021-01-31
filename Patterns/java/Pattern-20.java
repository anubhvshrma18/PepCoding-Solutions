/*--

*				*	
*				*	
*		*		*	
*	*		*	*	
*				*	

--*/
//code
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        for(int r=1;r<=n;r++){
            for(int c=1;c<=n;c++){
                if(c==1 || c==n){
                    System.out.print("*\t");
                }
                else if(r==c && r>(n/2)){
                    System.out.print("*\t");
                }
                else if((r+c==n+1) && (r>=(n/2)+1)){
                    System.out.print("*\t");
                }
                else{
                    System.out.print("\t");
                }
                
            }
            
            System.out.println();
        }
        // write ur code here

    }
}