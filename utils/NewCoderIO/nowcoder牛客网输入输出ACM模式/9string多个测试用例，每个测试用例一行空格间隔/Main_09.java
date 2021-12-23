import java.util.Arrays;
import java.util.Scanner;

public class Main_09 {
    public void so(String[] s){
        Arrays.sort(s,(o1, o2)->{
            if(o1.compareTo(o2)<0) return -1;
            else return 1; });
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Main s = new Main();
        while(sc.hasNextLine()){
            String str = sc.nextLine();
            if(str.equals("")) break;
            String[] arr = str.split(" ");
            s.so(arr);
            for(int i=0;i<arr.length;i++){
                if(i<arr.length-1)System.out.print(arr[i]+" ");
                else System.out.print(arr[i]);
            }
            System.out.println();
        }
    }
}