#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>   
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <time.h>     


using namespace std;


class CompareDist
{
public:
    bool operator()(pair<double, int> n1,pair<double, int> n2) 
    {
        return n1.first>n2.first;
    }
};

struct point
{
	int x, y;
	point()
	{

	}
	point(int a, int b)
	{
		x = a;
		y = b;
	}

	bool operator==(const point &p)
	{
		return x==p.x && y==p.y;
	}
};


vector<point>  getCentroid(unordered_map<int, vector<point> > &mp)
{
    int k = mp.size();
    vector<point> centroids;

    for(auto &it: mp)
    {
    	int xsum=0, ysum=0;
    	for(int j=0; j<it.second.size(); j++)
    	{ 
    		xsum += it.second[j].x;
    		ysum += it.second[j].y;
    	}
    	point center;
    	center.x = xsum/it.second.size();
    	center.y = ysum/it.second.size();
        centroids.push_back(center);       
    }
    return centroids;    
}

double getDistance(point &A, point &B)
{
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

/*
   Get the sum of distance from respective centroids
*/
double getAccumulatedDistancesFromCentroids(vector<point> &centroids, unordered_map<int, vector<point> > &mp)
{
	double sum = 0;
    for(int i=0; i<centroids.size(); i++)
    {
    	for(int j=0; j<mp[i].size(); j++)
    		sum += getDistance(centroids[i], mp[i][j]);
    }
    return sum;
}

void printPoint(vector<point> &points)
{
	for(int i=0; i<points.size(); i++)
	{
		cout<<"("<<points[i].x<<","<<points[i].y<<") ";
	}
	cout<<"\n\n";
}

void printPointsFromMap(unordered_map<int, vector<point> > &mp)
{
	for(int i=0; i<mp.size(); i++)
	{
		cout<<i<<": Points: ";
		for(int j=0; j<mp[i].size(); j++)
		{
            cout<<"("<<mp[i][j].x<<","<<mp[i][j].y<<") ";
		} 
		cout<<"\n";
	}
	cout<<"\n";

}

void printPointAndCentroid(vector<point> &centroids, unordered_map<int, vector<point> > &mp)
{
	for(int i=0; i<centroids.size(); i++)
	{
		cout<<"Points "<<mp[i].size()<<": ";
		for(int j=0; j<mp[i].size(); j++)
		{
            cout<<"("<<mp[i][j].x<<","<<mp[i][j].y<<") ";
		} 
		cout<<"centroid: ("<<centroids[i].x<<","<<centroids[i].y<<")\n";
	}
	cout<<"\n";	
}

bool isExist(vector<point> &visited, point &p)
{
   for(int i=0; i<visited.size(); i++)
   {
   	  if(visited[i]==p) // since we have implement == operator we should be good.
   	  	return true;
   }
   return false;
}

double kMeansVariation(vector<point> points, int k)
{
	int n = points.size();
	const double threshold = 0.001;

	if(!k || !n || n < k)
		return 0;

	unordered_map<int, vector<point> > mp;

	for(int i=0; i<n; i++) 
	{
		mp[ i % k ].push_back(points[i]);
	}

    double ans = 0.0;
    

    // infinite loop begins here
    int c = 0;
    while(true)
    { 	 
        //printPointsFromMap(mp);
        cout<<"******** iteration "<<c++<<" ********\n";
		vector<point> centroids = getCentroid(mp);
   		printPointAndCentroid(centroids, mp);

		double new_ans = getAccumulatedDistancesFromCentroids(centroids, mp);
    	if( abs(ans - new_ans) < threshold)
    	{
    		return ans;
    	}

    	ans = new_ans;
    	unordered_map<int, vector<point> > mp_copy;

        /* Ideally it should have been a map but then your need to implement
           a hash function for 2d point which is a bit non-trivial for the scope
           of this program, so we will just do a brute force */ 
        vector<point> visited;
	    for(int i=0; i<n; i++)
	    {
	        priority_queue<pair<double,int>, vector<pair<double,int> >,CompareDist> q;
	    	for (int j = 0; j < k; ++j)
	    	{
	    		double dist = getDistance(points[i], centroids[j]);
	            q.push(make_pair(dist, j));
	    	}
	 
	        while(!q.empty())
	        {
	           pair<double, int> pt = q.top(); q.pop();
	           /* Either current bucket is full or this point has been 
	              already assigned to a bucket*/
	           if((mp_copy[pt.second].size()==mp[pt.second].size())|| isExist(visited, points[i]))
	           	  continue;
	           else
	           {
	           	  mp_copy[pt.second].push_back(points[i]);
	           	  visited.push_back(points[i]);
	           }	
	       }
	    }
	    mp = mp_copy;
	}
    return INT_MAX;
}

int main()
{
   //kMeansVariation()
	int n = 1000; //generate n points with random values
	int k = 20; //classify them in k cluster
	int max = 100; // generate points in [0, 0] to [max, max] grid

    /* initialize random seed: */
    srand (time(NULL));	

    vector<point> points;
    while(n)
    {
    	point p;
        p.x = rand() % max;
        p.y = rand() % max;
        if(isExist(points, p))
        	continue;
        points.push_back(p);
        n--;
    }
    printPoint(points);
    double dist = kMeansVariation(points, k);
    cout<<"Sum of distances from points to their centroid "<<dist<<"\n";
	return 0;
}