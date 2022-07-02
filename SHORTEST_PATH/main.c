#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_INT 2147483647

struct Vertex
{
	struct Vertex* next;
	int length;
	int endVertex;
};

void readConnections(struct Vertex** graph)
{
	int startVertex, endVertex, length;
	scanf_s("%d", &startVertex);
	scanf_s("%d", &endVertex);
	scanf_s("%d", &length);

	struct Vertex* newConnection = (struct Vertex*)malloc(sizeof(struct Vertex));
	struct Vertex* tmp = NULL;

	newConnection->endVertex = endVertex;
	newConnection->length = length;
	newConnection->next = NULL;

	if (graph[startVertex] == NULL)
	{
		graph[startVertex] = newConnection;
	}
	else
	{
		tmp = graph[startVertex];
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newConnection;
	}
	newConnection = NULL;
	tmp = NULL;

	newConnection = (struct Vertex*)malloc(sizeof(struct Vertex));
	newConnection->endVertex = startVertex;
	newConnection->length = length;
	newConnection->next = NULL;

	if (graph[endVertex] == NULL)
	{
		graph[endVertex] = newConnection;
	}
	else
	{
		tmp = graph[endVertex];
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newConnection;
	}

	tmp = NULL;
	newConnection = NULL;
	free(tmp);
	free(newConnection);
}

void dijkstraAlgorithm(struct Vertex** graph, int numberOfNodes)
{
	int startVertex, endVertex, index, minimumLength, j, k;
	struct Vertex* tmp = NULL;

	int * minLength = (int*)malloc(numberOfNodes * sizeof(int));
	int * verticeBefore = (int*)malloc(numberOfNodes * sizeof(int));
	bool * usedVertices = (bool*)malloc(numberOfNodes * sizeof(bool));

	scanf_s("%d", &startVertex);
	scanf_s("%d", &endVertex);

	for (j = 0; j < numberOfNodes; j++)
	{
		minLength[j] = MAX_INT;
		verticeBefore[j] = -1;
		usedVertices[j] = false;
	}

	minLength[startVertex] = 0;
	index = startVertex;

	for (j = 0; j < numberOfNodes; j++)
	{
		minimumLength = MAX_INT;

		for (k = 0; k < numberOfNodes; k++)
		{
			if (minLength[k] < minimumLength && !usedVertices[k])
			{
				minimumLength = minLength[k];
				index = k;
			}
		}
		usedVertices[index] = true;

		tmp = graph[index];

		while (tmp != NULL)
		{
			if (minLength[tmp->endVertex] > minLength[index] + tmp->length)
			{
				minLength[tmp->endVertex] = minLength[index] + tmp->length;
				verticeBefore[tmp->endVertex] = index;
			}
			tmp = tmp->next;
		}
	}

	if (minLength[endVertex] == MAX_INT)
		printf("!\n");
	else
		printf("%d\n", minLength[endVertex]);

	free(minLength);
	free(verticeBefore);
	free(usedVertices);
}

int main()
{
	int i = 0;
	int numberOfNodes, numberOfConnections, numberOfTests;
	struct Vertex** graph;

	scanf_s("%d", &numberOfNodes);
	scanf_s("%d", &numberOfConnections);
	
	graph = (struct Vertex**)malloc(numberOfNodes * sizeof(struct Vertex*));

	for (i = 0; i < numberOfNodes; i++)
	{
		graph[i] = NULL;
	}

	for (i = 0; i < numberOfConnections; i++)
	{
		readConnections(graph);
	}

	scanf_s("%d", &numberOfTests);

	for (i = 0; i < numberOfTests; i++)
	{
		dijkstraAlgorithm(graph, numberOfNodes);
	}	

	for (i = 0; i < numberOfNodes; i++)
	{
		free(graph[i]);
	}
	free(graph);

	return 0;
}