/*--

*	
*	*	
*	*	*	
*	*	*	*	
*	*	*	*	*	

---*/
//Code
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        for (int row = 1; row <= n; row++) {

            for (int str = 1; str <= row; str++) {
                System.out.print("*\t");
            }
            System.out.println();
        }
    }
}