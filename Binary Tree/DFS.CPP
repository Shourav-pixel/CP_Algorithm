
class Solution {
public:

//DFS
void callmar(TreeNode* root,vector<int>&ans,int level)
{
    if(root  == NULL)return ;
    if(level == ans.size())
    {
        ans.push_back(root->val);
    }
    callmar(root->right,ans,level+1);
    callmar(root->left,ans,level+1);

    return ;

    
    
}
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
       callmar(root,ans,0);

       return ans;
    }
};