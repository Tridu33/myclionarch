import java.util.*;
public class Main_08 {
    public void so(String[] s){
        Arrays.sort(s,(o1,o2)->{
            if(o1.compareTo(o2)<0) return -1;
            else return 1;
        });
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Main m = new Main();
        int count = sc.nextInt();
        while (sc.hasNextLine()){
            String[] arr = sc.nextLine().split(" ");
            m.so(arr);
            for(int i=0;i<arr.length;i++){
                if(i<arr.length-1)System.out.print(arr[i]+" ");
                else System.out.print(arr[i]);
            }
        }
    }
}