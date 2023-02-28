class Solution {
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> result = new LinkedList<>();
        traverse(root, new HashMap<>(), result);
        return result;
    }
    
    private String traverse(TreeNode node, Map<String, Integer> frequencyMap, List<TreeNode> result) {
        if (node == null) {
            return "";
        }
        String key = ("(" + traverse(node.left, frequencyMap, result) + ")" + node.val + 
                      "(" + traverse(node.right, frequencyMap, result) + ")");
        frequencyMap.put(key, frequencyMap.getOrDefault(key, 0) + 1);
        if (frequencyMap.get(key) == 2) {
            result.add(node);
        }
        return key;
    }
}