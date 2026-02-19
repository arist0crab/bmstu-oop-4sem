#include "edge.h"


status_t push_back_edge(edges_t &edges, const edge_t &edge)
{
    status_t sc = SUCCESS;

    if (edges.size == edges.capacity)
        sc = ERR_OUT_OF_RANGE;

    if (sc == SUCCESS)
        edges.array[edges.size++] = edge;

    return sc;
}

status_t allocate_edges_array(edges_t &edges, const size_t array_capacity)
{
    status_t sc = SUCCESS;

    edges.array = (edge_t *)calloc(array_capacity, sizeof(edge_t));
    if (edges.array == NULL)
        sc = ERR_MEM;

    if (sc == SUCCESS)
    {
        edges.size = 0;
        edges.capacity = array_capacity;
    }

    return sc;
}

status_t init_edges(edges_t &edges)
{
    edges.array = NULL;
    edges.capacity = 0;
    edges.size = 0;

    return SUCCESS;
}

status_t free_edges(edges_t &edges)
{
    if (edges.array)
        free(edges.array);

    edges.array = NULL;
    edges.capacity = 0;
    edges.size = 0;

    return SUCCESS;
}


