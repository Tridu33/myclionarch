class Solution{
public:
    bool isValidSerialization(string preorder){
        int n =  preorder.size();
        int i = 0;
        int slots = 1;
        for(;i<n;){
            if(slots == 0){
                return false;
            }
            if(preorder[i] == ','){i++;
            }else if(preorder[i] == '#'){
                slots--;
                i++;
            }else{
                while(i<n && preorder[i] != ','){i++;}
                slots++;
            }
        }
        return slots == 0;
    }
};