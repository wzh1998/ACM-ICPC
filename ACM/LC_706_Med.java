class MyHashMap {
    List<Integer> keyList;
    List<Integer> valueList;
    
    /** Initialize your data structure here. */
    public MyHashMap() {
        keyList = new ArrayList<> ();
        valueList = new ArrayList<> ();
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        for(int i = 0; i < keyList.size(); i++) {
            if(keyList.get(i) == key) {
                valueList.set(i, value);
                return;
            }
        }
        keyList.add(key);
        valueList.add(value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        for(int i = 0; i < keyList.size(); i++) {
            if(keyList.get(i) == key) 
                return valueList.get(i);
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        for(int i = 0; i < keyList.size(); i++) {
            if(keyList.get(i) == key) {
                keyList.remove(i);
                valueList.remove(i);
                
                return;
            }
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */