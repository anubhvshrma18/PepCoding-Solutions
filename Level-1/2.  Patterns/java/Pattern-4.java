/*
*	*	*	*	*	
	*	*	*	*	
		*	*	*	
			*	*	
				*
*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        for (int row = 1; row <= n; row++) {
            for (int i = 1; i <= row - 1; i++) {
                System.out.print("\t");
            }
            for (int j = 1; j <= n - row + 1; j++) {
                System.out.print("*\t");
            }
            System.out.println();
        }
        // write ur code here

    }
}