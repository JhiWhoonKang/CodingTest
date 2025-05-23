// #include <string>
// #include <vector>
// #include <iostream>
// #include <queue>

// using namespace std;

// int t0 = 0;
// int t8 = 0;
// int t1 = 0;

// void searching(int startNode, vector<vector<int>>& graph)
// {
//     queue<int> q;
//     q.push(startNode);
    
//     bool isVisited = false;
    
//     while(!q.empty())
//     {
//         int currNode = q.front();
//         q.pop();
        
//         if(currNode == startNode && !isVisited)
//         {
//            ++t0;
//             return;
//         }                
        
//         if(graph[currNode].size() >= 2)
//         {
//             ++t8;
//             return;
//         }
        
//         for(int idx = 0; idx < graph[currNode].size(); ++idx)
//         {
//             q.push(graph[currNode][idx]);
//         }
//         isVisited = true;
//     }
//     ++t1;
//     return;
// }

// vector<int> solution(vector<vector<int>> edges) {
//     vector<int> answer;
    
//     vector<int> toVector(1000001, 0);
//     vector<int> fromVector(1000001, 0);
//     vector<vector<int>> graph(1000001);
    
//     int createdNode = 0;
    
//     for(const auto& edge : edges)
//     {
//         ++toVector[edge[0]];
//         ++fromVector[edge[1]];
        
//         graph[edge[0]].push_back(edge[1]);
//     }
    
//     for(int idx = 1; idx < 1000001; ++idx)
//     {
//         if(toVector[idx] >= 2 && fromVector[idx] == 0)
//         {
//             createdNode = idx;
//             answer.push_back(createdNode);
//             break;
//         }
//     }
    
//     vector<int> start = graph[answer[0]];
    
//     for(int idx = 0; idx < start.size(); ++idx)
//     {
//         searching(start[idx], graph);
//     }
    
//     answer.push_back(t0);
//     answer.push_back(t1);
//     answer.push_back(t8);
    
//     return answer;
// }

#include <string>  
#include <vector>  
#include <iostream>  
#include <queue>  
using namespace std;  
  
int inde[1000005];  
int outde[1000005];  
vector<vector<int>> path(1000005);  
int t8=0,t1=0,t0=0;  
  
void check(int start){  
	queue<int> q;  
	q.push(start);  
	bool isvisted = false;   //시작점을 방문 했는지
	while(!q.empty()){  
		int now = q.front();  
		q.pop();  
		if(now == start && isvisted){  
			t0++;  
			return;  
		}  
  
		if(path[now].size() >= 2){  
			t8++;  
			return;  
		}  
  
		for(int i=0; i< path[now].size(); i++){  
			q.push(path[now][i]);  
		}	  
		isvisted = true;  
	}  
	t1++;  
	return;  
}  
  
  
vector<int> solution(vector<vector<int>> edges) {  
	vector<int> answer;  
  
	for(int i=0; i<edges.size(); i++){  
		inde[edges[i][1]]++;  
		outde[edges[i][0]]++;  
		path[edges[i][0]].push_back(edges[i][1]);  
	}  
  
	for(int i=1; i<1000005; i++){  
		if(inde[i] == 0 && outde[i] >=2){  
			answer.push_back(i);  
		}  
	}  
  
	vector<int> start = path[answer[0]];  
	for(int i=0; i<start.size(); i++){  
		check(start[i]);  
	}  
	answer.push_back(t0);  
	answer.push_back(t1);  
	answer.push_back(t8);  
  
	return answer;  
}