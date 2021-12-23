import java.util.Scanner;
public class Main_02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int[][] nums = new int[t][2];
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < 2; j++) {
                nums[i][j] = sc.nextInt();
            }
        }
        sc.close();
        //输出结果
        for (int i = 0; i < t; i++) {
            System.out.println(nums[i][0] + nums[i][1]);
        }
    }
}