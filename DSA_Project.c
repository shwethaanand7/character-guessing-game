// DSA INNOVATIVE PROBLEM
// AKINATOR - CHARACTER GUESSING GAME (PLANETS)

#include<stdio.h>
#include<stdlib.h>

// node structure

struct planet
{
    char *question;
    char *yes, *no;
    struct planet *yesptr, *noptr;
};

// null checking

void null_check(struct planet *ptr)
{
    if (ptr==NULL)
    {
        printf("Memory cannot be allocated");
        exit(1);
    }
}

// creation of node

struct planet* create_tree_node(char *y, char *n, char *ques)
{                                           
    struct planet* new_planet=malloc(sizeof(struct planet));
    null_check(new_planet);
    new_planet->yes=y;
    new_planet->no=n;
    new_planet->question=ques;
    new_planet->yesptr=NULL;
    new_planet->noptr=NULL;
    return (new_planet);
}

// function for questions and their corresponding answers

struct planet* questions()
{
    struct planet* root=NULL;
    char *q1="Is your planet a Gas Giant?";
    char *ygg="jupiter,saturn,uranus,neptune";
    char *ngg="mercury,venus,earth,mars";
    root=create_tree_node(ygg, ngg, q1);
    
    struct planet* root2=NULL;
    char *q2="Is your planet Red in colour?";
    char *yrc="mars,venus";
    char *nrc="mercury,earth";
    root2=create_tree_node(yrc, nrc, q2);
    root->noptr=root2;
    
    struct planet* root3=NULL;
    char *q3="Is your planet Blue in colour?";
    char *ybc="neptune,uranus";
    char *nbc="jupiter,saturn";
    root3=create_tree_node(ybc, nbc, q3);
    root->yesptr=root3;
    
    struct planet* root4=NULL;
    char *q4="Is your planet the nearest to the sun?";
    char *yns="mercury";
    char *nns="earth";
    root4=create_tree_node(yns, nns, q4);
    root2->noptr=root4;
    
    struct planet* root5=NULL;
    char *q5="Are humans planning to call your planet their next home?";
    char *ynh="mars";
    char *nnh="venus";
    root5=create_tree_node(ynh, nnh, q5);
    root2->yesptr=root5;
    
    struct planet* root6=NULL;
    char *q6="Does your planet have rings around it?";
    char *yr="saturn";
    char *nr="jupiter";
    root6=create_tree_node(yr, nr, q6);
    root3->noptr=root6;
    
    struct planet* root7=NULL;
    char *q7="Is your planet the farthest from the sun?";
    char *yfs="neptune";
    char *nfs="uranus";
    root7=create_tree_node(yfs, nfs, q7);
    root3->yesptr=root7;
    
    return(root);
    
}

// deleting the tree

void deletetree(struct planet** rootptr)
{
    if((*rootptr)==NULL){
        return;
    }
    deletetree(&(*rootptr)->yesptr);
    deletetree(&(*rootptr)->noptr);
    printf("Deleting Node: %s\n", (*rootptr)->question);
    free(*rootptr);
    *rootptr=NULL;
}

// function to make a guess

void guess(struct planet* root)
{
    while(root)
    {
        char c,f;
        printf("%s\n",root->question);
        printf("y or n? ");
        scanf("%c",&c);
        printf("\n");
        while ((f=getchar()) != '\n' && f !=EOF);
        if(c == 'y')
        {
            if(root->yesptr==NULL){
                printf("Your planet is %s.",root->yes);
                break;
            }
            else{
                root=root->yesptr;
            }
        }
        else if (c == 'n')
        {
            if(root->noptr==NULL){
                printf("Your planet is %s.",root->no);
                printf("\n");
                break;
            }
            else{
                root=root->noptr; 
            }
        }
        else
        {
            printf("Enter a valid input\n");
            printf("\n");
        }
    }
}

// main function

int main()
{
    printf("Welcome to Akinator\nThink of a planet.\n");
    printf("\n");
    char p,c;
    struct planet* root= questions();
    while (1)
    {
        guess(root);
        printf("\n");
        printf("Press p to play again. ");
        scanf("%c",&p);
        printf("\n");   
        while ((c=getchar()) != '\n' && c != EOF);
        if (p!='p')
        {
            printf("Thanks for playing!");
            break;
        }
    }
}