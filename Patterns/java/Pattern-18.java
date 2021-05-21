/*
*	*	*	*	*	*	*	
	*				*		
		*		*			
			*				
		*	*	*			
	*	*	*	*	*		
*	*	*	*	*	*	*	

*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
            //upper half
        for(int r=1;r<=n/2;r++){
            for(int i=1;i<=n;i++){
                if(r==1 || r==n){
                    System.out.print("*\t");
                }
                else if(r==i || r+i==n+1){
                    System.out.print("*\t"); 
                }
                else{
                    System.out.print("\t");
                }
            }
            System.out.print("\n");
        }
        //lower half pyramid
        int spc=n/2;
        int str=1;
        for(int r=(n/2)+1;r<=n;r++){
            
            for(int i=1;i<=spc;i++){
                System.out.print("\t");
            }
            for(int i=1;i<=str;i++){
                System.out.print("*\t");
            }
            for(int i=1;i<=spc;i++){
                System.out.print("\t");
            }
            spc--;
            str+=2;
            System.out.print("\n");
        }
        
        // write ur code here

    }
}