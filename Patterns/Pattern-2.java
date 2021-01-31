/*--

*	*	*	*	*	
*	*	*	*	
*	*	*	
*	*	
*
--
*/	
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        for (int row = n; row >= 1; row--) {
            for (int i = 1; i <= row; i++) {
                System.out.print("*\t");
            }
            System.out.println();
        }
        // write ur code here

    }
}