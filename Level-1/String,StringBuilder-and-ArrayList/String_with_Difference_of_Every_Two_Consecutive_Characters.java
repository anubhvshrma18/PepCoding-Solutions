import java.io.*;
import java.util.*;

public class Main {

    public static String solution(String str) {
        // write your code here
        String res="";
        res+=str.charAt(0);
        for(int i=1;i<str.length();i++){
            char curr=str.charAt(i);
            char prev=str.charAt(i-1);
            int n=curr-prev;
            res+=n;
            res+=curr;
        }

        return res;
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        System.out.println(solution(str));
    }

}