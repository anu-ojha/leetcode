class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        Map<Character, Integer> map = new HashMap<>();
        int ans = 0;
        int counter = 0;
        for (int left = 0, right = 0; right < s.length(); right++) {
            // count > 0 means repeating character
            char cRight = s.charAt(right);
            map.put(cRight, map.getOrDefault(cRight, 0) + 1);
            if (map.get(cRight) > 1) {
                counter++;
            }

            while (counter > 0) {
                char cLeft = s.charAt(left);
                map.put(cLeft, map.get(cLeft) - 1);
                // map.get(cLeft) == 1 means the cLeft is the duplicated character, 
                // and we have remove it, so after left++, it will be distinct.
                if (map.get(cLeft) == 1) {
                    counter--;
                }
                left++;
            }
            ans = Math.max(ans, right - left + 1);
        }

        return ans;
    }
}