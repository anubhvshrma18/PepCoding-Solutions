import java.io.*;
import java.util.*;

public class Main {

    public static String compression1(String str) {
        // write your code here
        String n="";
        int count=0;
        n+=str.charAt(0);
        for(int i=0;i<str.length()-1;i++){
            if(str.charAt(i)!=str.charAt(i+1)){
                n+=str.charAt(i+1);
            }
            
        }
        return n;
    }

    public static String compression2(String str) {
        // write your code here 
        String n="";
        int count=1;
        n+=str.charAt(0);
        
        for(int i=1;i<str.length();i++){
            if(str.charAt(i-1)!=str.charAt(i)){
                if(count>1){
                    n+=count;
                    count=1;
                }
                n+=str.charAt(i);
                
            }
            else{
                count++;  
            }
            
        }
        if(count>1){
            n+=count;
        }

        return n;
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        System.out.println(compression1(str));
        System.out.println(compression2(str));
    }

}