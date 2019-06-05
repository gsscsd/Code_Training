import java.util.*;

public class SSS
{

    public static void xyz()
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        ArrayList<String> arr = new ArrayList<String>();
        for(int i = 0;i < n;i++)
        {
            String temp = sc.nextLine();
            arr.add(temp);
        }

        for(int i = 0;i < arr.size();i++)
        {
            int theMax = -1;
            String theS = "";
            for(int j = 0;j < arr.size();j++)
            {
                if(i != j)
                {
                    String s0 = arr.get(i);
                    String s1 = arr.get(j);
                    String s_temp = "";
                    for(int k = 0;k < Math.min(s0.length(),s1.length());k++)
                    {
                        s_temp += String.valueOf(s0.charAt(k)); 
                        if(s0.charAt(k) != s1.charAt(k))
                        {
                            if(theMax < s_temp.length())
                            {
                                theMax = s_temp.length();
                                theS = s_temp;
                            }
                            break;
                        }
                    }
                }
            }
            System.out.println(theS);
        }

    }

    public static void main(String args[])
    {
        xyz();
    }
}


