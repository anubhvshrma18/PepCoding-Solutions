import java.io.*;
import java.util.*;

public class Main {

    public static void solution(String str) {
        //write your code here
        for(int i=0;i<str.length();i++){
            for(int j=i;j<str.length();j++){
                String sub=str.substring(i,j+1);
                if(reverse(sub)==1){
                    System.out.println(sub);
                }
            }
        }

    }
    public static int reverse(String s){
        int str=0,flag=0;
        int end=s.length()-1;
        while(str<end){
            if(s.charAt(str)==s.charAt(end)){
                str++;
                end--;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag==1){
            return 0;
        }
        else{
            return 1;
        }
        
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        solution(str);
    }

}