'''

* Program: [pratica5.py]

* Author: [Gabriel Dias Barros]

* Date: [03/04/2024]

*License: [GNU General Public License]


'''
import sys

def dijkstra(graph, s, t):
    # Número de vértices no grafo
    num_vertices = len(graph)
    
    # Inicializa o vetor de distâncias com infinito para todos os vértices, exceto o vértice de origem
    dist = [float('inf')] * num_vertices
    dist[s] = 0
    
    # Inicializa o vetor de visitados como falso para todos os vértices
    visited = [False] * num_vertices
    
    # Loop para encontrar o menor caminho
    for _ in range(num_vertices):
        # Encontra o vértice não visitado mais próximo
        u = min_distance(dist, visited)
        visited[u] = True
        
        # Atualiza as distâncias dos vértices adjacentes ao vértice atual
        for v in range(num_vertices):
            if not visited[v] and graph[u][v] != 0 and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]
    
    # Retorna a distância mínima até o destino
    return dist[t]

def min_distance(dist, visited):
    min_dist = float('inf')
    min_index = -1
    for v in range(len(dist)):
        if dist[v] < min_dist and not visited[v]:
            min_dist = dist[v]
            min_index = v
    return min_index

# Exemplo de uso:
graph = [
    [0, 4, 0, 0, 0, 0, 0, 8, 0],
    [4, 0, 8, 0, 0, 0, 0, 11, 0],
    [0, 8, 0, 7, 0, 4, 0, 0, 2],
    [0, 0, 7, 0, 9, 14, 0, 0, 0],
    [0, 0, 0, 9, 0, 10, 0, 0, 0],
    [0, 0, 4, 14, 10, 0, 2, 0, 0],
    [0, 0, 0, 0, 0, 2, 0, 1, 6],
    [8, 11, 0, 0, 0, 0, 1, 0, 7],
    [0, 0, 2, 0, 0, 0, 6, 7, 0]
]

source = 0  # Nó de origem
target = 4  # Nó de destino
print("A menor distância entre", source, "e", target, "é:", dijkstra(graph, source, target))
