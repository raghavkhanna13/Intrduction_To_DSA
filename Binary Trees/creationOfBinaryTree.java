import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class creationOfBinaryTree {

    static class Node {
        int data;
        Node left;
        Node right;

        Node(int x) {
            this.data = x;
            this.left = null;
            this.right = null;
        }
    }

    static void levelOrderTraversal(Node root) {
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        q.add(null);

        while (!q.isEmpty()) {
            Node temp = q.peek();
            q.remove();
            
            if (temp == null) {
                System.out.println();
                if (!q.isEmpty()) {
                    q.add(null);
                }
            }
            
            else {
                System.out.print(temp.data + " ");

                if (temp.left != null) {
                    q.add(temp.left);
                }
                if (temp.right != null) {
                    q.add(temp.right);
                }
            }

        }
    }

    static void inorderTraversal(Node root){
        //LNR
        //base case
        if(root == null){
            return;
        }

        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }
    static void preorderTraversal(Node root){
        //NLR
        //base case
        if(root == null){
            return;
        }

        System.out.print(root.data + " ");
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    }
    static void postorderTraversal(Node root){
        //LRN
        //base case
        if(root == null){
            return;
        }

        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.data + " ");
    }

    static Node buildTree(Node root) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the data: ");
        int data;
        data = sc.nextInt();

        root = new Node(data);

        if (data == -1)
            return null;

        System.out.println("Enter data for inserting in left of " + data);
        root.left = buildTree(root.left);
        System.out.println("Enter data for inserting in right of " + data);
        root.right = buildTree(root.right);
        return root;

    }

    static Node buildFromLevelOrder(Node root){
        Queue<Node> q = new LinkedList<>();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the root data: ");
        int data = sc.nextInt();
        root = new Node(data);
        q.add(root);

        while(!q.isEmpty()){
            Node temp = q.peek();
            q.remove();

            System.out.println("Enter the left node for " + temp.data);
            int leftData = sc.nextInt();

            if(leftData != -1){
                temp.left = new Node(leftData);
                q.add(temp.left);
            }

            System.out.println("Enter the right node for " + temp.data);
            int rightData = sc.nextInt();

            if(rightData != -1){
                temp.right = new Node(rightData);
                q.add(temp.right);
            }
        }
        sc.close();
        return root;

    }

    public static void main(String[] args) {

        Node root = null;
        // root = buildTree(root);
        root = buildFromLevelOrder(root);

        System.out.println("Level order traversal: ");
        // level order traversal
        levelOrderTraversal(root);

        // input
        // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

         
        //inorder
        // System.out.println("Inorder: ");
        // inorderTraversal(root);
        // System.out.println();
        // //preorder
        // System.out.println("preorder: ");
        // preorderTraversal(root);
        
        // System.out.println();
        // //postorder
        // System.out.println("postorder: ");
        // postorderTraversal(root);
        // System.out.println();
        
    }
}