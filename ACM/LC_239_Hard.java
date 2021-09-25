class MonotonicQueue {
    Deque<Integer> queue;
    public MonotonicQueue() {
        queue = new LinkedList<> ();
    }
    public void add(int num) {
        while(!queue.isEmpty() && num > queue.peekLast()) 
            queue.pollLast();
        queue.addLast(num);
    }
    public void poll(int num) {
        if(num == queue.peekFirst())
            queue.pollFirst();
    }
    public int queryMax() {
        return queue.peekFirst();
    }
}

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        MonotonicQueue mq = new MonotonicQueue();
        int[] result = new int[nums.length - k + 1];
        
        for(int i = 0; i < k; i++) 
            mq.add(nums[i]);
        result[0] = mq.queryMax();
        
        
        
        for(int left = 0, right = k - 1; right + 1 < nums.length; left++, right++) {
            mq.add(nums[right + 1]);
            mq.poll(nums[left]);
            result[left + 1] = mq.queryMax();
        }
        
        return result;
        
    }
}