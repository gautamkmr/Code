# Python3 program for Sum-square series using 
# hamiltonian path concept and backtracking 

# Function to check wheter we can add number 
# v with the path in the position pos. 
def issafe(v, graph, path, pos): 
    
    # if there is no edge between v and the 
    # last element of the path formed so far 
    # return false. 
    if (graph[path[pos - 1]][v] == 0): 
        return False
    
    # Otherwise if there is an edge between 
    # v and last element of the path formed so 
    # far, then check all the elements of the 
    # path. If v is already in the path return 
    # false. 
    for i in range(pos): 
        
        if (path[i] == v): 
            return False

    # If none of the previous cases satisfies 
    # then we can add v to the path in the 
    # position pos. Hence return true. 
    return True

# Function to form a path based on the graph. 
def formpath(graph, path, pos): 

    # If all the elements are included in the 
    # path i.e. length of the path is n then 
    # return true i.e. path formed. 
    n = len(graph) - 1
    if (pos == n + 1): 
        return True

    # This loop checks for each element if it 
    # can be fitted as the next element of the 
    # path and recursively finds the next 
    # element of the path. 
    for v in range(1, n + 1): 
        
        if issafe(v, graph, path, pos): 
            path[pos] = v 
            
            # Recurs for next element of the path. 
            if (formpath(graph, path, pos + 1) == True): 
                return True
            
            # If adding v does not give a solution 
            # then remove it from path 
            path[pos] = -1
            
    # if any vertex cannot be added with the 
    # formed path then return false and 
    # backtracks. 
    return False

# Function to find out sum-square series. 
def hampath(n): 
    
    # base case: if n = 1 there is no solution 
    if n == 1: 
        return 'No Solution'

    # Make an array of perfect squares from 1 
    # to (2 * n-1) 
    l = list() 
    
    for i in range(1, int((2 * n-1) ** 0.5) + 1): 
        l.append(i**2) 

    for i in range(0, len(l)):
        print(l[i]) 
    # Form the graph where sum of two adjacent 
    # vertices is a perfect square 
    graph = [[0 for i in range(n + 1)] for j in range(n + 1)] 
    #print(graph)    
    for i in range(1, n + 1): 
        for ele in l: 
            
            if ((ele-i) > 0 and (ele-i) <= n 
                and (2 * i != ele)): 
                graph[i][ele - i] = 1
                graph[ele - i][i] = 1
    for i in range(n+1):
        print(graph[i])
            
    # strating from 1 upto n check for each 
    # element i if any path can be formed 
    # after taking i as the first element. 
    for j in range(1, n + 1): 
        path = [-1 for k in range(n + 1)] 
        path[1] = j 

        # If starting from j we can form any path 
        # then we will return the path 
        if formpath(graph, path, 2) == True: 
            return path[1:] 
            
    # If no path can be formed at all return 
    # no solution. 
    return 'No Solution'
    
# Driver Function 
print(17, '->', hampath(17)) 
print(20, '->', hampath(20)) 
print(25, '->', hampath(25)) 
