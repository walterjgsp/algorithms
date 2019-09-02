// Problem Statement

// A transaction is possibly invalid if:

// * the amount exceeds $1000, or;
// * if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
// Each transaction string transactions[i] consists of comma separated values representing the name, time (in minutes), 
// amount, and city of the transaction.

// Given a list of transactions, return a list of transactions that are possibly invalid.  You may return the answer in any order.

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    struct Transaction{
        string name,city;
        int time,amount,pos;
        Transaction(string t_name, string t_city, int t_time, int t_amount, int t_pos){
            name = t_name, city = t_city, time = t_time, amount = t_amount, pos = t_pos;
        }

        bool operator <(const Transaction & t2) const{
            return time < t2.time;
        }
    };

    Transaction createTransaction(string transaction, int pos){
        stringstream ss(transaction);
        string temp;
        vector<string> splited;

        while(getline(ss,temp,',')){
            splited.push_back(temp);
        }

        return Transaction(splited[0],splited[3],stoi(splited[1]),stoi(splited[2]),pos);
    }

public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Transaction> parsed;
        unordered_set<int> invalids_positions;
        unordered_set<string> transactions_invalid;

        for(int i=0;i<transactions.size();i++){
            auto parsedObj = createTransaction(transactions[i],i);
            parsed.push_back(parsedObj); 
            if(parsedObj.amount>1000){
                invalids_positions.insert(i);
            }
        }

        sort(parsed.begin(),parsed.end());
        unordered_map<string,vector<Transaction>> memo;

        for(auto trans : parsed){
            if(memo.find(trans.name)!=memo.end() && !memo[trans.name].empty()){
                auto name_regs = memo[trans.name];
                int index = name_regs.size()-1;
                while(index >=0 && trans.time - name_regs[index].time <= 60){
                    if(trans.city != name_regs[index].city){
                        invalids_positions.insert(name_regs[index].pos);
                        invalids_positions.insert(trans.pos);
                    }
                    index--;
                }
            }
            memo[trans.name].push_back(trans);
        }

        for(auto pos : invalids_positions){
            transactions_invalid.insert(transactions[pos]);
        }

        vector<string> result(transactions_invalid.begin(),transactions_invalid.end());
        return result;
    }
};

void printVec(const vector<string> &vec){
    for(auto val : vec){
        cout<<val<<endl;
    }
}

int main(){
    vector<string> transactions = {"alice,20,800,mtv","alice,50,200,mtv","alice,80,200,mtSv","alice,82,200,mtSv"};
    Solution sol;
    printVec(sol.invalidTransactions(transactions));

    return 0;
}