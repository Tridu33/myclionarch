import java.util.Scanner;
public class Main_03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            //判断什么时候退出循环，结束输入
            if (a == 0 && b == 0) {
                break;
            }
            System.out.println(a + b);
        }
        sc.close();
    }
}