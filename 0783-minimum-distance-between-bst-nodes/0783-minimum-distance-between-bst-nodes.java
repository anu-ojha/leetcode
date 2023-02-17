class Solution {
  Integer minDiff;
  Integer prev;
  public int minDiffInBST(TreeNode root) {
    minDiff = Integer.MAX_VALUE;
    prev = null;
    helper(root);
    return minDiff;
  }
  
  private void helper(TreeNode root) {
    if (root == null) {
      return;
    }
    helper(root.left);
    if (prev != null) {
      minDiff = Math.min(minDiff, root.val - prev);
    }
    prev = root.val;
    helper(root.right);
  }
}
