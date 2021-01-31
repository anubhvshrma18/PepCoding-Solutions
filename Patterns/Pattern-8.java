/*--

			    *	
			*		
		*			
	*				
*


--*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        for(int r=n;r>=1;r--){
            for(int c=1;c<=n;c++){
                if(c==r){
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