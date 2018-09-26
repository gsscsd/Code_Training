import java.util.Scanner;

public class Solution {


    //最远加油站优先
        public int  greedy(int numOfGS,int []distOfGS,int []allowedGasoline,int distance,int initialGasoline){
                // int count=0,m=dist.length;
                // for(int j=0; j<m; j++)
                // if(dist[j] > n)
                //         return -1;

                // for(int i=0,sum=0; i<m; i++){
                //         sum += dist[i];
                //         if(sum > n){
                //                 count++;
                //                 sum = dist[i];
                //         }
                // }

                // return count;

    }
    public int minGasStation(int numOfGS,int []distOfGS,int []allowedGasoline,int distance,int initialGasoline) {
        Queue<Integer> queue = new queue<>(new Comparator<Integer>() {
                @Override
                public int compare(Integer integer, Integer t1) {
                return t1 - integer;
                }
        });
        int result = 0;
        int i = 0;
        long fuel = initialGasoline;
        while(true){
                while(i < numOfGS && distOfGS[i]<= fuel){
                        queue.add(allowedGasoline[i]);
                        i++;
                }
                if(fuel >= distance){
                        return result;
                }
                if(queue.isEmpty()){
                        return -1;
                }
                fuel += queue.poll();
                result++;
        }
}

}
