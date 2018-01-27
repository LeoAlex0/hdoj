import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.Collector;

public class Main {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        final int N=in.nextInt();

        for (int i=0;i<N;i++){
            final CharSequence s=in.next();

            String collect = s.chars().boxed().collect(Collector.of(
                    ArrayList<Integer>::new,
                    (arr,t)-> {
                        final int n=arr.size();
                        if (n!=0 && arr.get(n-1).equals(t)){
                            arr.set(n-2,arr.get(n-2)+1);
                        }
                        else {
                            arr.add(1);
                            arr.add(t);
                        }
                    },
                    (arr1,arr2) -> {arr1.addAll(arr2);return arr1;},
                    (arr) -> {
                        final int n=arr.size();
                        StringBuilder ret= new StringBuilder();
                        for (int k=0;k<n/2;k++){
                            if (!arr.get(k<<1).equals(1)) ret.append(arr.get(k << 1));
                            ret.append((char) arr.get((k << 1) + 1).intValue());
                        }
                        return ret.toString();
                    }));

            System.out.println(collect);
        }
    }
}
