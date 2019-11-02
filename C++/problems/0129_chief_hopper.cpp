// Problem Statement
// Chief's bot is playing an old DOS based game. 
// There is a row of buildings of different heights arranged at each index along a number line. 
// The bot starts at building 0 and at a height of 0. You must determine the minimum energy his bot needs at the 
// start so that he can jump to the top of each building without his energy going below zero.

// Units of height relate directly to units of energy. The bot's energy level is calculated as follows:

// If the bot's botEnergy is less than the height of the building, his newEnergy = botEnergy - (height - botEnergy)
// If the bot's botEnergy is greater than the height of the building, his newEnergy = botEnergy + (botEnergy - height)

// Return an integer that represents the minimum starting botEnergy that will allow completion of the course. 
#include<bits/stdc++.h>

using namespace std;

class Solution{
private:
    bool canFinish(const vector<int> &vec, long long int energy){
        for(auto val : vec){
            if(energy<val){
                energy = energy - (val-energy);
            }else{
                energy = (energy + (energy - val))%100000007;
            }

            if(energy<0){
                return false;
            }
        }

        return true;
    }
    
public:
    int chiefHopper(vector<int> arr){
        int start = 0, end = 0;
        for(auto val : arr){
            end=max(end,val);
        }
        int result = INT_MAX;

        while(start<=end){
            int mid = start+(end-start)/2;

            cout<<"mid: "<<mid<<endl;
            if(canFinish(arr,mid)){
                cout<<"canFinish"<<endl;
                end = mid-1;
                result = min(result,mid);
            }else{
                start = mid+1;
            }
        }

        return result;
    }
};

vector<int> test1(){
    return {4,4};
}

vector<int> test2(){
    return {4};
}

vector<int> test3(){
    return {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
}

vector<int> test4(){
    return {
        1401,2019,1748,3785,3236,3177,3443,3772,2138,1049,353,908,
        310,2388,1322,88,2160,2783,435,2248,1471,706,2468,2319,3156,
        3506,2794,1999,1983,2519,2597,3735,537,344,3519,3772,3872,2961,
        3895,2010,10,247,3269,671,2986,942,758,1146,77,1545,3745,1547,2250,
        2565,217,1406,2070,3010,3404,404,1528,2352,138,2065,3047,3656,2188,
        2919,2616,2083,1280,2977,2681,548,4000,1667,1489,1109,3164,1565,
        2653,3260,3463,903,1824,3679,2308,245,2689,2063,648,568,766,785,
        2984,3812,440,1172,2730
    };
}

int main(){
    vector<int> heights = test4();
    Solution sol;
    cout<<sol.chiefHopper(heights)<<endl;
    return 0;
}