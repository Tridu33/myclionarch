import java.util.Scanner;

public class Main_07 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String[] sArr = sc.nextLine().split(" ");
            int sum = 0;
            for(int i = 0; i < sArr.length; i++){
                sum += Integer.parseInt(sArr[i]);
            }
            System.out.println(sum);
        }
    }
}