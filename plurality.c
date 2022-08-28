#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    string nameCandidate;
    int vote;
}
candidatesAndVote;

void voteOne(string name);
void printWinner(void);

candidatesAndVote Candidates[4];
int main(int votes, string candidate[])
{
   
    
    for(int i = 0; i< votes;i++)
    {
        Candidates[i].nameCandidate = candidate[i];
    }
    
    for(int i = 0; i< votes;i++)
    {
        string VoteName = get_string("Candidate name:");
        
        voteOne(VoteName);
    }
   
    
    printWinner();
}



void voteOne(string name)
{
    for(int i = 0; i<4; i++)
    {
        if(strcmp(name, "Bob")== 0)
        {
            Candidates[i].vote +=1;
           printf("%i\n", Candidates[2].vote);
        }    

    }
}
void printWinner(void)
{
    int maior =  Candidates[0].vote;
    
    for(int i = 0; i<4; i++)
    {
       if(Candidates[i].vote > maior)
       {
           maior = Candidates[i].vote;
       }
    }
    for(int i = 0; i<4; i++)
    {
        if(maior == Candidates[i].vote)
        {
            printf("%s\n", Candidates[i].nameCandidate);
        }
    }
    
    
}
