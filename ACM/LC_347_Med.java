/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-09-10 23:20:29
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-25 15:00:24
*/

// solution based on priority queue (heap)
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<> ();
        for(int num : nums)
            map.put(num, map.getOrDefault(num, 0) + 1);
        
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<> ((a1, a2) -> a1.getValue() - a2.getValue());
        for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
            pq.add(entry);
            if(pq.size() > k)
                pq.poll();
        }
        
        int[] result = new int[k];
        for(int i = k - 1; i >= 0; i--) 
            result[i] = pq.poll().getKey();
        
        return result;
    }
    
}

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<> ();
        List<Integer>[] bucket = new ArrayList[nums.length + 1];
        
        for(int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        for(int num : map.keySet()) {
            int freq = map.get(num);
            if(bucket[freq] == null) {
                bucket[freq] = new ArrayList<> ();
            }
            bucket[freq].add(num);
        }
        
        int[] result = new int[k];
        int counter = 0;
        for(int i = bucket.length - 1; i >= 0 && counter < k; i--) {
            if(bucket[i] != null) {
                for(int j = 0; j < bucket[i].size(); j++) {
                    result[counter] = bucket[i].get(j);
                    counter++;
                }
            }
        }
        
        return result;
    }
}