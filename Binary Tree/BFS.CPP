class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int branch = 1;
        int sum = INT_MIN;
        int lvl  = 1;
        while(!q.empty())
        {
            int n = q.size();
            int currsum = 0;
             
            for(int i=0;i<n;i++)
            {
                currsum+=q.front()->val;
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                }
                 if(q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }

            if(currsum>sum)
            {
                sum = currsum;
                branch = lvl;

            }
            lvl++;
        }
    return branch;
    }
};