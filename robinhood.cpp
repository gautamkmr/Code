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

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class input
{
  public:
    string symbol;
    int date;
    string side;
    int quantity;
    float price;
};

input getInputObject(string symbol, int date, string side, int quantity, float price) 
{
    input obj;
    obj.symbol = symbol;
    obj.date = date;
    obj.side = side;
    obj.quantity = quantity;
    obj.price = price;
    return obj;
}

class output
{
 public:
    string symbol;
    int date_bought;
    int date_sold;
    float price_bought_at;
    float price_sold_at;
    int quantity;
    float capital_gain;
};

output getOutputObject(string symbol, int date_bought, int date_sold, float price_bought_at, float price_sold_at, int quantity, float capital_gain)
{
    output obj;
    obj.symbol = symbol;
    obj.date_bought = date_bought;
    obj.date_sold = date_sold;
    obj.price_bought_at = price_bought_at;
    obj.price_sold_at = price_sold_at;
    obj.quantity = quantity;
    obj.capital_gain = capital_gain;
    return obj;
}
    
void printVector(vector<output> ans)
{
    for(int i=0; i<ans.size(); i++)
    {
        cout<<"symbol:"<<ans[i].symbol<<", date_bought:"<<ans[i].date_bought<<", date_sold:"<<ans[i].date_sold<<", price_bought_at:"<<ans[i].price_bought_at<<", price_sold_at:"<<ans[i].price_sold_at<<", quantity:"<<ans[i].quantity<<", capital_gain:"<<ans[i].capital_gain<<"\n";
    }
}


 int main() {
     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<input> in;

    in.push_back(getInputObject("FB", 1, "buy", 1, 200.00));
    in.push_back(getInputObject("AAPL", 3, "buy", 2, 100.00));
    in.push_back(getInputObject("FB", 4, "sell", 1, 150.00));
    in.push_back(getInputObject("AAPL", 6, "buy", 1, 150.00));
    in.push_back(getInputObject("AAPL", 7, "sell", 1, 200.00));
    in.push_back(getInputObject("AAPL", 8, "buy", 4, 210.00));
    in.push_back(getInputObject("AAPL", 11, "sell", 4, 220.00));

    unordered_map<string, queue<input> > mp;   
    
    vector<output> ans;

    for(int i=0; i<in.size(); i++)
    {
        if(in[i].side == "buy")
        {
              mp[in[i].symbol].push(in[i]);  
        }
        else 
        {
           float capital_gain = 0; 
           while(true)
           { 
             input buyobj = mp[in[i].symbol].front();
             if(in[i].quantity == buyobj.quantity)
             {
               capital_gain = in[i].quantity*(in[i].price - buyobj.price); 
               ans.push_back(getOutputObject(in[i].symbol, buyobj.date, in[i].date, buyobj.price, in[i].price, in[i].quantity, capital_gain));
               mp[in[i].symbol].pop();
               break;
             }
             else if(in[i].quantity < buyobj.quantity)
             {
                capital_gain = in[i].quantity*(in[i].price - buyobj.price);
                ans.push_back(getOutputObject(in[i].symbol, buyobj.date, in[i].date, buyobj.price, in[i].price, in[i].quantity, capital_gain));
                mp[in[i].symbol].front().quantity -= in[i].quantity;
                break;
             }
             else  
             {
                capital_gain =   buyobj.quantity *(in[i].price - buyobj.price);
                ans.push_back(getOutputObject(in[i].symbol, buyobj.date, in[i].date, buyobj.price, in[i].price, buyobj.quantity, capital_gain));
                in[i].quantity -= buyobj.quantity;
                mp[in[i].symbol].pop(); 
             }
           }
        }
     }
    printVector(ans);
    return 0;
 }





// void  make_obj(int totalcg, unordered_map<string, string> sellobj, unordered_map<string, string> buyobj, int quantity)
// {
//     cout<<"symbol:"<<sellobj["symbol"]<<", data_bought:"<<buyobj.date<<", date_sold:"<< sellobj.date<<", price_bought_at:"<< buyobj.price<<", price_sold_at:"<<sellobj.price<<", quantity:"<<quantity<<"capital_gain:"<<totalcg<<"\n";
// }


// vector<unordered_map<string, string> > process(vector<unordered_map<string, string> > in)
// {
//     unordered_map<string, vector<unordered_map<string, string> > mp;   // "FB"->[{"symbol": "FB", "date": 1, "side": "buy", "quantity": 1, "price": 200.00} ]
    
//     vector<unordered_map<string, string> > ans;
    
//     for(int i=0; i<in.size(); i++)
//     {
//         if(in[i].side == "buy")
//         {
//             if(mp.find(in[i].symbol) == mp.end())
//               mp[in[i].symbol] = in[i];
//             else
//               mp[in[i].symbol].push_bacj(in[i]);
//         }
//         else
//         {
//             int c = in[i].quantity;
//             vector<unordered_map<string, string> > buy = mp[in[i].symbol];
//             int totalcg = 0;
//             while(true)
//             {
//                  unordered_map<string, string> buyobj = buy.front();
//                  if(buyobj.quantity == c)
//                  {
//                      totalcg = (in[i].price - buyobj.price)*c;
//                      unordered_map<string, string> obj4ans = make_obj(totalcg, in[i], buyobj, c);
//                      ans.push_back(obj4ans);
//                      buy.pop_front();
//                      break;
//                  }
//                  else if (buyobj.quantity > c)
//                  {
//                      totalcg = (in[i].price - buyobj.price)*c;
//                      unordered_map<string, string> obj4ans = make_obj(totalcg, in[i], buyobj, c);
//                      ans.push_back(obj4ans);      
//                      buy.front().quantity = buy.front().quantity - c;
//                      break;
//                  }
//                  else //buyobj.quantity < c
//                  {
//                      totalcg = (in[i].price - buyobj.price)*buyobj.quantity;
//                      unordered_map<string, string> obj4ans = make_obj(totalcg, in[i], buyobj, buyobj.quantity);
//                      ans.push_back(obj4ans); 
//                      c = c -  buyobj.quantity;
//                      buy.pop_front();
//                  }
//             }
//         }
//     }
//     return ans; 
// }


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     return 0;
// }

