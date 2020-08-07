#include "graph.hpp" 


void DFS(Graph & graph,Vertex & start)
{
	std::vector<Vertex> likeStack;	
	std::vector<Vertex>::const_iterator likeStackIt;	
	std::vector<Vertex>::const_iterator likeStackCheckedIt;
	
	std::vector<Vertex>::const_iterator zenitIt;
	std::list<Edge>::iterator depositIt;
	std::multimap<bool, Vertex> checked;
	std::multimap<bool, Vertex>::iterator checkedIt;

	for (zenitIt = graph.zenit.begin();
		 zenitIt != graph.zenit.end(); ++zenitIt){
		checked.insert(std::make_pair(false, *zenitIt));
	}


//	likeStackIt = likeStack.begin();
	likeStackCheckedIt = likeStackIt;
	likeStackCheckedIt = likeStack.begin();		

	std::vector<Vertex> traverse;
	std::vector<Vertex>::iterator traverseIt;
	std::vector<Vertex>::iterator traverseCheckedIt;

	traverse.push_back(start);     //this is the beginning
	traverseIt = traverse.begin();
	traverseCheckedIt = traverseIt;
	Vertex checkNode; //for verifying checked node or not
	Vertex traverseTemp;
	Vertex likeStackTemp;

	//need for checking node 
	//if true means node was checked , false - not
	for (checkedIt = checked.begin(); checkedIt != checked.end(); ++checkedIt){	
		if (checkedIt->second.m_node == start.m_node){
		int node = checkedIt->second.m_node;
		std::string name = checkedIt->second.m_name;
		Vertex phantomNode(node, name);
		checked.erase(checkedIt);
		checked.insert(std::make_pair(true, phantomNode));
		}
	}


//.... DONE
	int times = 0; //for countion traverseIt++;
	int markStackCount = 0; //for counting source node
	int markTargetCount = 0;//for counting target node
	int markStackCountRepeat = 0; //for counting repeat node if have not target
	bool hasCycle = false; // end of traverse node and t_target node same or not 
	likeStackIt = likeStack.begin(); //need after new push_back action
	traverseIt = traverse.begin(); // need after new push_back action
		
	int node = traverseIt->m_node -1;

	for (depositIt = graph.deposit[node].begin(); 
	     depositIt != graph.deposit[node].end(); ++depositIt){

	    if(traverseIt->m_node == depositIt->m_source.m_node){
		if (0 == markTargetCount){
			//std::cout << depositIt->m_target.m_name << " ";
			for(checkedIt = checked.begin(); 
			      checkedIt != checked.end(); ++checkedIt){
				if ((checkedIt->second.m_node == depositIt->m_target.m_node)	
				     &&  (false == checkedIt->first)){
					traverse.push_back(depositIt->m_target);	
					likeStack.push_back(depositIt->m_source);
					++markTargetCount;
					//change mode for this node false/true
					for (checkedIt = checked.begin();
					      checkedIt != checked.end(); ++checkedIt){
						if(checkedIt->second.m_name == depositIt->m_target.m_name){
						  checked.erase(checkedIt);
						  checked.insert(std::make_pair(true, depositIt->m_target));
						}
					}
				}  
			}
	        }			
	   }				
	}

 for (int i = 0; i <= GRAPH_ORDER ; ++i){ 

	hasCycle = false;
	markStackCount = 0; //for counting source node
	markTargetCount = 0;//for counting target node
	likeStackIt = likeStack.begin(); //need after new push_back action
	traverseIt = traverse.begin(); // need after new push_back action


   if (markStackCountRepeat == 0){

	//checking for having cycle
	node = traverse.back().m_node -1;
	for (depositIt = graph.deposit[node].begin();
		 depositIt != graph.deposit[node].end(); ++depositIt){
		if (traverse.back().m_node == depositIt->m_target.m_node){
			hasCycle = true; //in case having cycle need only ++i
		} 
	}
	if (true == hasCycle ) { 
		++traverseIt;
	}else{
		++times;
		for(int count = 0; count < times; ++count){
			++traverseIt;
			}
		}
   }


	node = traverseIt->m_node -1;
	//binding likeStack and traverse
	//binding(graph, traverse, int markStackCount, int markTargetCount, checked);
	for (depositIt = graph.deposit[node].begin(); 
	     depositIt != graph.deposit[node].end(); ++depositIt){

	    if(traverseIt->m_node == depositIt->m_source.m_node){
		if (0 == markTargetCount){
			//std::cout << depositIt->m_target.m_name << " ";
			for(checkedIt = checked.begin(); 
			      checkedIt != checked.end(); ++checkedIt){
				if ((checkedIt->second.m_node == depositIt->m_target.m_node)	
				     &&  (false == checkedIt->first)){
					traverse.push_back(depositIt->m_target);	
					likeStack.push_back(depositIt->m_source);
					++markTargetCount;
					//change mode for this node false/true
					for (checkedIt = checked.begin();
					      checkedIt != checked.end(); ++checkedIt){
						if(checkedIt->second.m_name == depositIt->m_target.m_name){
						  checked.erase(checkedIt);
						  checked.insert(std::make_pair(true, depositIt->m_target));
						}
					}
				}  
			}
	        }			
	   }				
	}
	
	//unbinding likeStack 
     if (0 == markTargetCount){
	node = likeStack.back().m_node -1;
	for (depositIt = graph.deposit[node].begin();
		 depositIt != graph.deposit[node].end(); ++depositIt){
			
			if(0 == markStackCount){
				for(checkedIt = checked.begin(); 
				   checkedIt != checked.end(); ++checkedIt){
				    if((checkedIt->second.m_node == depositIt->m_target.m_node) 
					&& (false == checkedIt->first)){
					traverse.push_back(depositIt->m_target);
					markStackCount = 0;
					markStackCountRepeat = 0;
					//change mode this node false/true;
					for (checkedIt = checked.begin(); 
					      checkedIt != checked.end(); ++checkedIt){
					    if(checkedIt->second.m_name == depositIt->m_target.m_name){
						checked.erase(checkedIt);
						checked.insert(std::make_pair(true, depositIt->m_target));	
					    }
					}	
				    } else {++markStackCountRepeat;}		
				}
			}
	}

    if (0 == markStackCount ){
		likeStack.pop_back();
	}
    }

} // end of checkedIt for 


///********* PART FOR TESTING  ****************/////////
	std::cout << RED ;
	std::cout << ".... checked node" << std::endl;	
	std::cout << RESET;

	for (auto x : checked ){
		std::cout <<"["<< x.first << "]  ";
		std::cout << x.second.m_node << " " << x.second.m_name << " " << std::endl;
	}

	std::cout << YELLOW << "... inside the likeStack .... " << RESET << std::endl;
	for (auto x : likeStack){
		std::cout << x.m_node << " " << x.m_name << " ";
	}
	std::cout << GREEN << "\nDepth first search for "
 		  << "traversing graph data structure\n" << RESET;
		for (auto x : traverse){
		std::cout << x.m_node  << " " << x.m_name << " - ";
	}
}
