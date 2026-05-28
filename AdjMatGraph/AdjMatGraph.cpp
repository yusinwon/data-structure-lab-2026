#include "AdjMatGraph.h"

int main()
{
    SrchAMGraph g; 
    for (int i = 0; i < 7; i++) 
        g.insertVertex('A' + i);
    g.insertEdge(0, 1); 
    g.insertEdge(0, 3); 
    g.insertEdge(1, 2); 
    g.insertEdge(1, 3); 
    g.insertEdge(2, 3);
    g.insertEdge(4, 5); 
    g.insertEdge(3, 6); 
    g.insertEdge(4, 6); 
    printf("인접 행렬로 표현한 그래프\n");
    g.display();

    FILE* fp;
    fopen_s(&fp, "text_out.txt", "w"); 
        fprintf(fp, "--- 그래프 인접 행렬 데이터 ---\n");
        g.display(fp);
        fclose(fp);
        printf("\n'text_out.txt' 파일에 그래프 데이터가 저장되었습니다.\n");
  
    printf("\nDFS  ==> ");
    g.resetVisited();  
    g.DFS(0);         
    printf("\n");
    return 0;
}
