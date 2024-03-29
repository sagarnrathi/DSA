#ifndef _COMMON_H
#define _COMMON_H

#define _CRT_RAND_S
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#define G_INVALID_VERTEX 2
#define G_INVALID_EDGE 3
#define G_VERTEX_EXIST 4
#define G_EDGE_EXIST 5
#define G_INCONSITENT 6

#ifndef V_BUCKET_SIZE 
#define V_BUCKET_SIZE 16
#endif

#ifndef H_BUCKET_SIZE
#define H_BUCKET_SIZE 16
#endif

typedef unsigned int vertex_t ;
typedef int status_t;
typedef long long ssize_t;
typedef struct hnode hnode_t;
typedef hnode_t hlist_t;
typedef struct vnode vnode_t;
typedef vnode_t vlist_t;
typedef struct hhashq hhashq_t ;
typedef struct vhashq vhashq_t ;
typedef enum color color_t;
typedef struct graph graph_t;

enum color{
    WHITE = 0 ,
    GRAY  ,
    BLACK
} ;

void *xmalloc(size_t number_of_bytes);

#endif;
