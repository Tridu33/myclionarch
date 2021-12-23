import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()){
            String[] array = scanner.nextLine().split(",");
            Arrays.sort(array);
            for (int i = 0; i < array.length; ++i){
                if (i == array.length - 1){
                    System.out.println(array[i]);
                    break;
                }
                System.out.print(array[i] + ",");
            }
        }
    }
}