import java.util.List;
import java.util.Scanner;
import java.util.Vector;
import java.io.*;


public class Demo{

    public static int p(int m,int n)
    {
        int res = 0;

        for(int i = m ;i <= n;++i)
        {
            String temp = String.valueOf(i);
            boolean flag = true;
            int len = temp.length();
            for(int j = 0;j < len / 2;j++)
            {   

                if(temp.charAt(j) == temp.charAt(len - j - 1))
                {
                    flag = false;
                }
            }
            if(flag) res++;
        }
        return res;

    }

    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
 
        int m = sc.nextInt();
        int n = sc.nextInt();
        sc.close();
 
        int res = p(m, n);
        System.out.println(res);
    }
}