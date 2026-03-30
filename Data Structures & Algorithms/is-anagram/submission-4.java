class Solution {
    public boolean isAnagram(String s, String t) {
        // using array count to count occurence of characters in s and t
        // time: O(n+m), space: O(1), n: length of s and t: length of t
        // if (s.length() != t.length()) {
        //     return false;
        // }
        // int[] count = new int[26];
        // for (int i = 0; i < s.length(); i++) {
        //     count[s.charAt(i) - 'a']++;
        //     count[t.charAt(i) - 'a']--;
        // }

        // for (int value: count) {
        //     if (value != 0) {
        //         return false;
        //     }
        // }
        // return true;


        // hash table
        if (s.length() != t.length()) {
            return false;
        }
        HashMap<Character, Integer> countS = new HashMap<>();
        HashMap<Character, Integer> countT = new HashMap<>();
        for (int i = 0; i< s.length(); i++) {
            countS.put(s.charAt(i), countS.getOrDefault(s.charAt(i), 0) + 1);
            countT.put(t.charAt(i), countT.getOrDefault(t.charAt(i), 0) + 1);
        }
        return countS.equals(countT);
    }
}
