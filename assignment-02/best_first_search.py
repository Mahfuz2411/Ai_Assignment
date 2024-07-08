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

def best_first_search(start, graph, n, hValue):
    pq = MinHeap()
    visited = {}
    pq.push(hValue[start], start)
    
    while not pq.is_empty():
        weight, node = pq.pop()
        if node in visited: 
            continue
        visited[node] = True
        print(node, end=" ")
        if not weight:
            break
        
        for adjNode in graph[node]:
            if adjNode not in visited:
                pq.push(hValue[adjNode], adjNode)
    print()

if __name__ == "__main__":
    n, m = map(int, input().split())
    graph = {}
    hValue = {}
    
    for _ in range(m):
        a, b = input().split()
        if a in graph:
            graph[a].append(b)
        else:
            graph[a] = [b]
            
        if b in graph:
            graph[b].append(a)
        else:
            graph[b] = [a]
    
    for _ in range(n):
        a, w = input().split()
        hValue[a] = int(w);
    
    start = input()  
    best_first_search(start, graph, n, hValue)