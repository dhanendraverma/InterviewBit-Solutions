
bool comp(int a, int b){
    string x = to_string(a); //converting int to string
    string y = to_string(b);
    return (x+y)>(y+x); //concatenate them in both ways and compare them r
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> temp = A; //copying it into temp as given vector is constant
    sort(temp.begin(), temp.end(), comp); //sorting based on comp function

    string ans = "";
    for(int i = 0; i<temp.size(); i++)
        ans += to_string(temp[i]);  //once sorted just append one after another


    if(ans[0] == '0') //return only one 0 when ans is zero
        return "0";

    return ans;
}
