import java.util.Scanner;
public class Main_04 {
    public static void main(String[] args) {
        int sum = 0;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            //n为0结束输入
            if (n == 0) {
                break;
            }
            //每次循环开始之前sum置0
            sum = 0;
            for (int i = 0; i < n; i++) {
                sum += sc.nextInt();
            }
            System.out.println(sum);
        }
        sc.close();
    }
}
