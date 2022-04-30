// dfs
// visited = {}
// void dfs(i)
// {
//     if(condition)
//       return;
//     visited[i] = true;
//     for(status j from i)
//     {
//       if(!visited[j])
//         dfs[j];
//     }
// }

// void dfs(TreeNode* root)
// {
//     if(condition)
//       return;
//     for(child in root)
//       df(child);
// }

// void dfs(TreeNode* root)
// {
//     if(condition)
//       return;
//     pre_order_do();
//     dfs(root->left);
//     in_order_do();
//     dfs(root->right);
//     post_order_do();
// }

// dfs iterative
// enum STATUS {NV, V}; (V: visted, NT: not visited)

// struct Node
// {
//   Node(TreeNode* n, STATUS s): node(n), status(s) {}
//   TreeNode* node;
//   STATUS status;
// };

// void dfs(TreeNode* root)
// {
//    Node root_node(root, NT);
//    stack<Node> nstack;
//    nstack.push(root);
//    while(nstack.size())
//    {
//       Node node = nstack.top();
//       nstack.pop();
//       if(!node.node)
//          continue;
//       if(node.status == NV)
//       {
//          node.status = V;
//          Node right_node(node.node->right, NV);
//          Node left_node(left.node->right, NV);
//          nstack.push(right_node);
//          nstack.push(node);         // in order
//          nstack.push(left_node);
//       }
//       else
//          do_something();
//    }
// }
