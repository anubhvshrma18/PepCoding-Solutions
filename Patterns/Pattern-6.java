/*--

*	*	*		*	*	*	
*	*				*	*	
*						*	
*	*				*	*	
*	*	*		*	*	*	

--*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        int nsp=1;
        for(int r=1;r<=n;r++){
            int str=(n-nsp)/2;
            for(int i=1;i<=str+1;i++){
                System.out.print("*\t");
            }
            for(int i=1;i<=nsp;i++){
                System.out.print("\t");
            }
            for(int i=1;i<=str+1;i++){
                System.out.print("*\t");
            }
            if(r<((n/2)+1)){
                nsp+=2;
            }
            if(r>=((n/2)+1)){
                nsp-=2;
            }
            System.out.print("\n");
        }
        // write ur code here

    }
}