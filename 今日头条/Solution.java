/**

 */

// public class Solution 
// {

//     public static void main(String args[])
//     {


//     }

// }

import java.util.List;
import java.util.Scanner;
import java.util.Vector;
 
public class Solution {
 
    public static List xy(List list, int i) {
        List lst = new Vector();
 
        if (i >= list.size())    //递归出口
            return list;
 
        int t = (Integer) list.get(i);//获取幸运数字
 
        if (t == 1) {            //1这是特殊情况
            t = 2;
        }
 
        int l = list.size() / t;//移除转移操作执行l次
        int y = list.size() % t;//计算list剩余数目
 
        for (int k = 0; k < l; k++) {
            for (int j = 0; j < (t - 1); j++) {
                lst.add(list.remove(0));//将保留数放入新list，放入数目与幸运数字大小有关
            }
            list.remove(0);//移除掉非保留数
        }
        if (y > 0) {
            for (int k = 0; k < y; k++) {
                lst.add(list.remove(0));//将list剩余数加入新list
            }
        }
 
        i++;//幸运数游标加1
        List nlst = xy(lst, i);//递归直到递归出口
 
        return nlst;
    }
 
    public static int p(int m, int n) {//筛选符合条件的数字数目
        List list = new Vector();
        for (int i = 1; i <= m + n; i++) {
            list.add(i);
        }
 
        List nl = xy(list, 0);
        int c = 0;
        for (int j = 0; j < nl.size(); j++) {
 
            int nn = (Integer) nl.get(j);
            if (m < nn && n > nn) {
                c++;
            }
        }
        return c;
    }
 
    public static void main(String[] args) {
         
//        System.out.print("用户输入：");
         
        Scanner sc = new Scanner(System.in);
 
        int m = sc.nextInt();
        int n = sc.nextInt();
        sc.close();
 
        int res = p(m, n);
        System.out.println(res);
         
    }
 
}
