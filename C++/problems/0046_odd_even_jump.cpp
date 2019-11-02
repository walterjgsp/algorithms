// Problem Statement

// You are given an integer array A.  From some starting index, you can make a
// series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are called odd
// numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even numbered jumps.
//
// You may from index i jump forward to index j (with i < j) in the following way:
//
// *During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j
//   such that A[i] <= A[j] and A[j] is the smallest possible value.
//   If there are multiple such indexes j, you can only jump to the smallest such index j.
// *During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j
//   such that A[i] >= A[j] and A[j] is the largest possible value.
//   If there are multiple such indexes j, you can only jump to the smallest such index j.
// *(It may be the case that for some index i, there are no legal jumps.)
//
// A starting index is good if, starting from that index, you can reach the end of
// the array (index A.length - 1) by jumping some number of times (possibly 0 or more than once.)
//
// Return the number of good starting indexes.

class Solution {
private:
    class BinaryTree{
    private:
        struct TreeNode{
            int val,index;
            TreeNode *left, *right;
            TreeNode(int x,int i){
                val = x;
                index = i;
                left = NULL;
                right = NULL;
            }
        };
        TreeNode *root;

    public:
        BinaryTree(){
            root = NULL;
        }

        void insert(int val, int index){
            if(!root){
                root = new TreeNode(val,index);
                return;
            }

            bool inserted = false;

            TreeNode *it = root;
            while(!inserted){
                if(val == it->val){
                    it-> index = index;
                    inserted = true;
                }else if(val < it->val){
                    if(it->left) it = it->left;
                    else{
                        it->left = new TreeNode(val,index);
                        inserted = true;
                    }
                }else{
                    if(it->right) it = it->right;
                    else{
                        it->right = new TreeNode(val,index);
                        inserted = true;
                    }
                }
            }
        }

        int querySmallerBigger(int val){
            if(!root)
                return -1;

            int actual_val = INT_MAX,index=-1;
            TreeNode *it=root;
            while(it){
                if(val <= it->val){
                    if(actual_val>it->val){
                        actual_val = it->val;
                        index = it->index;
                    }

                    it = it->left;
                }else{
                    it = it->right;
                }
            }

            return index;
        }

        int queryBiggerSmaller(int val){
            if(!root)
                return -1;

            int actual_val = INT_MIN,index=-1;
            TreeNode *it = root;
            while(it){
                if(val >= it->val){
                    if(actual_val<it->val){
                        actual_val = it->val;
                        index = it->index;
                    }

                    it = it->right;
                }else{
                    it = it->left;
                }
            }

            return index;
        }
    };

public:
    int oddEvenJumps(vector<int>& A) {
        if(A.empty())
            return 0;

        BinaryTree bts;
        vector<int> odd (A.size()), even(A.size());
        int result = 0;

        odd[A.size()-1] = 1;
        even[A.size()-1] = 1;

        bts.insert(A[A.size()-1],A.size()-1);

        for(int i = A.size()-2;i>=0;i--){
            int oddjump = bts.querySmallerBigger(A[i]);
            int evenjump = bts.queryBiggerSmaller(A[i]);

            if(oddjump == -1)
                odd[i] = 0;
            else
                odd[i] = even[oddjump];

            if(evenjump == -1)
                even[i] = 0;
            else
                even[i] = odd[evenjump];

            bts.insert(A[i],i);
        }

        for(auto val : odd){
            result+=val;
        }

        return result;
    }
};

int main(){
  vector<int> vec = {2,3,1,1,4};
  Solution sol;
  cout<< sol.oddEvenJumps(vec)<<endl;
}
