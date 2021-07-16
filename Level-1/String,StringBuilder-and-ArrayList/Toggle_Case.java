import java.io.*;
import java.util.*;

public class Main {

    public static String toggleCase(String str) {
        //write your code here
        // StringBuilder s=new StringBuilder(str);
        String ne="";
        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            if(ch>='a' && ch<='z'){
                char n=(char)((ch-'a')+'A');
                ne+=n;
            }
            else if(ch>='A' && ch<='Z'){
                char n=(char)((ch-'A')+'a');
                ne+=n;
            }
        }

        return ne;
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        System.out.println(toggleCase(str));
    }

}