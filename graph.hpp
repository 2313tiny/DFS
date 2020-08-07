
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<iomanip>

#include<set>
#include<map>

#define YELLOW "\033[01;033m"
#define GREEN "\033[01;032m"
#define RESET "\033[01;0m"
#define RED "\033[01;031m"

const int GRAPH_ORDER = 10;
 
class Vertex{
public:
	std::string m_name;
	int m_node;

public:
	Vertex() : m_name("none")
		 , m_node(0) {}
	Vertex(const Vertex & t){
		this->m_name = t.m_name;
		this->m_node = t.m_node;
	}
	Vertex(const int n, const std::string name)
		: m_name(name)
		, m_node(n){}
	Vertex & operator=(const Vertex & obj)	
	{
		this->m_name = obj.m_name;
		this->m_node = obj.m_node;
		return *this;
	}
};

class Edge{
public:
	Vertex m_target;
	Vertex m_source;
	Edge(const Vertex & s, const Vertex & t)
	    : m_source(s)
	    , m_target(t){}
};


class Graph{
public:
	std::vector<Vertex> zenit; //vertex
	std::list<Edge> deposit[GRAPH_ORDER];	
public:
	Graph(){}
	Graph(const Graph & t){}
	Graph & operator=(const Graph &){}
public:
	void add_vertex(const Vertex & node){
		zenit.push_back(node);
	}
	void add_edge(const Vertex & s, const Vertex & t){
		int p = s.m_node;
		Edge e(s,t);
		deposit[p-1].push_back(e);
	}
	void display_edge(Vertex & vert) const{
		int p = vert.m_node;	
		std::list<Edge>::const_iterator edgeIt;
		for (edgeIt = deposit[p-1].begin();
		     edgeIt != deposit[p-1].end(); ++edgeIt){
		     //std::cout << edgeIt->m_source.m_name
		     std::cout << edgeIt->m_target.m_name << " ";
		}
	}
	void display() const{
		std::cout << YELLOW;
		std::cout << "You have this map " << RESET << std::endl;
		for (auto x : zenit){
			std::cout << x.m_node <<" "<< x.m_name << " -> ";
			display_edge(x);	
			std::cout << std::endl;
		}
	}
};


void DFS(Graph & graph, Vertex & start); //Breadth-first search

 
#endif //GRAPH_HPP
