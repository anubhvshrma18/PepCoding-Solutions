/*
*	
	*	
		*	
			*	
				*	
*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        for(int r=1;r<=n;r++){
            for(int c=1;c<=n;c++){
                if(r==c){
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