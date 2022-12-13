import java.util.Scanner;

public class checkPalindrome{

    static boolean check(int i, String str){
        if(str.charAt(i) != str.charAt(str.length() - i - 1))
            return false;

        if(i >= str.length()/2)
            return true;
        
        return check(i+1, str);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        sc.close();
        if(check(0, str)){
            System.out.println("YES");
        }
        else{
            System.out.println("NO");
        }
    }
}