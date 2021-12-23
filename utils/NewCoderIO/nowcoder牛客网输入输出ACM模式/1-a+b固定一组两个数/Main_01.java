import java.util.Scanner;
/**
 * 输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据包括多组
 */
public class Main_01 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(a + b);
        }
        sc.close();
    }
}