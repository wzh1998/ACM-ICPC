/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-06-27 15:14:25
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-18 12:11:11
*/

//2021-09 solution
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<> ();
        
        if(nums.length < 3) return result;
        
        Arrays.sort(nums);    
        
        for(int i = 0; i < nums.length - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = nums.length - 1;
            
            while(left < right) {
                if(nums[left] + nums[right] < target) left++;
                else if(nums[left] + nums[right] > target) right--;
                else {
                    List<Integer> triplet = new ArrayList<> ();
                    triplet.add(nums[i]);
                    triplet.add(nums[left]);
                    triplet.add(nums[right]);
                    result.add(triplet);
                    
                    left++;
                    right--;
            
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        
        return result;
    }
}

// Narive solution
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<> ();
        
        if(nums.length < 3) return result;
        
        Arrays.sort(nums);
        Map<Integer, Integer> map = new HashMap<> ();
        
        for(int i = 0; i < nums.length; i++) 
            map.put(nums[i], i);
        
        
        for(int i = 0; i < nums.length - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            for(int j = i + 1; j < nums.length - 1; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                if(map.containsKey(-nums[i]-nums[j])) {
                    int k = map.get(-nums[i]-nums[j]);
                    if(k > j) {
                        List<Integer> triplet = new ArrayList<> ();
                        triplet.add(nums[i]);
                        triplet.add(nums[j]);
                        triplet.add(nums[k]);
                        result.add(triplet);
                    }
                }
                
            }
        }
        
        return result;
    }
}

// previous solution
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
		
		List<List<Integer>> result = new ArrayList<>();
        if(nums.length < 3) return result;
        
        Arrays.sort(nums);
        for(int i = 0; i < nums.length - 2; i++) {
        	if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
        		int target = -nums[i];
            	int front = i + 1;
            	int back = nums.length - 1;
            	
            	while(front < back) {
            		int currentSum = nums[front] + nums[back];
            		if(currentSum < target) front++;
            		else if(currentSum > target) back--;
            		else {
            			List<Integer> currentComb = new ArrayList<>();
            			int frontVal = nums[front];
            			int backVal = nums[back];
            			
            			currentComb.add(-target);
            			currentComb.add(frontVal);
            			currentComb.add(backVal);
            			result.add(currentComb);
            			
            			while(front < back - 1) {
            				front++;
            				if(nums[front] != frontVal) break;
            			}
            			while(back > front) {
            				back--;
            				if(nums[back] != backVal) break;
            			}
            		}
            	}
        	}
        }
        return result;
    }
}