#ifndef TEST_HPP
#define TEST_HPP
#include<iostream>
#include<cassert>
#define YELLOW "\033[01;033m"
#define GREEN "\033[01;032m"
#define RESET "\033[01;0m"
 
#include"graph.hpp" 
 
void test_v1()
{
 	Vertex point1(1, "Moscow");
	Vertex point2(2, "St.Petersburg");
	Vertex point3(3, "Kazan");
	Vertex point4(4, "Rostov");
	Vertex point5(5, "Magadan");
	Vertex point6(6, "Tuda-Uta");	
	Vertex point7(7, "Novosibirsk");
	Vertex point8(8, "Samara");
	Vertex point9(9, "Ufa");
	Vertex point10(10, "Yekaterinburg");

	Graph harta;
	harta.add_vertex(point1);	
	harta.add_vertex(point2);	
	harta.add_vertex(point3);	
	harta.add_vertex(point4);	
	harta.add_vertex(point5);	
	harta.add_vertex(point6);
	harta.add_vertex(point7);
	harta.add_vertex(point8);
	harta.add_vertex(point9);
	harta.add_vertex(point10);

	harta.add_edge( point1, point4 );
	harta.add_edge( point1, point2 );

	harta.add_edge( point2, point1 );
	harta.add_edge( point2, point3 );
	harta.add_edge( point2, point5 );
	harta.add_edge( point2, point7 );
	harta.add_edge( point2, point8 );
									
	harta.add_edge( point3, point2 );
	harta.add_edge( point3, point4 );
	harta.add_edge( point3, point9 );
	harta.add_edge( point3, point10 );

	harta.add_edge( point4, point1 );
	harta.add_edge( point4, point3 );

	harta.add_edge( point5, point2 );
	harta.add_edge( point5, point6 );
	harta.add_edge( point5, point7 );
	harta.add_edge( point5, point8 );

	harta.add_edge( point6, point5 );

	harta.add_edge( point7, point5 );
	harta.add_edge( point7, point8 );

	harta.add_edge( point8, point2 );
	harta.add_edge( point8, point5 );
	harta.add_edge( point8, point7 );

	harta.add_edge( point9, point3 );

	harta.add_edge( point10, point3 );
	
	std::cout << "\n\n";
	harta.display();
	
	std::cout << "\n\n";
	DFS(harta, point6);
}
void test_v2()
{
	//empty body
}
void test_v3()
{
	//empty body
}
 
 
#endif // TEST_HPP
