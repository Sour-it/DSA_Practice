Carpet into Box
(Greedy Solution)

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        
        if(C>D)
            swap(C,D);
            
        if(A>B)
            swap(A,B);
            
        int res = 0;
        
        while(B>D){
            B/=2;
            res++;
            if(A>B)
                swap(A,B);
        }
        
        while(A>C){
            A/=2;
            res++;
        }
        
        return res;
    }
};