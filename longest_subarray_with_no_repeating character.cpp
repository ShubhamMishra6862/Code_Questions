bool check(string str,int l,int r){
         for(int i=l;i<r;i++){
             if(str[i]==str[r])
             {
                 return true;
             }
        }
         return false;
    }
    int lengthOfLongestSubstring(string str) {
        int window=0;
        int l=0,r=1;
        if(str.length()==1)
        {
            return 1;
        }
        while(l<str.length() && r<str.length()){
             if(check(str,l,r)){
                 l++;
             }
             else{
                window=max(window,r-l+1);
                r++;
             }
        }
        return window;
    }
