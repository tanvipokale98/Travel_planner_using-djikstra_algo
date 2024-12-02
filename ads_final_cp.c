#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define no_of_talukas 13
struct features
{
    char visit[1][100];
    char stay[1][100];
};
struct features f[no_of_talukas];
int visited[no_of_talukas];
int dist[no_of_talukas], parent[no_of_talukas];
int source, destination;
char routes[no_of_talukas][20] = {"junnar", "ambegaon", "khed", "maval", "mulshi", "haveli", "velhe", "bhor", "purandar", "baramati", "shirur", "daundh", "indapur"};
// adjacency matrix of pune district
// 0=junnar 1=ambegaon 3=khed 4=maval 5=mulshi 6= haveli 7= vehle 8=bhor 9=purandar 10=baramati 11=shirur 12=daundh 13=indapur
// 0 represents 0 distance between 2 talukas and any other no. represents distance between 2 talukas those are directly connected
int adj[no_of_talukas][no_of_talukas] = {
    {0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0},
    {34, 0, 56, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0},
    {0, 56, 0, 60, 0, 47, 0, 0, 0, 0, 57, 0, 0},
    {0, 0, 60, 0, 73, 67, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 73, 0, 50, 70, 0, 0, 0, 0, 0, 0},
    {0, 0, 47, 67, 50, 0, 48, 65, 40, 0, 69, 80, 0},
    {0, 0, 0, 0, 70, 48, 0, 48, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 65, 48, 0, 63, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 40, 0, 63, 0, 100, 0, 80, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 42, 59},
    {76, 94, 57, 0, 0, 69, 0, 0, 0, 0, 0, 57, 0},
    {0, 0, 0, 0, 0, 80, 0, 0, 80, 42, 57, 0, 74},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 59, 0, 74, 0}};

// information of different talukas
void store()
{
    strncpy(f[0].visit[0], "Visit: {Shivneri Fort, Lenyadri Caves, Shri Girijatmaj Ganpati Temple}", 99);
    strncpy(f[0].stay[0], "Stay: {Hotel 7 Rays, Hotel Platinum}", 99);
    strncpy(f[1].visit[0], "Visit: {Pranav Sunset Point, Gujarwadi Waterfall}", 99);
    strncpy(f[1].stay[0], "Stay: {Omkar Executive, Hotel Ellora Park}", 99);
    strncpy(f[2].visit[0], "Visit: {Kundeshwar Temple, Parashuram temple}", 99);
    strncpy(f[2].stay[0], "Stay: {Prathamesh Farms and Agro Resort, Bisu Hotel & Resort}", 99);
    strncpy(f[3].visit[0], "Visit: {Khandi Waterfalls, Goradeshwar Temple}", 99);
    strncpy(f[3].stay[0], "Stay: {Maval Srushti, Adventure Maval Panshet}", 99);
    strncpy(f[4].visit[0], "Visit: {Mulashi Dam, Tamhini Ghat}", 99);
    strncpy(f[4].stay[0], "Stay: {The Green Gate Resort Mulashi}", 99);
    strncpy(f[5].visit[0], "Visit: {Dagadu Sheth Halwai Ganpati Mandir, Sinhgad Fort, ShanivarWada, Saras Baug}", 99);
    strncpy(f[5].stay[0], "Stay: {Hotel Grand Tullip, Sunndaram Hotel, Lokesh Hotel}", 99);
    strncpy(f[6].visit[0], "Visit: {Torana Fort, Panshet Dam, Rajgad Fort}", 99);
    strncpy(f[6].stay[0], "Stay: {Hotel Rajgad Niwara, Hotel Jai Malhar}", 99);
    strncpy(f[7].visit[0], "Visit: {Bhatghar Dam, Baneshwar Temple, Prati Balaji temple}", 99);
    strncpy(f[7].stay[0], "Stay: {Hotel Sarthak, Adventure Maval Panshet}", 99);
    strncpy(f[8].visit[0], "Visit: {Purandar Fort, Dive Ghat Valley, Torana Fort}", 99);
    strncpy(f[8].stay[0], "Stay: {Purandar resort}", 99);
    strncpy(f[9].visit[0], "Visit: {Bhigwan Bird Sanctuary, Vidya Pratishthan Museum, Krishi Vigyan Kendra}", 99);
    strncpy(f[9].stay[0], "Stay: {City Inn Baramati, Krishna Sagar Residency}", 99);
    strncpy(f[10].visit[0], "Visit: {Ranjangaon Ganpati Temple, Mayur Baug, Morachi Chincholi}", 99);
    strncpy(f[10].stay[0], "Stay: {Aranyagiri Countryside Resort, Hotel Sangram Palace}", 99);
    strncpy(f[11].visit[0], "Visit: {Mohangad Fort, Patas Lake, Shivaji Maharaj Shivsmarak}", 99);
    strncpy(f[11].stay[0], "Stay: {Hotel 7 Rays, Hotel Platinum}", 99);
    strncpy(f[12].visit[0], "Visit: {Bhigwan Bird Sanctuary, Shree Siddhivinayak Temple}", 99);
    strncpy(f[12].stay[0], "Stay: {The Royal Inn, Hotel Surya}", 99);
}
void route()
{
    // take input
    printf("\n---------------Welcome to TravelPlanner---------------------------\n");
    printf(" locations\n");
    printf("-----------------------------------------------------------\n");
    printf("id      location\n");
    for (int i = 0; i < 13; i++)
    {
        printf("%d\t%s\n", i, routes[i]);
    }
    // printf("0\tjunnar\n1\tambegaon\n2\tkhed\n3\tmaval\n4\tmulshi\n5\thaveli\n6\tvelhe\n7\tbhor\n8\tpurandar\n9\tbaramati\n10\tshirur\n11\tdaudh\n12\tindapur\n");
    printf("enter your source location id:");
    scanf("%d", &source);
    printf("enter your destination location id:");
    scanf("%d", &destination);
}
void display(int src)
{
    // print results
    printf("distance from vertex %d to %d is %dkm\n", src, destination, dist[destination]);
    printf("Path: ");
    int path[no_of_talukas];
    int count = 0;
    for (int i = destination; i != -1; i = parent[i])
    {
        path[count++] = i;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%s", routes[path[i]]);
        if (i > 0)
            printf(" -> ");
    }
    printf("\n");
    printf("**********************************************************\n");
    printf("suggestions on your destination %s\n", routes[destination]);
    printf("-------------------------------------------------------\n");
    printf("%s\n", f[destination].visit[0]);
    printf("%s\n", f[destination].stay[0]);
    printf("-------------------------------------------------------\n");
}

int findMin(int dist[no_of_talukas], int visited[no_of_talukas])
{
    int min = 10000, u = -1;
    for (int i = 0; i < no_of_talukas; i++)
    {
        if (visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            u = i;
        }
    }
    return u;
}
void dijkstra(int src)
{

    // dijikstras algorithm to find minimum distance from source taluka to destination taluka
    int u = -1;
    for (int i = 0; i < no_of_talukas; i++)
    {
        visited[i] = 0;
        dist[i] = 10000;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int i = 0; i < no_of_talukas - 1; i++)
    {
        u = findMin(dist, visited);
        visited[u] = 1;
        for (int j = 0; j < no_of_talukas; j++)
        {
            if (!visited[j] && adj[u][j] && dist[u] != 10000 && dist[u] + adj[u][j] < dist[j])
            {
                dist[j] = dist[u] + adj[u][j];
                parent[j] = u;
            }
        }
    }
    display(src);
}
int main()
{
    store();
    route();
    dijkstra(source);
}