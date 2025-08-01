/**
 * @file 1791-find-center-of-star-graph.cpp
 * @author Perry Huang
 * @date 2024-04-11
 * 1791. Find Center of Star Graph
 * There is an undirected star graph consisting of n nodes labeled from 1 to n.
 * A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with
 * every other node. You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is
 * an edge between the nodes ui and vi. Return the center of the given star graph.
 */

#include <vector>

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
};
