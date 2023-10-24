// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1

int countRev (string s)
{
    stack<char> stk;
    int count = 0;
    for(auto x : s){
        if (x == '{'){
            stk.push(x);
        } else {
            if(stk.empty()){
                count++;
                stk.push('{');
            } else if(stk.top() != '{'){
                count++;
                stk.pop();
            } else {
                stk.pop();
            }
        }
    }
    
    if(stk.size()%2 == 0){
        count += stk.size()/2;
        return count;
    } else {
        return -1;
    }    
}
