class MinHeap:
    def __init__(self):
        self.queue = []

    def push(self, priority, item):
        self.queue.append((priority, item))
        self.queue.sort()  

    def pop(self):
        if self.queue:
            return self.queue.pop(0)  
        else:
            pass

    def is_empty(self):
        return len(self.queue) == 0

def a_star_search(start, graph, n, hValue):
    pq = MinHeap()
    visited = {}
    wValue = {}
    pq.push(hValue[start], start)
    wValue[start] = 0
    
    while not pq.is_empty():
        weight, node = pq.pop()
        if node in visited: 
            continue
        visited[node] = True
        print(node, end=" ")
        if not hValue[node]:
            break
        
        for adjNode, adjWidth in graph[node]:
            if adjNode not in wValue:
                wValue[adjNode] = float('inf')          
            if adjNode not in visited:
                if wValue[adjNode] > wValue[node] + adjWidth:
                    wValue[adjNode] = wValue[node] + adjWidth
                pq.push(hValue[adjNode]+wValue[adjNode], adjNode)
                
    print()

if __name__ == "__main__":
    n, m = map(int, input().split())
    graph = {}
    hValue = {}
    
    for _ in range(m):
        a, b, c = input().split()
        if a in graph:
            graph[a].append((b, int(c)))
        else:
            graph[a] = [(b, int(c))]
            
        if b in graph:
            graph[b].append((a, int(c)))
        else:
            graph[b] = [(a, int(c))]
    
    for _ in range(n):
        a, w = input().split()
        hValue[a] = int(w);
    
    start = input()  
    a_star_search(start, graph, n, hValue)