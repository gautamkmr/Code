#include <iostream>
#include <string>
#include <vector>

/*

Tax Basis

It's tax season! Given a set of transactions, find out the cost basis and capital gain / loss for each sell. The cost basis for a sold equity is the price at which the equity being sold was bought at.

You are provided with a sorted list of transactions, each of which contain the following information:

	(date: int, symbol: string, side: string (buy/sell}, quantity: int, price: float).

For each sell, output the following information:

	(symbol: string, date_bought: int, date_sold: int, price_bought_at: float, price_sold_at, quantity: int, capital_gain: float)


Example:

Input:
[
    {"symbol": "FB", "date": 1, "side": "buy", "quantity": 1, "price": 200.00},
    {"symbol": "AAPL", "date": 3, "side": "buy", "quantity": 2, "price": 100.00},
    {"symbol": "FB", "date": 4, "side": "sell", "quantity": 1, "price": 150.00},
    {"symbol": "AAPL", "date": 6, "side": "buy", "quantity": 1, "price": 150.00},
    {"symbol": "AAPL", "date": 7, "side": "sell", "quantity": 1, "price": 200.00},
    {"symbol": "AAPL", "date": 8, "side": "buy", "quantity": 4, "price": 210.00},
    {"symbol": "AAPL", "date": 11, "side": "sell", "quantity": 4, "price": 220.00}
]


Output:

[
    {"symbol": "FB", "date_bought": 1, "date_sold": 4, "price_bought_at": 200.00, "price_sold_at": 150.00, "quantity": 1, "capital_gain": -50.00},
    {"symbol": "AAPL", "date_bought": 3, "date_sold": 7, "price_bought_at": 100.00, "price_sold_at": 200.00, "quantity": 1, "capital_gain": 100.00},
    {"symbol": "AAPL", "date_bought": 3, "date_sold": 11, "price_bought_at": 100.00, "price_sold_at": 220.00, "quantity": 1, "capital_gain": 120.00},
    {"symbol": "AAPL", "date_bought": 6, "date_sold": 11, "price_bought_at": 150.00, "price_sold_at": 220.00, "quantity": 1, "capital_gain": 70.00},
    {"symbol": "AAPL", "date_bought": 8, "date_sold": 11, "price_bought_at": 210.00, "price_sold_at": 220.00, "quantity": 2, "capital_gain": 20.00}
]


*/



void  make_obj(int totalcg, unordered_map<string, string> sellobj, unordered_map<string, string> buyobj, int quantity)
{
    cout<<"symbol:"<<sellobj["symbol"]<<", data_bought:"<<buyobj.date<<", date_sold:"<< sellobj.date<<", price_bought_at:"<< buyobj.price<<", price_sold_at:"<<sellobj.price<<", quantity:"<<quantity<<"capital_gain:"<<totalcg<<"\n";
}


vector<unordered_map<string, string> > process(vector<unordered_map<string, string> > in)
{
    unordered_map<string, vector<unordered_map<string, string> > mp;   // "FB"->[{"symbol": "FB", "date": 1, "side": "buy", "quantity": 1, "price": 200.00} ]
    
    vector<unordered_map<string, string> > ans;
    
    for(int i=0; i<in.size(); i++)
    {
        if(in[i].side == "buy")
        {
            if(mp.find(in[i].symbol) == mp.end())
              mp[in[i].symbol] = in[i];
            else
              mp[in[i].symbol].push_bacj(in[i]);
        }
        else
        {
            int c = in[i].quantity;
            vector<unordered_map<string, string> > buy = mp[in[i].symbol];
            int totalcg = 0;
            while(true)
            {
                 unordered_map<string, string> buyobj = buy.front();
                 if(buyobj.quantity == c)
                 {
                     totalcg = (in[i].price - buyobj.price)*c;
                     unordered_map<string, string> obj4ans = make_obj(totalcg, in[i], buyobj, c);
                     ans.push_back(obj4ans);
                     buy.pop_front();
                     break;
                 }
                 else if (buyobj.quantity > c)
                 {
                     totalcg = (in[i].price - buyobj.price)*c;
                     unordered_map<string, string> obj4ans = make_obj(totalcg, in[i], buyobj, c);
                     ans.push_back(obj4ans);      
                     buy.front().quantity = buy.front().quantity - c;
                     break;
                 }
                 else //buyobj.quantity < c
                 {
                     totalcg = (in[i].price - buyobj.price)*buyobj.quantity;
                     unordered_map<string, string> obj4ans = make_obj(totalcg, in[i], buyobj, buyobj.quantity);
                     ans.push_back(obj4ans); 
                     c = c -  buyobj.quantity;
                     buy.pop_front();
                 }
            }
        }
    }
    return ans; 
}

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

