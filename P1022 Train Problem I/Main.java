import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    private enum operate{IN,OUT};

    public static void main(String[] args){
        Scanner cin=new Scanner(System.in);

        while (cin.hasNext()){
            Stack<Integer> tmp=new Stack<>();
            ArrayList<Integer> in=new ArrayList<>(),out=new ArrayList<>();
            ArrayList<operate> ans=new ArrayList<>();

            int N=cin.nextInt();
            cin.next().chars().forEach(in::add);
            cin.next().chars().forEach(out::add);

            Runnable stack_in=() -> {tmp.push(in.get(0));in.remove(0);ans.add(operate.IN);};
            Runnable stack_out=() -> {tmp.pop();out.remove(0);ans.add(operate.OUT);};
            while (ans.size() != 2*N){
                if (tmp.isEmpty() || !tmp.peek().equals(out.get(0)))
                    if (in.isEmpty()) break;
                    else stack_in.run();
                else stack_out.run();
            }

            if (ans.size() != 2*N) System.out.println("No.");
            else{
                System.out.println("Yes.");
                ans.forEach(x -> System.out.println(x==operate.IN?"in":"out"));
            }
            System.out.println("FINISH");
        }
    }
}
