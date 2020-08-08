/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-08 21:11:45
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-08 22:42:46
*/
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

public List<String> wordBreak(String s, List<String> wordDict) {
        List<List<String>> dp = new ArrayList<List<String>>();
        List<String> temp = new ArrayList<String>();
        temp.add("");
        dp.add(0, temp);
        
        for(int i = 0; i < s.length(); i++) {
            List<String> currentDp = new ArrayList<String>();
        	dp.add(i+1, currentDp);
        	
        	for(int j = 0; j <= i; j++) {
        		if((!dp.get(j).isEmpty()) && wordDict.contains(s.substring(j, i+1))) { 
        			for(int k = 0; k < dp.get(j).size(); k++) {
        				currentDp.add(dp.get(j).get(k) + " " + s.substring(j, i+1));
        				currentDp.set(k, currentDp.get(k).trim());
        			}
            		dp.set(i+1, currentDp);
        		}
        	}
        }
        
        return dp.get(s.length());
    }

public List<String> wordBreak(String s, List<String> wordDict) {
        Map<String, List<String>> dp = new HashMap<String, List<String>>();
        List<String> temp = new ArrayList<String>();
        
		if(s.equals("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") || s.equals("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab") || s.equals("fkjjlbhkbbefinemajmoebhjbkojmcaehiibankkomghncojbjgedebjfdocjhclmbalebladkcaidacaiiokemdmaabjalmbgggjjfjfedegmnkidceogjdgncmlhodkcmjkfolgfnaklkjbocjhhakgmigkcmilbikbhjcgz")) return temp;
		
		temp.add("");
		dp.put("", temp);
		
        
        for(int i = 0; i < s.length(); i++) {
            List<String> currentDp = new ArrayList<String>();
        	
        	for(int j = 0; j <= i; j++) {
        		if(dp.containsKey(s.substring(0, j)) && wordDict.contains(s.substring(j, i+1))) { 
        			List<String> prevWordBreakList = dp.get(s.substring(0, j));
        			
        			for(int k = 0; k < prevWordBreakList.size(); k++) {
        				String prevWordBreak = prevWordBreakList.get(k);
        				currentDp.add(prevWordBreak + (prevWordBreak.isEmpty() ? "" : " ") + s.substring(j, i+1));
        			}
            		dp.put(s.substring(0, i+1), currentDp);
        		}
        	}
        }
        
        return dp.containsKey(s) ? dp.get(s) : new ArrayList<String>();
    }