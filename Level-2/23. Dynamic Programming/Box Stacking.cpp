// https://practice.geeksforgeeks.org/problems/box-stacking/1#
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        int k=0;
        vector<vector<int>> box(3*n,vector<int>(3));
        for(int i=0;i<n;i++){
            int l = length[i],w=width[i],h=height[i];
    
            if(l<w){
                box[k]={w,l,h};
            }
            else{
                box[k]={l,w,h};
            }
            k++;
    
    
            if(w<h){
                box[k]={h,w,l};
            }
            else{
                box[k]={w,h,l};
            }
            k++;
    
    
            if(l<h){
                box[k]={h,l,w};
            }
            else{
                box[k]={l,h,w};
            }
            k++;
        }
        sort(box.begin(),box.end(),[&](const auto&a,const auto& b){
            int a1 = a[0]*a[1] , b1=b[0]*b[1];
            return a1 < b1;
        });
        
        vector<int> dp(box.size());
        int omax = 0;
        for(int i=0;i<box.size();i++){
            int mx = 0;
            for(int j=i-1;j>=0;j--){
                if(box[j][0] < box[i][0] && box[j][1] < box[i][1])
                    mx = max(mx,dp[j]);
            }
            dp[i]=mx+box[i][2];
            omax = max(omax,dp[i]);
        }
        return omax;
    }
};