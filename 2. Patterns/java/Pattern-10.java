/*
		*	
	*		*	
*				*	
	*		*	
		*	
*/
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int str = 0;
        int nsp = n / 2;
        int ns = -1;
        int ext = 0;
        for (int r = 1; r <= n; r++) {

            if ((r == 1) || (r == n)) {
                str = 1;
                ext = 1;
            } else {
                str = 2;
                ext = 0;
            }

            for (int i = 1; i <= nsp; i++) {
                System.out.print("\t");
            }
            for (int i = 1; i <= (str - 1) + ext; i++) {
                System.out.print("*\t");
            }
            for (int i = 1; i <= ns; i++) {
                System.out.print("\t");
            }
            for (int i = 1; i <= (str - 1); i++) {
                System.out.print("*\t");
            }
            if (r < ((n / 2) + 1)) {
                nsp--;
                ns += 2;
            }
            if (r >= ((n / 2) + 1)) {
                nsp++;
                ns -= 2;
            }
            System.out.println();

        }
        // write ur code here

    }
}
