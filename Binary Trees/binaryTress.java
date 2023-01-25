import java.util.*;

public class binaryTress {

    static class TreeNode {
        int data;
        TreeNode left;
        TreeNode right;

        TreeNode(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    static void preorder(TreeNode root) {
        if (root == null)
            return;

        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    static void inorder(TreeNode root) {
        if (root == null)
            return;

        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    static void postorder(TreeNode root) {
        if (root == null)
            return;

        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }

    //print level wise 
    static List<List<Integer>> levelOrder(TreeNode root){
        Queue <TreeNode> q = new LinkedList<>();
        List<List<Integer>> result = new LinkedList<List<Integer>>();

        if(root == null)
            return result;

        q.offer(root);
        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> temp = new LinkedList<>();
            for(int i = 0; i < size; i++){
                if(q.peek().left != null)
                    q.offer(q.peek().left);
                if(q.peek().right != null)
                    q.offer(q.peek().right);
                
                temp.add(q.poll().data);
            }

            result.add(temp);
        }

        return result;
    }

    static List<Integer> iterativePreOrder(TreeNode root){
        List<Integer> result = new ArrayList<>();
        if(root == null)
            return result;
        
        Stack <TreeNode> st = new Stack<>();
        st.push(root);
        while(!st.empty()){
            root = st.pop();
            result.add(root.data);

            if(root.right != null)
                st.push(root.right);
            if(root.left != null)
                st.push(root.left);
        }

        return result;
    }

    static List<Integer> iterativeInorder(TreeNode root){
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();
        TreeNode node = root;
        while(true){
            if(node != null){
                st.push(node);
                node = node.left;
            }
            else{
                if(st.isEmpty()){
                    break;
                }
                node = st.pop();
                result.add(node.data);
                node = node.right;

            }
        }

        return result;
    }

    static List<Integer> iterativePostOrder(TreeNode root){
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> st1 = new Stack<>();
        Stack<TreeNode> st2 = new Stack<>();

        st1.push(root);
        while(!st1.isEmpty()){
            root = st1.pop();
            st2.push(root);
            if(root.left != null){
                st1.push(root.left);
            }
            if(root.right != null){
                st1.push(root.right);
            }
        }

        while(!st2.isEmpty()){
            result.add(st2.pop().data);
        }

        return result;
    }


    static void display(List<List<Integer>> ans){
        for(int i = 0; i < ans.size(); i++){
            System.out.println(ans.get(i));
        }
    }

    static void display1(List<Integer> ans){
        for(int i = 0; i < ans.size(); i++){
            System.out.print(ans.get(i)+" ");
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        // preorder(root);
        // System.out.println();
        // inorder(root);
        // System.out.println();
        // postorder(root);
        // System.out.println();

        // display(levelOrder(root));
        display1(iterativePostOrder(root));
    }
}
