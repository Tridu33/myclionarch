
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;
 
public class IOjava {
    public static void main(String[] args) throws Exception {
        // 输入重定向
        BufferedInputStream in = new BufferedInputStream(new FileInputStream("stdinjava.txt"));
        System.setIn(in);
        Scanner stdin = new Scanner(System.in);
        int a = stdin.nextInt();
        int b = stdin.nextInt();
        stdin.close();
        // 输出重定向
        PrintStream out = new PrintStream(new FileOutputStream("stdoutjava.txt"));
        System.setOut(out);
        System.out.print(a + b);
        out.close(); // 关闭重定向
    }
}