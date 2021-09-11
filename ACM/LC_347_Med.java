/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-09-10 23:20:29
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-10 23:20:35
*/
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