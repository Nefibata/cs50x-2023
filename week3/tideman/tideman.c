#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool isCyclic(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i=0;i<candidate_count;i++){
        if(strcmp(candidates[i],name)==0){
            ranks[rank]=i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for(int i=0;i<candidate_count;i++){
        int temp=ranks[i];
        for(int j=0;j<candidate_count;j++){
            bool flag=true;
            for(int m=0;m<=i;m++){
                if(ranks[m]==j) flag=false;
            }
            if(flag){
                preferences[temp][j]+=1;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for(int i=0;i<candidate_count;i++){
        for (int j=0; j <candidate_count;j++){
            if(preferences[i][j]>preferences[j][i]){
                pairs[pair_count].winner=i;
                pairs[pair_count].loser=j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair temp={0,0};
    for (int i = 0; i < pair_count-1; i++) {
        for (int j = 0; j <pair_count -i-1; j++) {
            int temp2 =preferences[pairs[j].winner][pairs[j].loser]-preferences[pairs[j].loser][pairs[j].winner];
            int temp3 =preferences[pairs[j+1].winner][pairs[j+1].loser]-preferences[pairs[j+1].loser][pairs[j+1].winner];
            if ( temp2<temp3) {
                temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
            }
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for(int i=0;i<pair_count;i++){
        locked[pairs[i].winner][pairs[i].loser]=true;
        if(isCyclic()){
            locked[pairs[i].winner][pairs[i].loser]=false;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    bool winfind [candidate_count];
    for(int i=0;i<candidate_count;i++){
        for (int j=0; j <candidate_count;j++){
            if(locked[i][j]){
                winfind[j]=true;
            }
            
        }

    }
    for(int i=0;i<candidate_count;i++){
        if(!winfind[i]){
            printf("%s\n",candidates[i]);

        }
    }

    return;
}
bool dfs(int node, bool visited[], bool recStack[]) {
    if (recStack[node]) {
        return true;  // 发现了回溯边，存在环
    }
    if (visited[node]) {
        return false; // 已经完成遍历的节点，无需再处理
    }

    // 标记此节点为已访问和递归栈中
    visited[node] = true;
    recStack[node] = true;

    // 遍历所有邻接节点
    for (int i = 0; i < 9; i++) {
        if (locked[node][i]) {
            if (dfs( i, visited, recStack)) {
                return true;
            }
        }
    }

    // 移除递归栈中的标记（回溯时）
    recStack[node] = false;
    return false;
}

bool isCyclic(void) {
    bool visited[9] = {0};
    bool recStack[9] = {0};

    // 对每个节点进行DFS检查
    for (int i = 0; i < 9; i++) {
        if (!visited[i]) {
            if (dfs( i, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}
