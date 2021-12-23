import java.util.*;

public class Main_05 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        for(int i=0; i < len; i++){
            int num = sc.nextInt();
            int sum = 0;
            for(int j = 0; j < num; j++){
                sum += sc.nextInt();
            }
            System.out.println(sum);
        }
    }
}